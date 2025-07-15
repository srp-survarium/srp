void __thiscall vostok::vfs::vfs_iterator::access_association(
        vostok::vfs::vfs_iterator *this,
        boost::function1<void,vostok::ai::sensors::sensed_object const &> *callback)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( this->m_link_target )
    vostok::vfs::base_node<1>::access_association(this->m_link_target, callback);
  else
    vostok::vfs::base_node<1>::access_association(this->m_node, callback);
}
