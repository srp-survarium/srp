BOOL __thiscall survarium::victory_items_container_core::can_use(
        survarium::victory_items_container_core *this,
        const survarium::usable_object_user_data *user)
{
  survarium::base_player *v3; // eax
  survarium::carryable_object *m_carried_item; // ecx

  v3 = user->owner->cast_to_base_player(user->owner);
  m_carried_item = v3->m_inventory.m_object->m_carried_item;
  if ( (void (__thiscall *)(survarium::base_player *, vostok::network_core::buffer_reader *, vostok::network_core::buffer_reader *, const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *, const unsigned int, const unsigned int, const bool))this->m_owner_team == (*(survarium::base_player_vtbl **)((char *)&v3->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable + (_DWORD)&loc_11066 + 2))[6].deserialize )
    return m_carried_item != 0;
  return !m_carried_item && this->m_victory_items._M_impl._M_start != this->m_victory_items._M_impl._M_finish;
}
