int __cdecl X509_NAME_hash(X509_name_st *x)
{
  const env_md_st *v1; // eax
  unsigned __int8 md[2]; // [esp+4h] [ebp-18h] BYREF
  unsigned __int16 v4; // [esp+6h] [ebp-16h]

  i2d_X509_NAME(x, 0);
  v1 = EVP_sha1();
  EVP_Digest(x->canon_enc, x->canon_enclen, md, 0, v1, 0);
  return md[0] | ((md[1] | (v4 << 8)) << 8);
}
