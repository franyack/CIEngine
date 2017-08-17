import base64
import json
from StringIO import StringIO

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

# print json.dumps({'img1': 1,'img2': 2,'img3': 3}, sort_keys=True)#, indent=4,separators=(',',': '))



# print json.dumps({'img1': str(imagen1),'img2': str(imagen2),'img3': str(imagen3)}, sort_keys=True, indent=4,separators=(',',': '))

io = StringIO()
json.dump([imagen1],io)
# print io.getvalue()

decrypt = base64.b64decode(io.getvalue())
file2 = open('images/Descript.jpg','wb')
file2.write(decrypt)
file2.close()


print "Done!"

             # decrypt = base64.b64decode(imagen1)
    #
    # file2 = open('/home/fran/Downloads/Descript.jpg','wb')
    # file2.write(decrypt)
    # file2.close()
    #
    #
    # print "Done!"
