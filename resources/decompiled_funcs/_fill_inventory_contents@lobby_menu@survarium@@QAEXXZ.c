void __thiscall survarium::lobby_menu::fill_inventory_contents(
        survarium::lobby_menu *this,
        survarium::lobby_menu *thisa)
{
  survarium::lobby_menu *v2; // ebx
  int v3; // eax
  const survarium::inventory_item_instance *v4; // ebp
  const survarium::inventory_item_instance *v5; // esi
  survarium::flash_movie_resource *m_object; // edx
  survarium::flash_movie_resource *v7; // edx
  unsigned int id; // edi
  int dict_id; // ebx
  unsigned int condition_or_stack; // ebp
  unsigned int v11; // edi
  unsigned int i; // [esp+74h] [ebp-50h]
  const survarium::inventory_item_instance *it_e; // [esp+78h] [ebp-4Ch]
  survarium::flash_value inventory_item_property; // [esp+7Ch] [ebp-48h] BYREF
  survarium::flash_value inventory_item; // [esp+94h] [ebp-30h] BYREF
  survarium::flash_value inventory_array; // [esp+ACh] [ebp-18h] BYREF

  v2 = thisa;
  v3 = (int)thisa->m_game->m_network_client->lobby_client(thisa->m_game->m_network_client);
  v4 = *(const survarium::inventory_item_instance **)(v3 + 1932);
  v5 = *(const survarium::inventory_item_instance **)(v3 + 1928);
  m_object = thisa->m_lobby_menu_ui.m_object;
  *(_DWORD *)inventory_array.body = 0;
  *(_DWORD *)&inventory_array.body[4] = 0;
  it_e = v4;
  Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&inventory_array);
  *(_DWORD *)inventory_item_property.body = 0;
  *(_DWORD *)&inventory_item_property.body[4] = 0;
  i = 0;
  if ( v5 != v4 )
  {
    do
    {
      v7 = v2->m_lobby_menu_ui.m_object;
      *(_DWORD *)inventory_item.body = 0;
      *(_DWORD *)&inventory_item.body[4] = 0;
      Scaleform::GFx::Movie::CreateObject(v7->movie->m_movie, (Scaleform::GFx::Value *)&inventory_item, 0, 0, 0);
      id = v5->id;
      dict_id = v5->dict_id;
      condition_or_stack = v5->condition_or_stack;
      if ( (inventory_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item_property.body + 8))(
          *(_DWORD *)inventory_item_property.body,
          &inventory_item_property,
          *(_DWORD *)&inventory_item_property.body[8]);
        *(_DWORD *)inventory_item_property.body = 0;
      }
      *(_DWORD *)&inventory_item_property.body[4] = 3;
      *(_DWORD *)&inventory_item_property.body[8] = id;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)inventory_item.body
                                                                                           + 20))(
        *(_DWORD *)inventory_item.body,
        *(_DWORD *)&inventory_item.body[8],
        "id",
        &inventory_item_property,
        (inventory_item.body[4] & 0x8F) == 10);
      if ( (inventory_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item_property.body + 8))(
          *(_DWORD *)inventory_item_property.body,
          &inventory_item_property,
          *(_DWORD *)&inventory_item_property.body[8]);
        *(_DWORD *)inventory_item_property.body = 0;
      }
      *(_DWORD *)&inventory_item_property.body[4] = 3;
      *(_DWORD *)&inventory_item_property.body[8] = dict_id;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)inventory_item.body
                                                                                           + 20))(
        *(_DWORD *)inventory_item.body,
        *(_DWORD *)&inventory_item.body[8],
        "dictId",
        &inventory_item_property,
        (inventory_item.body[4] & 0x8F) == 10);
      v11 = v5->condition_or_stack;
      if ( (inventory_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item_property.body + 8))(
          *(_DWORD *)inventory_item_property.body,
          &inventory_item_property,
          *(_DWORD *)&inventory_item_property.body[8]);
        *(_DWORD *)inventory_item_property.body = 0;
      }
      *(_DWORD *)&inventory_item_property.body[4] = 4;
      *(_DWORD *)&inventory_item_property.body[8] = v11;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)inventory_item.body
                                                                                           + 20))(
        *(_DWORD *)inventory_item.body,
        *(_DWORD *)&inventory_item.body[8],
        "condition",
        &inventory_item_property,
        (inventory_item.body[4] & 0x8F) == 10);
      if ( (inventory_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item_property.body + 8))(
          *(_DWORD *)inventory_item_property.body,
          &inventory_item_property,
          *(_DWORD *)&inventory_item_property.body[8]);
        *(_DWORD *)inventory_item_property.body = 0;
      }
      *(_DWORD *)&inventory_item_property.body[4] = 4;
      *(_DWORD *)&inventory_item_property.body[8] = condition_or_stack;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)inventory_item.body
                                                                                           + 20))(
        *(_DWORD *)inventory_item.body,
        *(_DWORD *)&inventory_item.body[8],
        "condition_or_stack",
        &inventory_item_property,
        (inventory_item.body[4] & 0x8F) == 10);
      (*(void (__thiscall **)(_DWORD, _DWORD, unsigned int, survarium::flash_value *))(**(_DWORD **)inventory_array.body
                                                                                     + 52))(
        *(_DWORD *)inventory_array.body,
        *(_DWORD *)&inventory_array.body[8],
        i,
        &inventory_item);
      if ( (inventory_item.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item.body + 8))(
          *(_DWORD *)inventory_item.body,
          &inventory_item,
          *(_DWORD *)&inventory_item.body[8]);
      ++i;
      v2 = thisa;
      ++v5;
    }
    while ( v5 != it_e );
  }
  Scaleform::GFx::Movie::Invoke(
    v2->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.inventory_list.setupInventoryData",
    0,
    (const Scaleform::GFx::Value *)&inventory_array,
    1u);
  if ( (inventory_item_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item_property.body + 8))(
      *(_DWORD *)inventory_item_property.body,
      &inventory_item_property,
      *(_DWORD *)&inventory_item_property.body[8]);
    *(_DWORD *)inventory_item_property.body = 0;
  }
  *(_DWORD *)&inventory_item_property.body[4] = 0;
  if ( (inventory_array.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_array.body + 8))(
      *(_DWORD *)inventory_array.body,
      &inventory_array,
      *(_DWORD *)&inventory_array.body[8]);
}
