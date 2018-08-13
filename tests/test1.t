
#
    Basic method parameter test
    Note that parameter assignment is not supported because the parameters
    must be present in a call. Assigning would imply that that you can omit 
    it and it will have a default value.
#

import some_junk;
some_method(num:abc, strg:xyz)(SomeClass:asdf){}
some_other(bool:bacon, bool:eggs)(bool:retv) {}
# This fails #
# goobers(,)(){} #
