void __usercall vostok::get_common_prefix(
        const char *second@<edx>,
        vostok::buffer_string *out_string,
        const char *first)
{
  int v3; // esi
  const char *v4; // eax
  int v5; // edx
  char v6; // cl
  char *end_src; // [esp+8h] [ebp-4h] BYREF

  v3 = 0;
  if ( *first )
  {
    v4 = first;
    v5 = second - first;
    do
    {
      v6 = v4[v5];
      if ( !v6 )
        break;
      if ( *v4 != v6 )
        break;
      ++v4;
      ++v3;
    }
    while ( *v4 );
  }
  end_src = (char *)&first[v3];
  vostok::buffer_string::assign<char const *>(out_string, (char **)&first, (const char **)&end_src);
}
