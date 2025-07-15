void __cdecl free_string(ui_string_st *uis)
{
  if ( (uis->flags & 1) != 0 )
  {
    CRYPTO_free((void *)uis->out_string);
    if ( uis->type == UIT_BOOLEAN )
    {
      CRYPTO_free((void *)uis->_.string_data.result_minsize);
      CRYPTO_free((void *)uis->_.string_data.result_maxsize);
      CRYPTO_free((void *)uis->_.string_data.test_buf);
    }
  }
  CRYPTO_free(uis);
}
