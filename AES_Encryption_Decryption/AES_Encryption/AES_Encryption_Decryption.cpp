// AES_Encryption.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/*
	AES 128 Encryption and Decryption
	Omer Faruk Yuceturk 2018


	For some steps I followed videos from: https://www.youtube.com/user/WhatsACreel

*/
#include <iostream>
#include "AES_Header.h"

using namespace std;

unsigned char state_array[16] = {};
const unsigned char message[17] = "Merhabalar dunya";/*4D6572686162616C61722064756E7961*/
unsigned char aes_key_128[16] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };/*0F0E0D0C0B0A09080706050403020100*/
unsigned char test_key_1[16] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };/*0F0E0D0C0B0A09080706050403020100*/
unsigned char test_key_2[16] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };/*0F0E0D0C0B0A09080706050403020100*/
unsigned char test_key_3[16] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };/*0F0E0D0C0B0A09080706050403020100*/
unsigned char test_key_4[16] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };/*0F0E0D0C0B0A09080706050403020100*/
unsigned char test_key_5[16] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };/*0F0E0D0C0B0A09080706050403020100*/
unsigned char round_key_example[16] = {0xAA, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9, 0xF8, 0xF7, 0xF6, 0xF5, 0xF4, 0xF3, 0xF2, 0xF1, 0xAA};/*AAFEFDFCFBFAF9F8F7F6F5F4F3F2F1AA*/
unsigned char aes_key_256[32] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };/*000102030405060708090A0B0C0D0E0F000102030405060708090A0B0C0D0E0F*/
unsigned char round_keys_128[176]; // 16Byte initial key, 16*10 round keys
unsigned char round_keys_256[240]; // 32Byte initial key, total 240 round keys for 14 rounds
unsigned char encrypted_text[16];
unsigned char decrypted_text[16];


int main()
{

	printf("\tByte Degistirme Ornegi\nGirdi:\n\n");
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", test_key_1[i]);
		if (i % 16 == 15) {
			printf("\n");
		}
	}

	printf("\nCikti:\n\n");
	sub_bytes(test_key_1);
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", test_key_1[i]);
		if (i % 16 == 15) {
			printf("\n");
		}
	}
	getchar();

	printf("\n\n\n");
	printf("\tSatir Kaydirma Ornegi\nGirdi:\n\n");
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", test_key_2[i]);
		if (i % 16 == 15) {
			printf("\n");
		}
	}

	printf("\nCikti:\n\n");
	shift_rows(test_key_2);
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", test_key_2[i]);
		if (i % 16 == 15) {
			printf("\n");
		}
	}
	getchar();

	printf("\n\n\n");
	printf("\tSutun Karistirma Ornegi\nGirdi:\n\n");
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", test_key_3[i]);
		if (i % 16 == 15) {
			printf("\n");
		}
	}

	printf("\nCikti:\n\n");
	mix_cols(test_key_3);
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", test_key_3[i]);
		if (i % 16 == 15) {
			printf("\n");
		}
	}
	getchar();

	printf("\n\n\n");
	printf("\tAnahtar Genisletme Ornegi:\n\n");
	generate_round_keys_256(aes_key_256, round_keys_256);
	for (int i = 0; i < 240; i++)
	{
		printf("%02x ", round_keys_256[i]);
		if (i % 16 == 15) {
			printf("\n");
		}
	}
	getchar();

	//arr_to_coe();

	printf("\n\n\n");
	//generate_round_keys_128(aes_key_128, round_keys_128);
	generate_round_keys_256(aes_key_256, round_keys_256);
	//AES_encrypt_128(message, aes_key_128, encrypted_text);
	AES_encrypt_256(message, aes_key_256, encrypted_text);
	printf("\n\n\tSifrelenecek Mesaj:\n");
	for (int i = 0; i < 16; i++)
	{
		printf("%c", message[i]);
	}
	printf("\n\n\t256 Bitlik Anahtar(Onaltilik Formatta):\n");
	for (int i = 0; i < 32; i++)
	{
		printf("%02x", round_keys_256[i]);
	}
	printf("\n\n\tSifrelenmis mesaj (Onaltilik Formatta):\n");
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", encrypted_text[i]);
	}
	/*printf("\n\nDecrypted msg as hex:\n");
	//AES_decrypt_128(encrypted_text, aes_key_128, decrypted_text);
	AES_decrypt_256(encrypted_text, aes_key_256, decrypted_text);
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", decrypted_text[i]);
	}
	printf("\n\nDecrypted msg as chars:\n");
	for (int i = 0; i < 16; i++)
	{
		printf("%c", decrypted_text[i]);
	}*/
	printf("\n\n");
	getchar();
	return 0;
}

