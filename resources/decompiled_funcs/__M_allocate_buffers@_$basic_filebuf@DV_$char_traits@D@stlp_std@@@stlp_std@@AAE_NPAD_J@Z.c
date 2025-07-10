char __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_allocate_buffers(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this,
        char *__buf,
        __int64 __n)
{
  unsigned int v3; // ebx
  char *v6; // eax
  int v7; // eax
  unsigned int *p_n; // eax
  unsigned int v9; // edi
  int v10; // eax
  char *M_ext_buf; // eax
  char *v12; // ecx
  __int64 M_width; // [esp-18h] [ebp-28h]
  __int64 v14; // [esp+8h] [ebp-8h] BYREF

  v3 = __n;
  if ( __buf )
  {
    this->_M_int_buf = __buf;
    this->_M_int_buf_dynamic = 0;
  }
  else
  {
    if ( SHIDWORD(__n) > 0 )
      return 0;
    v6 = (char *)malloc(__n);
    this->_M_int_buf = v6;
    if ( !v6 )
      return 0;
    this->_M_int_buf_dynamic = 1;
  }
  v7 = this->_M_codecvt->do_max_length(this->_M_codecvt);
  M_width = this->_M_width;
  v14 = v7;
  __n = M_width * __PAIR64__(HIDWORD(__n), v3);
  if ( __n >= v7 )
    p_n = (unsigned int *)&__n;
  else
    p_n = (unsigned int *)&v14;
  v9 = *p_n;
  v10 = p_n[1];
  this->_M_ext_buf = 0;
  if ( v10 <= 0 )
    this->_M_ext_buf = (char *)malloc(v9);
  M_ext_buf = this->_M_ext_buf;
  if ( M_ext_buf )
  {
    v12 = &this->_M_int_buf[v3];
    this->_M_ext_buf_EOS = &M_ext_buf[v9];
    this->_M_int_buf_EOS = v12;
    return 1;
  }
  else
  {
    if ( this->_M_int_buf_dynamic )
      free(this->_M_int_buf);
    free(this->_M_ext_buf);
    this->_M_int_buf = 0;
    this->_M_int_buf_EOS = 0;
    this->_M_ext_buf = 0;
    this->_M_ext_buf_EOS = 0;
    return 0;
  }
}
