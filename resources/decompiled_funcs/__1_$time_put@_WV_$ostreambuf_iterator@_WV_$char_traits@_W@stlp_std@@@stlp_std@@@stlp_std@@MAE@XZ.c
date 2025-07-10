void __thiscall stlp_std::time_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::~time_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
        stlp_std::time_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this)
{
  this->__vftable = (stlp_std::time_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > >_vtbl *)&stlp_std::time_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::`vftable';
  stlp_std::priv::_WTime_Info::~_WTime_Info(&this->_M_timeinfo);
  stlp_std::locale::facet::~facet(this);
}
