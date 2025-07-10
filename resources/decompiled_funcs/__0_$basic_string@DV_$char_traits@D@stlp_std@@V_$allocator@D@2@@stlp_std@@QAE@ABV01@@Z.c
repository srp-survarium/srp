void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__s)
{
  stlp_std::allocator<char> __a; // [esp+27h] [ebp-1h] BYREF

  stlp_std::allocator<char>::allocator<char>(&__a, &__s->_M_start_of_storage);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_String_base<char,stlp_std::allocator<char>>(this, &__a);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&__a);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_range_initialize(
    this,
    __s->_M_start_of_storage._M_data,
    __s->_M_finish);
}
