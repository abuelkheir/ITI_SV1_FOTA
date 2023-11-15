import rsa
from Crypto.Cipher import AES
import os

def load_private_key():
    script_dir = os.path.dirname(__file__)
    private_key_path = os.path.join(script_dir, 'private.pem')

    with open(private_key_path, 'rb') as key_file:
        key_data = key_file.read()
    private_key = rsa.PrivateKey.load_pkcs1(key_data)
    return private_key

def load_encrypted_file(input_path):
    with open(input_path, 'rb') as encrypted_file:
        encrypted_aes_key = encrypted_file.read(256)  # Assuming a 2048-bit RSA key
        nonce = encrypted_file.read(16)
        tag = encrypted_file.read(16)
        ciphertext = encrypted_file.read()

    return encrypted_aes_key, nonce, tag, ciphertext

def decrypt_file(input_path, output_path, private_key_filename):
    # Set the working directory to the script's directory
    os.chdir(os.path.dirname(__file__))

    # Load the private key
    private_key = load_private_key()

    # Load the encrypted file components
    encrypted_aes_key, nonce, tag, ciphertext = load_encrypted_file(input_path)

    # Decrypt the AES key with RSA
    aes_key = rsa.decrypt(encrypted_aes_key, private_key)

    # Decrypt the file content with AES
    cipher = AES.new(aes_key, AES.MODE_EAX, nonce=nonce)
    decrypted_data = cipher.decrypt_and_verify(ciphertext, tag)

    # Save the decrypted data to the output file (TEST_256KB_Decrypted.hex)
    with open(output_path, 'wb') as decrypted_file:
        decrypted_file.write(decrypted_data)

if __name__ == "__main__":
    decrypt_file('encrypted_output.enc', 'TEST_256KB_Decrypted.hex', 'private.pem')
import rsa
from Crypto.Cipher import AES
import os

def load_private_key():
    script_dir = os.path.dirname(__file__)
    private_key_path = os.path.join(script_dir, 'private.pem')

    with open(private_key_path, 'rb') as key_file:
        key_data = key_file.read()
    private_key = rsa.PrivateKey.load_pkcs1(key_data)
    return private_key

def load_encrypted_file(input_path):
    with open(input_path, 'rb') as encrypted_file:
        encrypted_aes_key = encrypted_file.read(256)  # Assuming a 2048-bit RSA key
        nonce = encrypted_file.read(16)
        tag = encrypted_file.read(16)
        ciphertext = encrypted_file.read()

    return encrypted_aes_key, nonce, tag, ciphertext

def decrypt_file(input_path, output_path, private_key_filename):
    # Set the working directory to the script's directory
    os.chdir(os.path.dirname(__file__))

    # Load the private key
    private_key = load_private_key()

    # Load the encrypted file components
    encrypted_aes_key, nonce, tag, ciphertext = load_encrypted_file(input_path)

    # Decrypt the AES key with RSA
    aes_key = rsa.decrypt(encrypted_aes_key, private_key)

    # Decrypt the file content with AES
    cipher = AES.new(aes_key, AES.MODE_EAX, nonce=nonce)
    decrypted_data = cipher.decrypt_and_verify(ciphertext, tag)

    # Save the decrypted data to the output file (TEST_256KB_Decrypted.hex)
    with open(output_path, 'wb') as decrypted_file:
        decrypted_file.write(decrypted_data)

if __name__ == "__main__":
    decrypt_file('encrypted_output.enc', 'TEST_256KB_Decrypted.hex', 'private.pem')
