int __cdecl stlp_std::_Underflow<char,stlp_std::char_traits<char>>::_M_doit(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *__this)
{
  char *M_saved_egptr; // ecx
  char *M_saved_gptr; // eax
  void *M_mmap_base; // eax
  DWORD v5; // edi
  int v6; // edx
  int v7; // ebp
  __int64 v8; // rax
  __int64 v9; // rcx
  __int64 v10; // rax
  __int64 v11; // kr00_8
  __int64 v12; // rcx
  bool v13; // sf
  bool v14; // cc
  char *v15; // eax
  char *v16; // edx
  int v17; // [esp+4h] [ebp-10h]

  if ( __this->_M_in_input_mode )
  {
    if ( __this->_M_in_putback_mode )
    {
      M_saved_egptr = __this->_M_saved_egptr;
      __this->_M_gbegin = __this->_M_saved_eback;
      M_saved_gptr = __this->_M_saved_gptr;
      __this->_M_gnext = M_saved_gptr;
      __this->_M_gend = M_saved_egptr;
      __this->_M_in_putback_mode = 0;
      if ( M_saved_gptr != M_saved_egptr )
        return (unsigned __int8)*M_saved_gptr;
    }
  }
  else if ( !stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_switch_to_input_mode(__this) )
  {
    return -1;
  }
  if ( !__this->_M_base._M_regular_file || !__this->_M_always_noconv || (__this->_M_base._M_openmode & 4) == 0 )
    return stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_underflow_aux(__this);
  M_mmap_base = __this->_M_mmap_base;
  if ( M_mmap_base )
    stlp_std::_Filebuf_base::_M_unmap(&__this->_M_base, M_mmap_base, __this->_M_mmap_len);
  v5 = stlp_std::_Filebuf_base::_M_seek(&__this->_M_base, 0, 2);
  v7 = v6;
  LODWORD(v8) = stlp_std::_Filebuf_base::_M_file_size(&__this->_M_base);
  HIDWORD(v9) = HIDWORD(v8);
  v17 = v8;
  if ( v8 <= 0 || v7 < 0 || __SPAIR64__(v7, v5) >= v8 )
  {
    __this->_M_mmap_base = 0;
    __this->_M_mmap_len = 0;
    return stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_underflow_aux(__this);
  }
  v10 = __SPAIR64__(v7, v5) / stlp_std::_Filebuf_base::_M_page_size * stlp_std::_Filebuf_base::_M_page_size;
  LODWORD(v9) = v17;
  v11 = __SPAIR64__(v7, v5) % stlp_std::_Filebuf_base::_M_page_size;
  v12 = v9 - v10;
  HIDWORD(__this->_M_mmap_len) = HIDWORD(v12);
  v13 = __this->_M_mmap_len < 0;
  v14 = SHIDWORD(__this->_M_mmap_len) <= 0;
  LODWORD(__this->_M_mmap_len) = v12;
  if ( !v13 && (!v14 || LODWORD(__this->_M_mmap_len) > (unsigned int)&loc_100000) )
    __this->_M_mmap_len = (unsigned int)&loc_100000;
  v15 = (char *)stlp_std::_Filebuf_base::_M_mmap(&__this->_M_base, v10, __this->_M_mmap_len);
  __this->_M_mmap_base = v15;
  if ( v15 )
  {
    v16 = &v15[LODWORD(__this->_M_mmap_len)];
    __this->_M_gbegin = v15;
    __this->_M_gnext = &v15[v11];
    __this->_M_gend = v16;
    return (unsigned __int8)v15[v11];
  }
  else
  {
    __this->_M_mmap_len = 0;
    return stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_underflow_aux(__this);
  }
}