void AES_encrypt_128(const unsigned char message[], const unsigned char key[], unsigned char encrypted[]) {
	for (int i = 0; i < 16; i++)
	{
		state_array[i] = message[i];
	}
	add_round_key(state_array, aes_key_128);

	for (int i = 0; i < 9; i++)
	{
		sub_bytes(state_array);
		shift_rows(state_array);
		mix_cols(state_array);
		add_round_key(state_array, round_keys_128 + (16 * (i + 1)));
	}
	// Last step
	sub_bytes(state_array);
	shift_rows(state_array);
	add_round_key(state_array, round_keys_128 + (16 * (10)));

	for (int i = 0; i < 16; i++)
	{
		encrypted[i] = state_array[i];
	}


}
void AES_encrypt_256(const unsigned char message[], const unsigned char key[], unsigned char encrypted[]) {
	for (int i = 0; i < 16; i++)
	{
		state_array[i] = message[i];
	}
	add_round_key(state_array, round_keys_256);

	for (int i = 0; i < 13; i++)
	{
		sub_bytes(state_array);
		shift_rows(state_array);
		mix_cols(state_array);
		add_round_key(state_array, round_keys_256 + (16 * (i + 1)));
	}
	// Last step
	sub_bytes(state_array);
	shift_rows(state_array);
	add_round_key(state_array, round_keys_256 + (16 * (14)));

	for (int i = 0; i < 16; i++)
	{
		encrypted[i] = state_array[i];
	}


}
void AES_decrypt_128(const unsigned char encrypted[], const unsigned char key[], unsigned char decrypted[]) {
	for (int i = 0; i < 16; i++)
	{
		state_array[i] = encrypted[i];
	}

	add_round_key(state_array, round_keys_128 + (16 * 10));
	inv_shift_rows(state_array);
	inv_sub_bytes(state_array);

	for (int i = 0; i < 9; i++)
	{
		add_round_key(state_array, round_keys_128 + (16 * (9 - i)));
		inv_mix_cols(state_array);
		inv_shift_rows(state_array);
		inv_sub_bytes(state_array);
	}

	add_round_key(state_array, key);

	for (int i = 0; i < 16; i++)
	{
		decrypted_text[i] = state_array[i];
	}
}
void AES_decrypt_256(const unsigned char encrypted[], const unsigned char key[], unsigned char decrypted[]) {
	for (int i = 0; i < 16; i++)
	{
		state_array[i] = encrypted[i];
	}

	add_round_key(state_array, round_keys_256 + (16 * 14));
	inv_shift_rows(state_array);
	inv_sub_bytes(state_array);

	for (int i = 0; i < 13; i++)
	{
		add_round_key(state_array, round_keys_256 + (16 * (13 - i)));
		inv_mix_cols(state_array);
		inv_shift_rows(state_array);
		inv_sub_bytes(state_array);
	}

	add_round_key(state_array, key);

	for (int i = 0; i < 16; i++)
	{
		decrypted_text[i] = state_array[i];
	}
}

void add_round_key(unsigned char state[], const unsigned char round_key[]) {
	for (int i = 0; i < 16; i++)
	{
		state[i] ^= round_key[i];
	}
}

void sub_bytes(unsigned char state[]) {
	for (int i = 0; i < 16; i++)
	{
		state[i] = s_box[state[i]];
	}
}
void inv_sub_bytes(unsigned char state[]) {
	for (int i = 0; i < 16; i++)
	{
		state[i] = inv_s_box[state[i]];
	}
}

void shift_rows(unsigned char state[]) {
	unsigned char tmp1 = 0;
	unsigned char tmp2 = 0;

	tmp1 = state[1];
	state[1] = state[5];
	state[5] = state[9];
	state[9] = state[13];
	state[13] = tmp1;

	tmp1 = state[2];
	tmp2 = state[6];
	state[2] = state[10];
	state[6] = state[14];
	state[10] = tmp1;
	state[14] = tmp2;

	tmp1 = state[15];
	state[15] = state[11];
	state[11] = state[7];
	state[7] = state[3];
	state[3] = tmp1;
}

void inv_shift_rows(unsigned char state[]) {
	unsigned char tmp1 = 0;
	unsigned char tmp2 = 0;

	tmp1 = state[13];
	state[13] = state[9];
	state[9] = state[5];
	state[5] = state[1];
	state[1] = tmp1;

	tmp1 = state[2];
	tmp2 = state[6];
	state[2] = state[10];
	state[6] = state[14];
	state[10] = tmp1;
	state[14] = tmp2;

	tmp1 = state[3];
	state[3] = state[7];
	state[7] = state[11];
	state[11] = state[15];
	state[15] = tmp1;
}

