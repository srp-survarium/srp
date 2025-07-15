void __userpurge boost::asio::basic_streambuf<stlp_std::allocator<char>>::reserve(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *this@<ecx>,
        stlp_std::vector<char,stlp_std::allocator<char> > *a2@<esi>,
        unsigned int n)
{
  char *M_start; // ecx
  char *v4; // ebx
  char *v5; // edi
  int v6; // eax
  unsigned int v7; // ecx
  char *M_data; // eax
  unsigned int *v9; // eax
  char *v10; // eax
  char *v11; // edi
  stlp_std::__Named_exception v12; // [esp+8h] [ebp-134h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __str; // [esp+118h] [ebp-24h] BYREF
  int v14; // [esp+130h] [ebp-Ch] BYREF
  char *v15; // [esp+134h] [ebp-8h] BYREF

  M_start = a2[3]._M_impl._M_start;
  v4 = (char *)(a2[2]._M_impl._M_start - M_start);
  v5 = (char *)(a2[1]._M_impl._M_end_of_storage._M_data - M_start);
  v6 = a2->_M_impl._M_end_of_storage._M_data - M_start;
  if ( n > a2[2]._M_impl._M_start - a2[1]._M_impl._M_end_of_storage._M_data )
  {
    if ( v6 )
    {
      v5 -= v6;
      memmove((unsigned __int8 *)M_start, (unsigned __int8 *)a2->_M_impl._M_end_of_storage._M_data, (unsigned int)v5);
    }
    v7 = n;
    if ( n > v4 - v5 )
    {
      M_data = a2[2]._M_impl._M_end_of_storage._M_data;
      if ( n > (unsigned int)M_data || v5 > &M_data[-n] )
      {
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
          &__str,
          "boost::asio::streambuf too long",
          (const stlp_std::allocator<char> *)&n + 3);
        stlp_std::__Named_exception::__Named_exception(&v12, &__str);
        v12.__vftable = (stlp_std::__Named_exception_vtbl *)&stlp_std::length_error::`vftable';
        stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&__str);
        boost::throw_exception(&v12);
        stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v12);
      }
      else
      {
        v4 = &v5[n];
        v14 = 1;
        v15 = &v5[n];
        HIBYTE(n) = 0;
        v9 = (unsigned int *)&v14;
        if ( &v5[v7] )
          v9 = (unsigned int *)&v15;
        stlp_std::vector<char,stlp_std::allocator<char>>::resize(a2 + 3, *v9, (const char *)&n + 3);
      }
    }
    v10 = a2[3]._M_impl._M_start;
    v11 = &v5[(_DWORD)v10];
    a2->_M_impl._M_finish = v10;
    a2->_M_impl._M_end_of_storage._M_data = v10;
    a2[1]._M_impl._M_start = v11;
    a2[1]._M_impl._M_finish = v11;
    a2[1]._M_impl._M_end_of_storage._M_data = v11;
    a2[2]._M_impl._M_start = &v10[(_DWORD)v4];
  }
}
