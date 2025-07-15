void __thiscall vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(
        vostok::vfs::overlapped_node_iterator *this)
{
  vostok::vfs::overlapped_node_iterator::clear(this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
