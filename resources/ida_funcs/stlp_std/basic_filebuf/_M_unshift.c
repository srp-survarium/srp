char __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_unshift(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this)
{
  const stlp_std::codecvt<char,char,int> *M_codecvt; // ecx
  int v3; // eax
  int v4; // edi
  char *M_ext_buf_EOS; // [esp-8h] [ebp-1Ch]
  char *__enext; // [esp+10h] [ebp-4h] BYREF

  if ( this->_M_in_output_mode && !this->_M_constant_width )
  {
    do
    {
      M_codecvt = this->_M_codecvt;
      M_ext_buf_EOS = this->_M_ext_buf_EOS;
      __enext = this->_M_ext_buf;
      v3 = M_codecvt->do_unshift(M_codecvt, &this->_M_state, __enext, M_ext_buf_EOS, &__enext);
      v4 = v3;
      if ( v3 == 3 || __enext == this->_M_ext_buf && !v3 )
        break;
      if ( v3 == 2 || !stlp_std::_Filebuf_base::_M_write(&this->_M_base, this->_M_ext_buf, __enext - this->_M_ext_buf) )
        return 0;
    }
    while ( v4 == 1 );
  }
  return 1;
}
