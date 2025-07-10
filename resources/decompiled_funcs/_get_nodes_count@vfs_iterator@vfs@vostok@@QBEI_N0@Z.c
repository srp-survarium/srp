unsigned int __thiscall vostok::vfs::vfs_iterator::get_nodes_count(
        vostok::vfs::vfs_iterator *this,
        bool skip_erased_nodes,
        bool recurse_on_link_nodes)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( this->m_link_target )
    return vostok::vfs::calculate_count_of_nodes<1>(this->m_link_target, skip_erased_nodes, recurse_on_link_nodes);
  else
    return vostok::vfs::calculate_count_of_nodes<1>(this->m_node, skip_erased_nodes, recurse_on_link_nodes);
}
