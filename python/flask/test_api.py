import requests

respond = requests.get("http://localhost:3000/api/love")

print(respond.content)

