import io
import base64
from PIL import Image

path_to_img = 'images/img 1.jpg'   # TODO: modify this!
img = Image.open(path_to_img)
# Show
# img.show()

# # Encode
in_mem_file = io.BytesIO()
img.save(in_mem_file, format=img.format)
# reset file pointer to start
in_mem_file.seek(0)
img_bytes = in_mem_file.read()
base64_encoded_result = base64.b64encode(img_bytes)
print "Base64 string (only first 100 chars): %s" % base64_encoded_result[:100]
#
# # Decode
# base64_decoded_bytes = base64.b64decode(base64_encoded_result)
# img2_bytes = io.BytesIO(base64_decoded_bytes)
# img2 = Image.open(img2_bytes)
# # Show
# img2.show()

# from the previous result...
import json

json_example = {'base64_img': base64_encoded_result}
path_to_json = path_to_img.split('.')[0]+'.json'  # TODO: modify this!

# write to disk
with open(path_to_json, 'w') as f:
    json.dump(json_example, f)

# check proper saving
with open(path_to_json, 'r') as f:
    json_img = json.load(f)

# Decode
base64_img = json_img['base64_img']
base64_decoded_bytes = base64.b64decode(base64_img)
img3_bytes = io.BytesIO(base64_decoded_bytes)
img3 = Image.open(img3_bytes)
# Show
img3.show()