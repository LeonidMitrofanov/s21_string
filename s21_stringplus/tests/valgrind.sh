cd src

make rebuild
#make test_valgrind
make test_valgrind
#make dev_test_sprintf_valgrind
#make dev_main_test_manual_valgrind
cat valgrind.log