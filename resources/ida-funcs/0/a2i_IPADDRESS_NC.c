void __cdecl a2i_IPADDRESS_NC(char *ipasc)
{
  int v1; // eax
  int v2; // edi
  char *v3; // eax
  char *v4; // esi
  _BYTE *v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  asn1_string_st *v9; // esi
  unsigned __int8 d[32]; // [esp+8h] [ebp-24h] BYREF

  strchr(ipasc, 0x2Fu);
  v2 = v1;
  if ( v1 )
  {
    v3 = BUF_strdup(ipasc);
    v4 = v3;
    if ( v3 )
    {
      v5 = (_BYTE *)(v3 - ipasc + v2);
      *v5 = 0;
      v6 = a2i_ipadd((int)ipasc, d, v3);
      v7 = v6;
      if ( v6 )
      {
        v8 = a2i_ipadd(v6, &d[v6], v5 + 1);
        CRYPTO_free(v4);
        if ( v8 )
        {
          if ( v7 == v8 )
          {
            v9 = ASN1_OCTET_STRING_new();
            if ( v9 )
            {
              if ( !ASN1_OCTET_STRING_set(v9, d, v7 + v8) )
                ASN1_OCTET_STRING_free(v9);
            }
          }
        }
      }
      else
      {
        CRYPTO_free(v4);
      }
    }
  }
}
