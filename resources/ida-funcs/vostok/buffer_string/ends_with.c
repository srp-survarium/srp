bool __userpurge vostok::buffer_string::ends_with@<al>(
        vostok::buffer_string *this@<ecx>,
        int a2@<eax>,
        const char *string)
{
  unsigned int v3; // edi

  v3 = *(_DWORD *)(a2 + 4) - *(_DWORD *)a2;
  if ( v3 )
    return vostok::strings::ends_with(*(const char **)a2, v3, strlen(string), string);
  else
    return &string[strlen(string) + 1] == string + 1;
}
