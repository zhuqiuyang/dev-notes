class Functor f where 
  fmap :: (a -> b) -> f a -> f b

instance Functor [] where
  fmap = map

map (*2) [1..3]