/*
Dot product of the state vectors each column and the fixed vector(2 3 1 1 ....)

2	3	1	1		V
1	2	3	1	.	E
1	1	2	3		C
3	1	1	2		T
*/
void mix_cols(unsigned char state[]) {
	unsigned char tmp[16];

	tmp[0] = (unsigned char)(gf_mul_2_lut[state[0]] ^ gf_mul_3_lut[state[1]] ^ state[2] ^ state[3]);
	tmp[1] = (unsigned char)(state[0] ^ gf_mul_2_lut[state[1]] ^ gf_mul_3_lut[state[2]] ^ state[3]);
	tmp[2] = (unsigned char)(state[0] ^ state[1] ^ gf_mul_2_lut[state[2]] ^ gf_mul_3_lut[state[3]]);
	tmp[3] = (unsigned char)(gf_mul_3_lut[state[0]] ^ state[1] ^ state[2] ^ gf_mul_2_lut[state[3]]);

	tmp[4] = (unsigned char)(gf_mul_2_lut[state[4]] ^ gf_mul_3_lut[state[5]] ^ state[6] ^ state[7]);
	tmp[5] = (unsigned char)(state[4] ^ gf_mul_2_lut[state[5]] ^ gf_mul_3_lut[state[6]] ^ state[7]);
	tmp[6] = (unsigned char)(state[4] ^ state[5] ^ gf_mul_2_lut[state[6]] ^ gf_mul_3_lut[state[7]]);
	tmp[7] = (unsigned char)(gf_mul_3_lut[state[4]] ^ state[5] ^ state[6] ^ gf_mul_2_lut[state[7]]);

	tmp[8] = (unsigned char)(gf_mul_2_lut[state[8]] ^ gf_mul_3_lut[state[9]] ^ state[10] ^ state[11]);
	tmp[9] = (unsigned char)(state[8] ^ gf_mul_2_lut[state[9]] ^ gf_mul_3_lut[state[10]] ^ state[11]);
	tmp[10] = (unsigned char)(state[8] ^ state[9] ^ gf_mul_2_lut[state[10]] ^ gf_mul_3_lut[state[11]]);
	tmp[11] = (unsigned char)(gf_mul_3_lut[state[8]] ^ state[9] ^ state[10] ^ gf_mul_2_lut[state[11]]);

	tmp[12] = (unsigned char)(gf_mul_2_lut[state[12]] ^ gf_mul_3_lut[state[13]] ^ state[14] ^ state[15]);
	tmp[13] = (unsigned char)(state[12] ^ gf_mul_2_lut[state[13]] ^ gf_mul_3_lut[state[14]] ^ state[15]);
	tmp[14] = (unsigned char)(state[12] ^ state[13] ^ gf_mul_2_lut[state[14]] ^ gf_mul_3_lut[state[15]]);
	tmp[15] = (unsigned char)(gf_mul_3_lut[state[12]] ^ state[13] ^ state[14] ^ gf_mul_2_lut[state[15]]);

	for (int i = 0; i < 16; i++)
	{
		state[i] = tmp[i];
	}
}

