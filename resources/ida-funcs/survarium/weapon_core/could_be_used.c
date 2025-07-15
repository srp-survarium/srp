int __thiscall survarium::weapon_core::could_be_used(survarium::weapon_core *this, const survarium::base_player *user)
{
  int result; // eax

  if ( *(_BYTE *)(*(_DWORD *)((int (__thiscall *)(vostok::resources::unmanaged_resource **))this->m_prev_in_global_delay_delete_list->survarium::inventory_item::vostok::resources::unmanaged_resource::m_flags.survarium::inventory_item::vostok::resources::unmanaged_resource::m_flags)(&this->m_prev_in_global_delay_delete_list)
                + 1745) != 2 )
    return 1;
  result = 0;
  if ( !user->m_animation_player.m_tree_buffers[0][261] )
    return 1;
  return result;
}
