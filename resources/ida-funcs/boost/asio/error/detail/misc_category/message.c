stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__thiscall boost::asio::error::detail::misc_category::message(
        boost::asio::error::detail::misc_category *this,
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *result,
        int value)
{
  const stlp_std::allocator<char> *v3; // eax
  const stlp_std::allocator<char> *v5; // eax
  const stlp_std::allocator<char> *v6; // eax
  const stlp_std::allocator<char> *v7; // eax
  const stlp_std::allocator<char> *v8; // eax
  char v9; // [esp+Fh] [ebp-5h] BYREF
  char v10; // [esp+10h] [ebp-4h] BYREF
  char v11; // [esp+11h] [ebp-3h] BYREF
  char v12; // [esp+12h] [ebp-2h] BYREF
  char v13; // [esp+13h] [ebp-1h] BYREF

  if ( value == 1 )
  {
    v3 = (const stlp_std::allocator<char> *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v13);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      result,
      "Already open",
      v3);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v13);
    return result;
  }
  else if ( value == 2 )
  {
    v5 = (const stlp_std::allocator<char> *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v12);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      result,
      "End of file",
      v5);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v12);
    return result;
  }
  else if ( value == 3 )
  {
    v6 = (const stlp_std::allocator<char> *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v11);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      result,
      "Element not found",
      v6);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v11);
    return result;
  }
  else
  {
    if ( value == 4 )
    {
      v7 = (const stlp_std::allocator<char> *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v10);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        result,
        "The descriptor does not fit into the select call's fd_set",
        v7);
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v10);
    }
    else
    {
      v8 = (const stlp_std::allocator<char> *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v9);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        result,
        "asio.misc error",
        v8);
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v9);
    }
    return result;
  }
}
