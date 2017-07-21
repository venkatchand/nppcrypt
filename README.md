## nppcrypt


a plugin for notepad++ (https://notepad-plus-plus.org/).

features: encryption/decryption with symmetric ciphers like aes. hash-functions like sha3. generation of (pseudo)random values (i.e. for passwords), various encoding options.

##### download:
###### test/alpha (1.0.1.4)
* x86:: http://www.cerberus-design.de/nppcrypt/nppcryptv1014c.x86.zip (md5: 105089f4e6073930303913bfd15b19d6)
* x64:: http://www.cerberus-design.de/nppcrypt/nppcryptv1014c.x64.zip (md5: ccb87309bb3b092caa06c37fa9db87c1)
###### 1.0.1.3
* x86:: http://www.cerberus-design.de/nppcrypt/nppcryptv1013.x86.zip (md5: 0191b7da5389ce95d637705f13154ed6)
* x64:: http://www.cerberus-design.de/nppcrypt/nppcryptv1013.x64.zip (md5: b4f6c5bf060e9f5491ef5e7df37d8d55)

##### email:
kontakt (at) cerberus-design . de

##### this software uses:

- [1] [crypto++](https://www.cryptopp.com) ( important: base64.h and base64.cpp were modified to allow custom linebreaks. see doc/cryptopp-mod )
- [2] [tinyxml2](http://www.grinninglizard.com/tinyxml2) version 2.1.0, part of this project under [tinyxml2](src/tinyxml2)
- [3] [bcrypt](http://www.openwall.com/crypt/) version 1.3, part of this project under [bcrypt](src/bcrypt)
- [4] [scrypt](https://www.tarsnap.com/scrypt.html) version 1.2.0, part of this project under [scrypt](src/scrypt)

#### important:
This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

#### changlog
###### v1.0.1.4:
 - added ChaCha cipher & BLAKE2 hashes (cryptopp >v.5.6.3 needed)
 - interface improvements
 - ...
###### v1.0.1.3:
 - several dialogs (random/covert/hash) are now non-modal and dockable
 - added copy to clipboard buttons

----------
#### how to compile nppcrypt:
In order to compile nppcrypt you first need to compile a custom version of cryptopp. Download the [crypto++](https://www.cryptopp.com) sourcecode and replace the files base64.h and base64.cpp with the custom versions you find under /doc/cryptopp-mod. Then use the Visual Studio Solution (.sln) included with cryptopp to compile cryptlib (static library, runtime-lib: /MT). Now you either have to edit the nppcrypt project-files to indicate where cryptopp can be found or use the existing folder structure: on the same level as nppcrypt: libs/cryptopp/lib with the following files for x86/x64-release/debug: cryptlib_x64_mt_s.lib, cryptlib_x64_mtd_s.lib, cryptlib_x86_mt_s.lib, cryptlib_x86_mtd_s.lib. /libs/cryptopp/include with all cryptopp header files. Now you should be able to compile all nppcrypt configurations.


----------
### FAQ

##### 1. What is this strange xml-stuff (<nppcrypt>...</nppcrypt>) above my encrypted data all about?
Well, first of all it would be quite hard to remember all the different options that were used for different encryptions. Secondly a lot of encryptions need additional data (IV, Salt, tag). Select this header together with your encrypted data and all this stuff will be read automaticly. Of course you can just delete the header and only select the encrypted data for decryption. But in this case you have to select all the right options yourself and provide the missing data (i.e. iv).

##### 2. What is a nppcrypt-file?
In the preferences-dialog you can specify a nppcrypt-file-extension (like mp3 doc etc.). If you futhermore check the "enable" box nppcrypt will now monitor all files you open and save with notepad++. for example: you specified the nppcrypt-file-extension "nbak" and now you save a file as "secret.nbak": the encryption dialog will automaticly open and you 
can choose the encryption-method of your liking. the next time you open this file you will be automaticly asked for your password. #IMPORTANT#: nppcrypt does NOT monitor the auto-backup-feature of notepad++.

##### 3. what are good options for strong encryption?
for example: aes/rijndael 256, gcm , 16-byte salt, scrypt (at least N=14, r=8, p=1, see google), pseudo-random iv

##### 4. this version fails to decrypt stuff i encrypted with an older version!
well, that should not happen, but... please downgrade to the older version (www.cerberus-design.de/downloads), decrypt and then reupdate. you might also send the exact problematic encryption-options to kontakt (at) cerberus-design . de

##### 5. nppcrypt shows me most of what went into the encryption (header) but is there other stuff i might want to know?
1) all user input (passwords...) is converted to utf8.
2) bcrypt output is always 24 bytes long. therefore it is hashed by keccak-shake128 to get the needed key-length.
3) some cipher modes provide authentication (gcm/ccm/eax). nppcrypt authenticates the IV and Salt data (as base64 strings) and the encrypted data.
4) nppcrypt can add an additional hmac value to authenticate the data (see auth-tab in encryption-dialog). for this purpose everything beween <nppcrypt> and </nppcrypt> in the header and the encrypted data is hashed.