/*
Dot product of the state vectors each column and the fixed vector(14 11 13 9 ....)

14	11	13	9		V
9	14	11	13	.	E
13	9	14	11		C
11	13	9	14		T
*/
void inv_mix_cols(unsigned char state[]) {
	unsigned char tmp[16];
	tmp[0] = (unsigned char)(gf_mul_14_lut[state[0]] ^ gf_mul_11_lut[state[1]] ^ gf_mul_13_lut[state[2]] ^ gf_mul_9_lut[state[3]]);
	tmp[1] = (unsigned char)(gf_mul_9_lut[state[0]] ^ gf_mul_14_lut[state[1]] ^ gf_mul_11_lut[state[2]] ^ gf_mul_13_lut[state[3]]);
	tmp[2] = (unsigned char)(gf_mul_13_lut[state[0]] ^ gf_mul_9_lut[state[1]] ^ gf_mul_14_lut[state[2]] ^ gf_mul_11_lut[state[3]]);
	tmp[3] = (unsigned char)(gf_mul_11_lut[state[0]] ^ gf_mul_13_lut[state[1]] ^ gf_mul_9_lut[state[2]] ^ gf_mul_14_lut[state[3]]);

	tmp[4] = (unsigned char)(gf_mul_14_lut[state[4]] ^ gf_mul_11_lut[state[5]] ^ gf_mul_13_lut[state[6]] ^ gf_mul_9_lut[state[7]]);
	tmp[5] = (unsigned char)(gf_mul_9_lut[state[4]] ^ gf_mul_14_lut[state[5]] ^ gf_mul_11_lut[state[6]] ^ gf_mul_13_lut[state[7]]);
	tmp[6] = (unsigned char)(gf_mul_13_lut[state[4]] ^ gf_mul_9_lut[state[5]] ^ gf_mul_14_lut[state[6]] ^ gf_mul_11_lut[state[7]]);
	tmp[7] = (unsigned char)(gf_mul_11_lut[state[4]] ^ gf_mul_13_lut[state[5]] ^ gf_mul_9_lut[state[6]] ^ gf_mul_14_lut[state[7]]);

	tmp[8] = (unsigned char)(gf_mul_14_lut[state[8]] ^ gf_mul_11_lut[state[9]] ^ gf_mul_13_lut[state[10]] ^ gf_mul_9_lut[state[11]]);
	tmp[9] = (unsigned char)(gf_mul_9_lut[state[8]] ^ gf_mul_14_lut[state[9]] ^ gf_mul_11_lut[state[10]] ^ gf_mul_13_lut[state[11]]);
	tmp[10] = (unsigned char)(gf_mul_13_lut[state[8]] ^ gf_mul_9_lut[state[9]] ^ gf_mul_14_lut[state[10]] ^ gf_mul_11_lut[state[11]]);
	tmp[11] = (unsigned char)(gf_mul_11_lut[state[8]] ^ gf_mul_13_lut[state[9]] ^ gf_mul_9_lut[state[10]] ^ gf_mul_14_lut[state[11]]);

	tmp[12] = (unsigned char)(gf_mul_14_lut[state[12]] ^ gf_mul_11_lut[state[13]] ^ gf_mul_13_lut[state[14]] ^ gf_mul_9_lut[state[15]]);
	tmp[13] = (unsigned char)(gf_mul_9_lut[state[12]] ^ gf_mul_14_lut[state[13]] ^ gf_mul_11_lut[state[14]] ^ gf_mul_13_lut[state[15]]);
	tmp[14] = (unsigned char)(gf_mul_13_lut[state[12]] ^ gf_mul_9_lut[state[13]] ^ gf_mul_14_lut[state[14]] ^ gf_mul_11_lut[state[15]]);
	tmp[15] = (unsigned char)(gf_mul_11_lut[state[12]] ^ gf_mul_13_lut[state[13]] ^ gf_mul_9_lut[state[14]] ^ gf_mul_14_lut[state[15]]);

	for (int i = 0; i < 16; i++)
	{
		state[i] = tmp[i];
	}
}


void key_expand_core(unsigned char key[], unsigned char round) {
	// Rotate left by 1 byte
	unsigned char t = key[0];
	key[0] = key[1];
	key[1] = key[2];
	key[2] = key[3];
	key[3] = t;

	// S-Box all 4 bytes
	for (unsigned char i = 0; i < 4; i++)
	{
		key[i] = s_box[key[i]];
	}

	//RCon (xor with rcon LUT's value)
	key[0] ^= rcon[round];

}

void generate_round_keys_128(unsigned char key[], unsigned char expanded_keys[]) {
	for (int i = 0; i < 16; i++)
	{
		expanded_keys[i] = key[i];
	}

	int bytes_generated = 16;
	int rcon_iter = 1;
	unsigned char temp[4];

	// Loop until 176 bytes generated, which we have generated 16 bytes by copying first key.
	while (bytes_generated < 176) {
		for (int i = 0; i < 4; i++)
		{
			temp[i] = expanded_keys[i + bytes_generated - 4];
		}
		if (bytes_generated % 16 == 0) {
			key_expand_core(temp, rcon_iter);
			++rcon_iter;
		}
		for (int i = 0; i < 4; i++)
		{
			expanded_keys[bytes_generated] = expanded_keys[bytes_generated - 16] ^ temp[i];
			++bytes_generated;
		}

	}

}


