import customtkinter as ck
from tkinter import filedialog
from frames.chapters_frame import ChaptersFrame
from frames.player_frame import PlayerFrame
from PIL import Image

# Constants 
WIN_WIDTH = "800"
WIN_HEIGHT = "600"
WIN_SIZE = f"{WIN_WIDTH}x{WIN_HEIGHT}"

class App(ck.CTk):
  def __init__(self):
    super().__init__()

    self._set_appearance_mode("dark")

    self.title("AudioGlyph")
    self.geometry(WIN_SIZE)

    # Configure rows and columns
    for i in range(5):
      self.rowconfigure(i, weight=1)
      self.columnconfigure(i, weight=1)

    
    self.open_btn = ck.CTkButton(self, text="Open", width=50, height=50, command=self.open_file)
    self.open_btn.grid(row=0, column=0, padx=0, pady=0, sticky="nsew")

    chapters = []
    for i in range(36):
      chapters.append(f"Chapter {i+1}")

    self.chapters_frame = ChaptersFrame(self, chapters)
    self.chapters_frame.grid(row=0, column=5, rowspan=6, padx=0, pady=0, sticky="ns")

    self.player_frame = PlayerFrame(self)
    self.player_frame.grid(row=5, column=0, columnspan=5, padx=0, pady=0, sticky="ew")

    self.image_path = "audioglyph_logo.png"
    self.image = Image.open(self.image_path)

    self.ck_image = ck.CTkImage(light_image=self.image, dark_image=self.image, size=(500,500))

    self.cover_image = ck.CTkLabel(self, image=self.ck_image, text="")
    self.cover_image.grid(row=1, column=0, rowspan=4, columnspan=5 ,padx=0, pady=0, sticky="nsew")


  def open_file(self):
    dir_path = filedialog.askdirectory(title="Open Directory")
    if dir_path:
      print(f"Selected dir: {dir_path}")

app = App()
app.mainloop()