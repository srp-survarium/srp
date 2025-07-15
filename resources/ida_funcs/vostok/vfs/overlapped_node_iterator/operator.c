void __thiscall vostok::vfs::overlapped_node_iterator::operator++(vostok::vfs::overlapped_node_iterator *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->node = this->node->m_hashset_next.pointer;
  this->node = vostok::vfs::vfs_hashset::skip_nodes_with_wrong_path(this->node, this->path);
}
