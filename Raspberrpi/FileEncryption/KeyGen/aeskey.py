from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

def generate_aes_key_and_save(key_filename):
    # Generate a random AES key (128 bits)
    aes_key = get_random_bytes(16)

    # Save the AES key to a file
    with open(key_filename, 'wb') as key_file:
        key_file.write(aes_key)

if __name__ == "__main__":
    generate_aes_key_and_save('aes_key.txt')
