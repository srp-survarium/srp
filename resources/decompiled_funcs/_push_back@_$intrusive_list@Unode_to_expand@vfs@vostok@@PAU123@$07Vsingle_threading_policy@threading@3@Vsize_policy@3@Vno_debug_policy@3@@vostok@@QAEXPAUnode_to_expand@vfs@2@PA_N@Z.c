void __thiscall vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        survarium::game_camera *object,
        bool *out_pushed_first)
{
  vostok::size_policy *v3; // ecx
  vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *thisa; // [esp+4h] [ebp-Ch]

  thisa = this;
  object->m_inverted_view_matrix.i.y = 0.0;
  if ( this )
    this = (vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)((char *)this + 4);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::size_policy::increment_size(v3, thisa);
  if ( out_pushed_first )
    *out_pushed_first = thisa->m_first == 0;
  if ( thisa->m_first )
    thisa->m_last->next = (vostok::vfs::node_to_expand *)object;
  else
    thisa->m_first = (vostok::vfs::node_to_expand *)object;
  thisa->m_last = (vostok::vfs::node_to_expand *)object;
  survarium::weapon_user_dead_state::finalize(object);
}
