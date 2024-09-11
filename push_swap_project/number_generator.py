import random

def generate_unique_random_numbers():
    try:
        total_words = int(input("Entrez le nombre total de mots: "))
        if total_words <= 0:
            print("Le nombre doit être supérieur à zéro.")
            return
        
        random_numbers = []
        while len(random_numbers) < total_words:
            num = random.randint(-1000, 1000)
            if num not in random_numbers:
                random_numbers.append(num)
        
        print("Nombres générés aléatoirement:")
        print(" ".join(map(str, random_numbers)))
    
    except ValueError:
        print("Veuillez entrer un nombre entier valide.")

generate_unique_random_numbers()

