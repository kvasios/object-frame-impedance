# Object Frame Impedance Control

My diploma thesis from ECE NTUA (2013) - finally rescued from a dusty hard drive after 13 years! 🎓

## What is this?

A MATLAB/Simulink implementation of **object-level impedance control** for a simulated 4-finger (16-DoF) robotic hand, using the ODE physics engine.

### ⚠️ Important Note

**~90% of this work is a reproduction** of the method presented in:

> **T. Wimböck, C. Ott, G. Hirzinger**  
> *"Passivity-based Object-Level Impedance Control for a Multifingered Hand"*  
> IEEE/RSJ International Conference on Intelligent Robots and Systems (IROS), 2006, pp. 4621-4627  
> [DOI: 10.1109/IROS.2006.282170](https://doi.org/10.1109/IROS.2006.282170)

**My actual contribution:**
- Full mathematical analysis of the control framework (went a bit overboard honestly - the thesis is heavy on math)
- Complete Forward Kinematics analysis with DH parameter determination for the 4-finger hand
- Full dynamics equations of the fingers derived symbolically using the [Robotica](http://www.obreschkow.de/Robotica/) package for Mathematica (Euler-Lagrange formulation)
- Gravity compensation term computed symbolically in Mathematica (yes, the whole thing)
- Mathematical justification for why the proposed stiffness parameters make sense
- Enhanced damping control law (integrated from another paper)
- Implementation in MATLAB/Simulink with ODE physics engine (which was a nightmare to set up back then)
- Results reproduction and validation
- Extension to the contact force model

The core control idea is not mine - that's Wimböck et al.'s work. But the thesis includes extensive mathematical derivations and analysis that go beyond the original paper, plus the complete simulation framework.

## Demo

| Translation + Rotation | Force Response |
|:----------------------:|:--------------:|
| ![translation_rotation](media/translation_rotation1.gif) | ![force](media/Force1.gif) |

## What's in here

- 📄 **[Thesis PDF](doc/dipl.-thesis/K.Vasios-ECE-Dipl.-Thesis.pdf)** - The full diploma thesis (in Greek)
- 📝 **[LaTeX source](doc/dipl.-thesis/latex/)** - If you want to compile it yourself
- 🔧 **[MATLAB/Simulink code](matlab/)** - The simulation implementation
- 🧮 **[Mathematica notebooks](mathematica/)** - Symbolic dynamics derivation using Robotica (inertia matrix, gravity terms, Jacobians)
- 🎬 **[Videos](media/)** - Simulation recordings

## TL;DR

The idea (from Wimböck et al.): instead of controlling each finger joint separately, control the *object's* position/orientation directly through impedance control. The controller makes the grasped object behave like a mass-spring-damper system in Cartesian space, with internal forces maintaining grasp stability.

## Building the thesis

```bash
cd doc/dipl.-thesis/latex
./compile.sh
```

Requires XeLaTeX + GFS Didot Greek fonts. See [thesis README](doc/dipl.-thesis/README.md) for details.

---

*Supervisor: Prof. Konstantinos Tzafestas, Signals Control & Robotics, ECE NTUA*
