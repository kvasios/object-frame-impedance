#!/bin/bash
# Thesis Compilation Script
# Requires: XeLaTeX (for Greek fonts) + BibTeX
set -e
cd "$(dirname "$0")"

MAIN="KVasios-ECE-Dipl.-Thesis"

echo "=== Compiling: ${MAIN}.tex ==="
echo ""

# Check for xelatex
if ! command -v xelatex &> /dev/null; then
    echo "ERROR: xelatex not found!"
    echo "Install with: sudo apt install texlive-xetex texlive-fonts-extra"
    exit 1
fi

# First pass
echo "[1/4] First XeLaTeX pass..."
xelatex -interaction=nonstopmode "${MAIN}.tex" || {
    echo "First pass failed (may need fonts). Check ${MAIN}.log"
    exit 1
}

# BibTeX
echo "[2/4] BibTeX pass..."
bibtex "${MAIN}" || {
    echo "BibTeX failed. Check ${MAIN}.blg"
    exit 1
}

# Second pass (resolve references)
echo "[3/4] Second XeLaTeX pass..."
xelatex -interaction=nonstopmode "${MAIN}.tex"

# Third pass (finalize)
echo "[4/4] Final XeLaTeX pass..."
xelatex -interaction=nonstopmode "${MAIN}.tex"

echo ""
echo "=== Compilation Complete ==="
echo "Output: ${MAIN}.pdf"
echo ""

# Show page count
if command -v pdfinfo &> /dev/null; then
    PAGES=$(pdfinfo "${MAIN}.pdf" 2>/dev/null | grep Pages | awk '{print $2}')
    echo "Pages: ${PAGES}"
fi

