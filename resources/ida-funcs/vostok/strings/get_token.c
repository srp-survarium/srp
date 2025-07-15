const char *__usercall vostok::strings::get_token@<eax>(
        unsigned __int8 separator@<al>,
        char *string,
        char *result,
        unsigned int result_size)
{
  int v4; // eax
  int v5; // esi
  int v7; // edi

  strchr(string, separator);
  v5 = v4;
  if ( v4 )
  {
    v7 = v4 - (_DWORD)string;
    memcpy((unsigned __int8 *)result, (unsigned __int8 *)string, v4 - (_DWORD)string);
    result[v7] = 0;
    return (const char *)(v5 + 1);
  }
  else
  {
    vostok::strings::copy(result, result_size, string);
    return 0;
  }
}
