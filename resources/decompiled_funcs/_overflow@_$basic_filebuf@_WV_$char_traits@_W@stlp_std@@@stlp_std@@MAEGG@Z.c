int __thiscall stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::overflow(
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        unsigned __int16 __c)
{
  int result; // eax
  wchar_t *M_pnext; // ebp
  wchar_t *M_int_buf; // edi
  const stlp_std::codecvt<wchar_t,char,int> *M_codecvt; // ecx
  int v7; // eax
  char *M_ext_buf_EOS; // [esp+4h] [ebp-20h]
  const wchar_t *__inext; // [esp+1Ch] [ebp-8h] BYREF
  char *__enext; // [esp+20h] [ebp-4h] BYREF

  if ( !this->_M_in_output_mode
    && !stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_switch_to_output_mode(this) )
  {
    return 0xFFFF;
  }
  M_pnext = this->_M_pnext;
  this->_M_pend = this->_M_int_buf_EOS - 1;
  LOWORD(result) = __c;
  M_int_buf = this->_M_int_buf;
  this->_M_pbegin = M_int_buf;
  this->_M_pnext = M_int_buf;
  if ( __c != 0xFFFF )
    *M_pnext++ = __c;
  if ( M_int_buf == M_pnext )
  {
LABEL_16:
    if ( (_WORD)result == 0xFFFF )
      return 0;
    else
      return (unsigned __int16)result;
  }
  else
  {
    while ( 1 )
    {
      M_codecvt = this->_M_codecvt;
      M_ext_buf_EOS = this->_M_ext_buf_EOS;
      __enext = this->_M_ext_buf;
      __inext = M_int_buf;
      v7 = M_codecvt->do_out(M_codecvt, &this->_M_state, M_int_buf, M_pnext, &__inext, __enext, M_ext_buf_EOS, &__enext);
      if ( v7 == 3 || v7 == 2 )
        break;
      if ( (__inext != M_pnext || __enext - this->_M_ext_buf != this->_M_width * (M_pnext - M_int_buf))
        && (this->_M_constant_width || __inext == M_int_buf) )
      {
        break;
      }
      if ( !stlp_std::_Filebuf_base::_M_write(&this->_M_base, this->_M_ext_buf, __enext - this->_M_ext_buf) )
        break;
      M_int_buf += __inext - M_int_buf;
      if ( M_int_buf == M_pnext )
      {
        LOWORD(result) = __c;
        goto LABEL_16;
      }
    }
    this->_M_in_output_mode = 0;
    this->_M_in_input_mode = 0;
    this->_M_pbegin = 0;
    this->_M_pnext = 0;
    this->_M_pend = 0;
    this->_M_in_error_mode = 1;
    return 0xFFFF;
  }
}
