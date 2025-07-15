void __thiscall vostok::logging::path_parts::~path_parts(vostok::logging::path_parts *this)
{
  const char **i; // [esp+4h] [ebp-4h]

  for ( i = this->m_parts.m_begin; i != this->m_parts.m_end; ++i )
    ;
  this->m_parts.m_end = this->m_parts.m_begin;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
