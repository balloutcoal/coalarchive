To run a desktop environment on Linux you need graphics drivers. 90% of distros come pre-loaded which do all the work for you
## Check current graphics card(s)
 ```
$ lspci -k | grep -EA3 'VGA|3D|Display'
```

```
$ glxinfo | grep "OpenGL renderer"
```
## What works
It's really really easy to mess up graphics drivers and get an invalid input error on your monitor so it's best not to get too touchy with the graphics. I stick with the Nvidia/AMD proprietary drivers which are just nvidia, and amdgpu.