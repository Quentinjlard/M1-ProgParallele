# Nom du programme final
TARGET = TP1

# Compilateur
CC = g++

# Options de compilation
CFLAGS = -std=c++11 -pthread

# Répertoire des fichiers source
SRCDIR = src

# Répertoire pour les fichiers objets
OBJDIR = obj

# Liste des fichiers source
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Générer la liste des fichiers objets à partir des fichiers source
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# Règle par défaut
all: $(TARGET)

# Crée le programme final en liant les fichiers objets
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile chaque fichier source en fichier objet
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Nettoie les fichiers objets et l'exécutable
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Lancer le programme
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
