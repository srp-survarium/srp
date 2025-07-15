void __usercall decode_finger_print(char (*out_finger_print)[64]@<edi>)
{
  int v1; // eax
  char *v2; // eax
  int v3; // esi

  v1 = 0;
  while ( s_finger_print_original[v1] == s_finger_print[v1 + 16] )
  {
    if ( (unsigned int)++v1 >= 0x20 )
    {
      strcpy_s((char *)out_finger_print, 0x40u, "<this build has not been finger printed>");
      strcpy_s((char *)&vostok::memory::g_crt_allocator.m_arena_start, 0x200u, (const char *)out_finger_print);
      return;
    }
  }
  v2 = (char *)out_finger_print;
  v3 = 32;
  do
  {
    *v2 = v2[&s_finger_print[16] - (const unsigned __int8 *)out_finger_print] ^ 0x55;
    ++v2;
    --v3;
  }
  while ( v3 );
  (*out_finger_print)[32] = 0;
  strcpy_s((char *)&vostok::memory::g_crt_allocator.m_arena_start, 0x200u, (const char *)out_finger_print);
}
