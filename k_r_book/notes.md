## K & R Book Notes

#### Internal `static`

This confusion usually comes about because the static keyword serves two purposes.

When used at file level, it controls the visibility of its object outside the compilation unit, not the duration of the object (visibility and duration are layman's terms I use during educational sessions, the ISO standard uses different terms which you may want to learn eventually, but I've found they confuse most beginning students).

Objects created at file level already have their duration decided by virtue of the fact that they're at file level. The static keyword then just makes them invisible to the linker.

When used inside functions, it controls duration, not visibility. Visibility is already decided since it's inside the function - it can't be seen outside the function. The static keyword in this case, causes the object to be created at the same time as file level objects.

Note that, technically, a function level static may not necessarily come into existence until the function is first called (and that may make sense for C++ with its constructors) but every C implementation I've ever used creates its function level statics at the same time as file level objects.

Also, whilst I'm using the word "object", I don't mean it in the sense of C++ objects (since this is a C question). It's just because static can apply to variables or functions at file level and I need an all-encompassing word to describe that.

Function level statics are still used quite a bit - they can cause trouble in multi-threaded programs if that's not catered for but, provided you know what you're doing (or you're not threading), they're the best way to preserve state across multiple function calls while still providing for encapsulation.

Even with threading, there are tricks you can do in the function (such as allocation of thread specific data within the function) to make it workable without exposing the function internals unnecessarily.

The only other choices I can think of are global variables and passing a "state variable" to the function each time.

In both these cases, you expose the inner workings of the function to its clients and make the function dependent on the good behavior of the client (always a risky assumption).
