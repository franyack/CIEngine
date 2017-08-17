import base64
import json


#
# for i in range(1,4):
#     with open("images/img %d.jpg" %i, "rb") as file:
#         imagen = base64.b64encode(file.read())

with open("images/img 1.jpg", "rb") as file1:
         imagen1 = base64.b64encode(file1.read())

with open("images/img 2.jpg", "rb") as file2:
         imagen2 = base64.b64encode(file2.read())

with open("images/img 3.jpg", "rb") as file3:
         imagen3 = base64.b64encode(file3.read())

print(imagen1)
print(imagen2)
print(imagen3)

             # decrypt = base64.b64decode(imagen1)
    #
    # file2 = open('/home/fran/Downloads/Descript.jpg','wb')
    # file2.write(decrypt)
    # file2.close()
    #
    #
    # print "Done!"
