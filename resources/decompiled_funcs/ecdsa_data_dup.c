ecdsa_data_st *__cdecl ecdsa_data_dup(void *data)
{
  if ( data )
    return ECDSA_DATA_new_method(0);
  else
    return 0;
}
