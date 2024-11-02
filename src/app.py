import customtkinter as ck
from frames.chapters_frame import ChaptersFrame
from frames.player_frame import PlayerFrame
from PIL import Image, ImageTk

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


    chapters = ["Chapter 1", "Chapter 2", "Chapter 3", "Chapter 4", "Chapter 5", "Chapter 6", "Chapter 7"]
    self.chapters_frame = ChaptersFrame(self, chapters)
    self.chapters_frame.grid(row=0, column=5, rowspan=6, padx=0, pady=0, sticky="ns")

    self.player_frame = PlayerFrame(self)
    self.player_frame.grid(row=5, column=0, columnspan=5, padx=0, pady=0, sticky="ew")

    self.image_path = "audioglyph_logo.png"
    self.image = Image.open(self.image_path)

    self.ck_image = ck.CTkImage(light_image=self.image, dark_image=self.image, size=(500,500))

    self.cover_image = ck.CTkLabel(self, image=self.ck_image, text="")
    self.cover_image.grid(row=0, column=0, rowspan=5, columnspan=5 ,padx=0, pady=0, sticky="nsew")



app = App()
app.mainloop()