int __cdecl PEM_bytes_read_bio(
        unsigned __int8 **pdata,
        int *plen,
        char **pnm,
        char *name,
        bio_st *bp,
        int (__cdecl *cb)(char *, int, int, void *),
        void *u)
{
  char *v7; // edi
  BOOL EVP_CIPHER_INFO; // eax
  unsigned __int8 *v10; // ebp
  int v11; // eax
  int *v12; // ecx
  int v13; // esi
  char *header; // [esp+10h] [ebp-3Ch] BYREF
  unsigned __int8 *data; // [esp+14h] [ebp-38h] BYREF
  char *namea; // [esp+18h] [ebp-34h] BYREF
  int len; // [esp+1Ch] [ebp-30h] BYREF
  void *ua; // [esp+20h] [ebp-2Ch]
  int *v19; // [esp+24h] [ebp-28h]
  int (__cdecl *callback)(char *, int, int, void *); // [esp+28h] [ebp-24h]
  int v21; // [esp+2Ch] [ebp-20h]
  unsigned __int8 **v22; // [esp+30h] [ebp-1Ch]
  evp_cipher_info_st cipher; // [esp+34h] [ebp-18h] BYREF

  v22 = pdata;
  v19 = plen;
  ua = u;
  callback = cb;
  namea = 0;
  header = 0;
  data = 0;
  v21 = 0;
  if ( !PEM_read_bio(bp, &namea, &header, &data, &len) )
  {
LABEL_4:
    if ( (ERR_peek_error() & 0xFFF) == 0x6C )
      ERR_add_error_data(2, "Expecting: ", name);
    return 0;
  }
  while ( 1 )
  {
    v7 = namea;
    if ( check_pem(namea, name) )
      break;
    CRYPTO_free(v7);
    CRYPTO_free(header);
    CRYPTO_free(data);
    if ( !PEM_read_bio(bp, &namea, &header, &data, &len) )
      goto LABEL_4;
  }
  EVP_CIPHER_INFO = PEM_get_EVP_CIPHER_INFO(header, &cipher);
  v10 = data;
  if ( EVP_CIPHER_INFO && PEM_do_header(&cipher, data, &len, callback, ua) )
  {
    v11 = len;
    v12 = v19;
    *v22 = v10;
    *v12 = v11;
    if ( pnm )
      *pnm = v7;
    v13 = 1;
    if ( pnm )
      goto LABEL_15;
  }
  else
  {
    v13 = v21;
  }
  CRYPTO_free(v7);
LABEL_15:
  CRYPTO_free(header);
  if ( !v13 )
    CRYPTO_free(v10);
  return v13;
}
