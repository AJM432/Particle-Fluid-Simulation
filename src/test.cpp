/* #include <vector> */
/* #include <SFML/Graphics.hpp> */
/* #include <iostream> */

/* int main() { */
/*     /1* std::vector<double> vec1 = {1, 2}; *1/ */
/*     /1* std::vector<double> vec2 = {3, 4}; *1/ */
/*     sf::Vector2<double> vec1 = sf::Vector2<double>(61, 2); */
/*     sf::Vector2<double> a = vec1*2; */
/*     std::cout << 2*vec1.x << std::endl; */
/*     return 0; */
/* } */

/* // C++ program to find out execution time of */
/* // of functions */
/* #include <algorithm> */
/* #include <chrono> */
/* #include <iostream> */
/* #include<vector> */
/* using namespace std; */
/* using namespace std::chrono; */

/* // For demonstration purpose, we will fill up */
/* // a vector with random integers and then sort */
/* // them using sort function. We fill record */
/* // and print the time required by sort function */
/* int main() */
/* { */

/*   vector<int> values(10000); */

/*   // Generate Random values */
/*   auto f = []() -> int { return rand() % 10000; }; */

/*   // Fill up the vector */
/*   generate(values.begin(), values.end(), f); */

/*   // Get starting timepoint */
/*   auto start = high_resolution_clock::now(); */

/*   // Call the function, here sort() */
/*   sort(values.begin(), values.end()); */

/*   // Get ending timepoint */
/*   auto stop = high_resolution_clock::now(); */

/*   // Get duration. Substart timepoints to */
/*   // get duration. To cast it to proper unit */
/*   // use duration cast method */
/*   auto duration = duration_cast<microseconds>(stop - start); */

/*   cout << "Time taken by function: " */
/*     << duration.count() << " microseconds" << endl; */

/*   return 0; */
/* } */
/* #include <stdio.h> */
/* #include <chrono> */

/* int main () { */
/*     double sum = 0; */
/*     double add = 1; */

/*     // Start measuring time */
/*     auto begin = std::chrono::high_resolution_clock::now(); */
    
/*     int iterations = 1000*1000*1000; */
/*     for (int i=0; i<iterations; i++) { */
/*         sum += add; */
/*         add /= 2.0; */
/*     } */
    
/*     // Stop measuring time and calculate the elapsed time */
/*     auto end = std::chrono::high_resolution_clock::now(); */
/*     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); */
    
/*     printf("Result: %.20f\n", sum); */
    
/*     printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9); */
    
/*     return 0; */
/* } */
#include <time.h>
#include <iostream>

int main() {
    const clock_t begin_time = clock();
    // do something
    std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}