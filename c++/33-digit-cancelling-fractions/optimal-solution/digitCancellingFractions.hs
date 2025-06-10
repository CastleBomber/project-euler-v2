// Digit Cancelling Fractions - Best Posts by Wi, and Deepseek
import Data.Ratio ((%), numerator, denominator)

-- Find all non-trivial digit-canceling fractions of form xy/yz = x/z
findFractions :: [(Integer, Integer)]
findFractions =
  [ (10*x + y, 10*y + z)
  | x <- [1..9], y <- [1..9], z <- [1..9]
  , 9 * x * z == y * (10 * x - z)
  , y /= z  -- Avoid trivial cases (e.g., 11/11)
  ]

-- Compute the product of all valid fractions and simplify
main :: IO ()
main = do
  let fractions = findFractions
      productFraction = foldl1 (\acc (n, d) -> acc * (n % d)) (map (\(n, d) -> n % d) fractions)
      simplifiedDenominator = denominator productFraction
  putStrLn $ "Valid fractions: " ++ show fractions
  putStrLn $ "Product's denominator: " ++ show simplifiedDenominator