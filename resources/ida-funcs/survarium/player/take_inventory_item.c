void __thiscall survarium::player::take_inventory_item(
        survarium::player *this,
        const vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *item)
{
  survarium::inventory *m_object; // ecx
  int v4; // eax
  survarium::game_world_ui *v5; // ecx
  int v6; // eax

  m_object = this->m_inventory.m_object;
  v4 = 0;
  while ( m_object->m_slots[accept_slots[v4]].item.m_object )
  {
    if ( (unsigned int)++v4 >= 6 )
      return;
  }
  survarium::inventory::set_item(m_object, accept_slots[v4], item);
  v5 = *(survarium::game_world_ui **)((char *)&dword_10F7C + (_DWORD)this);
  if ( v5 )
  {
    v6 = *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_10F04 + (_DWORD)this) + 952) + 8);
    if ( v6 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        if ( *(_BYTE *)(v6 + 52) == this->id )
          survarium::game_world_ui::fill_quick_slots(v5, v5);
      }
    }
  }
}
