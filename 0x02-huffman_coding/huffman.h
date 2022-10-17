#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
	char data;
	size_t freq;
} symbol_t;


#define CHAR_TABLE_SIZE 256
#define FREQ_TABLE_SIZE 256

typedef char char_table_t[CHAR_TABLE_SIZE];
typedef size_t freq_table_t[FREQ_TABLE_SIZE];

extern char *program_invocation_name;
extern char *program_invocation_short_name;

int huffman(char mode, char *ifilename, char *ofilename);
int huffman_compress(FILE *istream, FILE *ostream);
int huffman_decompress(FILE *istream, FILE *ostream);
char_table_t *char_table(void);
freq_table_t *freq_table(void);
int freq_table_read(FILE *istream);
int freq_table_write(FILE *ostream);

symbol_t *symbol_create(char data, size_t freq);
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size);
int huffman_extract_and_insert(heap_t *priority_queue);
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size);
int huffman_codes(char *data, size_t *freq, size_t size);

#endif /*__HUFFMAN_H__*/
