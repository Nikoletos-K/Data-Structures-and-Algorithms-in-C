# common.mk

# Paths
MY_PATH := $(dir $(lastword $(MAKEFILE_LIST)))
MODULES := $(MY_PATH)modules
INCLUDE := $(MY_PATH)include
LIB		:= $(MY_PATH)lib

override CFLAGS += -g -Werror -Wall -MMD -I$(INCLUDE)

# Linker options
LDFLAGS += -lm

ifneq (,$(findstring coverage,$(MAKECMDGOALS)))
	override CFLAGS += --coverage
	override LDFLAGS += --coverage
endif

# compiler
CC = gcc

WITH_OBJS := $(subst _OBJS,,$(filter %_OBJS,$(.VARIABLES)))
PROGS := $(filter-out %.a,$(WITH_OBJS))
LIBS := $(filter %.a,$(WITH_OBJS))

OBJS := $(foreach target, $(WITH_OBJS), $($(target)_OBJS))

DEPS := $(patsubst %.o, %.d, $(filter %.o, $(OBJS)))

COV_FILES := $(patsubst %.o,%.gcda,$(OBJS)) $(patsubst %.o,%.gcno,$(OBJS))

RUN_TARGETS ?= $(addprefix run-, $(PROGS))
VAL_TARGETS ?= $(addprefix valgrind-, $(PROGS))
COV_TARGETS ?= $(addprefix coverage-, $(PROGS))

$(foreach test, $(filter %_test, $(PROGS)),	\
	$(eval $(test)_ARGS ?= --time)			\
)


all: $(PROGS) $(LIBS)

.SECONDEXPANSION:

$(PROGS): $$($$@_OBJS)
	$(CC)  $^ -o $@ $(LDFLAGS)

$(LIBS): $$($$@_OBJS)
	ar -rcs $@ $^

-include $(DEPS)

clean:
	@$(RM) $(PROGS) $(LIBS) $(OBJS) $(DEPS) $(COV_FILES)
	@$(RM) -r coverage

run-%: %
	./$* $($*_ARGS)

run: $(RUN_TARGETS)

valgrind-%: %
	valgrind --error-exitcode=1 --track-origins=yes --leak-check=full --show-leak-kinds=all ./$* $($*_ARGS)

valgrind: $(VAL_TARGETS)

lcov:
	@mkdir -p coverage
	lcov --rc lcov_branch_coverage=1 --capture --directory=$(MY_PATH) --output-file coverage/lcov.info
	lcov --rc lcov_branch_coverage=1 --remove coverage/lcov.info '*.h' --output-file coverage/lcov.info
	cd coverage && genhtml --rc lcov_branch_coverage=1 lcov.info
	@echo "To see the report open the file below in your brower:"
	@echo "$$PWD/coverage/index.html"

coverage-%: clean run-% lcov
	@true 						# dummy εντολή, γιατί ένα pattern rule αγνοείται αν δεν υπάρχουν εντολές για το target)
coverage: clean run lcov

$(RUN_TARGETS):
$(VAL_TARGETS):
$(COV_TARGETS):

.PHONY: clean run valgrind coverage lcov
