int __usercall X509_STORE_CTX_get_ex_new_index@<eax>(int a1@<edi>, int a2@<ebx>)
{
  return CRYPTO_get_ex_new_index(a1, a2);
}
