void __usercall stlp_std::__insert_grouping_aux_wchar_t_stlp_std::priv::__basic_iostring_wchar_t___(
        stlp_std::priv::__basic_iostring<wchar_t> *iostr@<esi>,
        unsigned int __group_pos@<edx>,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *grouping,
        wchar_t separator,
        wchar_t Plus,
        wchar_t Minus,
        int basechars)
{
  wchar_t *M_data; // eax
  int v8; // ebp
  int v9; // ebp
  int v10; // edi
  wchar_t *inserted; // eax
  unsigned int v12; // ebx
  char *v13; // ecx
  stlp_std::priv::__basic_iostring<wchar_t> *v14; // edx
  wchar_t *v15; // ecx
  wchar_t *M_finish; // eax
  int v17; // ecx
  unsigned int v18; // eax
  int *v19; // ecx
  unsigned int v20; // ecx
  int __first_pos; // [esp+0h] [ebp-Ch]
  unsigned int v22; // [esp+4h] [ebp-8h] BYREF
  int v23; // [esp+8h] [ebp-4h] BYREF

  M_data = iostr->_M_start_of_storage._M_data;
  if ( iostr->_M_finish - M_data >= __group_pos )
  {
    v8 = 0;
    if ( *M_data == Plus || *M_data == Minus )
      v8 = 1;
    v9 = basechars + v8;
    v10 = 0;
    __first_pos = v9;
    inserted = &M_data[__group_pos];
    v12 = 0;
    while ( 1 )
    {
      v13 = grouping->_M_start_of_storage._M_data;
      if ( v12 < grouping->_M_finish - v13 )
        v10 = v13[v12++];
      if ( v10 <= 0 )
        break;
      v14 = (stlp_std::priv::__basic_iostring<wchar_t> *)iostr->_M_start_of_storage._M_data;
      if ( v10 >= (((char *)inserted - (char *)v14) >> 1) - v9 || v10 == 127 )
        break;
      v15 = &inserted[-v10];
      M_finish = iostr->_M_finish;
      if ( v15 == M_finish )
      {
        if ( v14 == iostr )
        {
          v17 = 16 - (((char *)M_finish - (char *)iostr) >> 1);
          v9 = __first_pos;
        }
        else
        {
          v17 = iostr->_M_buffers._M_end_of_storage - M_finish;
        }
        if ( v17 == 1 )
        {
          v18 = ((char *)M_finish - (char *)v14) >> 1;
          v23 = 1;
          v22 = v18;
          if ( 2147483646 == v18 )
            stlp_std::__stl_throw_length_error("basic_string");
          v19 = (int *)&v22;
          if ( v18 <= 1 )
            v19 = &v23;
          v20 = *v19 + v18 + 1;
          if ( v20 > 0x7FFFFFFE || v20 < v18 )
            v20 = 2147483646;
          stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_reserve(
            iostr,
            v20);
        }
        iostr->_M_finish[1] = 0;
        *iostr->_M_finish++ = separator;
        inserted = iostr->_M_finish - 1;
      }
      else
      {
        inserted = stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_insert_aux(
                     iostr,
                     v15,
                     separator);
      }
    }
  }
}
