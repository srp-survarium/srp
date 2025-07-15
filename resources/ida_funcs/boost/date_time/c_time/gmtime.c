tm *__cdecl boost::date_time::c_time::gmtime(const __int64 *t)
{
  survarium::game_options *v1; // eax
  const std::exception *v2; // eax
  survarium::game_camera v4[3]; // [esp+Bh] [ebp-129h] BYREF
  tm *resulta; // [esp+140h] [ebp+Ch]

  resulta = _gmtime64(t);
  if ( !resulta )
  {
    v1 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)v4);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v4[0].__vftable
                                                                                            + 1),
      "could not convert calendar time to UTC time",
      (const stlp_std::allocator<char> *)v1);
    stlp_std::runtime_error::runtime_error(
      (stlp_std::runtime_error *)((char *)&v4[0].m_inverted_view_matrix.lines[1].elements[1] + 1),
      (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v4[0].__vftable
                                                                                                  + 1));
    boost::throw_exception(v2);
    stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)((char *)&v4[0].m_inverted_view_matrix.lines[1].elements[1]
                                                                             + 1));
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v4[0].__vftable + 1));
    survarium::weapon_user_dead_state::finalize(v4);
  }
  return resulta;
}
