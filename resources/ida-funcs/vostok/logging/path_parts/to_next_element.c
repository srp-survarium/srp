void __thiscall vostok::logging::path_parts::to_next_element(vostok::logging::path_parts *this)
{
  const char *v1; // eax
  int v3; // [esp+4h] [ebp-8h]

  strchr((char *)this->m_current_element, 0x3Au);
  this->m_current_element = v1;
  if ( this->m_current_element && *((_BYTE *)this->m_current_element + 1) )
  {
    ++this->m_current_element;
  }
  else
  {
    v3 = ++this->m_index;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    this->m_current_element = this->m_parts.m_begin[v3];
  }
}
