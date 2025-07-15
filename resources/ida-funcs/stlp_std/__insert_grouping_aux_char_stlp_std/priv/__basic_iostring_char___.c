void __usercall stlp_std::__insert_grouping_aux_char_stlp_std::priv::__basic_iostring_char___(
        stlp_std::priv::__basic_iostring<char> *iostr@<esi>,
        char *__group_pos@<edx>,
        char separator@<bl>,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *grouping,
        char Plus,
        char Minus,
        int basechars)
{
  char *M_data; // eax
  int v8; // edi
  char *inserted; // eax
  int v10; // edi
  unsigned int v11; // ebp
  char *v12; // ecx
  stlp_std::priv::__basic_iostring<char> *v13; // edx
  char *M_finish; // ecx
  char *v15; // eax
  char *v16; // eax
  unsigned int v17; // ecx
  int *v18; // eax
  unsigned int v19; // eax
  int v20; // [esp+0h] [ebp-Ch]
  unsigned int v21; // [esp+4h] [ebp-8h] BYREF
  int v22; // [esp+8h] [ebp-4h] BYREF

  M_data = iostr->_M_start_of_storage._M_data;
  if ( (char *)(iostr->_M_finish - M_data) >= __group_pos )
  {
    v8 = 0;
    if ( *M_data == Plus || *M_data == Minus )
      v8 = 1;
    v20 = basechars + v8;
    inserted = &M_data[(_DWORD)__group_pos];
    v10 = 0;
    v11 = 0;
    while ( 1 )
    {
      v12 = grouping->_M_start_of_storage._M_data;
      if ( v11 < grouping->_M_finish - v12 )
        v10 = v12[v11++];
      if ( v10 <= 0 )
        break;
      v13 = (stlp_std::priv::__basic_iostring<char> *)iostr->_M_start_of_storage._M_data;
      if ( v10 >= inserted - (char *)v13 - v20 || v10 == 127 )
        break;
      M_finish = iostr->_M_finish;
      v15 = &inserted[-v10];
      if ( v15 == M_finish )
      {
        if ( v13 == iostr )
          v16 = (char *)((char *)iostr - M_finish + 16);
        else
          v16 = (char *)(iostr->_M_buffers._M_end_of_storage - M_finish);
        if ( v16 == (char *)1 )
        {
          v17 = M_finish - (char *)v13;
          v22 = 1;
          v21 = v17;
          if ( -2 == v17 )
            stlp_std::__stl_throw_length_error("basic_string");
          v18 = (int *)&v21;
          if ( v17 <= 1 )
            v18 = &v22;
          v19 = *v18 + v17 + 1;
          if ( v19 == -1 || v19 < v17 )
            v19 = -2;
          stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_reserve(
            iostr,
            v19);
        }
        iostr->_M_finish[1] = 0;
        *iostr->_M_finish++ = separator;
        inserted = iostr->_M_finish - 1;
      }
      else
      {
        inserted = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_insert_aux(
                     iostr,
                     v15,
                     separator);
      }
    }
  }
}
