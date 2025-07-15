ecdh_data_st *__usercall ecdh_data_dup@<eax>(int a1@<ebx>, void *a2)
{
  if ( a2 )
    return ECDH_DATA_new_method(0, a1);
  else
    return 0;
}
