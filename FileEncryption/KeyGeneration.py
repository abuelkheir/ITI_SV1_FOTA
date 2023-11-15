import rsa
Pi_Public_Key,Pi_Private_Key=rsa.newkeys(2048)

with open("public.pem","wb") as file:
    file.write(Pi_Public_Key.save_pkcs1("PEM"))
    
with open("private.pem","wb") as file:
    file.write(Pi_Private_Key.save_pkcs1("PEM"))
        
