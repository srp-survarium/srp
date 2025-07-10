void __thiscall vostok::logging::path_parts::concat2buffer(vostok::logging::path_parts *this, char (*buffer)[512])
{
  survarium::game_camera *v2; // ecx
  vostok::logging::path_parts *thisa; // [esp+0h] [ebp-1Ch]
  unsigned int part_length; // [esp+10h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-8h]
  unsigned int string_length; // [esp+18h] [ebp-4h]

  thisa = this;
  string_length = 0;
  (*buffer)[0] = 0;
  for ( i = 0; ; ++i )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    if ( !thisa->m_parts.m_begin[i] )
      break;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)thisa->m_parts.m_begin);
    part_length = vostok::strings::length(thisa->m_parts.m_begin[i]);
    survarium::weapon_user_dead_state::finalize(v2);
    vostok::memory::copy(
      (unsigned __int8 *)&(*buffer)[string_length],
      512 - string_length,
      (unsigned __int8 *)thisa->m_parts.m_begin[i],
      part_length + 1);
    string_length += part_length;
    this = (vostok::logging::path_parts *)(i + 1);
  }
  if ( string_length )
  {
    if ( (*buffer)[string_length - 1] == 58 )
      (*buffer)[string_length - 1] = 0;
  }
}
