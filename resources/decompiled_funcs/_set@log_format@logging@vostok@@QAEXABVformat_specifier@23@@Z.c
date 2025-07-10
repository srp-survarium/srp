void __thiscall vostok::logging::log_format::set(
        vostok::logging::log_format *this,
        vostok::logging::format_specifier *format_expression)
{
  survarium::game_camera *v2; // ecx
  vostok::logging::format_specifier_enum *k; // [esp+8h] [ebp-3Ch]
  unsigned int j; // [esp+14h] [ebp-30h]
  unsigned int i; // [esp+18h] [ebp-2Ch]
  vostok::fixed_vector<enum vostok::logging::format_specifier_enum,8> specifiers; // [esp+1Ch] [ebp-28h] BYREF

  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&specifiers);
  vostok::logging::format_specifier::fill_specifier_list(format_expression, &specifiers, (char (*)[512])this);
  for ( i = 0; i < 8; ++i )
  {
    this->indexes[i] = 0;
    this->enabled[i] = 0;
  }
  for ( j = 0; ; ++j )
  {
    v2 = (survarium::game_camera *)(specifiers.m_end - specifiers.m_begin);
    if ( j >= (unsigned int)v2 )
      break;
    survarium::weapon_user_dead_state::finalize(v2);
    this->indexes[j] = specifiers.m_begin[j];
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    this->enabled[specifiers.m_begin[j]] = 1;
  }
  for ( k = specifiers.m_begin; k != specifiers.m_end; ++k )
    ;
}
