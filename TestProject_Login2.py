#TestPush
import os
import sys
import time

def clear_screen():
    os.system("cls" if os.name == "nt" else "clear")


def read_user_data():
    user_data = {}
    try:
        with open("user_data.txt", "r") as file:
            for line in file:
                username, password = line.strip().split(",")
                user_data[username] = password
    except FileNotFoundError:
                pass
    return user_data


def write_user_data(user_data):
    with open("user_data.txt", "w") as file:
        for username, password in user_data.items():
            file.write(f"{username},{password}\n")


def sign_up():
    print("\n")
    username = input("Enter your desired username: ")
    password = input("Enter your password: ")

    user_data = read_user_data()

    if username in user_data:
        print("Username already exists. Please choose a different username.")
    else:
        user_data[username] = password
        write_user_data(user_data)
        print("Sign up successful!")
        time.sleep(3)  


def login():
    print("\n")
    username = input("Enter your username: ")
    password = input("Enter your password: ")

    user_data = read_user_data()

    if username in user_data and user_data[username] == password:
        print("Login successful!")
        time.sleep(3)  
        return username
    else:
        print("Invalid username or password.")
        return None

def menu(logged_in_user):
    clear_screen()  
    print("===== Welcome to the CLUB! =====")
    print("     ===== ! Enjoy ! =====      ")
    time.sleep(3) 
    sys.exit()
    

 


def main():
    while True:
        clear_screen()  
        print("====WELCOME====")
        print("===============")
        print("1. Sign up")
        print("2. Login")
        print("3. Exit")
        choice = input("Enter your choice (1/2/3): ")

        if choice == "1":
            sign_up()
        elif choice == "2":
            logged_in_user = login()
            if logged_in_user:
                menu(logged_in_user)
        elif choice == "3":
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    main()
