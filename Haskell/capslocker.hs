import Data.Char

main = do
    contents <- getContents
    putStr (map toUpper contents)
    

-- $ ghc --make capslocker
-- $ cat haiku.txt | ./capslocker
-- I'M A LIL' TEAPOT
-- WHAT'S WITH THAT AIRPLANE FOOD, HUH?
-- IT'S SO SMALL, TASTELESS
-- capslocker <stdin>: hGetLine: end of file