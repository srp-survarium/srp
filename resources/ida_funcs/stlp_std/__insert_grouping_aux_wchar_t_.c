int __usercall stlp_std::__insert_grouping_aux_wchar_t_@<eax>(
        wchar_t *last@<eax>,
        wchar_t *first,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *grouping,
        wchar_t separator,
        wchar_t Plus,
        wchar_t Minus,
        int basechars)
{
  wchar_t *v8; // eax
  unsigned int v10; // ebp
  wchar_t *v11; // edx
  unsigned __int8 *v12; // esi
  int v13; // edi
  char *M_data; // eax
  int sign; // [esp+4h] [ebp-4h]
  wchar_t *firsta; // [esp+Ch] [ebp+4h]

  v8 = first;
  if ( first == last )
    return 0;
  v10 = 0;
  sign = 0;
  if ( *first == Plus || *first == Minus )
  {
    sign = 1;
    v8 = first + 1;
  }
  v11 = &v8[basechars];
  firsta = v11;
  v12 = (unsigned __int8 *)last;
  v13 = 0;
  while ( 1 )
  {
    M_data = grouping->_M_start_of_storage._M_data;
    if ( v10 < grouping->_M_finish - M_data )
      v13 = M_data[v10++];
    if ( v13 <= 0 || v13 >= (v12 - (unsigned __int8 *)v11) >> 1 || v13 == 127 )
      break;
    ++last;
    v12 -= 2 * v13;
    if ( (char *)last - (char *)v12 > 0 )
    {
      memmove(v12 + 2, v12, (char *)last - (char *)v12);
      v11 = firsta;
    }
    *(_WORD *)v12 = separator;
  }
  return basechars + sign + last - v11;
}
