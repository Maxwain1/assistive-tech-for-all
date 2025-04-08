import speech_recognition as sr

def listen_for_speech():
    recognizer = sr.Recognizer()

    with sr.Microphone() as source:
        print("Please say something...")
        recognizer.adjust_for_ambient_noise(source)
        audio = recognizer.listen(source)

    try:
        print("Recognizing...")
        text = recognizer.recognize_google(audio)
        print(f"You said: {text}")
        return text

    except sr.UnknownValueError:
        print("Sorry, I couldn't understand the audio.")
    except sr.RequestError:
        print("Sorry, there was an issue with the speech recognition service.")

if __name__ == "__main__":
    listen_for_speech()
