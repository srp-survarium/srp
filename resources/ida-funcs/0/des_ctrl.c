int __usercall des_ctrl@<eax>(int a1@<edi>, evp_cipher_ctx_st *c, int type, int arg, unsigned __int8 *ptr)
{
  if ( type != 6 )
    return -1;
  if ( RAND_bytes(a1) <= 0 )
    return 0;
  DES_set_odd_parity((unsigned __int8 (*)[8])ptr);
  return 1;
}
