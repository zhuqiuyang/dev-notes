(print "What's your name?")

(defvar *name* (read))

(defun hello (name)
    (format t "Hello ~a! ~%" name)
)

(setq *print-case* :capitalize)

(hello *name*)
