#include <pgmspace.h>
#define THINGNAME "esp32_max30102"

const char ssid[]="M2 Luthfan";
const char password[] ="nisanisa";
const char AWS_IOT_ENDPOINT[]="au77sfuxdybdm-ats.iot.us-east-1.amazonaws.com";


// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUFokQRlhZHQytC5MbXook8s4LI+gwDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTI0MDUxMDE1MTEz
NloXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAOLdmFGzGm9JbhGWdjb+
CstMuBMhMDPyDYfdgHiliteVFGUjzQ/THzyZDrNwYTTYljJEfv9CiWT7picHD2Iq
FYNQGGNzGgxXX0P+ySOglGk6a7D96fUMW60Tbe6fJDDjXXEPtLnduRC3fL3hUxtN
FaqaMasHw6yCf7jmdI61zz5oVBUaOZwOFlyZFLukmXtxxfb3n4mGd854bCHgtkYl
SLyLd31MFqIxRTYFFXiH1RLNus32whbycjFiRDRpJ8twRVtyWVIITKIT7y3DnRy1
kxUufSIscd2l4Pw3rSjOKFN/1XqvxELxktwWm9s69lxymPfOL/CC6yvU41Uepujf
en8CAwEAAaNgMF4wHwYDVR0jBBgwFoAUo9EeiaXmg5qnZwkoa39NU4B3bZcwHQYD
VR0OBBYEFGe9uqBPdMlplHyIqlZhiOOnc8i+MAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQAMV3p6Y027IOp1rPZBX/TrbENf
iIi4OpCDI4e/EgLnCdwWA63XdDLbjKTkICgpg/BA1JqC2XySfOpIsksVcfepc3Lt
wgqyXqrvbXmdUbx2VKruY1y7O8P7+KZl5GzPu9OAx/DZMYNtzH1bVMkJSqlxhdNM
EkjsvKTGtPugiJnoQeSIUZxH7qz+i7fJGPxDw6PNNWxSvY09se+Jz82fHgjFcBdd
qIrUotCa21smZoSj+vyxxitX4ibnDDVRWoSsX7FWzljZGhZqefYcmDphLs8SpgmE
Cz5CUlMubF2juSPaolCOUnXtiH+gt4jX485KDnICXuRpabjt9hARnNwmIgZu
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpQIBAAKCAQEA4t2YUbMab0luEZZ2Nv4Ky0y4EyEwM/INh92AeKWK15UUZSPN
D9MfPJkOs3BhNNiWMkR+/0KJZPumJwcPYioVg1AYY3MaDFdfQ/7JI6CUaTprsP3p
9QxbrRNt7p8kMONdcQ+0ud25ELd8veFTG00VqpoxqwfDrIJ/uOZ0jrXPPmhUFRo5
nA4WXJkUu6SZe3HF9vefiYZ3znhsIeC2RiVIvIt3fUwWojFFNgUVeIfVEs26zfbC
FvJyMWJENGkny3BFW3JZUghMohPvLcOdHLWTFS59Iixx3aXg/DetKM4oU3/Veq/E
QvGS3Bab2zr2XHKY984v8ILrK9TjVR6m6N96fwIDAQABAoIBAQCRKRUjgaRyfNuu
6UVu3pJtjwNhSiUbt8+slbB0ggga9Ur9hDDb5Uzha1YavteUBtnkBCv2jM55DQQ9
iKjxONhXE1Lnn2iVaPqN+WMeJsuPoU/zCiU/JM8sKXh37OAtX+4UP+Z130dhSObK
YHjayTIJ3WvWcbtkkIPE/cCq5+5ZkReEa3AurUtdvky+ezgR4ZJgaJhA4IN7EnH6
SMBlpfUlYUSFiZkVUJaRXhW/tdzxFswH+xpSnq1NEsUNgbLukOfwa6RBl0snPiHr
5/mbX3s//Z9nyZhSCF+BpeFw43aOrSk4KPQEHRVA2pOHyERfh1RcYgyaAiSnQP+6
9hyHcSpRAoGBAPE8NjRJVJSMxG+WpCYGgHm/r7vMTYS0a8tvkHc2uV0qAP5JO4c4
X2w2Pyv3D7cdEiL6ER5SnPksbnF7ZIQBqDgU5c++avp09bUpQayPQY+syOqH1ORS
4bz06PZpIe6ol0yzNiv9PMF94L4KPb0Tz/gdmyBfefl7Z7VUI3lTDUTdAoGBAPDA
O8rZsYWNymXxS0fZcUcf59UHnHsI0mr4NZamYTH9Vhg3lJE6HlqnXwO1fBfpCUz9
bWjIo0Xvhie5hr5IFEYRHB5xBv23/sFWSd0YJfcgy0IoMzEd/45G4w37aLvPPvq2
Mn8zB/Hxm0PvkDom4Jrx0pk0qg8LfP9Wt+frbMkLAoGAPMhgHAKSFi/12uwJBi/D
NWoQHHCY46QWORcuPmuCfy/zOh83qZWRrZFpj2lcA1aG2FtL7uj/9mS0m1Fs/Tnx
qdfSI+slx1+q/W+cxZ7+9PWjVjzNbo5XpKXNATFyRFEkdkX9k03mfhZ6h0fLUJXq
Y+kJyjlkYXEvq2e83HgJst0CgYEAxuJHguAr4uSrm2OmiQh8qAEXh8jt4EX9bhj2
TCnOiXl7Mi5YMVEN2l4CBBJdHXOKF2wUgkedehzReuetBGyPMwLXc95zpA3oCte5
1UgptOoGf/SttZnOkD7HO7nBX8VphbwWIzaJDbpGRe0V/LQ5QEcdbysugZc//8An
1ROLntkCgYEAz4WSAkNz3glVM9r6NzF27fUUbXKZIm7dVZl9bIXvn89jDzIibbxx
8XOQexfm+NoTjgmajShU8B2JqpFxI9GgVxiwD3PjHbkPGgOxLjjPVCqXEv65kjKg
qKlub1+X89d2K4HG9mlV5KK9DYKrC01rWPjVLgBQyEY+E5/H4fqkMhU=
-----END RSA PRIVATE KEY-----
)KEY";
