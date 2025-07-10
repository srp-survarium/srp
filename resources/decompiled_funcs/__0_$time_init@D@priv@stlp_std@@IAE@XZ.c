void __thiscall stlp_std::priv::time_init<char>::time_init<char>(stlp_std::priv::time_init<char> *this)
{
  stlp_std::priv::_Time_Info::_Time_Info(&this->_M_timeinfo);
  this->_M_dateorder = no_order;
  stlp_std::priv::_Init_timeinfo(&this->_M_timeinfo);
}
