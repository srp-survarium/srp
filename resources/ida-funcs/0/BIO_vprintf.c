int __cdecl BIO_vprintf(bio_st *bio, char *format, int a3)
{
  void *v3; // esi
  int v4; // edi
  void *str; // [esp+Ch] [ebp-818h] BYREF
  int v7; // [esp+10h] [ebp-814h] BYREF
  unsigned int v8; // [esp+14h] [ebp-810h] BYREF
  const __m128i *v9; // [esp+18h] [ebp-80Ch] BYREF
  int v10; // [esp+1Ch] [ebp-808h] BYREF
  char v11[2048]; // [esp+20h] [ebp-804h] BYREF

  v9 = (const __m128i *)v11;
  v8 = 2048;
  str = 0;
  CRYPTO_push_info_((int)bio, a3, "doapr()", ".\\crypto\\bio\\b_print.c", 0x31Au);
  dopr(&v9, (char **)&str, &v8, (unsigned int *)&v7, &v10, format);
  v3 = str;
  if ( str )
  {
    v4 = BIO_write(a3, bio, (const char *)str, v7);
    CRYPTO_free(v3);
  }
  else
  {
    v4 = BIO_write(a3, bio, v11, v7);
  }
  CRYPTO_pop_info(v4, a3);
  return v4;
}
