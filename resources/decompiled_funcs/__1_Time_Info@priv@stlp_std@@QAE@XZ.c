void __thiscall stlp_std::priv::_Time_Info::~_Time_Info(stlp_std::priv::_Time_Info *this)
{
  `eh vector destructor iterator'(
    this->_M_am_pm,
    0x18u,
    2,
    (void (__thiscall *)(void *))stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block);
  `eh vector destructor iterator'(
    this->_M_monthname,
    0x18u,
    24,
    (void (__thiscall *)(void *))stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block);
  `eh vector destructor iterator'(
    this->_M_dayname,
    0x18u,
    14,
    (void (__thiscall *)(void *))stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block);
  stlp_std::priv::_Time_Info_Base::~_Time_Info_Base(this);
}
