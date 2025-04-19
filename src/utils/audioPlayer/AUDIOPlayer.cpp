#include<AUDIOPlayer.h>
using namespace std;

AUDIOPlayer::AUDIOPlayer()
{

}

void AUDIOPlayer::speak(std::string & text, int & languageOption)
{
    #ifdef _WIN32
    HRESULT hr = CoInitialize(NULL);
    if (SUCCEEDED(hr)) {
        ISpVoice* pVoice = NULL;
        hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
        if (SUCCEEDED(hr)) {
            wstring wtext(text.begin(), text.end());

            WCHAR* langTag = nullptr;
            if (languageOption == 1) {
                langTag = L"Language=0C0A"; 
            } else if (languageOption == 2) {
                langTag = L"Language=409";  
            } else if(languageOption == 3){
                langTag = L"Language=40C";
            }else if (languageOption == 4){
                langTag = L"Language= 410";
            }else if (languageOption == 5){
                langTag = L"Language = 407";
            }else{ cout<<"opcion invalida";}

            if (langTag) {
                IEnumSpObjectTokens* pEnum = NULL;
                ULONG count = 0;
                ISpObjectToken* cpToken = NULL;

                hr = SpEnumTokens(SPCAT_VOICES, langTag, NULL, &pEnum);
                if (SUCCEEDED(hr) && pEnum != NULL) {
                    hr = pEnum->Next(1, &cpToken, &count);
                    if (SUCCEEDED(hr) && count > 0 && cpToken != NULL) {
                        pVoice->SetVoice(cpToken);
                        cpToken->Release();
                    } else {
                        cout << "No se encontró una voz para ese idioma." << endl;
                    }
                    pEnum->Release();
                }
            }

            pVoice->Speak(wtext.c_str(), SPF_IS_XML, NULL);
            pVoice->Release();
        }
        CoUninitialize();
    }
#elif __APPLE__
    
    string command = "say \"" + text + "\"";
    system(command.c_str());
#else
    
    cout << "La función de texto a voz no está disponible en este sistema." << endl;
#endif
}