void generate_round_keys_256(unsigned char key[], unsigned char expanded_keys[]) {
	for (int i = 0; i < 32; i++)
	{
		expanded_keys[i] = key[i];
	}

	int bytes_generated = 32;
	int rcon_iter = 1;
	unsigned char temp[4];

	// Loop until 240 bytes generated, which we have generated 32 bytes by copying first key.
	while (bytes_generated < 240) {
		for (int i = 0; i < 4; i++)
		{
			temp[i] = expanded_keys[i + bytes_generated - 4];
		}
		if (bytes_generated % 32 == 0) {
			/*	unsigned char t = key[0];
				key[0] = key[1];
				key[1] = key[2];
				key[2] = key[3];
				key[3] = t;

				// S-Box all 4 bytes
				for (unsigned char i = 0; i < 4; i++)
				{
					key[i] = s_box[key[i]];
				}

				//RCon (xor with rcon LUT's value)
				key[0] ^= rcon[round];			*/
			key_expand_core(temp, rcon_iter);
			++rcon_iter;
		}
		else if (bytes_generated % 16 == 0) {
			for (unsigned char i = 0; i < 4; i++)
			{
				temp[i] = s_box[temp[i]];
			}
		}
		for (int i = 0; i < 4; i++)
		{
			expanded_keys[bytes_generated] = expanded_keys[bytes_generated - 32] ^ temp[i];
			++bytes_generated;
		}

	}

}

/*
s_box
inv_s_box
gf_mul_2_lut
gf_mul_3_lut
gf_mul_9_lut
gf_mul_11_lut
gf_mul_13_lut
gf_mul_14_lut
rcon


*/
void arr_to_coe() {
	int i = 0;
	FILE *sboxf, *invsboxf, *gf2f, *gf3f, *gf9f, *gf11f, *gf13f, *gf14f, *rconf;
	sboxf = fopen("sboxf.coe", "w+");
	invsboxf = fopen("invsboxf.coe", "w+");
	gf2f = fopen("gf2f.coe", "w+");
	gf3f = fopen("gf3f.coe", "w+");
	gf9f = fopen("gf9f.coe", "w+");
	gf11f = fopen("gf11f.coe", "w+");
	gf13f = fopen("gf13f.coe", "w+");
	gf14f = fopen("gf14f.coe", "w+");
	rconf = fopen("rconf.coe", "w+");

	fprintf(sboxf, "%s\n%s\n", "memory_initialization_radix=16;", "memory_initialization_vector=");
	fprintf(invsboxf, "%s\n%s\n", "memory_initialization_radix=16;", "memory_initialization_vector=");
	fprintf(gf2f, "%s\n%s\n", "memory_initialization_radix=16;", "memory_initialization_vector=");
	fprintf(gf3f, "%s\n%s\n", "memory_initialization_radix=16;", "memory_initialization_vector=");
	fprintf(gf9f, "%s\n%s\n", "memory_initialization_radix=16;", "memory_initialization_vector=");
	fprintf(gf11f, "%s\n%s\n", "memory_initialization_radix=16;", "memory_initialization_vector=");
	fprintf(gf13f, "%s\n%s\n", "memory_initialization_radix=16;", "memory_initialization_vector=");
	fprintf(gf14f, "%s\n%s\n", "memory_initialization_radix=16;", "memory_initialization_vector=");
	fprintf(rconf, "%s\n%s\n", "memory_initialization_radix=16;", "memory_initialization_vector=");

	for (i = 0; i < 255; ++i) {
		fprintf(sboxf, "%02x,\n", s_box[i]);
		fprintf(invsboxf, "%02x,\n", inv_s_box[i]);
		fprintf(gf2f, "%02x,\n", gf_mul_2_lut[i]);
		fprintf(gf3f, "%02x,\n", gf_mul_3_lut[i]);
		fprintf(gf9f, "%02x,\n", gf_mul_9_lut[i]);
		fprintf(gf11f, "%02x,\n", gf_mul_11_lut[i]);
		fprintf(gf13f, "%02x,\n", gf_mul_13_lut[i]);
		fprintf(gf14f, "%02x,\n", gf_mul_14_lut[i]);
		fprintf(rconf, "%02x,\n", rcon[i]);
	}
	fprintf(sboxf, "%02x;", s_box[255]);
	fprintf(invsboxf, "%02x;", inv_s_box[255]);
	fprintf(gf2f, "%02x;", gf_mul_2_lut[255]);
	fprintf(gf3f, "%02x;", gf_mul_3_lut[255]);
	fprintf(gf9f, "%02x;", gf_mul_9_lut[255]);
	fprintf(gf11f, "%02x;", gf_mul_11_lut[255]);
	fprintf(gf13f, "%02x;", gf_mul_13_lut[255]);
	fprintf(gf14f, "%02x;", gf_mul_14_lut[255]);
	fprintf(rconf, "%02x;", rcon[255]);

	fclose(sboxf);
	fclose(invsboxf);
	fclose(gf2f);
	fclose(gf3f);
	fclose(gf9f);
	fclose(gf11f);
	fclose(gf13f);
	fclose(gf14f);
	fclose(rconf);
}
