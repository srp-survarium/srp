void __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_setup_codecvt(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this,
        stlp_std::locale *__loc,
        int __on_imbue)
{
  stlp_std::locale *v3; // edi
  const stlp_std::codecvt<char,char,int> *v5; // eax
  int v6; // edi
  int *p_on_imbue; // eax
  int v8; // eax
  const stlp_std::codecvt<char,char,int> *M_codecvt; // ecx

  v3 = __loc;
  if ( stlp_std::locale::_M_get_facet(__loc, &stlp_std::codecvt<char,char,int>::id) )
  {
    v5 = (const stlp_std::codecvt<char,char,int> *)stlp_std::locale::_M_use_facet(
                                                     v3,
                                                     &stlp_std::codecvt<char,char,int>::id);
    this->_M_codecvt = v5;
    v6 = v5->do_encoding(v5);
    __on_imbue = 1;
    __loc = (stlp_std::locale *)v6;
    p_on_imbue = &__on_imbue;
    if ( v6 >= 1 )
      p_on_imbue = (int *)&__loc;
    this->_M_width = *p_on_imbue;
    v8 = this->_M_codecvt->do_max_length(this->_M_codecvt);
    this->_M_constant_width = v6 > 0;
    M_codecvt = this->_M_codecvt;
    this->_M_max_width = v8;
    this->_M_always_noconv = M_codecvt->do_always_noconv(M_codecvt);
  }
  else
  {
    this->_M_codecvt = 0;
    this->_M_max_width = 1;
    this->_M_width = 1;
    this->_M_always_noconv = 0;
    this->_M_constant_width = 0;
    if ( (_BYTE)__on_imbue )
      stlp_std::locale::_M_use_facet(v3, &stlp_std::codecvt<char,char,int>::id);
  }
}


void __thiscall stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_setup_codecvt(
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        stlp_std::locale *__loc,
        int __on_imbue)
{
  stlp_std::locale *v3; // edi
  const stlp_std::codecvt<wchar_t,char,int> *v5; // eax
  int v6; // edi
  int *p_on_imbue; // eax
  int v8; // eax
  const stlp_std::codecvt<wchar_t,char,int> *M_codecvt; // ecx

  v3 = __loc;
  if ( stlp_std::locale::_M_get_facet(__loc, &stlp_std::codecvt<wchar_t,char,int>::id) )
  {
    v5 = (const stlp_std::codecvt<wchar_t,char,int> *)stlp_std::locale::_M_use_facet(
                                                        v3,
                                                        &stlp_std::codecvt<wchar_t,char,int>::id);
    this->_M_codecvt = v5;
    v6 = v5->do_encoding(v5);
    __on_imbue = 1;
    __loc = (stlp_std::locale *)v6;
    p_on_imbue = &__on_imbue;
    if ( v6 >= 1 )
      p_on_imbue = (int *)&__loc;
    this->_M_width = *p_on_imbue;
    v8 = this->_M_codecvt->do_max_length(this->_M_codecvt);
    this->_M_constant_width = v6 > 0;
    M_codecvt = this->_M_codecvt;
    this->_M_max_width = v8;
    this->_M_always_noconv = M_codecvt->do_always_noconv(M_codecvt);
  }
  else
  {
    this->_M_codecvt = 0;
    this->_M_max_width = 1;
    this->_M_width = 1;
    this->_M_always_noconv = 0;
    this->_M_constant_width = 0;
    if ( (_BYTE)__on_imbue )
      stlp_std::locale::_M_use_facet(v3, &stlp_std::codecvt<wchar_t,char,int>::id);
  }
}
