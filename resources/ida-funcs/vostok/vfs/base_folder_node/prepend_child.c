void __thiscall vostok::vfs::base_folder_node<1>::prepend_child(
        vostok::vfs::base_folder_node<1> *this,
        vostok::vfs::base_node<1> *child)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  child->m_parent.pointer = this;
  child->m_next.max_storage = this->m_first_child.max_storage;
  this->m_first_child.pointer = child;
}
