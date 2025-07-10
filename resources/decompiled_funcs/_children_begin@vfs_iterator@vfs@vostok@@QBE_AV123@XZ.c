vostok::vfs::vfs_iterator *__thiscall vostok::vfs::vfs_iterator::children_begin(
        vostok::vfs::vfs_iterator *this,
        vostok::vfs::vfs_iterator *result)
{
  vostok::vfs::base_node<1> *first_child; // eax
  vostok::vfs::base_node<1> *v4; // [esp+0h] [ebp-28h]
  vostok::vfs::vfs_iterator out; // [esp+14h] [ebp-14h] BYREF
  vostok::vfs::base_node<1> *child_link_target; // [esp+24h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( this->m_node )
  {
    if ( this->m_link_target )
      first_child = vostok::vfs::base_node<1>::get_first_child(this->m_link_target);
    else
      first_child = vostok::vfs::base_node<1>::get_first_child(this->m_node);
    v4 = first_child;
  }
  else
  {
    v4 = 0;
  }
  child_link_target = vostok::vfs::find_referenced_link_node(v4);
  vostok::vfs::vfs_iterator::vfs_iterator(
    &out,
    v4,
    child_link_target,
    this->m_hashset,
    (vostok::vfs::vfs_iterator::type_enum)((this->m_type & 1) != 0 ? type_recursive : type_not_scanned));
  vostok::vfs::vfs_iterator::vfs_iterator(result, &out);
  return result;
}
