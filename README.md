# img2vector

A tool written in C++ and OpenCV to vectorize a set of images and save to file. Currently saves pixel values in normalized form - `x / 255`. Program converts all images to grayscale first before producing the vector.

## Manual Installation
```bash
$ cmake .
$ make
```

## Installing as a snap
```bash
$ snapcraft
$ sudo snap install img2vector_0.1_*.snap --dangerous --devmode # we're not signed
```

## Syntax
```bash
$ img2vector [input-dir] [output-file]

# Example
$ img2vector ~/Pictures/data data.csv
```
