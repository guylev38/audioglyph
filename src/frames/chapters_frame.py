import customtkinter as ck

class ChaptersFrame(ck.CTkScrollableFrame):
  def __init__(self, master, chapters, border_width=2):
    super().__init__(master, border_width=border_width, label_text="Chapters")
    self.chapters = chapters

    self.columnconfigure(0, weight=1)
    self.rowconfigure(0, weight=1)


    for i, chapter in enumerate(self.chapters):
      chapter_button = ck.CTkButton(self, width=100, height=50, text=chapter)
      chapter_button.grid(row=i, column=0, padx=10, pady=(10,0), sticky="ew")

