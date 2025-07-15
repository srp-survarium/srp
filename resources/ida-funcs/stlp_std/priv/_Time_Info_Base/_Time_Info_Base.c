void __thiscall stlp_std::priv::_Time_Info_Base::_Time_Info_Base(stlp_std::priv::_Time_Info_Base *this)
{
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *p_M_date_format; // ecx

  this->_M_time_format._M_finish = (char *)this;
  this->_M_time_format._M_start_of_storage._M_data = (char *)this;
  *this->_M_time_format._M_finish = 0;
  p_M_date_format = &this->_M_date_format;
  p_M_date_format->_M_finish = (char *)p_M_date_format;
  p_M_date_format->_M_start_of_storage._M_data = (char *)p_M_date_format;
  *p_M_date_format->_M_finish = 0;
  this->_M_date_time_format._M_finish = (char *)&this->_M_date_time_format;
  this->_M_date_time_format._M_start_of_storage._M_data = (char *)&this->_M_date_time_format;
  *this->_M_date_time_format._M_finish = 0;
  this->_M_long_date_format._M_finish = (char *)&this->_M_long_date_format;
  this->_M_long_date_format._M_start_of_storage._M_data = (char *)&this->_M_long_date_format;
  *this->_M_long_date_format._M_finish = 0;
  this->_M_long_date_time_format._M_finish = (char *)&this->_M_long_date_time_format;
  this->_M_long_date_time_format._M_start_of_storage._M_data = (char *)&this->_M_long_date_time_format;
  *this->_M_long_date_time_format._M_finish = 0;
}
