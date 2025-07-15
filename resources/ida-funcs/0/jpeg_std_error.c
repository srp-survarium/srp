void (__cdecl __noreturn **__cdecl jpeg_std_error(void (__cdecl __noreturn **a1)(int a1)))(int a1)
{
  void (__cdecl __noreturn **result)(int); // eax

  result = a1;
  *a1 = sub_47FCE0;
  a1[1] = (void (__cdecl __noreturn *)(int))sub_47FD60;
  a1[2] = (void (__cdecl __noreturn *)(int))sub_47FD00;
  a1[3] = (void (__cdecl __noreturn *)(int))sub_47FDA0;
  a1[4] = (void (__cdecl __noreturn *)(int))sub_47FE50;
  a1[26] = 0;
  a1[27] = 0;
  a1[5] = 0;
  a1[28] = (void (__cdecl __noreturn *)(int))jpeg_std_message_table;
  a1[29] = (void (__cdecl __noreturn *)(int))126;
  a1[30] = 0;
  a1[31] = 0;
  a1[32] = 0;
  return result;
}
