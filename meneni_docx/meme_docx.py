#!/usr/bin/env python3
import os
from docx import Document

# Zjistí, kde leží tento skript
current_folder = os.path.dirname(os.path.abspath(__file__))
meme_link = "https://i.imgflip.com/30b1gx.jpg"
#meme_link = "https://cz.pornhub.com/view_video.php?viewkey=690e3f41a3d0e"

print(f"📂 Spouštím přepis všech .docx souborů ve složce:\n{current_folder}\n")

# Projdi všechny složky a podsložky
for current_dir, _, files in os.walk(current_folder):
    for file in files:
        if file.lower().endswith(".docx"):
            path = os.path.join(current_dir, file)
            try:
                doc = Document()
                doc.add_paragraph(f"Podívej se na tohle meme: {meme_link}")
                doc.save(path)
                print(f"✅ Přepsán: {path}")
            except Exception as e:
                print(f"❌ Chyba u {path}: {e}")

print("\n🎉 Hotovo! Všechny .docx soubory v této složce a jejích podsložkách byly přepsány.")



# -----------------------------------------------
# INSTRUKCE K SPUŠTĚNÍ NA WINDOWS:
# 1. Nainstaluj Python (pokud ho nemáš):
#    https://www.python.org/downloads/
#    Při instalaci zaškrtni "Add Python to PATH".
#
# 2. Otevři PowerShell nebo CMD a nainstaluj knihovnu python-docx:
#    pip install python-docx
#
# 3. Ulož tento skript do složky, kde chceš přepsat .docx soubory.
#
# 4. Otevři PowerShell nebo CMD ve složce skriptu.
#
# 5. Spusť skript:
#    v terminalu jdi do slozky kterou budes mazat
#    python meme_docx.py
#
# 6. Všechny .docx soubory v této složce a podsložkách budou přepsány textem s odkazem.
# -----------------------------------------------