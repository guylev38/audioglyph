import customtkinter as ck


class ChapterWidget(ck.CTkButton):
  def __init__(self, master, name, path):
    super().__init__(master=master)
    self.name = name
    self.path = path

  def on_click_chapter(self):
    print(f"Name - {self.name}")
    print(f"Path - {self.path}")
    
  

  
  
