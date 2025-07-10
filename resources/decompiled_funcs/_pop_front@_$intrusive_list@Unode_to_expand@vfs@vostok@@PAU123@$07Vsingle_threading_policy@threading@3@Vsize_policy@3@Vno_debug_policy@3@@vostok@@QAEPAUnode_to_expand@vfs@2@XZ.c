vostok::vfs::node_to_expand *__thiscall vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(
        vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this)
{
  BOOL v1; // ecx
  survarium::game_camera *v3; // ecx
  vostok::vfs::node_to_expand *result; // [esp+14h] [ebp-8h]

  v1 = this->m_first == 0;
  if ( v1 )
    return 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v1);
  if ( this->m_first )
  {
    vostok::size_policy::decrement_size(this, this);
    result = this->m_first;
    v3 = (survarium::game_camera *)this;
    this->m_first = result->next;
    if ( !this->m_first )
    {
      v3 = (survarium::game_camera *)this;
      this->m_last = 0;
    }
    result->next = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    return result;
  }
  else
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    return 0;
  }
}
