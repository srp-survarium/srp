int ssleay_rand_cleanup()
{
  int result; // eax

  OPENSSL_cleanse(state, 1043);
  state_num = 0;
  state_index = 0;
  result = OPENSSL_cleanse(md, 20);
  entropy = 0.0;
  md_count[0] = 0;
  md_count[1] = 0;
  initialized = 0;
  return result;
}
