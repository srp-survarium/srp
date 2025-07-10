ecdh_data_st *__cdecl ecdh_data_dup(void *data)
{
  if ( data )
    return ECDH_DATA_new_method(0);
  else
    return 0;
}
