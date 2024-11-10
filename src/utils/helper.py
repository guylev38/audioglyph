from pathlib import Path

class Helper():
  def __init__(self):
    pass

  def list_files(self, dir_path):
    path = Path(dir_path)
    files = []
    for file in path.iterdir():
      if file.is_file() and file.name.endswith(".mp3"):
        files.append(file.name.strip(".mp3"))
    return files
  
  def find_cover_image(self, dir_path):
    path = Path(dir_path).absolute()
    for file in path.iterdir():
      if file.name.endswith(".jpg") or file.name.endswith(".png"):
        return f"{dir_path}/{file.name}"
    
    print("Error helper.py: Cover image not found")


    