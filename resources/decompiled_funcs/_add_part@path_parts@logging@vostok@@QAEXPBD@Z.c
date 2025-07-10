void __thiscall vostok::logging::path_parts::add_part(vostok::logging::path_parts *this, const char *part)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( this->m_parts.m_begin == this->m_parts.m_end )
    this->m_current_element = part;
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    (vostok::buffer_vector<void const *> *)this,
    (const void **)&part);
}
