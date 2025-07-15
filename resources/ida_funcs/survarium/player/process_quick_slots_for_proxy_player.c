void __usercall survarium::player::process_quick_slots_for_proxy_player(
        survarium::player *this@<ecx>,
        survarium::player *a2@<esi>)
{
  int v2; // edi
  survarium::inventory *m_object; // eax
  survarium::weapon_core *v4; // eax
  int v5; // edi
  survarium::inventory *v6; // eax
  survarium::weapon_core *v7; // eax
  survarium::player_input *v8; // eax
  survarium::player_input *v9; // eax
  survarium::player_input *v10; // eax
  survarium::player_input *v11; // eax
  survarium::player_input *v12; // eax
  survarium::player_input *v13; // eax
  _BYTE v14[20]; // [esp+8h] [ebp-14h] BYREF

  if ( (survarium::player::remote_input(a2, (int)v14)->actions_mask & 0x1000) != 0 )
  {
    v2 = (int)a2->m_current_active_object.m_object->cast_weapon_core(a2->m_current_active_object.m_object);
    m_object = a2->m_inventory.m_object;
    if ( m_object->m_slots[7].item.m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v4 = m_object->m_slots[7].item.m_object->cast_weapon_core(m_object->m_slots[7].item.m_object);
        if ( v4 )
        {
          if ( (survarium::weapon_core *)v2 != v4 && survarium::weapon_core::could_be_used(v4, a2) )
            survarium::inventory::action(a2->m_inventory.m_object, weapon1_slot, 1);
        }
      }
    }
  }
  if ( (survarium::player::remote_input(a2, (int)v14)->actions_mask & 0x2000) != 0 )
  {
    v5 = (int)a2->m_current_active_object.m_object->cast_weapon_core(a2->m_current_active_object.m_object);
    v6 = a2->m_inventory.m_object;
    if ( v6->m_slots[10].item.m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v7 = v6->m_slots[10].item.m_object->cast_weapon_core(v6->m_slots[10].item.m_object);
        if ( v7 )
        {
          if ( (survarium::weapon_core *)v5 != v7 && survarium::weapon_core::could_be_used(v7, a2) )
            survarium::inventory::action(a2->m_inventory.m_object, weapon2_slot, 1);
        }
      }
    }
  }
  if ( (survarium::player::remote_input(a2, (int)v14)->actions_mask & 0xC000) != 0 )
  {
    v8 = survarium::player::remote_input(a2, (int)v14);
    survarium::inventory::action(a2->m_inventory.m_object, quick_slot1, (v8->actions_mask & 0x4000) != 0);
  }
  if ( (survarium::player::remote_input(a2, (int)v14)->actions_mask & 0x30000) != 0 )
  {
    v9 = survarium::player::remote_input(a2, (int)v14);
    survarium::inventory::action(a2->m_inventory.m_object, quick_slot2, v9->actions_mask & 0x10000);
  }
  if ( (((unsigned int)&loc_BFFFF + 1) & survarium::player::remote_input(a2, (int)v14)->actions_mask) != 0 )
  {
    v10 = survarium::player::remote_input(a2, (int)v14);
    survarium::inventory::action(a2->m_inventory.m_object, quick_slot3, (v10->actions_mask & 0x40000) != 0);
  }
  if ( (((unsigned int)&loc_2FFFFF + 1) & survarium::player::remote_input(a2, (int)v14)->actions_mask) != 0 )
  {
    v11 = survarium::player::remote_input(a2, (int)v14);
    survarium::inventory::action(a2->m_inventory.m_object, quick_slot4, (v11->actions_mask & 0x100000) != 0);
  }
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[1379896] & survarium::player::remote_input(a2, (int)v14)->actions_mask) != 0 )
  {
    v12 = survarium::player::remote_input(a2, (int)v14);
    survarium::inventory::action(a2->m_inventory.m_object, quick_slot5, (v12->actions_mask & 0x400000) != 0);
  }
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[39128632]
      & survarium::player::remote_input(a2, (int)v14)->actions_mask) != 0 )
  {
    v13 = survarium::player::remote_input(a2, (int)v14);
    survarium::inventory::action(a2->m_inventory.m_object, quick_slot6, v13->actions_mask & 0x1000000);
  }
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905848]
      & survarium::player::remote_input(a2, (int)v14)->actions_mask) != 0 )
    survarium::inventory::action(a2->m_inventory.m_object, back_slot, 1);
}
