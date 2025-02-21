# Ray Tracing Reality: One of My Most Complex Creations

**miniRt-3D-RayTracer** is a fully-featured, customizable 3D ray tracing engine developed in C. It supports advanced features such as reflection, refraction, shadows, and a variety of other ray tracing effects. The project is designed to both demonstrate ray tracing techniques and provide a tool for rendering 3D scenes using simple configuration files.

## Project Overview

The primary goal of **miniRt-3D-RayTracer** is to provide a fully featured ray tracing engine, demonstrating advanced rendering techniques in a customizable and accessible way. It was built as both an educational tool for understanding ray tracing principles and a production-quality renderer capable of producing photorealistic scenes.

### Key Features:
- **Reflection:** Accurately models the reflection of light rays off surfaces.
- **Refraction:** Simulates the bending of light as it passes through transparent materials (e.g., glass or water).
- **Shadows:** Generates realistic shadows by tracing light paths and checking for occlusions.
- **Ray Tracing Effects:** Includes advanced features like anti-aliasing, depth of field, and more, adding realism to the rendered scene.
- **Customizable Scene Configurations:** Easily customize the 3D scene using the `/miniRt/parsing/parse_example.rt` configuration file. You can define different objects, materials, and lighting.
- **Flexible Rendering Pipeline:** The engine processes each object in the scene, traces rays, calculates color, and handles lighting effects to generate realistic images.

## How Ray Tracing Works

Ray tracing is a rendering technique that simulates the way light interacts with objects in a scene to create realistic images. It traces the path of rays as they travel through the scene, bouncing off surfaces or passing through transparent materials. This process includes key steps such as:

1. **Ray Casting:** For each pixel on the screen, a ray is cast into the scene to determine what object it hits.
2. **Lighting Calculations:** Based on the intersection point, the engine calculates how light from different sources interacts with the object. This includes diffuse, specular, reflection, and refraction components.
3. **Reflection and Refraction:** When rays hit reflective or refractive surfaces, new rays are generated to trace their paths and calculate color contributions from the surrounding environment.
4. **Shadows:** Rays are traced towards light sources to check if an object casts a shadow on the surface where the initial ray hit.
5. **Advanced Effects:** MiniRt includes various additional ray tracing techniques like anti-aliasing and depth of field to improve visual quality.
   
