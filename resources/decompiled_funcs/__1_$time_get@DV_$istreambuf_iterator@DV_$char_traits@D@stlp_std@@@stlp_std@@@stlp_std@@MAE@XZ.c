void __thiscall stlp_std::time_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::~time_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>(
        stlp_std::time_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this)
{
  this->__vftable = (stlp_std::time_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > >_vtbl *)&stlp_std::time_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::`vftable';
  stlp_std::priv::_Time_Info::~_Time_Info(&this->_M_timeinfo);
  stlp_std::locale::facet::~facet(this);
}
