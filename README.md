## Computer Graphics HW 6 - 202011378 차현준


Components Implemented
1. Software Rasterizer<br>
Triangles are rasterized in screen space using a bounding box loop and barycentric coordinates.
<br>
Per-pixel depth values are interpolated and stored in a custom DepthBuffer for visibility handling.

2. Transformations<br>
Vertices are transformed through a standard Model-View-Projection (MVP) pipeline using glm.
<br><br>
Normal vectors are transformed using the normal matrix: transpose(inverse(model)).
<br><br>
3. Lighting (Phong Reflection Model)<br>
All three shading models are based on the same lighting function:
<br><br>
vec3 color = ambient + diffuse + specular;<br>
Ambient, diffuse, and specular terms are computed using a point light source at (-4, 4, -3).
<br><br>
Gamma correction (1/2.2) is applied after shading to match monitor display.
<br><br>
Shading Techniques Implemented<br/>
Flat Shading<br>
One lighting computation per triangle.<br>
<br>
The color is calculated at the triangle centroid using the face normal.
<br><br>
Entire triangle is filled with this single color.
<br><br>
Gouraud Shading<br>
Lighting is computed per vertex using precomputed smooth normals.
<br><br>
The final pixel color is interpolated using barycentric weights.
<br><br>
Highlight artifacts may occur depending on mesh resolution.
<br><br>
Phong Shading<br>
Per-pixel normal and position are interpolated across the triangle.
<br><br>
Lighting is calculated at each pixel, resulting in smooth highlights and superior realism.
<br><br>
Significantly improves specular quality over Gouraud shading.
<br><br>
Mesh Generation<br>
A UV-sphere is procedurally generated with adjustable stacks and slices.
<br><br>
Vertex positions and smooth normals are computed and stored in global buffers.
<br><br>
Shared vertices across triangles ensure proper normal interpolation and shading continuity.
<br><br>
Compliance with Assignment Restrictions<br/>
No use of OpenGL’s vertex pipeline, triangle rasterization, or fragment shading.
<br><br>
Only glDrawPixels() is used for displaying the final rendered image.
<br><br>
All transformations, shading, and visibility testing are done entirely on the CPU.
<br><br>
Final Output Quality<br>
Visual quality is dependent on mesh resolution.
<br><br>
Recommended: stacks = 128, slices = 128 or higher for smooth shading.
<br><br>

## Results
<br><br>
![image](https://github.com/user-attachments/assets/08a9d7b5-b759-4d94-aaed-a8f0a26a3cfa)
<br>
Flat Shading

<br><br>
![image](https://github.com/user-attachments/assets/78df9417-58f9-4a77-ab17-440110f23407)
<br>
Gouraud Shading

<br><br>
![image](https://github.com/user-attachments/assets/6281f19c-f2e2-4c1b-bc53-ad4200105dcb)
<br>
Phong Shading

