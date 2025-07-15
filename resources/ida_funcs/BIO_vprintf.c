unsigned int __cdecl BIO_vprintf(bio_st *bio, char *format)
{
  char *v2; // esi
  unsigned int v3; // edi
  char *buffer; // [esp+Ch] [ebp-818h] BYREF
  unsigned int retlen; // [esp+10h] [ebp-814h] BYREF
  unsigned int maxlen; // [esp+14h] [ebp-810h] BYREF
  char *sbuffer; // [esp+18h] [ebp-80Ch] BYREF
  int truncated; // [esp+1Ch] [ebp-808h] BYREF
  char in[2048]; // [esp+20h] [ebp-804h] BYREF

  sbuffer = in;
  maxlen = 2048;
  buffer = 0;
  CRYPTO_push_info_((unsigned int)bio, "doapr()", ".\\crypto\\bio\\b_print.c", 0x31Au);
  dopr(&sbuffer, &buffer, &maxlen, &retlen, &truncated, format);
  v2 = buffer;
  if ( buffer )
  {
    v3 = BIO_write(bio, buffer, retlen);
    CRYPTO_free(v2);
  }
  else
  {
    v3 = BIO_write(bio, in, retlen);
  }
  CRYPTO_pop_info(v3);
  return v3;
}
