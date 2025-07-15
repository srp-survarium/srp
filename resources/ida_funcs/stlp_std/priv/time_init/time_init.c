void __thiscall stlp_std::priv::time_init<char>::time_init<char>(stlp_std::priv::time_init<char> *this)
{
  stlp_std::priv::_Time_Info::_Time_Info(&this->_M_timeinfo);
  this->_M_dateorder = no_order;
  stlp_std::priv::_Init_timeinfo(&this->_M_timeinfo);
}


void __thiscall stlp_std::priv::time_init<wchar_t>::time_init<wchar_t>(stlp_std::priv::time_init<wchar_t> *this)
{
  stlp_std::priv::_WTime_Info::_WTime_Info(&this->_M_timeinfo);
  this->_M_dateorder = no_order;
  stlp_std::priv::_Init_timeinfo_0(&this->_M_timeinfo);
}
