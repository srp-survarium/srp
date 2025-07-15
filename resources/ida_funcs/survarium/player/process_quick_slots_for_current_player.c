void __usercall survarium::player::process_quick_slots_for_current_player(
        survarium::player *this@<ecx>,
        const survarium::base_player *a2@<esi>)
{
  int v2; // edi
  survarium::inventory *m_object; // eax
  survarium::weapon_core *v4; // eax
  int v5; // ecx
  int v6; // edi
  survarium::inventory *v7; // eax
  survarium::weapon_core *v8; // eax
  int v9; // ecx
  survarium::game_world_ui *v10; // ecx
  survarium::game_world_ui *v11; // ecx
  survarium::game_world_ui *v12; // ecx
  survarium::game_world_ui *v13; // ecx
  survarium::game_world_ui *v14; // ecx
  survarium::game_world_ui *v15; // ecx
  survarium::game_world_ui *v16; // ecx
  bool key_down; // [esp+4h] [ebp-4h]
  bool key_downa; // [esp+4h] [ebp-4h]
  bool key_downb; // [esp+4h] [ebp-4h]
  bool key_downc; // [esp+4h] [ebp-4h]
  bool key_downd; // [esp+4h] [ebp-4h]
  bool key_downe; // [esp+4h] [ebp-4h]

  if ( (a2->input(a2)->actions_mask & 0x1000) != 0 )
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
          if ( (survarium::weapon_core *)v2 != v4 )
          {
            if ( survarium::weapon_core::could_be_used(v4, a2) )
            {
              survarium::inventory::action(a2->m_inventory.m_object, weapon1_slot, 1);
            }
            else if ( *(int *)((char *)&dword_10F7C + (_DWORD)a2) )
            {
              survarium::game_world_ui::show_screen_message(
                v5,
                "st_weapon_could_not_be_used",
                *(survarium::game_world_ui **)((char *)&dword_10F7C + (_DWORD)a2));
            }
          }
        }
      }
    }
  }
  if ( (a2->input(a2)->actions_mask & 0x2000) != 0 )
  {
    v6 = (int)a2->m_current_active_object.m_object->cast_weapon_core(a2->m_current_active_object.m_object);
    v7 = a2->m_inventory.m_object;
    if ( v7->m_slots[10].item.m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v8 = v7->m_slots[10].item.m_object->cast_weapon_core(v7->m_slots[10].item.m_object);
        if ( v8 )
        {
          if ( (survarium::weapon_core *)v6 != v8 )
          {
            if ( survarium::weapon_core::could_be_used(v8, a2) )
            {
              survarium::inventory::action(a2->m_inventory.m_object, weapon2_slot, 1);
            }
            else if ( *(int *)((char *)&dword_10F7C + (_DWORD)a2) )
            {
              survarium::game_world_ui::show_screen_message(
                v9,
                "st_weapon_could_not_be_used",
                *(survarium::game_world_ui **)((char *)&dword_10F7C + (_DWORD)a2));
            }
          }
        }
      }
    }
  }
  if ( (a2->input(a2)->actions_mask & 0xC000) != 0 )
  {
    key_down = (a2->input(a2)->actions_mask & 0x4000) != 0;
    if ( survarium::inventory::action(a2->m_inventory.m_object, quick_slot1, key_down) )
    {
      if ( *(int *)((char *)&dword_10F7C + (_DWORD)a2) )
        survarium::game_world_ui::add_quick_slot_to_update(v10, quick_slot1);
    }
  }
  if ( (a2->input(a2)->actions_mask & 0x30000) != 0 )
  {
    key_downa = BYTE2(a2->input(a2)->actions_mask) & 1;
    if ( survarium::inventory::action(a2->m_inventory.m_object, quick_slot2, key_downa) )
    {
      if ( *(int *)((char *)&dword_10F7C + (_DWORD)a2) )
        survarium::game_world_ui::add_quick_slot_to_update(v11, quick_slot2);
    }
  }
  if ( (((unsigned int)&loc_BFFFF + 1) & a2->input(a2)->actions_mask) != 0 )
  {
    key_downb = (a2->input(a2)->actions_mask & 0x40000) != 0;
    if ( survarium::inventory::action(a2->m_inventory.m_object, quick_slot3, key_downb) )
    {
      if ( *(int *)((char *)&dword_10F7C + (_DWORD)a2) )
        survarium::game_world_ui::add_quick_slot_to_update(v12, quick_slot3);
    }
  }
  if ( (((unsigned int)&loc_2FFFFF + 1) & a2->input(a2)->actions_mask) != 0 )
  {
    key_downc = (a2->input(a2)->actions_mask & 0x100000) != 0;
    if ( survarium::inventory::action(a2->m_inventory.m_object, quick_slot4, key_downc) )
    {
      if ( *(int *)((char *)&dword_10F7C + (_DWORD)a2) )
        survarium::game_world_ui::add_quick_slot_to_update(v13, quick_slot4);
    }
  }
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[1379896] & a2->input(a2)->actions_mask) != 0 )
  {
    key_downd = (a2->input(a2)->actions_mask & 0x400000) != 0;
    if ( survarium::inventory::action(a2->m_inventory.m_object, quick_slot5, key_downd) )
    {
      if ( *(int *)((char *)&dword_10F7C + (_DWORD)a2) )
        survarium::game_world_ui::add_quick_slot_to_update(v14, quick_slot5);
    }
  }
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[39128632] & a2->input(a2)->actions_mask) != 0 )
  {
    key_downe = HIBYTE(a2->input(a2)->actions_mask) & 1;
    if ( survarium::inventory::action(a2->m_inventory.m_object, quick_slot6, key_downe) )
    {
      if ( *(int *)((char *)&dword_10F7C + (_DWORD)a2) )
        survarium::game_world_ui::add_quick_slot_to_update(v15, quick_slot6);
    }
  }
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905848] & a2->input(a2)->actions_mask) != 0
    && survarium::inventory::action(a2->m_inventory.m_object, back_slot, 1) )
  {
    if ( *(int *)((char *)&dword_10F7C + (_DWORD)a2) )
      survarium::game_world_ui::add_quick_slot_to_update(v16, back_slot);
  }
}
