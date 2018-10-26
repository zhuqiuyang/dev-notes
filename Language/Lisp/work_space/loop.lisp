(let ((x 'a))
    (do (
          (x 1 (+ x 1))
          (y x x)
        )
        ((> x 5))
        (format t "(~A ~A)  " x y)
    )
)


(defun show-squares (start end)
  (do ((i start (+ i 1)))
      ((> i end) 'done)
    (format t "~A ~A~%" i (* i i))))


    (let ((x 'a))
    (do (
          (x 1 (+ x 1))
          (y x x)
        )
        ((> x 5))
        (format t "(~A ~A)  " x y))
    )