## No Magic

Find confuse, find essence.

### Bjarne Stroustrup: Why I Created C++

In the late 1970s, Stroustrup applied the idea of "classes" to the C programming language to create a new language that allows for high level abstraction—but is efficient and close to the hardware. Read more at BigThink.com:
Transcript: What inspired you to create C++? In the really old days, people had to write their code directly to work on the hardware. They wrote load and store instructions to get stuff in and out of memory and they played about with bits and bytes and stuff. You could do pretty good work with that, but it was very specialized. Then they figured out that you could build languages fit for humans for specific areas. Like they built FORTRAN for engineers and scientists and they built COBALT for businessmen.

And then in the mid-'60s, a bunch of Norwegians, mostly Ole-Johan Dahl and Kristen Nygaard thought why can’t you get a language that sort of is fit for humans for all domains, not just linear algebra and business. And they built something called SIMULA. And that’s where they introduced the class as the thing you have in the program to represent a concept in your application world. So if you are a mathematician, a matrix will become a class, if you are a businessman, a personnel record might become a class, in telecommunications a dial buffer might become a class—you can represent just about anything as a class. And they went a little bit further and represented relationships between classes; any hierarchical relationship could be done as a bunch of classes. So you could say that a fire engine is a kind of a truck which is a kind of a car which is a kind of a vehicle and organize things like that. This became know as object-oriented programming or also in some variance of it as data abstraction.

And my idea was very simple: to take the ideas from SIMULA for general abstraction for the benefit of sort of humans representing things... so humans could get it with low level stuff, which at that time was the best language for that was C, which was done at Bell Labs by Dennis Ritchie. And take those two ideas and bring them together so that you could do high-level abstraction, but efficiently enough and close enough to the hardware for really demanding computing tasks. And that is where I came in. And so C++ has classes like SIMULA but they run as fast as C code, so the combination becomes very useful.

What makes C++ such a widely used language?

If I have to characterize C++’s strength, it comes from the ability to have abstractions and have them so efficient that you can afford it in infrastructure. And you can access hardware directly as you often have to do with operating systems with real time control, little things like cell phones, and so the combination is something that is good for infrastructure in general.

Another aspect that’s necessary for infrastructure is stability. When you build an infrastructure it could be sort of the lowest level of IBM mainframes talking to the hardware for the higher level of software, which is a place they use C++. Or a fuel injector for a large marine diesel engine or a browser, it has to be stable for a decade or so because you can’t afford to fiddle with the stuff all the time. You can’t afford to rewrite it, I mean taking one of those ships into harbor costs a lot of money. And so you need a language that’s not just good at what it’s doing, you have to be able to rely on it being available for decades on a variety of different hardware and to be used by programmers over a decade or two at least. C++ is not about three decades old. And if that’s not the case, you have to rewrite your code all the time. And that happens primarily with experimental languages and with proprietary commercial languages that change to

C++’s problem is the complexity part because we haven’t been able to clean it up. There’s still code written in the 80’s that are running and people don’t like their running codes to break. It could cost them millions or more.

Interviewed by Max Miller
