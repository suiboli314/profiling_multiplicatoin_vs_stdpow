# ReadMe

## Profile runtime performance

- The program generates a dataset with `1000` random numbers ranged from `[1, 1000000]`.
- The program simply compares the runtime performance of the following two methods. 
    1. default `*` operator
    2. `std::pow()`
- The program runs these two methods `10000` times for the same dataset. In total, `1000 x 10000` times for each method.

### Using `*` Operator
`times runtime: 0.038474`

### Using `std::pow()`
`pow   runtime: 0.774296`

### Difference
`pow : times = 20.1`


### Usage of `std::pow()`
When there is a exponential or something that is hard to be expressed directly by multiplication, such as `2^4.345`, `std::pow()` will be very handy to use.
