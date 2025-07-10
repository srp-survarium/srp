char *__cdecl stlp_std::__insert_grouping_aux_char_(
        char *first,
        char *last,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *grouping,
        char separator,
        char Plus,
        char Minus,
        int basechars)
{
  char *v7; // edx
  char *v8; // ebp
  unsigned int v10; // ebx
  char *v11; // edx
  unsigned __int8 *v12; // esi
  int v13; // edi
  char *M_data; // eax
  char *firsta; // [esp+8h] [ebp+4h]
  int sign; // [esp+Ch] [ebp+8h]

  v7 = first;
  v8 = last;
  if ( first == last )
    return 0;
  v10 = 0;
  sign = 0;
  if ( *first == Plus || *first == Minus )
  {
    sign = 1;
    v7 = first + 1;
  }
  v11 = &v7[basechars];
  v12 = (unsigned __int8 *)v8;
  firsta = v11;
  v13 = 0;
  while ( 1 )
  {
    M_data = grouping->_M_start_of_storage._M_data;
    if ( v10 < grouping->_M_finish - M_data )
      v13 = M_data[v10++];
    if ( v13 <= 0 || v13 >= v12 - (unsigned __int8 *)v11 || v13 == 127 )
      break;
    ++v8;
    v12 -= v13;
    if ( v8 - (char *)v12 > 0 )
    {
      memmove(v12 + 1, v12, v8 - (char *)v12);
      v11 = firsta;
    }
    *v12 = separator;
  }
  return &v8[sign - (_DWORD)v11 + basechars];
}
