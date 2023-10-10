/**
 * Source: Aistina's Stackoverflow Question
 * Link:https://stackoverflow.com/questions/2200236/project-euler-15
 */

#include "latticePaths.h"

/**
 * Binomial Coefficient
 * ~Combination VS Permutation
 * 40 steps to finish, 20 increases in x, 20 increases in y
 *
 * We solve this by choosing the increases in x
 * How many different ways are there to choose 20 elements
 * out of a set of 40 elements?
 *
 * C(n,r) = (n,r) = n!/((r!)(n-r)!)
 *
 * @param length - length of the grid
 * @return
 */
double discreteMathSolution(int length) {
  int n = length * 2; // Number of steps made on the grid
  int r = length;     // n,r combination notation
  double result = 0;

  result = factorial(n) / (factorial(r) * factorial(n - r));

  return result;
}

/**
 * Computes the factorial of a given number
 *
 * @param n - length of the grid
 * @return n!
 */
double factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  return n * factorial(n - 1);
}

// /**
//  * Memoize
//  * Cache
//  */
// static Func<A1, A2, R> Memoize<A1, A2, R>(this Func<A1, A2, R> f){
//   // Return a function which is f with caching
//   var dictionary = new Dictionary<string, R>();

//   return(A1 a1, A2 a2) => {
//     R r;
//     string key = a1 + "x" + a2;

//     if(!dictionary.TryGetValue(key, out r)){
//       // Not yet in cache
//       r = f(a1, a2);
//       dictionary.Add(key, r);
//     }

//     return r;
//   };
// }

// /**
//  * Calculate the surface of the block to the finish line
//  */
// static long calcsurface(long x, long y){
//   return (gridSize - x) * (gridSize - y);
// }

// /**
//  * Call using progress (0, 0)
//  */
// static Func<long, long, long> progress = ((Func<long, long, long>)((long x, long y) => 
// {
//   // First calculate the surface of the block remaining
//   long surface = calcsurface(x, y);
//   long i = 0;

//   // Zero surface means only 1 path remains
//   // (We either go only right, or only down)
//   if(surface == 0){
//     return 1;
//   }

//   // Calculate it in the right direction
//   if (x < gridSize){
//     i += progress(x + 1, y);
//   }

//   // And in the down direction
//   if (y < gridSize){
//     i += progress(x, y + 1);
//   }

//   return i;
// })).Memoize();
