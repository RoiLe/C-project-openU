#ifndef FIRSTPASS_H
#define FIRSTPASS_H

/*void first_pass_proccess(char *currLine,  int typeOfSentence, DI_ptr *instruction_head, DI_ptr *instruction_tail,
 symLine *symbol_table_head, symLine *symbol_table_tail, long ic, long dc, int currentNumberLine);*/


/*
	Creates the data image table. 
	[adress ; source code ; machine code]
	 
	The first part is the instruction lines.
	The second part is the guidances lines.

	**variables**
	curr -> the current line that we add. 
	temp -> pointer that help to store the next line.

	operand_list -> current openrands of guidances line.
	source_code_flag -> help to add the source code just to correct line in the table. 
	lines_counter -> counter of the guidances line (will help forward to put the correct adress).
	curr_adress -> current adress.
	num_of_operands -> number of operands.

*/
int data_image_line_create(DI_ptr *curr_line_ptr, DI_ptr *tail_ptr, char *currLine, long adress, int typeOfSentence, char *key_word, char* operands, int line_number);

/*
	Creates the symbol table.
	Every label, external, entry values get inside.
	[symbol ; value(adress) ; arrtibute]

	This table will update in the second pass.

	**variables**
	curr_symbol_line -> the current line that we creating.
*/
symLine *add_to_symbol_table(char *label, long adress, int type_of_sentence);

/*
	Connect the adresses in the data image, 
	between instruction line and guidance lines.

	**variables**
	curr_adress -> the current adress. 
*/
void connect_adresses(dataImg *guidance_table, long last_ic);

/*
	Free the symbol table,
	every line. 
	
*/
void free_symbol_table_nodes(symLine *head_symbol_line);

/*
	Free the data image table, 
	every line. 
*/
void free_data_image_nodes(dataImg* head_data_image);




/*-----------------------not in use--------------------------*/
/*---------unless you want to see the prints-----------------*/
/*
	prints the data image table
	[adress | source code | machine code]
 */
void data_image_print(dataImg *head);

/*
	prints the symbols table
	[symbol | value | attribute]

*/
void symbol_table_print(symLine *symbol_table_head);



#endif
