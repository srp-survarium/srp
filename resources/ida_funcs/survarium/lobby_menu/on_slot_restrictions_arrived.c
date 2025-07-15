void __thiscall survarium::lobby_menu::on_slot_restrictions_arrived(
        survarium::lobby_menu *this,
        survarium::lobby_menu *thisa)
{
  survarium::lobby_menu *v2; // esi
  int v3; // eax
  survarium::flash_movie_resource *m_object; // edx
  int v5; // ebx
  int v6; // edi
  unsigned __int8 *v7; // esi
  survarium::flash_movie_resource *v8; // ecx
  int v9; // ebp
  int v10; // esi
  unsigned __int8 i; // [esp+4Bh] [ebp-49h]
  survarium::flash_value slot_restriction_item_property; // [esp+4Ch] [ebp-48h] BYREF
  survarium::flash_value slot_restriction_item; // [esp+64h] [ebp-30h] BYREF
  survarium::flash_value slot_restrictions_array; // [esp+7Ch] [ebp-18h] BYREF

  v2 = thisa;
  v3 = (int)thisa->m_game->m_network_client->lobby_client(thisa->m_game->m_network_client);
  m_object = thisa->m_lobby_menu_ui.m_object;
  *(_DWORD *)slot_restrictions_array.body = 0;
  *(_DWORD *)&slot_restrictions_array.body[4] = 0;
  v5 = v3;
  Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&slot_restrictions_array);
  *(_DWORD *)slot_restriction_item_property.body = 0;
  *(_DWORD *)&slot_restriction_item_property.body[4] = 0;
  i = 0;
  if ( *(_DWORD *)(v5 + 2128) )
  {
    v6 = 0;
    do
    {
      v7 = (unsigned __int8 *)(*(_DWORD *)(v5 + 2124) + 2 * v6);
      v8 = thisa->m_lobby_menu_ui.m_object;
      *(_DWORD *)slot_restriction_item.body = 0;
      *(_DWORD *)&slot_restriction_item.body[4] = 0;
      Scaleform::GFx::Movie::CreateObject(v8->movie->m_movie, (Scaleform::GFx::Value *)&slot_restriction_item, 0, 0, 0);
      v9 = *v7;
      if ( (slot_restriction_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)slot_restriction_item_property.body
                                                                         + 8))(
          *(_DWORD *)slot_restriction_item_property.body,
          &slot_restriction_item_property,
          *(_DWORD *)&slot_restriction_item_property.body[8]);
        *(_DWORD *)slot_restriction_item_property.body = 0;
      }
      *(_DWORD *)&slot_restriction_item_property.body[4] = 4;
      *(_DWORD *)&slot_restriction_item_property.body[8] = v9;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)slot_restriction_item.body
                                                                                           + 20))(
        *(_DWORD *)slot_restriction_item.body,
        *(_DWORD *)&slot_restriction_item.body[8],
        "slot_id",
        &slot_restriction_item_property,
        (slot_restriction_item.body[4] & 0x8F) == 10);
      v10 = v7[1];
      if ( (slot_restriction_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)slot_restriction_item_property.body
                                                                         + 8))(
          *(_DWORD *)slot_restriction_item_property.body,
          &slot_restriction_item_property,
          *(_DWORD *)&slot_restriction_item_property.body[8]);
        *(_DWORD *)slot_restriction_item_property.body = 0;
      }
      *(_DWORD *)&slot_restriction_item_property.body[4] = 4;
      *(_DWORD *)&slot_restriction_item_property.body[8] = v10;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)slot_restriction_item.body
                                                                                           + 20))(
        *(_DWORD *)slot_restriction_item.body,
        *(_DWORD *)&slot_restriction_item.body[8],
        "category_id",
        &slot_restriction_item_property,
        (slot_restriction_item.body[4] & 0x8F) == 10);
      (*(void (__thiscall **)(_DWORD, _DWORD, int, survarium::flash_value *))(**(_DWORD **)slot_restrictions_array.body
                                                                            + 52))(
        *(_DWORD *)slot_restrictions_array.body,
        *(_DWORD *)&slot_restrictions_array.body[8],
        v6,
        &slot_restriction_item);
      if ( (slot_restriction_item.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)slot_restriction_item.body + 8))(
          *(_DWORD *)slot_restriction_item.body,
          &slot_restriction_item,
          *(_DWORD *)&slot_restriction_item.body[8]);
      v6 = ++i;
    }
    while ( (unsigned int)i < *(_DWORD *)(v5 + 2128) );
    v2 = thisa;
  }
  Scaleform::GFx::Movie::Invoke(
    v2->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.player_profile.profileItems.setSlotsRestrictions",
    0,
    (const Scaleform::GFx::Value *)&slot_restrictions_array,
    1u);
  if ( (slot_restriction_item_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)slot_restriction_item_property.body
                                                                     + 8))(
      *(_DWORD *)slot_restriction_item_property.body,
      &slot_restriction_item_property,
      *(_DWORD *)&slot_restriction_item_property.body[8]);
    *(_DWORD *)slot_restriction_item_property.body = 0;
  }
  *(_DWORD *)&slot_restriction_item_property.body[4] = 0;
  if ( (slot_restrictions_array.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)slot_restrictions_array.body + 8))(
      *(_DWORD *)slot_restrictions_array.body,
      &slot_restrictions_array,
      *(_DWORD *)&slot_restrictions_array.body[8]);
}
