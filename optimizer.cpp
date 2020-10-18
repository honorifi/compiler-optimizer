#include <iostream>
#include <cstring>
#include <unordered_map>
#include <string>
#include "analyser.h"
#include "Topo_relative.h"
using namespace std;

extern Refer_table refer_table;

int main(int argc, char *argv[])
{
	char* reference_filename;
	char* func_unit_table;
	char* input_file;
	char* output_file;

	if (argc > 1) {
		reference_filename = argv[1];
	}
	else {
		reference_filename = (char*)malloc(32);
		strcpy(reference_filename, ".\\instruction.csv");
	}
		refer_table.load_table(reference_filename);

	if(argc>2){
		func_unit_table = argv[2];
	}
	else {
		func_unit_table = (char*)malloc(32);
		strcpy(func_unit_table, ".\\func_unit.txt");
	}
    load_func_table(func_unit_table);

	if (argc > 3) {
		input_file = argv[3];
	}
	else {
		input_file = (char*)malloc(32);
		strcpy(input_file, ".\\test.asm");
	}
	if (argc > 4) {
		output_file = argv[4];
	}
	else {
		output_file = (char*)malloc(32);
		strcpy(output_file, ".\\test_output.asm");
	}
    process_file(output_file, input_file, &(Topograph::reschedule));

    return 0;
}

