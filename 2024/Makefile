CXXFLAGS := -std=c++23 -O2 -Wall -Wextra
%.ex.out: %.ex.in %; <$(join $(dir $^),$(^F))
%.out:       %.in %; <$(join $(dir $^),$(^F))
.PHONY: %.out
