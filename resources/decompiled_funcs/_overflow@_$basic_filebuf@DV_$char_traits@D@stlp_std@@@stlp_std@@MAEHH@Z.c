int __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::overflow(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this,
        int __c)
{
  int v4; // ecx
  char *M_pnext; // ebp
  char *M_int_buf; // edi
  char *v7; // eax
  const stlp_std::codecvt<char,char,int> *M_codecvt; // ecx
  int v9; // eax
  char *M_ext_buf_EOS; // [esp+4h] [ebp-20h]
  const char *__inext; // [esp+1Ch] [ebp-8h] BYREF
  char *__enext; // [esp+20h] [ebp-4h] BYREF

  if ( !this->_M_in_output_mode
    && !stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_switch_to_output_mode(this) )
  {
    return -1;
  }
  v4 = __c;
  M_pnext = this->_M_pnext;
  M_int_buf = this->_M_int_buf;
  v7 = this->_M_int_buf_EOS - 1;
  this->_M_pbegin = M_int_buf;
  this->_M_pnext = M_int_buf;
  this->_M_pend = v7;
  if ( __c != -1 )
    *M_pnext++ = __c;
  if ( M_int_buf == M_pnext )
    return v4 != -1 ? v4 : 0;
  while ( 1 )
  {
    M_codecvt = this->_M_codecvt;
    M_ext_buf_EOS = this->_M_ext_buf_EOS;
    __enext = this->_M_ext_buf;
    __inext = M_int_buf;
    v9 = M_codecvt->do_out(M_codecvt, &this->_M_state, M_int_buf, M_pnext, &__inext, __enext, M_ext_buf_EOS, &__enext);
    if ( v9 == 3 )
      break;
    if ( v9 == 2
      || (__inext != M_pnext || __enext - this->_M_ext_buf != this->_M_width * (M_pnext - M_int_buf))
      && (this->_M_constant_width || __inext == M_int_buf)
      || !stlp_std::_Filebuf_base::_M_write(&this->_M_base, this->_M_ext_buf, __enext - this->_M_ext_buf) )
    {
      goto LABEL_18;
    }
    M_int_buf = (char *)__inext;
    if ( __inext == M_pnext )
      goto LABEL_15;
  }
  if ( stlp_std::_Filebuf_base::_M_write(&this->_M_base, M_int_buf, M_pnext - M_int_buf) )
  {
LABEL_15:
    v4 = __c;
    return v4 != -1 ? v4 : 0;
  }
LABEL_18:
  this->_M_in_output_mode = 0;
  this->_M_in_input_mode = 0;
  this->_M_pbegin = 0;
  this->_M_pnext = 0;
  this->_M_pend = 0;
  this->_M_in_error_mode = 1;
  return -1;
}
