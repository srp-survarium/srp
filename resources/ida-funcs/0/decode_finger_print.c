void __usercall decode_finger_print(char (*out_finger_print)[64]@<esi>)
{
  int v1; // eax
  int v2; // edi
  char *v3; // eax

  v1 = 0;
  v2 = 32;
  while ( s_finger_print_original[v1] == s_finger_print[v1 + 16] )
  {
    if ( (unsigned int)++v1 >= 0x20 )
    {
      strcpy_s((char *)out_finger_print, 0x40u, "<this build has not been finger printed>");
      goto LABEL_8;
    }
  }
  v3 = (char *)out_finger_print;
  do
  {
    *v3 = v3[&s_finger_print[16] - (const unsigned __int8 *)out_finger_print] ^ 0x55;
    ++v3;
    --v2;
  }
  while ( v2 );
  (*out_finger_print)[32] = 0;
LABEL_8:
  vostok::strings::copy<512>((char (*)[512])&s_command_line_keys_creation.m_mutex[2], (char *)out_finger_print);
}
