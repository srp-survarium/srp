void __thiscall vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::swap(
        vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *other)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  vostok::vfs::node_to_expand *m_last; // [esp+10h] [ebp-10h]
  vostok::vfs::node_to_expand *m_first; // [esp+1Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  m_first = this->m_first;
  this->m_first = other->m_first;
  other->m_first = m_first;
  m_last = this->m_last;
  this->m_last = other->m_last;
  other->m_last = m_last;
  stlp_std::swap<vostok::size_policy>(this, other);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
}


void __usercall vostok::intrusive_list<survarium::object_weapon,survarium::object_weapon *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::swap(
        vostok::intrusive_list<survarium::object_weapon,survarium::object_weapon *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<edi>,
        vostok::intrusive_list<survarium::object_weapon,survarium::object_weapon *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *other@<eax>)
{
  survarium::object_weapon *m_first; // eax
  survarium::object_weapon *m_last; // eax
  unsigned int m_size; // eax

  vostok::threading::mutex::lock(&this->vostok::threading::mutex);
  vostok::threading::mutex::lock(&other->vostok::threading::mutex);
  m_first = this->m_first;
  this->m_first = other->m_first;
  other->m_first = m_first;
  m_last = this->m_last;
  this->m_last = other->m_last;
  other->m_last = m_last;
  m_size = this->m_size;
  this->m_size = other->m_size;
  other->m_size = m_size;
  LeaveCriticalSection((LPCRITICAL_SECTION)&other->vostok::threading::mutex);
  LeaveCriticalSection((LPCRITICAL_SECTION)&this->vostok::threading::mutex);
}
