stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__copy_sign<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,char>(
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __first,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __last,
        stlp_std::priv::__basic_iostring<char> *__v,
        char __xplus,
        char __xminus)
{
  bool v6; // al
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *M_buf; // ecx
  char *M_gnext; // eax
  int v9; // eax
  char *v10; // eax
  stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *v11; // eax

  v6 = stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(&__first, &__last);
  M_buf = __first._M_buf;
  if ( !v6 )
  {
    if ( __first._M_have_c )
    {
      LOBYTE(v9) = __first._M_c;
    }
    else
    {
      M_gnext = __first._M_buf->_M_gnext;
      if ( M_gnext >= __first._M_buf->_M_gend )
      {
        v9 = ((int (*)(void))__first._M_buf->underflow)();
        M_buf = __first._M_buf;
      }
      else
      {
        v9 = (unsigned __int8)*M_gnext;
      }
      __first._M_c = v9;
      __first._M_eof = v9 == -1;
      __first._M_have_c = 1;
    }
    if ( (_BYTE)v9 != __xplus )
    {
      if ( (_BYTE)v9 != __xminus )
        goto LABEL_15;
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::push_back(
        __v,
        45);
      M_buf = __first._M_buf;
    }
    v10 = M_buf->_M_gnext;
    if ( v10 >= M_buf->_M_gend )
      M_buf->uflow(M_buf);
    else
      M_buf->_M_gnext = v10 + 1;
    M_buf = __first._M_buf;
    __first._M_have_c = 0;
  }
LABEL_15:
  v11 = result;
  result->_M_buf = M_buf;
  *(_DWORD *)&result->_M_c = *(_DWORD *)&__first._M_c;
  return v11;
}
