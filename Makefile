gen-pgSetup:
	cmake -S . -B build -DADD_PAGE_SETUP=ON
gen-pg-moc:
	cmake -S . -B build -DADD_PAGE_SETUP=ON -DUSE_QOBJECT_MACRO=ON
gen:
	cmake -S . -B build
clean:
	@rm -rf build
help:
	@echo "Usage:"
	@echo "make gen-pgSetup - to generate project with page setup in TextEditor"
	@echo "make gen-pg-moc - to generate project with page setup and MOC in TextEditor"
	@echo "make gen - to generate project"
	@echo "make clean - to remove build directory"
