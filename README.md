# C++ Primitives

A library of primitives to be used and reused.

## How to Use

Download the project and do
`target_include_directories(${PROJECT_NAME} PRIVATE ${path_to_project}/include` to start using the primitives.

For example, if you want to use `FetchContent`, you may do:

```cmake
# Project definition...

include(FetchContent REQUIRED)

FetchContent_Declare(
        vitimiti_primitives
        GIT_REPOSITORY https://github.com/vitimiti/primitives.git
        GIT_TAG main)

FetchContent_MakeAvailable(vitimiti_primitives)

target_include_directories(${PROJECT_NAME} PRIVATE ${vitimiti_primitives_SOURCE_DIR}/include)

# Rest of the project configuration...
```

## Current Primitives

- `viti::primitives::point`: A structure with an X and Y coordinates that represents a point.
- `viti::primitives::size`: A structure with a Width and Height values that represents a size of a primitive.
