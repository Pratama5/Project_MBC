NamaIn = input("Masukkan nama anda: ")
PassIn = input("Masukkan pass anda: ")

NamaSv = "Putra Pratama Sijabat"
PassSv = "Pratamajabat"

if NamaIn==NamaSv:
    if PassIn==PassSv:
        print("Hello, ",NamaIn," Selamat Datang!!")
    else:
        print("Password Salah")
else:
    print("Nama Tidak Dikenali")
