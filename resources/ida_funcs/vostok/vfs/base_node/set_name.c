void __thiscall vostok::vfs::base_node<1>::set_name(vostok::vfs::base_node<1> *this, const char *name)
{
  unsigned int v2; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v2 = vostok::strings::length(name);
  vostok::strings::copy(this->m_name, v2 + 1, name);
}
