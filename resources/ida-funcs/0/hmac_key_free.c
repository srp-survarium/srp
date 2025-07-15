void __cdecl hmac_key_free(evp_pkey_st *pkey)
{
  char *ptr; // esi
  int v2; // eax

  ptr = pkey->pkey.ptr;
  if ( ptr )
  {
    v2 = *((_DWORD *)ptr + 2);
    if ( v2 )
      OPENSSL_cleanse(v2, *(_DWORD *)ptr);
    ASN1_OCTET_STRING_free((asn1_string_st *)ptr);
  }
}
