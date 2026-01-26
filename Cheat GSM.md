# Cheat GSM & MQTT

## Gestion SIM / Modem

| Commande | Description | Réponse attendue |
|----------|------------|----------------|
| `AT+CPIN="0000"` | Entrer le code PIN | `SMS DONE / PB DONE` |
| `AT+CPIN?` | Vérifier l’état du SIM | `READY` |
| `AT+CREG?` | Vérifier l’enregistrement réseau | `0,1 OK` |
| `AT+CFUN=1` | Activer le modem | `OK` |

## Configuration APN & réseau

| Commande | Description | Réponse attendue |
|----------|------------|----------------|
| `AT+CGDCONT=1,"IP","mmsbouygtel.com"` | Configurer le contexte PDP (APN) | `OK` |
| `AT+NETOPEN` | Ouvrir la pile IP | `OK` |
| `AT+CGATT=1` | Vérifier l’attachement PDP | `OK` |
| `AT+CGACT=1,1` | Activer le contexte PDP | `OK` |

> `AT+CGATT=1` est obligatoire pour un attachement PDP “classique”.

## MQTT (exemple Adafruit IO)

| Commande | Description | Paramètres / Notes |
|----------|------------|------------------|
| `AT+CMQTTSTART` | Démarrer le client MQTT | - |
| `AT+CMQTTACCQ=0,"FPGA"` | Créer un client MQTT | `0` = client ID, `"FPGA"` = nom du client |
| `AT+CMQTTCONNECT=0,"tcp://io.adafruit.com:1883",60,1,"Tom991","aio_MDP !"` | Connecter au broker | Client 0, broker Adafruit, port 1883, keepalive 60s, QoS 1, login `"Tom991"`, clé API |
| `AT+CMQTTSUB=0,21,1,Tom991/feeds/commande` | S’abonner à un feed MQTT | Client 0, longueur topic 21, QoS 1, topic `"Tom991/feeds/commande"` |

