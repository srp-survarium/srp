void __thiscall survarium::lobby_menu::fill_found_players(survarium::lobby_menu *this, survarium::lobby_menu *thisa)
{
  survarium::lobby_menu *v2; // esi
  int v3; // eax
  survarium::flash_movie_resource *m_object; // edx
  _DWORD *v5; // edi
  int v6; // ebx
  survarium::flash_movie_resource *v7; // edx
  int v8; // esi
  int v9; // esi
  int v10; // ecx
  bool v11; // zf
  unsigned int i; // [esp+4Ch] [ebp-68h]
  unsigned int count; // [esp+50h] [ebp-64h]
  survarium::flash_value value; // [esp+54h] [ebp-60h] BYREF
  survarium::flash_value list_item; // [esp+6Ch] [ebp-48h] BYREF
  survarium::flash_value array_value; // [esp+84h] [ebp-30h] BYREF
  int v17; // [esp+9Ch] [ebp-18h] BYREF
  int v18; // [esp+A0h] [ebp-14h]
  int v19; // [esp+A4h] [ebp-10h]

  v2 = thisa;
  v3 = (int)thisa->m_game->m_network_client->messaging_client(thisa->m_game->m_network_client);
  m_object = thisa->m_lobby_menu_ui.m_object;
  *(_DWORD *)array_value.body = 0;
  *(_DWORD *)&array_value.body[4] = 0;
  v5 = (_DWORD *)(v3 + 352);
  Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&array_value);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  count = (v5[1] - *v5) / 52;
  i = 0;
  if ( count )
  {
    v6 = 0;
    do
    {
      v7 = v2->m_lobby_menu_ui.m_object;
      *(_DWORD *)list_item.body = 0;
      *(_DWORD *)&list_item.body[4] = 0;
      Scaleform::GFx::Movie::CreateObject(v7->movie->m_movie, (Scaleform::GFx::Value *)&list_item, 0, 0, 0);
      v8 = *(_DWORD *)(v6 + *v5);
      if ( (value.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)value.body + 8))(
          *(_DWORD *)value.body,
          &value,
          *(_DWORD *)&value.body[8]);
        *(_DWORD *)value.body = 0;
      }
      *(_DWORD *)&value.body[4] = 4;
      *(_DWORD *)&value.body[8] = v8;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)list_item.body
                                                                                           + 20))(
        *(_DWORD *)list_item.body,
        *(_DWORD *)&list_item.body[8],
        "id",
        &value,
        (list_item.body[4] & 0x8F) == 10);
      v9 = *(_DWORD *)(v6 + *v5 + 4);
      v10 = 0;
      v17 = 0;
      v18 = 6;
      v19 = v9;
      if ( (value.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)value.body + 8))(
          *(_DWORD *)value.body,
          &value,
          *(_DWORD *)&value.body[8]);
        v10 = v17;
        *(_DWORD *)value.body = 0;
      }
      *(_DWORD *)&value.body[4] = 6;
      *(_DWORD *)&value.body[8] = v9;
      if ( (v18 & 0x40) != 0 )
        (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)v10 + 8))(v10, &v17, v19);
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)list_item.body
                                                                                           + 20))(
        *(_DWORD *)list_item.body,
        *(_DWORD *)&list_item.body[8],
        "name",
        &value,
        (list_item.body[4] & 0x8F) == 10);
      (*(void (__thiscall **)(_DWORD, _DWORD, unsigned int, survarium::flash_value *))(**(_DWORD **)array_value.body + 52))(
        *(_DWORD *)array_value.body,
        *(_DWORD *)&array_value.body[8],
        i,
        &list_item);
      if ( (list_item.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)list_item.body + 8))(
          *(_DWORD *)list_item.body,
          &list_item,
          *(_DWORD *)&list_item.body[8]);
      v6 += 52;
      v11 = ++i == count;
      v2 = thisa;
    }
    while ( !v11 );
  }
  Scaleform::GFx::Movie::Invoke(
    v2->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.fill_players_search",
    0,
    (const Scaleform::GFx::Value *)&array_value,
    1u);
  if ( (value.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)value.body + 8))(
      *(_DWORD *)value.body,
      &value,
      *(_DWORD *)&value.body[8]);
    *(_DWORD *)value.body = 0;
  }
  *(_DWORD *)&value.body[4] = 0;
  if ( (array_value.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)array_value.body + 8))(
      *(_DWORD *)array_value.body,
      &array_value,
      *(_DWORD *)&array_value.body[8]);
}
