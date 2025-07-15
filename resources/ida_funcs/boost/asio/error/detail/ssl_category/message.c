stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__thiscall boost::asio::error::detail::ssl_category::message(
        boost::asio::error::detail::ssl_category *this,
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *result,
        unsigned int value)
{
  survarium::game_options *v3; // eax
  char *__s; // [esp+0h] [ebp-1Ch]
  char v6; // [esp+17h] [ebp-5h] BYREF
  const char *s; // [esp+18h] [ebp-4h]

  s = ERR_reason_error_string(value);
  if ( s )
    __s = (char *)s;
  else
    __s = "asio.ssl error";
  v3 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v6);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    result,
    __s,
    (const stlp_std::allocator<char> *)v3);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v6);
  return result;
}
