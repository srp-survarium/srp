void __userpurge survarium::game_world_ui::update_quick_slot(
        survarium::profile_slot_enum slot@<eax>,
        survarium::game_world_ui *this)
{
  survarium::flash_value *v3; // eax
  int i; // ecx
  vostok::resources::unmanaged_resource *v5; // ebp
  survarium::player *m_object; // ecx
  survarium::player *v7; // eax
  survarium::inventory_item *v8; // ecx
  survarium::game_world_ui *v9; // ecx
  stlp_std::less<unsigned int> *v10; // edi
  int cooldown; // esi
  unsigned int m_amount_ms; // esi
  survarium::flash_movie_resource *v13; // edx
  survarium::flash_movie_resource *v14; // edx
  char *v15; // esi
  int j; // edi
  int v17; // ecx
  survarium::inventory_item_props current_item_props; // [esp+14h] [ebp-18Ch] BYREF
  survarium::flash_value oxygene_props[2]; // [esp+1Ch] [ebp-184h] BYREF
  survarium::flash_value slot_descr_value[2]; // [esp+4Ch] [ebp-154h] BYREF
  char v21; // [esp+7Ch] [ebp-124h] BYREF
  survarium::dictionary_item dict_item; // [esp+80h] [ebp-120h] BYREF

  v3 = slot_descr_value;
  for ( i = 1; i >= 0; --i )
  {
    v5 = 0;
    if ( v3 )
    {
      *(_DWORD *)v3->body = 0;
      *(_DWORD *)&v3->body[4] = 0;
    }
    ++v3;
  }
  Scaleform::GFx::Movie::CreateObject(
    this->m_game_hud_ui.m_object->movie->m_movie,
    (Scaleform::GFx::Value *)&slot_descr_value[1],
    0,
    0,
    0);
  m_object = this->m_game_world->m_game->m_network_client->m_current_player.m_object;
  v7 = 0;
  if ( m_object )
  {
    v7 = this->m_game_world->m_game->m_network_client->m_current_player.m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v8 = v7->m_inventory.m_object->m_slots[slot].item.m_object;
  if ( v8 )
  {
    v5 = v7->m_inventory.m_object->m_slots[slot].item.m_object;
    _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
  }
  if ( !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &v7->vostok::resources::unmanaged_intrusive_base,
      &v7->vostok::resources::unmanaged_resource);
  current_item_props.m_dict_id = 0;
  current_item_props.m_amount = -1;
  current_item_props.cooldown = -1;
  if ( !((unsigned __int8 (__thiscall *)(vostok::resources::unmanaged_resource *, survarium::inventory_item_props *))v5->__vftable[3].is_increasing_quality)(
          v5,
          &current_item_props) )
    survarium::game_world_ui::disactivate_quick_slot(v9, (int)this, slot);
  if ( slot == back_slot )
  {
    v10 = survarium::items_dictionary::item_by_id(
            this->m_game_world->m_game->m_items_dictionary.m_object,
            *((unsigned __int16 *)&v5[1].vostok::resources::resource_flags + 7));
    survarium::dictionary_item::dictionary_item(&dict_item, (const survarium::dictionary_item *)v10);
    if ( dict_item.item_category == 4 )
    {
      `vector constructor iterator'(
        oxygene_props[0].body,
        0x18u,
        2,
        (void *(__thiscall *)(void *))survarium::flash_value::flash_value);
      cooldown = current_item_props.cooldown;
      if ( (oxygene_props[0].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)oxygene_props[0].body + 8))(
          *(_DWORD *)oxygene_props[0].body,
          oxygene_props,
          *(_DWORD *)&oxygene_props[0].body[8]);
        *(_DWORD *)oxygene_props[0].body = 0;
      }
      *(_DWORD *)&oxygene_props[0].body[8] = cooldown;
      m_amount_ms = current_item_props.m_amount_ms;
      *(_DWORD *)&oxygene_props[0].body[4] = 4;
      if ( (oxygene_props[1].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)oxygene_props[1].body + 8))(
          *(_DWORD *)oxygene_props[1].body,
          &oxygene_props[1],
          *(_DWORD *)&oxygene_props[1].body[8]);
        *(_DWORD *)oxygene_props[1].body = 0;
      }
      v13 = this->m_game_hud_ui.m_object;
      *(_DWORD *)&oxygene_props[1].body[4] = 4;
      *(_DWORD *)&oxygene_props[1].body[8] = m_amount_ms;
      Scaleform::GFx::Movie::Invoke(
        v13->movie->m_movie,
        "root.set_oxygen",
        0,
        (const Scaleform::GFx::Value *)oxygene_props,
        2u);
      `vector destructor iterator'(
        oxygene_props[0].body,
        0x18u,
        2,
        (void (__thiscall *)(void *))survarium::flash_value::~flash_value);
    }
    if ( dict_item.item_cfg.m_object
      && !_InterlockedExchangeAdd(&dict_item.item_cfg.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      vostok::resources::unmanaged_intrusive_base::destroy(
        &dict_item.item_cfg.m_object->vostok::resources::unmanaged_intrusive_base,
        dict_item.item_cfg.m_object);
    }
  }
  else
  {
    survarium::game_world_ui::create_slot_value(
      (survarium::game_world_ui *)&current_item_props,
      this,
      (survarium::inventory_item_props *)slot,
      (survarium::flash_value *)&current_item_props,
      slot_descr_value[1].body);
    if ( (slot_descr_value[0].body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)slot_descr_value[0].body + 8))(
        *(_DWORD *)slot_descr_value[0].body,
        slot_descr_value,
        *(_DWORD *)&slot_descr_value[0].body[8]);
      *(_DWORD *)slot_descr_value[0].body = 0;
    }
    v14 = this->m_game_hud_ui.m_object;
    *(_DWORD *)&slot_descr_value[0].body[4] = 4;
    *(_DWORD *)&slot_descr_value[0].body[8] = slot - 13;
    Scaleform::GFx::Movie::Invoke(
      v14->movie->m_movie,
      "root.fill_slot",
      0,
      (const Scaleform::GFx::Value *)slot_descr_value,
      2u);
  }
  if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  v15 = &v21;
  for ( j = 1; j >= 0; --j )
  {
    v17 = *((_DWORD *)v15 - 5);
    v15 -= 24;
    if ( (v17 & 0x40) != 0 )
    {
      (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v15 + 8))(v15, *((_DWORD *)v15 + 2));
      *(_DWORD *)v15 = 0;
    }
    *((_DWORD *)v15 + 1) = 0;
  }
}
