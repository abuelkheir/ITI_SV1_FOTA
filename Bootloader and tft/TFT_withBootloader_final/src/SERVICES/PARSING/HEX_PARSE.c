

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.h"


#include"../../SERVICES/PARSING/HEX_PARSE.h"
#include "../../MCAL/FLASH_DRIVER/FLASH_interface.h"

u32 FLASH_ADDRESS = 0x08000000;

u32 Frist_FLASH_ADDRESS=0x08020000;

u16 DataBUF[100];

// Function to convert ASCII characters representing hexadecimal digits to their integer values
u8 APARSER_ParseAscii2Hex(u8 Copy_u8Ascii)
{
    u8 HEX_Value = 0;

    // Check if the ASCII character is a digit (0-9)
    if (Copy_u8Ascii >= 48 && Copy_u8Ascii <= 57)
    {
        HEX_Value = Copy_u8Ascii - 48; // Convert digit character to integer value
    }
    // Check if the ASCII character is an uppercase hexadecimal letter (A-F)
    else if (Copy_u8Ascii >= 'A' && Copy_u8Ascii <= 'F')
    {
        HEX_Value = Copy_u8Ascii - 55; // Convert letter character to integer value
    }

    // Return the resulting hexadecimal value
    return HEX_Value;
}



// Function to parse a record in Intel Hex format based on the record type
void APARSER_voidParseRecord(u8* Copy_BufRecord)
{
    // Switch based on the record type (located at index 8)
    switch (Copy_BufRecord[8])
    {
        case '0':
            // Record type 0: Data record, call function to parse data
            APAESER_voidParseData(Copy_BufRecord);
            break;

        case '4':
            // Record type 4: Set high address part, call function to parse
            APARSER_voidParseHighAddress(Copy_BufRecord);
            break;

        case '1':
            // Record type 1: End of file, nothing to do
            // Add any necessary end-of-file handling here if required
            break;

        // Add more cases for other record types if needed

        default:
            // Handle unknown record types if necessary
            break;
    }
}


// Function to parse data in Intel Hex format and write it to flash memory
void APAESER_voidParseData(u8 *Copy_u8BufData)
{
    // Variables to store count character values
    u8 CC_High, CC_Low, CC;

    // Variables to store individual hexadecimal digits
    u8 digit0, digit1, digit2, digit3;

    // Convert count character from ASCII to hexadecimal
    CC_High = APARSER_ParseAscii2Hex(Copy_u8BufData[1]);
    CC_Low = APARSER_ParseAscii2Hex(Copy_u8BufData[2]);
    CC = (CC_High << 4) | CC_Low;

    // Convert address from ASCII to hexadecimal and update FLASH_ADDRESS
    digit0 = APARSER_ParseAscii2Hex(Copy_u8BufData[3]);
    digit1 = APARSER_ParseAscii2Hex(Copy_u8BufData[4]);
    digit2 = APARSER_ParseAscii2Hex(Copy_u8BufData[5]);
    digit3 = APARSER_ParseAscii2Hex(Copy_u8BufData[6]);
    FLASH_ADDRESS &= 0xFFFF0000;
    FLASH_ADDRESS |= (digit0 << 12) | (digit1 << 8) | (digit2 << 4) | (digit3 << 0);

    // Process and store data in DataBUF
    for (u8 i = 0; i < (CC / 2); i++)
    {
        digit0 = APARSER_ParseAscii2Hex(Copy_u8BufData[(4 * i) + 9]);
        digit1 = APARSER_ParseAscii2Hex(Copy_u8BufData[(4 * i) + 10]);
        digit2 = APARSER_ParseAscii2Hex(Copy_u8BufData[(4 * i) + 11]);
        digit3 = APARSER_ParseAscii2Hex(Copy_u8BufData[(4 * i) + 12]);
        // Combine two hexadecimal digits into a single 16-bit value and store in DataBUF
        DataBUF[i] = (digit2 << 12) | (digit3 << 8) | (digit0 << 4) | (digit1 << 0);
    }

    // Write data to flash memory using MFDI_voidFlashWrite function
    MFDI_voidFlashWrite(FLASH_ADDRESS, DataBUF, (CC / 2));
}

unsigned char APARSER_u8VerifyChecksum(char *record)
{
    unsigned char checksum = 0;
    unsigned char recordLength = 0;

    // Calculate the record length
    while(record[recordLength] != '\n')
    {
        recordLength++;
    }

    // Calculate the checksum for the record (excluding the last two bytes)
    for (int i = 1; i < recordLength - 2; i += 2)
    {

        char highNibble = APARSER_ParseAscii2Hex(record[i]);
        char lowNibble = APARSER_ParseAscii2Hex(record[i + 1]);
        checksum = checksum+((highNibble << 4) | lowNibble);
    }

    // Calculate the one's complement
    checksum = ~checksum;

    // Calculate the two's complement
    checksum = checksum + 1;



    // Extract the received checksum from the record
    char receivedChecksumHighNibble = APARSER_ParseAscii2Hex(record[recordLength - 2]);

    char receivedChecksumLowNibble = APARSER_ParseAscii2Hex(record[recordLength - 1]);

    unsigned char receivedChecksum;
    receivedChecksum = receivedChecksumHighNibble << 4 | receivedChecksumLowNibble;



    // Compare the calculated checksum with the received checksum
    if (checksum == receivedChecksum)
    {
        return 1; // Checksum verified
    }
    else
    {
    	return 0;
    }

    return 0; // Checksum verification failed
}

// Function to parse a high address represented in ASCII and update the FLASH_ADDRESS
void APARSER_voidParseHighAddress(char *Copy_u8BufData)
{
    // Define variables to store individual hexadecimal digits
    unsigned char digit0, digit1, digit2, digit3;

    // Parse ASCII characters to hexadecimal values for each digit
    digit0 = APARSER_ParseAscii2Hex(Copy_u8BufData[9]);
    digit1 = APARSER_ParseAscii2Hex(Copy_u8BufData[10]);
    digit2 = APARSER_ParseAscii2Hex(Copy_u8BufData[11]);
    digit3 = APARSER_ParseAscii2Hex(Copy_u8BufData[12]);

    // Clear higher bits of FLASH_ADDRESS to prepare for update
    FLASH_ADDRESS &= 0x0000FFFF;

    // Update FLASH_ADDRESS with the parsed high address values
    FLASH_ADDRESS |= (digit0 << 28) | (digit1 << 24) | (digit2 << 20) | (digit3 << 16);
    Frist_FLASH_ADDRESS=FLASH_ADDRESS;
}

