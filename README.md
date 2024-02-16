Pi calctulating reference: https://maa.org/sites/default/files/pdf/pubs/amm_supplements/Monthly_Reference_12.pdf

Include Lib
```
cd long_arithmetic
```
```
mkdir buid
cmake ..
cmake --build .
```

Tests result
```
ctest
```

Web-interface of tests coverage
```
lcov -c -d . -o main_coverage.info
genhtml main_coverage.info --output-directory out
```
