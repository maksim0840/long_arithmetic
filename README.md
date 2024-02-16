Pi calctulating reference: https://maa.org/sites/default/files/pdf/pubs/amm_supplements/Monthly_Reference_12.pdf

Include Lib (launch file: build/main_file)
```
cd long_arithmetic
```
```
mkdir buid
cd build
cmake ..
cmake --build .
```

Tests result (launch file: build/test_file)
```
ctest
```

Web-interface of tests coverage (launch file: build/out/index.html)
```
lcov -c -d . -o main_coverage.info
genhtml main_coverage.info --output-directory out
```
