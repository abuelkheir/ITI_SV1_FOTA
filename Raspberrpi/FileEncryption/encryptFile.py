import rsa
from Crypto.Cipher import AES
import os

def load_public_key():
    script_dir = os.path.dirname(__file__)
    public_key_path = os.path.join(script_dir, 'public.pem')

    with open(public_key_path, 'rb') as key_file:
        key_data = key_file.read()
    public_key = rsa.PublicKey.load_pkcs1(key_data)
    return public_key

def load_aes_key(key_filename):
    script_dir = os.path.dirname(__file__)
    absolute_path = os.path.join(script_dir, key_filename)

    with open(absolute_path, 'rb') as key_file:
        aes_key = key_file.read()
    return aes_key

def encrypt_file(input_path, output_path, public_key_filename, aes_key_filename):
    # Set the working directory to the script's directory
    os.chdir(os.path.dirname(__file__))

    # Load the public key
    public_key = load_public_key()

    # Load the existing AES key
    aes_key = load_aes_key(aes_key_filename)

    # Encrypt the AES key with RSA
    encrypted_aes_key = rsa.encrypt(aes_key, public_key)

    # Encrypt the file content with AES
    cipher = AES.new(aes_key, AES.MODE_EAX)

    with open(input_path, 'rb') as file:
        plaintext = file.read()

    ciphertext, tag = cipher.encrypt_and_digest(plaintext)

    # Save the encrypted AES key and AES-encrypted file content
    with open(output_path, 'wb') as encrypted_file:
        encrypted_file.write(encrypted_aes_key)
        encrypted_file.write(cipher.nonce)
        encrypted_file.write(tag)
        encrypted_file.write(ciphertext)

if __name__ == "__main__":
    encrypt_file('TEST_256KB.hex', 'encrypted_output.enc', 'public.pem', 'aes_key.txt')
