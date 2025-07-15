ec_key_st *__cdecl EC_KEY_new()
{
  ec_key_st *result; // eax

  result = (ec_key_st *)CRYPTO_malloc(32, ".\\crypto\\ec\\ec_key.c", 73);
  if ( result )
  {
    result->version = 1;
    result->group = 0;
    result->pub_key = 0;
    result->priv_key = 0;
    result->enc_flag = 0;
    result->conv_form = POINT_CONVERSION_UNCOMPRESSED;
    result->references = 1;
    result->method_data = 0;
  }
  else
  {
    ERR_put_error(0x10u, 182, 65, ".\\crypto\\ec\\ec_key.c", 76);
    return 0;
  }
  return result;
}
