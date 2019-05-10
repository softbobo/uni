# Robert Schulze
# Matrikelnummer: 555625
# 09 Mai 2019

class instance():
    index = 0
    def __init__(self):
        pass

    
    def write_to_file(self, argument, outfile):
        outfile.write(str(argument))
        outfile.write('\t\t')