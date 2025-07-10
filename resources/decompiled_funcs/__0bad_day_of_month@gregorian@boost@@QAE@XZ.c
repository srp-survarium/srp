void __thiscall boost::gregorian::bad_day_of_month::bad_day_of_month(boost::gregorian::bad_day_of_month *this)
{
  survarium::game_options *v1; // eax
  const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v2; // eax
  char v4; // [esp+13h] [ebp-19h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v5; // [esp+14h] [ebp-18h] BYREF

  v1 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v4);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &v5,
    "Day of month value is out of range 1..31",
    (const stlp_std::allocator<char> *)v1);
  stlp_std::__Named_exception::__Named_exception(this, v2);
  this->__vftable = (boost::gregorian::bad_day_of_month_vtbl *)&stlp_std::logic_error::`vftable';
  this->__vftable = (boost::gregorian::bad_day_of_month_vtbl *)&stlp_std::out_of_range::`vftable';
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v5);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v4);
  this->__vftable = (boost::gregorian::bad_day_of_month_vtbl *)&boost::gregorian::bad_day_of_month::`vftable';
}
