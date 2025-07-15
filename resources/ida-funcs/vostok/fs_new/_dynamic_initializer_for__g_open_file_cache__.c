void vostok::fs_new::_dynamic_initializer_for__g_open_file_cache__()
{
  int v0; // edi
  unsigned int *p_counter; // esi

  v0 = 1;
  p_counter = &vostok::fs_new::g_open_file_cache[0].counter;
  do
  {
    vostok::fs_new::native_path_string::native_path_string((vostok::fs_new::native_path_string *)(p_counter - 72));
    *(p_counter - 3) = 0;
    *p_counter = 0;
    p_counter += 73;
    --v0;
  }
  while ( v0 >= 0 );
}
