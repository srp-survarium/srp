void __thiscall survarium::lobby_menu::on_price_items_arrived(
        survarium::lobby_menu *this,
        survarium::lobby_menu *trader_id,
        unsigned __int8 trader_ida)
{
  survarium::lobby_client *v3; // edi
  vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // eax
  const vostok::configs::binary_config_value *v6; // ebp
  int v7; // ecx
  unsigned int v8; // ebx
  const char *pointer; // edi
  survarium::flash_value *v10; // eax
  int i; // ecx
  survarium::flash_movie_resource *m_object; // edx
  survarium::text_translator *p_m_text_translator; // eax
  int v14; // ecx
  const void *v15; // esi
  int v16; // ebp
  survarium::price_item *v17; // esi
  int item_dict_id; // edi
  int cost; // esi
  char *v20; // esi
  int j; // edi
  int v22; // eax
  unsigned __int8 current_reputation_level; // [esp+90h] [ebp-4EAh]
  unsigned __int8 levels_count; // [esp+91h] [ebp-4E9h]
  survarium::flash_value price_item_property; // [esp+92h] [ebp-4E8h] BYREF
  int v26; // [esp+AAh] [ebp-4D0h]
  survarium::flash_value prices_array_item; // [esp+AEh] [ebp-4CCh] BYREF
  int v28; // [esp+C6h] [ebp-4B4h]
  unsigned __int16 *p_count; // [esp+CAh] [ebp-4B0h]
  const vostok::configs::binary_config_value *faction_levels; // [esp+CEh] [ebp-4ACh]
  survarium::lobby_client *lobby_client; // [esp+D2h] [ebp-4A8h]
  survarium::flash_value current_level[5]; // [esp+D6h] [ebp-4A4h] BYREF
  char v33; // [esp+14Eh] [ebp-42Ch] BYREF
  char faction_str[32]; // [esp+156h] [ebp-424h] BYREF
  wchar_t faction_level_name_w[514]; // [esp+176h] [ebp-404h] BYREF

  v3 = trader_id->m_game->m_network_client->lobby_client(trader_id->m_game->m_network_client);
  lobby_client = v3;
  sprintf_s<32>((char (*)[32])faction_str, "faction_%d", trader_ida);
  v4 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 trader_id->m_game->m_items_dictionary.m_object->dict_config.m_object->m_root,
                                                 "factions_dict");
  v5 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v4, faction_str);
  v6 = vostok::configs::binary_config_value::operator[](v5, "levels");
  v7 = 24 * v6->count;
  faction_levels = v6;
  levels_count = v7 / 24;
  current_reputation_level = 0;
  if ( levels_count )
  {
    v8 = 0;
    p_count = &v3->m_prices[trader_ida].count;
    v28 = 0;
    v26 = 0;
    while ( 1 )
    {
      pointer = (const char *)vostok::configs::binary_config_value::operator[](
                                (vostok::configs::binary_config_value *)((char *)v6->data.pointer + v26),
                                "name")->data.pointer;
      v10 = current_level;
      for ( i = 4; i >= 0; --i )
      {
        if ( v10 )
        {
          *(_DWORD *)v10->body = 0;
          *(_DWORD *)&v10->body[4] = 0;
        }
        ++v10;
      }
      if ( (current_level[0].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)current_level[0].body + 8))(
          *(_DWORD *)current_level[0].body,
          current_level,
          *(_DWORD *)&current_level[0].body[8]);
        *(_DWORD *)current_level[0].body = 0;
      }
      m_object = trader_id->m_lobby_menu_ui.m_object;
      *(_DWORD *)&current_level[0].body[4] = 4;
      *(_DWORD *)&current_level[0].body[8] = trader_ida;
      Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&current_level[1]);
      if ( (current_level[2].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)current_level[2].body + 8))(
          *(_DWORD *)current_level[2].body,
          &current_level[2],
          *(_DWORD *)&current_level[2].body[8]);
        *(_DWORD *)current_level[2].body = 0;
      }
      *(_DWORD *)&current_level[2].body[8] = v28;
      p_m_text_translator = &trader_id->m_game->m_text_translator;
      *(_DWORD *)&current_level[2].body[4] = 4;
      survarium::text_translator::translate_text(p_m_text_translator, pointer, faction_level_name_w);
      v14 = 0;
      *(_DWORD *)prices_array_item.body = 0;
      *(_DWORD *)&prices_array_item.body[4] = 7;
      *(_DWORD *)&prices_array_item.body[8] = faction_level_name_w;
      if ( (current_level[3].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)current_level[3].body + 8))(
          *(_DWORD *)current_level[3].body,
          &current_level[3],
          *(_DWORD *)&current_level[3].body[8]);
        v14 = *(_DWORD *)prices_array_item.body;
        *(_DWORD *)current_level[3].body = 0;
      }
      *(_DWORD *)&current_level[3].body[4] = 7;
      *(_DWORD *)&current_level[3].body[8] = faction_level_name_w;
      if ( (prices_array_item.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(int, survarium::flash_value *, _DWORD))(*(_DWORD *)v14 + 8))(
          v14,
          &prices_array_item,
          *(_DWORD *)&prices_array_item.body[8]);
      v15 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)((char *)faction_levels->data.pointer + v26),
              (char *)&stru_955964)->data.pointer;
      if ( (current_level[4].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)current_level[4].body + 8))(
          *(_DWORD *)current_level[4].body,
          &current_level[4],
          *(_DWORD *)&current_level[4].body[8]);
        *(_DWORD *)current_level[4].body = 0;
      }
      *(_DWORD *)&current_level[4].body[4] = 4;
      *(_DWORD *)&current_level[4].body[8] = v15;
      *(_DWORD *)price_item_property.body = 0;
      *(_DWORD *)&price_item_property.body[4] = 0;
      if ( *p_count )
      {
        v16 = 0;
        do
        {
          v17 = &lobby_client->m_prices[trader_ida].items[v16];
          if ( v17->reputation_level == current_reputation_level )
          {
            *(_DWORD *)prices_array_item.body = 0;
            *(_DWORD *)&prices_array_item.body[4] = 0;
            Scaleform::GFx::Movie::CreateObject(
              trader_id->m_lobby_menu_ui.m_object->movie->m_movie,
              (Scaleform::GFx::Value *)&prices_array_item,
              0,
              0,
              0);
            item_dict_id = v17->item_dict_id;
            if ( (price_item_property.body[4] & 0x40) != 0 )
            {
              (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)price_item_property.body
                                                                               + 8))(
                *(_DWORD *)price_item_property.body,
                &price_item_property,
                *(_DWORD *)&price_item_property.body[8]);
              *(_DWORD *)price_item_property.body = 0;
            }
            *(_DWORD *)&price_item_property.body[4] = 4;
            *(_DWORD *)&price_item_property.body[8] = item_dict_id;
            (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)prices_array_item.body
                                                                                                 + 20))(
              *(_DWORD *)prices_array_item.body,
              *(_DWORD *)&prices_array_item.body[8],
              "dictId",
              &price_item_property,
              (prices_array_item.body[4] & 0x8F) == 10);
            if ( (price_item_property.body[4] & 0x40) != 0 )
            {
              (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)price_item_property.body
                                                                               + 8))(
                *(_DWORD *)price_item_property.body,
                &price_item_property,
                *(_DWORD *)&price_item_property.body[8]);
              *(_DWORD *)price_item_property.body = 0;
            }
            *(_DWORD *)&price_item_property.body[4] = 4;
            *(_DWORD *)&price_item_property.body[8] = 10;
            (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)prices_array_item.body
                                                                                                 + 20))(
              *(_DWORD *)prices_array_item.body,
              *(_DWORD *)&prices_array_item.body[8],
              "count",
              &price_item_property,
              (prices_array_item.body[4] & 0x8F) == 10);
            cost = v17->cost;
            if ( (price_item_property.body[4] & 0x40) != 0 )
            {
              (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)price_item_property.body
                                                                               + 8))(
                *(_DWORD *)price_item_property.body,
                &price_item_property,
                *(_DWORD *)&price_item_property.body[8]);
              *(_DWORD *)price_item_property.body = 0;
            }
            *(_DWORD *)&price_item_property.body[4] = 4;
            *(_DWORD *)&price_item_property.body[8] = cost;
            (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)prices_array_item.body
                                                                                                 + 20))(
              *(_DWORD *)prices_array_item.body,
              *(_DWORD *)&prices_array_item.body[8],
              "cost",
              &price_item_property,
              (prices_array_item.body[4] & 0x8F) == 10);
            (*(void (__thiscall **)(_DWORD, _DWORD, survarium::flash_value *))(**(_DWORD **)current_level[1].body + 60))(
              *(_DWORD *)current_level[1].body,
              *(_DWORD *)&current_level[1].body[8],
              &prices_array_item);
            if ( (prices_array_item.body[4] & 0x40) != 0 )
              (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)prices_array_item.body + 8))(
                *(_DWORD *)prices_array_item.body,
                &prices_array_item,
                *(_DWORD *)&prices_array_item.body[8]);
          }
          ++v8;
          ++v16;
        }
        while ( v8 < *p_count );
        v8 = 0;
      }
      Scaleform::GFx::Movie::Invoke(
        trader_id->m_lobby_menu_ui.m_object->movie->m_movie,
        "root.setup_shop_data",
        0,
        (const Scaleform::GFx::Value *)current_level,
        5u);
      if ( (price_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)price_item_property.body + 8))(
          *(_DWORD *)price_item_property.body,
          &price_item_property,
          *(_DWORD *)&price_item_property.body[8]);
        *(_DWORD *)price_item_property.body = 0;
      }
      *(_DWORD *)&price_item_property.body[4] = 0;
      v20 = &v33;
      for ( j = 4; j >= 0; --j )
      {
        v22 = *((_DWORD *)v20 - 5);
        v20 -= 24;
        if ( (v22 & 0x40) != 0 )
        {
          (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v20 + 8))(v20, *((_DWORD *)v20 + 2));
          *(_DWORD *)v20 = 0;
        }
        *((_DWORD *)v20 + 1) = 0;
      }
      ++v28;
      v26 += 24;
      if ( ++current_reputation_level >= levels_count )
        break;
      v6 = faction_levels;
    }
  }
}
