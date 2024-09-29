# Endstone Shuffle

A plugin for [Endstone](https://endstone.dev) to automatically cycle through a set of MOTD messages.


## Setup
When running the plugin for the first time, a config will be generated under `bedrock_server/StoneShuffle/config.json`

Inside this file, you will find the following default configuration:
```json
{
     "refreshInterval": 10,                                                                                                                                                                                                                                                                                                                                                                     
     "messages": [                                                                                                                                                                                      
         "Hey. I'm a MOTD message.",                                                                                                                                                                    
         "Loudbook was here.",                                                                                                                                                                          
         "What's going on?"                                                                                                                                                                             
     ]                                                                                                                                                                                            
 }                                                                                                                                                                                                      
       
```

`refreshInterval` - The time in SECONDS between MOTD refreshes.

`messages` - A list of MOTD messages you'd like to cycle through.
