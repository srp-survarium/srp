void __usercall ssl_cipher_get_disabled(
        unsigned int *auth@<ebx>,
        unsigned int *enc@<esi>,
        unsigned int *mac@<edi>,
        unsigned int *mkey,
        unsigned int *ssl)
{
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  unsigned int v14; // eax
  int v15; // ecx

  *mkey = 0;
  *auth = 0;
  *enc = 0;
  *mac = 0;
  *ssl = 0;
  *mkey |= 6u;
  *auth |= 8u;
  *mkey |= 0x10u;
  *auth |= 0x20u;
  if ( !get_optional_pkey_id((unsigned int)mac, "gost94") )
    *auth |= 0x100u;
  if ( !get_optional_pkey_id((unsigned int)mac, "gost2001") )
    *auth |= 0x200u;
  if ( (*auth & 0x300) == 0x300 )
    *mkey |= 0x200u;
  *enc |= ssl_cipher_methods[0] == 0;
  v5 = *enc | (ssl_cipher_methods[1] != 0 ? 0 : 2);
  *enc = v5;
  v6 = v5 | (ssl_cipher_methods[2] != 0 ? 0 : 4);
  *enc = v6;
  v7 = v6 | (ssl_cipher_methods[3] != 0 ? 0 : 8);
  *enc = v7;
  v8 = v7 | (ssl_cipher_methods[4] != 0 ? 0 : 16);
  *enc = v8;
  v9 = v8 | (ssl_cipher_methods[6] != 0 ? 0 : 64);
  *enc = v9;
  v10 = v9 | (ssl_cipher_methods[7] != 0 ? 0 : 128);
  *enc = v10;
  v11 = v10 | (ssl_cipher_methods[8] != 0 ? 0 : 256);
  *enc = v11;
  v12 = v11 | (ssl_cipher_methods[9] != 0 ? 0 : 512);
  *enc = v12;
  v13 = v12 | (ssl_cipher_methods[10] != 0 ? 0 : 1024);
  *enc = v13;
  *enc = v13 | (ssl_cipher_methods[11] != 0 ? 0 : 2048);
  *mac |= ssl_digest_methods[0] == 0;
  v14 = *mac | (ssl_digest_methods[1] != 0 ? 0 : 2);
  *mac = v14;
  v15 = v14 | (ssl_digest_methods[2] != 0 ? 0 : 4);
  *mac = v15;
  if ( ssl_digest_methods[3] && ssl_mac_pkey_id[3] )
    *mac = v15;
  else
    *mac = v15 | 8;
}
