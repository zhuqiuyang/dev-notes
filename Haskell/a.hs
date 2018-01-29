-- class Functor f where 
--   fmap :: (a -> b) -> f a -> f b

-- instance Functor [] where
--   fmap = map

-- map (*2) [1..3]

main = do line <- getLine   
          let line' = reverse line  
          putStrLn $ "You said " ++ line' ++ " backwards!"  
          putStrLn $ "Yes, you really said" ++ line' ++ " backwards!"  