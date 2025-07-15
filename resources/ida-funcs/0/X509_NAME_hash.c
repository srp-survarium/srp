int __usercall X509_NAME_hash@<eax>(int a1@<edi>, X509_name_st *x)
{
  const env_md_st *v2; // eax
  unsigned __int8 md[2]; // [esp+4h] [ebp-18h] BYREF
  unsigned __int16 v5; // [esp+6h] [ebp-16h]

  i2d_X509_NAME(x, 0);
  v2 = EVP_sha1();
  EVP_Digest(a1, x->canon_enc, x->canon_enclen, md, 0, v2, 0);
  return md[0] | ((md[1] | (v5 << 8)) << 8);
}
