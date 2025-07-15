void __userpurge vostok::logging::path_parts::concat2buffer(
        char (*buffer)[512]@<edi>,
        vostok::logging::path_parts *this)
{
  int v2; // esi
  int i; // ebx
  const char **v4; // eax
  char *v5; // ecx
  char *v6; // eax
  unsigned int v7; // [esp+8h] [ebp-4h]

  v2 = 0;
  (*buffer)[0] = 0;
  for ( i = 0; ; ++i )
  {
    v4 = &this->m_parts.m_begin[i];
    if ( !*v4 )
      break;
    v5 = (char *)*v4;
    v7 = strlen(*v4);
    vostok::strings::copy(&(*buffer)[v2], 512 - v2, v5);
    v2 += v7;
  }
  if ( v2 )
  {
    v6 = &(*buffer)[v2 - 1];
    if ( *v6 == 58 )
      *v6 = 0;
  }
}
