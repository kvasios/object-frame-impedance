#!/bin/bash
# Thesis Compilation Script (English build)
# Requires: XeLaTeX + BibTeX
#
# Usage:
#   ./compile-en.sh            # compile only
#   ./compile-en.sh --release  # compile, clean artifacts, copy PDF to ../

cd "$(dirname "$0")"

MAIN="KVasios-ECE-Dipl.-Thesis-EN"
OUT_PDF="K.Vasios-ECE-Dipl.-Thesis-EN.pdf"
RELEASE=false

# Parse arguments
for arg in "$@"; do
    case $arg in
        --release)
            RELEASE=true
            shift
            ;;
    esac
done

echo "=== Compiling: ${MAIN}.tex ==="
echo ""

# Check for xelatex
if ! command -v xelatex &> /dev/null; then
    echo "ERROR: xelatex not found!"
    echo "Install with: sudo apt install texlive-xetex texlive-fonts-extra"
    exit 1
fi

# First pass (xelatex may return non-zero on warnings, so we check for output instead)
echo "[1/4] First XeLaTeX pass..."
xelatex -interaction=nonstopmode -shell-escape "${MAIN}.tex" || true
if [ ! -f "${MAIN}.aux" ]; then
    echo "First pass failed catastrophically. Check ${MAIN}.log"
    exit 1
fi

# BibTeX (only if bibliography is requested in the .aux)
if grep -q "\\\\bibdata" "${MAIN}.aux" 2>/dev/null; then
    echo "[2/4] BibTeX pass..."
    bibtex "${MAIN}" || true
else
    echo "[2/4] BibTeX pass... skipped (no bibliography)"
fi

# Second pass (resolve references)
echo "[3/4] Second XeLaTeX pass..."
xelatex -interaction=nonstopmode -shell-escape "${MAIN}.tex" || true

# Third pass (finalize)
echo "[4/4] Final XeLaTeX pass..."
xelatex -interaction=nonstopmode -shell-escape "${MAIN}.tex" || true

# Check we have a PDF
if [ ! -f "${MAIN}.pdf" ]; then
    echo "ERROR: No PDF generated. Check ${MAIN}.log"
    exit 1
fi

echo ""
echo "=== Compilation Complete ==="

# Show page count
if command -v pdfinfo &> /dev/null; then
    PAGES=$(pdfinfo "${MAIN}.pdf" 2>/dev/null | grep Pages | awk '{print $2}')
    echo "Pages: ${PAGES}"
fi

if [ "$RELEASE" = true ]; then
    echo ""
    echo "=== Release Mode ==="
    
    # Copy PDF to parent directory with final name
    cp -f "${MAIN}.pdf" "../${OUT_PDF}"
    echo "Copied: ../${OUT_PDF}"
    
    # Clean up LaTeX artifacts
    echo "Cleaning up artifacts..."
    rm -f "${MAIN}.aux" "${MAIN}.log" "${MAIN}.out" "${MAIN}.toc"
    rm -f "${MAIN}.lof" "${MAIN}.lot" "${MAIN}.bbl" "${MAIN}.blg"
    rm -f "${MAIN}.nav" "${MAIN}.snm" "${MAIN}.vrb" "${MAIN}.fls"
    rm -f "${MAIN}.fdb_latexmk" "${MAIN}.synctex.gz"
    rm -f "${MAIN}.pdf"  # remove local copy (final is in ../)
    rm -f texput.log
    
    echo "Artifacts cleaned."
    echo ""
    echo "Final output: doc/dipl.-thesis/${OUT_PDF}"
else
    # Just rename locally
    cp -f "${MAIN}.pdf" "${OUT_PDF}"
    echo "Output: ${OUT_PDF}"
    echo ""
    echo "Tip: Use --release to clean artifacts and copy PDF to ../"
fi
