import customtkinter as ck

class TopMenuFrame(ck.CTkFrame):
  def __init__(self, master, open_button_func):
    super().__init__(master)

    self.open_button = ck.CTkButton(self, width=60, 
                                    height=55, 
                                    corner_radius=0, 
                                    fg_color="lightgray", 
                                    text_color="black", 
                                    text="Open", 
                                    command=open_button_func)
    self.open_button._hover_color = "darkgray"
    self.open_button.grid(row=0, column=0, padx=0, pady=0, sticky="nsew")

