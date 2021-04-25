import requests
import json

def get_api():
    try:
        response = requests.get("http://api.open-notify.org/astros.json")
        if response:
            print("SUCCES")
        else:
            print("error occured")
        return response.json()
    except Exception as e:
        print("Error to get an API : "+ str (e))

def json_print(obj):
    try:
        text=json.dumps(obj, sort_keys=True, indent=4)
        return text
    except Exception as e:
        print("Failed convert to JSON : "+ str(e))


if __name__=="__main__":
    response=get_api()
    #print(response)
    json_response= json_print(response['people'])
    print(json_response)
