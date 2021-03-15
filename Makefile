
PROGRAMS = $(subst programs/, , $(wildcard programs/*))

all: programs lib tests

programs-%:
	$(MAKE) -C programs/$*

programs: $(addprefix programs-, $(PROGRAMS))		# depend στο programs-<foo> για κάθε στοιχείο του PROGRAMS

tests:
	$(MAKE) -C tests all

lib:
	$(MAKE) -C lib all

run: run-tests run-programs

run-programs-%:
	$(MAKE) -C programs/$* run

run-programs: $(addprefix run-programs-, $(PROGRAMS))

run-tests:
	$(MAKE) -C tests run

valgrind: valgrind-tests valgrind-programs


valgrind-programs-%:
	$(MAKE) -C programs/$* valgrind

valgrind-programs: $(addprefix valgrind-programs-, $(PROGRAMS))

valgrind-tests:
	$(MAKE) -C tests valgrind

clean-programs-%:
	$(MAKE) -C programs/$* clean

clean: $(addprefix clean-programs-, $(PROGRAMS))
	$(MAKE) -C tests clean
	$(MAKE) -C lib clean

.PHONY: programs tests lib run run-programs run-tests clean
