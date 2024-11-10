import customtkinter as ck
from tkinter import filedialog
from PIL import Image
from utils.helper import Helper
from frames.chapters_frame import ChaptersFrame
from frames.player_frame import PlayerFrame
from frames.top_menu_frame import TopMenuFrame

# Constants 
WIN_WIDTH = "800"
WIN_HEIGHT = "600"
WIN_SIZE = f"{WIN_WIDTH}x{WIN_HEIGHT}"
LOGO_PATH = "assets/audioglyph_logo.png"

helper = Helper() # Helper functions class

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

    # self.open_btn = ck.CTkButton(self, text="Open", width=50, height=50, command=self.open_directory)
    # self.open_btn.grid(row=0, column=0, padx=0, pady=0, sticky="nsew")

    self.top_menu = TopMenuFrame(self, open_button_func=self.open_directory)
    self.top_menu.grid(row=0, column=0, columnspan=5, padx=0, pady=0, sticky="nsew")

    self.image = Image.open(LOGO_PATH)
    self.ck_image = ck.CTkImage(light_image=self.image, dark_image=self.image, size=(500,500))

    self.cover_image = ck.CTkLabel(self, image=self.ck_image, text="")
    self.cover_image.grid(row=1, column=0, rowspan=2, columnspan=5 ,padx=0, pady=0, sticky="nsew")

    self.chapters_frame = ChaptersFrame(self)
    self.chapters_frame.grid(row=0, column=5, rowspan=6, padx=0, pady=0, sticky="ns")

    self.player_frame = PlayerFrame(self)
    self.player_frame.grid(row=5, column=0, columnspan=5, padx=0, pady=0, sticky="ew")

  def open_directory(self):
    chapter_files = []
    dir_path = filedialog.askdirectory(title="Open Directory")
    if dir_path:
      chapter_files = helper.list_files(dir_path)
      self.chapters_frame.reload_chapters(chapter_files)
      self.load_cover_image(dir_path)
    else:
      print("ERROR Opening Directory")

  def load_cover_image(self, directory):
    image_path = helper.find_cover_image(directory)
    image = Image.open(image_path)
    ck_image = ck.CTkImage(light_image=image, dark_image=image, size=(500,500))
    self.cover_image = ck.CTkLabel(self, image=ck_image, text="")

app = App()
app.mainloop()