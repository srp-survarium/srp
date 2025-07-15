int __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::pbackfail(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this,
        int __c)
{
  int result; // eax
  char *M_gnext; // edx
  char *M_gbegin; // edi
  char *v5; // edx
  char *v6; // esi
  char *v7; // edx

  if ( !this->_M_in_input_mode )
    return -1;
  M_gnext = this->_M_gnext;
  result = __c;
  M_gbegin = this->_M_gbegin;
  if ( M_gnext != M_gbegin && (__c == -1 || (_BYTE)__c == *(M_gnext - 1) || !this->_M_mmap_base) )
  {
    v5 = M_gnext - 1;
    this->_M_gnext = v5;
    if ( __c == -1 || (_BYTE)__c == *v5 )
      return (unsigned __int8)*v5;
    goto LABEL_15;
  }
  if ( __c != -1 )
  {
    v6 = (char *)&this[1];
    if ( !this->_M_in_putback_mode )
    {
      this->_M_saved_gptr = M_gnext;
      this->_M_saved_egptr = this->_M_gend;
      this->_M_saved_eback = M_gbegin;
      this->_M_in_putback_mode = 1;
      this->_M_gend = v6;
      this->_M_gnext = &this->_M_pback_buf[7];
      this->_M_gbegin = &this->_M_pback_buf[7];
LABEL_15:
      *this->_M_gnext = __c;
      return result;
    }
    if ( M_gbegin != this->_M_pback_buf )
    {
      v7 = this->_M_gend - 1;
      this->_M_gend = v6;
      this->_M_gnext = v7;
      this->_M_gbegin = v7;
      *v7 = __c;
      return result;
    }
  }
  return -1;
}


wchar_t __thiscall stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::pbackfail(
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        wchar_t __c)
{
  wchar_t result; // ax
  wchar_t *M_gnext; // edx
  wchar_t *M_gbegin; // edi
  wchar_t *v5; // edx
  wchar_t *v6; // esi
  wchar_t *v7; // edx

  if ( !this->_M_in_input_mode )
    return -1;
  M_gnext = this->_M_gnext;
  result = __c;
  M_gbegin = this->_M_gbegin;
  if ( M_gnext != M_gbegin && (__c == 0xFFFF || __c == *(M_gnext - 1) || !this->_M_mmap_base) )
  {
    v5 = M_gnext - 1;
    this->_M_gnext = v5;
    if ( __c == 0xFFFF || __c == *v5 )
      return *v5;
    goto LABEL_17;
  }
  if ( __c == 0xFFFF )
    return -1;
  v6 = (wchar_t *)&this[1];
  if ( !this->_M_in_putback_mode )
  {
    this->_M_saved_gptr = M_gnext;
    this->_M_saved_egptr = this->_M_gend;
    this->_M_saved_eback = M_gbegin;
    this->_M_in_putback_mode = 1;
    this->_M_gend = v6;
    this->_M_gnext = &this->_M_pback_buf[7];
    this->_M_gbegin = &this->_M_pback_buf[7];
LABEL_17:
    *this->_M_gnext = __c;
    return result;
  }
  if ( M_gbegin == this->_M_pback_buf )
    return -1;
  v7 = this->_M_gend - 1;
  this->_M_gend = v6;
  this->_M_gnext = v7;
  this->_M_gbegin = v7;
  *v7 = __c;
  return result;
}
