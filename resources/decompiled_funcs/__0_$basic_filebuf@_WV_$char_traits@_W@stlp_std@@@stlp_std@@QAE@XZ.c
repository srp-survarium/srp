void __thiscall stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>(
        stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *this)
{
  stlp_std::locale *v2; // eax
  stlp_std::locale v3; // [esp+Ch] [ebp-14h] BYREF
  stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> > *v4; // [esp+10h] [ebp-10h]
  int v5; // [esp+1Ch] [ebp-4h]

  v4 = this;
  this->__vftable = (stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> >_vtbl *)&stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
  this->_M_gbegin = 0;
  this->_M_gnext = 0;
  this->_M_gend = 0;
  this->_M_pbegin = 0;
  this->_M_pnext = 0;
  this->_M_pend = 0;
  stlp_std::locale::locale(&this->_M_locale);
  v5 = 0;
  this->__vftable = (stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t> >_vtbl *)&stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
  stlp_std::_Filebuf_base::_Filebuf_base(&this->_M_base);
  this->_M_constant_width = 0;
  this->_M_always_noconv = 0;
  this->_M_int_buf_dynamic = 0;
  this->_M_in_input_mode = 0;
  this->_M_in_output_mode = 0;
  this->_M_in_error_mode = 0;
  this->_M_in_putback_mode = 0;
  this->_M_int_buf = 0;
  this->_M_int_buf_EOS = 0;
  this->_M_ext_buf = 0;
  this->_M_ext_buf_EOS = 0;
  this->_M_ext_buf_converted = 0;
  this->_M_ext_buf_end = 0;
  this->_M_state = 0;
  this->_M_end_state = 0;
  this->_M_mmap_base = 0;
  this->_M_mmap_len = 0;
  this->_M_saved_eback = 0;
  this->_M_saved_gptr = 0;
  this->_M_saved_egptr = 0;
  this->_M_codecvt = 0;
  this->_M_width = 1;
  this->_M_max_width = 1;
  stlp_std::locale::locale(&v3);
  LOBYTE(v5) = 1;
  stlp_std::basic_filebuf<wchar_t,stlp_std::char_traits<wchar_t>>::_M_setup_codecvt(this, v2, 0);
  stlp_std::locale::~locale(&v3);
}