![Raytracing](https://github.com/user-attachments/assets/7806446e-cc36-42d0-9353-2de69aa16b5b)


## Key Implemented Features:
- **Reflection & Refraction:** Fully implemented using recursive ray tracing, allowing for reflective and transparent surfaces to be modeled.
- **Shadows:** Shadows are cast by tracing rays from the intersection point to the light sources, ensuring realistic shading.
- **Anti-Aliasing:** Implemented for smooth edges and better visual results.
- **Depth of Field:** Simulated by varying the rays’ origins slightly, creating a blur effect on out-of-focus objects.
- **Multiple Light Sources:** The engine supports multiple types of light sources that interact with materials and objects in the scene.

## Installation & Usage

### Prerequisites
- **GCC Compiler**
- **Libraries:**  
  minilibX (lib built on X11 protocol to draw a pixel in a canva) 

### Building the Project
1. **Clone the repository:**
   ```bash
   git clone https://github.com/Poider/miniRt-3D-RayTracer.git
   cd miniRt-3D-RayTracer/miniRt/
   ```

2. **Build the project using make:**
   ```bash
   make
   ```
   This command compiles all source files and generates the `miniRt` executable.

### Running the Ray Tracer
To render a scene, use the `miniRt` executable along with a configuration file (e.g., `parse_example.rt`):
```bash
./miniRt /parsing/parse_example.rt
```
This will render the 3D scene described in `parse_example.rt` with all the implemented ray tracing effects.

### Customizing Scenes
- The scene configuration file (`parse_example.rt`) allows you to customize various elements:
  - **Objects:** Define spheres, planes, and other geometric shapes.
  - **Materials:** Set properties like color, reflectivity, transparency, and texture.
  - **Lighting:** Add different types of light sources to illuminate the scene.
  - **Camera:** Adjust the camera’s position and orientation to define the view of the scene.

Simply edit the `parse_example.rt` file to define new objects, materials, and lighting setups. You can experiment with different configurations to create your own 3D scenes.

## Outcome

Once you run the ray tracer with your custom configuration file, the program will render an image that looks something like this:

```bash
$ ./miniRt /miniRt/parsing/parse_example.rt
Rendering scene...
Scene rendered successfully!
```

Your rendered scene will be opened in a window by minilibX.

Here is a brief description of how different features look in the rendered output:


- **Basic Shapes:**

<img width="1022" alt="Basic shapes" src="https://github.com/user-attachments/assets/2d3f6fbb-ae43-4e10-a62a-830b879df391" />

<p style="margin-bottom: 50px;"></p>

- **Index of Refraction from 1.0 to 2.0:**

<div style="display: flex; justify-content: center; gap: 10px;">
    <img src="https://github.com/user-attachments/assets/b17c3344-9985-4f60-9781-f711c992416a" width="120">
    <img src="https://github.com/user-attachments/assets/1c0bdda9-8827-4263-aa90-2ab275d07c49" width="120">
    <img src="https://github.com/user-attachments/assets/93cf9491-6812-48c9-8863-8e7ced93d8f7" width="120">
    <img src="https://github.com/user-attachments/assets/4716759e-c99c-4cf4-8bf2-c4a328169ba5" width="120">
    <img src="https://github.com/user-attachments/assets/84a23c1d-46ba-4162-89df-e0a872b075a0" width="120">
    <img src="https://github.com/user-attachments/assets/af1920eb-0e67-4d7f-b295-603b57c48984" width="120">
</div>

<p style="margin-bottom: 50px;"></p>

- **Rendering Multiple Objects:**

![Multiple Blocks](https://github.com/user-attachments/assets/1ee26874-6885-4584-b4b7-65d70e427eb2)

 <p style="margin-bottom: 50px;"></p>
 
- **Cornel Box:** 

![cornellbox](https://github.com/user-attachments/assets/3d7c1c32-7b1b-4a34-9ec3-e7d0c609145f)



- **Objects With Texures Mapping:**

![Texures](https://github.com/user-attachments/assets/3f850abb-7675-4a85-a193-54657088034f)

# Example scene configuration for miniRt
## Scene Configuration Guide
Each **.rt** configuration file consists of different elements that define the scene:

### Ambient Light
```
ambient
// ambient light ratio 0-1
// ambient light color
END
```

### Light Source
```
light
// light coordinates
// light brightness
// light color
END
```

### Camera
```
camera
// camera coordinates
// normalized orientation vector
// field of view
END
```

### Objects
Each object type has specific parameters and transformations.

#### Sphere
```
sphere
// sphere diameter
// sphere coordinates
    // transformations
// sphere color
// reflection
// transparency
// refractive index
// pattern // pattern_type pattern_color1 pattern_color2
    // if pattern then pattern transformations here / NULL
// specular
// diffuse
END
```

#### Plane
```
plane
// plane coordinates
    // transformations
// plane color
// reflection
// transparency
// refractive index
// pattern // pattern_type pattern_color1 pattern_color2
    // if pattern then pattern transformations here / NULL
// specular
// diffuse
END
```

#### Cylinder
```
cylinder
// cylinder diameter
// cylinder coordinates
    // transformations
// max height
// cylinder color
// reflection
// transparency
// refractive index
// pattern // pattern_type pattern_color1 pattern_color2
    // if pattern then pattern transformations here / NULL
// specular
// diffuse
// closed TRUE/FALSE
END
```

#### Cone
```
cone
// cone diameter
// cone coordinates
    // transformations
// cone height
// cone color
// reflection
// transparency
// refractive index
// pattern // pattern_type pattern_color1 pattern_color2
    // if pattern then pattern transformations here / NULL
// specular
// diffuse
// closed TRUE/FALSE
END
```

---

## Transformations & Patterns

### Transformations
Transformations modify object positioning, scaling, and rotation:
```
ROTX ROTY ROTZ TRANSLATE SCALE SHEAR
```
- **ROTX, ROTY, ROTZ** → Rotate object along X, Y, or Z axis.
- **TRANSLATE** → Move object in 3D space.
- **SCALE** → Resize object.
- **SHEAR** → Skew object.

### Patterns
Patterns define how colors are applied to an object:
```
CHECKERBOARD RING STRIPE GRADIENT
```
- **CHECKERBOARD** → Chess-like alternating colors.
- **RING** → Concentric rings.
- **STRIPE** → Stripes in a direction.
- **GRADIENT** → Smooth color transition.

Patterns can also be transformed just like objects.

---

## Example Scene Configuration
```sh
ambient
0.5
255, 255, 255
END

light
0, 10, 10
1.0
255, 255, 255
END

camera
0, 0, -10
0, 0, 1
60
END

sphere
2
0, 0, 5
TRANSLATE 2 0 0 SCALE 1.5
255, 0, 0
0.5
0.2
1.5
CHECKERBOARD 255,255,255 0,0,0
NULL
0.8
0.6
END
```
This scene places a red sphere with a checkerboard pattern, reflections, and transparency.

---

After saving changes to your `.rt` file, you can run `miniRt` again to render your custom scene.


## Contribution Guidelines

Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a feature branch.
3. Commit your changes with clear and descriptive messages.
4. Open a pull request detailing your changes and suggestions.

For significant changes, please open an issue first to discuss your proposed modifications.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
