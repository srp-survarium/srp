char __thiscall stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_allocate_buffers(
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        wchar_t *__buf,
        __int64 __n)
{
  int v3; // ebx
  wchar_t *v6; // eax
  int v7; // ebp
  int v8; // ebx
  unsigned int *p_n; // eax
  unsigned int v10; // edi
  int v11; // eax
  char *M_ext_buf; // eax
  wchar_t *v13; // edx
  __int64 M_width; // [esp-18h] [ebp-28h]
  __int64 v15; // [esp-10h] [ebp-20h]
  __int64 v16; // [esp+8h] [ebp-8h] BYREF

  v3 = HIDWORD(__n);
  if ( __buf )
  {
    this->_M_int_buf = __buf;
    this->_M_int_buf_dynamic = 0;
  }
  else
  {
    if ( 2 * __n > 0 )
      return 0;
    v6 = (wchar_t *)malloc(2 * __n);
    this->_M_int_buf = v6;
    if ( !v6 )
      return 0;
    this->_M_int_buf_dynamic = 1;
  }
  v7 = this->_M_codecvt->do_max_length(this->_M_codecvt);
  HIDWORD(v15) = v3;
  v8 = __n;
  LODWORD(v15) = __n;
  M_width = this->_M_width;
  v16 = v7;
  __n = M_width * v15;
  if ( M_width * v15 >= v7 )
    p_n = (unsigned int *)&__n;
  else
    p_n = (unsigned int *)&v16;
  v10 = *p_n;
  v11 = p_n[1];
  this->_M_ext_buf = 0;
  if ( v11 <= 0 )
    this->_M_ext_buf = (char *)malloc(v10);
  M_ext_buf = this->_M_ext_buf;
  if ( M_ext_buf )
  {
    v13 = &this->_M_int_buf[v8];
    this->_M_ext_buf_EOS = &M_ext_buf[v10];
    this->_M_int_buf_EOS = v13;
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
