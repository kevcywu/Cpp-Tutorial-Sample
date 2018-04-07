#include <iostream>
#include <cmath>

int main() {

    int max_value;
    std::cout << "Display prime numbers up to what value? ";
    std::cin >> max_value;
    
    for(int value = 2; value <= max_value; value++) {
        // See if value is primes
        bool is_prime = true; // Provisionally, value is prime
        double r = value;
        double root = sqrt(r);
        
        // Try all the possible value from 2 to the square root value
        for(int trial_factor = 2; is_prime && trial_factor <= root; trial_factor++)
            is_prime = (value % trial_factor != 0);

        // Display the prime number
        if(is_prime)
           std::cout << value << " ";   
    }
    
    std::cout << '\n';
    
    return 0;
}

