void __thiscall vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(
        vostok::vfs::overlapped_node_iterator *this,
        const vostok::vfs::overlapped_node_initializer *initializer)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  *(vostok::vfs::overlapped_node_initializer *)this = *initializer;
}
