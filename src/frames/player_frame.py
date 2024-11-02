import customtkinter as ck

class PlayerFrame(ck.CTkFrame):
  def __init__(self, master, border_width=2):
    super().__init__(master, border_width=border_width)


    self.grid_columnconfigure(0, weight=0)
    self.grid_rowconfigure(0, weight=0)
    

    self.pause_btn = ck.CTkButton(self, width=50, height=50, text="||")
    self.play_btn = ck.CTkButton(self, width=50, height=50, text="▶")
    self.stop_btn = ck.CTkButton(self, width=50, height=50, text="■")

    self.pause_btn.grid(row=0, column=0, padx=10, pady=10, sticky="ew")
    self.play_btn.grid(row=0, column=1, padx=10, pady=10, sticky="ew")
    self.stop_btn.grid(row=0, column=2, padx=10, pady=10, sticky="ew")
