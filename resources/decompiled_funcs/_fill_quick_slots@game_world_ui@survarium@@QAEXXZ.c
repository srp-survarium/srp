void __thiscall survarium::game_world_ui::fill_quick_slots(
        survarium::game_world_ui *this,
        survarium::game_world_ui *thisa)
{
  survarium::game_world_ui *v2; // esi
  survarium::flash_movie_resource *m_object; // ecx
  vostok::resources::unmanaged_resource *v4; // ebx
  survarium::flash_movie_resource *v5; // ecx
  survarium::game *m_game; // ecx
  survarium::player *v7; // eax
  survarium::player *v8; // edx
  int v9; // eax
  survarium::items_dictionary *v10; // eax
  stlp_std::priv::_Rb_tree_node_base *M_parent; // ecx
  unsigned int v12; // edi
  survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *p_m_items_dict; // eax
  survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *v14; // edx
  unsigned int v15; // esi
  survarium::game *v16; // ecx
  survarium::player *v17; // eax
  survarium::player *v18; // edx
  survarium::inventory_item *v19; // eax
  int *v20; // edi
  int v21; // eax
  void (__thiscall *v22)(int *, survarium::inventory_item_props *); // edx
  survarium::items_dictionary *v23; // eax
  stlp_std::priv::_Rb_tree_node_base *v24; // ecx
  unsigned int v25; // edi
  survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *v26; // eax
  survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *v27; // edx
  survarium::flash_movie_resource *v28; // ecx
  survarium::flash_value *v29; // eax
  int i; // ecx
  int cooldown; // esi
  unsigned int m_amount_ms; // esi
  survarium::flash_movie_resource *v33; // edx
  char *v34; // esi
  int j; // edi
  int v36; // ecx
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> item_in_back_slot; // [esp+3Ch] [ebp-1A0h]
  vostok::resources::unmanaged_resource *item_in_back_slota; // [esp+3Ch] [ebp-1A0h]
  survarium::inventory_item_props item_in_back_slot_props; // [esp+40h] [ebp-19Ch] BYREF
  survarium::inventory_item_props *item_props; // [esp+48h] [ebp-194h]
  survarium::flash_value b_val; // [esp+4Ch] [ebp-190h] BYREF
  unsigned int in_array_index; // [esp+64h] [ebp-178h]
  survarium::inventory_item_props current_item_props; // [esp+68h] [ebp-174h] BYREF
  survarium::flash_value slots_array; // [esp+70h] [ebp-16Ch] BYREF
  survarium::flash_value oxygene_props[2]; // [esp+88h] [ebp-154h] BYREF
  char v46; // [esp+B8h] [ebp-124h] BYREF
  survarium::dictionary_item dict_item; // [esp+BCh] [ebp-120h] BYREF

  v2 = thisa;
  m_object = thisa->m_game_hud_ui.m_object;
  v4 = 0;
  *(_DWORD *)slots_array.body = 0;
  *(_DWORD *)&slots_array.body[4] = 0;
  Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&slots_array);
  in_array_index = 0;
  item_props = (survarium::inventory_item_props *)13;
  item_in_back_slot.m_object = (survarium::inventory_item *)316;
  *(_DWORD *)&item_in_back_slot_props.m_dict_id = 6;
  while ( 1 )
  {
    v5 = v2->m_game_hud_ui.m_object;
    *(_DWORD *)b_val.body = 0;
    *(_DWORD *)&b_val.body[4] = 0;
    Scaleform::GFx::Movie::CreateObject(v5->movie->m_movie, (Scaleform::GFx::Value *)&b_val, 0, 0, 0);
    m_game = v2->m_game_world->m_game;
    v7 = m_game->m_network_client->m_current_player.m_object;
    v8 = 0;
    if ( v7 )
    {
      v8 = m_game->m_network_client->m_current_player.m_object;
      _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
    }
    v9 = *(int *)((char *)&item_in_back_slot.m_object->__vftable + (unsigned int)v8->m_inventory.m_object);
    if ( v9 )
    {
      v4 = *(vostok::resources::unmanaged_resource **)((char *)&item_in_back_slot.m_object->__vftable
                                                     + (unsigned int)v8->m_inventory.m_object);
      _InterlockedExchangeAdd((volatile signed __int32 *)(v9 + 208), 1u);
    }
    if ( !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &v8->vostok::resources::unmanaged_intrusive_base,
        &v8->vostok::resources::unmanaged_resource);
    if ( v4 )
    {
      current_item_props.m_dict_id = 0;
      current_item_props.m_amount = -1;
      current_item_props.cooldown = -1;
      ((void (__thiscall *)(vostok::resources::unmanaged_resource *, survarium::inventory_item_props *))v4->__vftable[3].is_increasing_quality)(
        v4,
        &current_item_props);
      v10 = v2->m_game_world->m_game->m_items_dictionary.m_object;
      M_parent = v10->m_items_dict._M_t._M_header._M_data._M_parent;
      v12 = *((unsigned __int16 *)&v4[1].vostok::resources::resource_flags + 7);
      p_m_items_dict = &v10->m_items_dict;
      v14 = p_m_items_dict;
      if ( M_parent )
      {
        do
        {
          if ( *(_DWORD *)&M_parent[1]._M_color < v12 )
          {
            M_parent = M_parent->_M_right;
          }
          else
          {
            v14 = (survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *)M_parent;
            M_parent = M_parent->_M_left;
          }
        }
        while ( M_parent );
        if ( v14 != p_m_items_dict && v12 < v14->_M_t._M_node_count )
          v14 = p_m_items_dict;
      }
      survarium::dictionary_item::dictionary_item(
        &dict_item,
        (const survarium::dictionary_item *)&v14->_M_t._M_key_compare);
      survarium::game_world_ui::create_slot_value(
        (survarium::game_world_ui *)item_props,
        thisa,
        item_props,
        (survarium::flash_value *)&current_item_props,
        &b_val);
      v15 = in_array_index;
      (*(void (__thiscall **)(_DWORD, _DWORD, unsigned int, survarium::flash_value *))(**(_DWORD **)slots_array.body + 52))(
        *(_DWORD *)slots_array.body,
        *(_DWORD *)&slots_array.body[8],
        in_array_index,
        &b_val);
      in_array_index = v15 + 1;
      if ( dict_item.item_cfg.m_object
        && !_InterlockedExchangeAdd(&dict_item.item_cfg.m_object->m_reference_count, 0xFFFFFFFF) )
      {
        vostok::resources::unmanaged_intrusive_base::destroy(
          &dict_item.item_cfg.m_object->vostok::resources::unmanaged_intrusive_base,
          dict_item.item_cfg.m_object);
      }
      if ( !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
      if ( (b_val.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)b_val.body + 8))(
          *(_DWORD *)b_val.body,
          &b_val,
          *(_DWORD *)&b_val.body[8]);
      v2 = thisa;
    }
    else if ( (b_val.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)b_val.body + 8))(
        *(_DWORD *)b_val.body,
        &b_val,
        *(_DWORD *)&b_val.body[8]);
    }
    item_in_back_slot.m_object = (survarium::inventory_item *)((char *)item_in_back_slot.m_object + 4);
    item_props = (survarium::inventory_item_props *)((char *)item_props + 1);
    if ( !--*(_DWORD *)&item_in_back_slot_props.m_dict_id )
      break;
    v4 = 0;
  }
  Scaleform::GFx::Movie::Invoke(
    v2->m_game_hud_ui.m_object->movie->m_movie,
    "root.fill_slots",
    0,
    (const Scaleform::GFx::Value *)&slots_array,
    1u);
  v16 = v2->m_game_world->m_game;
  v17 = v16->m_network_client->m_current_player.m_object;
  v18 = 0;
  if ( v17 )
  {
    v18 = v16->m_network_client->m_current_player.m_object;
    _InterlockedExchangeAdd(&v17->m_reference_count, 1u);
  }
  v19 = v18->m_inventory.m_object->m_slots[3].item.m_object;
  v20 = 0;
  item_in_back_slota = 0;
  if ( v19 )
  {
    item_in_back_slota = v18->m_inventory.m_object->m_slots[3].item.m_object;
    _InterlockedExchangeAdd(&v19->m_reference_count, 1u);
    v20 = (int *)v19;
  }
  if ( !_InterlockedExchangeAdd(&v18->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &v18->vostok::resources::unmanaged_intrusive_base,
      &v18->vostok::resources::unmanaged_resource);
  if ( v20 )
  {
    v21 = *v20;
    item_in_back_slot_props.m_dict_id = 0;
    item_in_back_slot_props.m_amount = -1;
    v22 = *(void (__thiscall **)(int *, survarium::inventory_item_props *))(v21 + 108);
    item_in_back_slot_props.cooldown = -1;
    v22(v20, &item_in_back_slot_props);
    v23 = v2->m_game_world->m_game->m_items_dictionary.m_object;
    v24 = v23->m_items_dict._M_t._M_header._M_data._M_parent;
    v25 = *((unsigned __int16 *)v20 + 139);
    v26 = &v23->m_items_dict;
    v27 = v26;
    if ( v24 )
    {
      do
      {
        if ( *(_DWORD *)&v24[1]._M_color < v25 )
        {
          v24 = v24->_M_right;
        }
        else
        {
          v27 = (survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *)v24;
          v24 = v24->_M_left;
        }
      }
      while ( v24 );
      if ( v27 != v26 && v25 < v27->_M_t._M_node_count )
        v27 = v26;
    }
    survarium::dictionary_item::dictionary_item(
      &dict_item,
      (const survarium::dictionary_item *)&v27->_M_t._M_key_compare);
    if ( dict_item.item_category == 4 )
    {
      v28 = thisa->m_game_hud_ui.m_object;
      *(_DWORD *)b_val.body = 0;
      *(_DWORD *)&b_val.body[4] = 2;
      b_val.body[8] = 1;
      Scaleform::GFx::Movie::Invoke(
        v28->movie->m_movie,
        "root.show_oxygen",
        0,
        (const Scaleform::GFx::Value *)&b_val,
        1u);
      v29 = oxygene_props;
      for ( i = 1; i >= 0; --i )
      {
        if ( v29 )
        {
          *(_DWORD *)v29->body = 0;
          *(_DWORD *)&v29->body[4] = 0;
        }
        ++v29;
      }
      cooldown = item_in_back_slot_props.cooldown;
      if ( (oxygene_props[0].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)oxygene_props[0].body + 8))(
          *(_DWORD *)oxygene_props[0].body,
          oxygene_props,
          *(_DWORD *)&oxygene_props[0].body[8]);
        *(_DWORD *)oxygene_props[0].body = 0;
      }
      *(_DWORD *)&oxygene_props[0].body[8] = cooldown;
      m_amount_ms = item_in_back_slot_props.m_amount_ms;
      *(_DWORD *)&oxygene_props[0].body[4] = 4;
      if ( (oxygene_props[1].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)oxygene_props[1].body + 8))(
          *(_DWORD *)oxygene_props[1].body,
          &oxygene_props[1],
          *(_DWORD *)&oxygene_props[1].body[8]);
        *(_DWORD *)oxygene_props[1].body = 0;
      }
      v33 = thisa->m_game_hud_ui.m_object;
      *(_DWORD *)&oxygene_props[1].body[4] = 4;
      *(_DWORD *)&oxygene_props[1].body[8] = m_amount_ms;
      Scaleform::GFx::Movie::Invoke(
        v33->movie->m_movie,
        "root.set_oxygen",
        0,
        (const Scaleform::GFx::Value *)oxygene_props,
        2u);
      v34 = &v46;
      for ( j = 1; j >= 0; --j )
      {
        v36 = *((_DWORD *)v34 - 5);
        v34 -= 24;
        if ( (v36 & 0x40) != 0 )
        {
          (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v34 + 8))(v34, *((_DWORD *)v34 + 2));
          *(_DWORD *)v34 = 0;
        }
        *((_DWORD *)v34 + 1) = 0;
      }
      if ( (b_val.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)b_val.body + 8))(
          *(_DWORD *)b_val.body,
          &b_val,
          *(_DWORD *)&b_val.body[8]);
    }
    if ( dict_item.item_cfg.m_object
      && !_InterlockedExchangeAdd(&dict_item.item_cfg.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      vostok::resources::unmanaged_intrusive_base::destroy(
        &dict_item.item_cfg.m_object->vostok::resources::unmanaged_intrusive_base,
        dict_item.item_cfg.m_object);
    }
    if ( !_InterlockedExchangeAdd(&item_in_back_slota->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &item_in_back_slota->vostok::resources::unmanaged_intrusive_base,
        item_in_back_slota);
  }
  if ( (slots_array.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)slots_array.body + 8))(
      *(_DWORD *)slots_array.body,
      &slots_array,
      *(_DWORD *)&slots_array.body[8]);
}
