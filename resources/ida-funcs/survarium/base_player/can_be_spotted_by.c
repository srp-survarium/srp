bool __thiscall survarium::base_player::can_be_spotted_by(
        survarium::base_player *this,
        const survarium::base_player *player)
{
  return (*(survarium::base_player_vtbl **)((char *)&player->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                          + (_DWORD)&loc_11066
                                          + 2))[6].deserialize != *(void (__thiscall **)(survarium::base_player *, vostok::network_core::buffer_reader *, vostok::network_core::buffer_reader *, const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *, const unsigned int, const unsigned int, const bool))(*(int *)((char *)&dword_10F30 + (_DWORD)this) + 440);
}
