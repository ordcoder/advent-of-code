CXXFLAGS := -std=c++23 -O2 -Wall -Wextra
%.ex.out: %.ex.in %; <$(join $(dir $^),$(^F))
%.out:       %.in %; <$(join $(dir $^),$(^F))
clean:; $(RM) [0-2][0-9]
