# CPP-CLI-APP-TEMPLATE

Enter project info here

<!--- TODO: remove this section after init -->
## Init template

1. Clone repo created from template

2. Enter repo directory

3. Run script:

```bash
./scripts/init_template.sh <APP_NAME>
```

## Build
```bash
cmake -S . -B_build
cmake --build _build
```

## Testing
```bash
cmake -S . -B_build -DBUILD_TESTS=ON
cmake --build _build
cd _build && ctest
# or 
cmake --build _build --target hello_test
./_build/hello_test
```

## Usage

```bash
CPP-CLI-APP-TEMPLATE --help
```
