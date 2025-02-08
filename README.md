# Qt c++

## Starting:
firstly you may need to use the following commands in linux:
```bash
export CMAKE_PREFIX_PATH="/path/to/Qt6:$CMAKE_PREFIX_PATH"
```
You may find the error like the following when build:
```bash
Could NOT find OpenGL (missing: OPENGL_opengl_LIBRARY OPENGL_glx_LIBRARY OPENGL_INCLUDE_DIR) 
-- Could NOT find OpenGL (missing: OPENGL_opengl_LIBRARY OPENGL_INCLUDE_DIR OpenGL) 
-- Could NOT find WrapOpenGL (missing: WrapOpenGL_FOUND) 
```
to solve this error:
```bash
sudo apt-get install mesa-common-dev
```
