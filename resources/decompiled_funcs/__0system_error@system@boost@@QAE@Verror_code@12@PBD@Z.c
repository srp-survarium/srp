void __thiscall boost::system::system_error::system_error(
        boost::system::system_error *this,
        boost::system::error_code ec,
        char *what_arg)
{
  const stlp_std::allocator<char> *v3; // eax
  stlp_std::allocator<char> *__a; // [esp+4h] [ebp-28h]
  char v6; // [esp+12h] [ebp-1Ah] BYREF
  char v7; // [esp+13h] [ebp-19h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __s; // [esp+14h] [ebp-18h] BYREF

  v3 = (const stlp_std::allocator<char> *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v7);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &__s,
    what_arg,
    v3);
  stlp_std::runtime_error::runtime_error(this, &__s);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&__s);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v7);
  this->__vftable = (boost::system::system_error_vtbl *)&boost::system::system_error::`vftable';
  this->m_error_code = ec;
  __a = (stlp_std::allocator<char> *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v6);
  this->m_what._M_finish = (char *)&this->m_what;
  stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>(
    &this->m_what._M_start_of_storage,
    __a,
    (char *)&this->m_what);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_allocate_block(&this->m_what, 0x10u);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_terminate_string(&this->m_what);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v6);
}
