void __thiscall survarium::lobby_menu::fill_ignore_list(survarium::lobby_menu *this, survarium::lobby_menu *thisa)
{
  survarium::lobby_menu *v2; // ebx
  int v3; // eax
  survarium::flash_movie_resource *m_object; // edx
  _DWORD *v5; // esi
  unsigned int v6; // ebp
  int v7; // ebx
  survarium::flash_movie_resource *v8; // ecx
  int v9; // edi
  int v10; // edi
  int v11; // ecx
  survarium::flash_value value; // [esp+6Ch] [ebp-60h] BYREF
  survarium::flash_value list_item; // [esp+84h] [ebp-48h] BYREF
  survarium::flash_value array_value; // [esp+9Ch] [ebp-30h] BYREF
  int v15; // [esp+B4h] [ebp-18h] BYREF
  int v16; // [esp+B8h] [ebp-14h]
  int v17; // [esp+BCh] [ebp-10h]

  v2 = thisa;
  v3 = (int)thisa->m_game->m_network_client->messaging_client(thisa->m_game->m_network_client);
  m_object = thisa->m_lobby_menu_ui.m_object;
  *(_DWORD *)array_value.body = 0;
  *(_DWORD *)&array_value.body[4] = 0;
  v5 = (_DWORD *)(v3 + 336);
  Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&array_value);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  v6 = 0;
  if ( (v5[1] - *v5) / 52 )
  {
    v7 = 0;
    do
    {
      v8 = thisa->m_lobby_menu_ui.m_object;
      *(_DWORD *)list_item.body = 0;
      *(_DWORD *)&list_item.body[4] = 0;
      Scaleform::GFx::Movie::CreateObject(v8->movie->m_movie, (Scaleform::GFx::Value *)&list_item, 0, 0, 0);
      v9 = *(_DWORD *)(v7 + *v5);
      if ( (value.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)value.body + 8))(
          *(_DWORD *)value.body,
          &value,
          *(_DWORD *)&value.body[8]);
        *(_DWORD *)value.body = 0;
      }
      *(_DWORD *)&value.body[4] = 4;
      *(_DWORD *)&value.body[8] = v9;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)list_item.body
                                                                                           + 20))(
        *(_DWORD *)list_item.body,
        *(_DWORD *)&list_item.body[8],
        "id",
        &value,
        (list_item.body[4] & 0x8F) == 10);
      v10 = *(_DWORD *)(v7 + *v5 + 4);
      v11 = 0;
      v15 = 0;
      v16 = 6;
      v17 = v10;
      if ( (value.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)value.body + 8))(
          *(_DWORD *)value.body,
          &value,
          *(_DWORD *)&value.body[8]);
        v11 = v15;
        *(_DWORD *)value.body = 0;
      }
      *(_DWORD *)&value.body[4] = 6;
      *(_DWORD *)&value.body[8] = v10;
      if ( (v16 & 0x40) != 0 )
        (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)v11 + 8))(v11, &v15, v17);
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)list_item.body
                                                                                           + 20))(
        *(_DWORD *)list_item.body,
        *(_DWORD *)&list_item.body[8],
        "name",
        &value,
        (list_item.body[4] & 0x8F) == 10);
      if ( (value.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)value.body + 8))(
          *(_DWORD *)value.body,
          &value,
          *(_DWORD *)&value.body[8]);
        *(_DWORD *)value.body = 0;
      }
      *(_DWORD *)&value.body[4] = 4;
      *(_DWORD *)&value.body[8] = 3;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)list_item.body
                                                                                           + 20))(
        *(_DWORD *)list_item.body,
        *(_DWORD *)&list_item.body[8],
        "icon",
        &value,
        (list_item.body[4] & 0x8F) == 10);
      (*(void (__thiscall **)(_DWORD, _DWORD, unsigned int, survarium::flash_value *))(**(_DWORD **)array_value.body + 52))(
        *(_DWORD *)array_value.body,
        *(_DWORD *)&array_value.body[8],
        v6,
        &list_item);
      if ( (list_item.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)list_item.body + 8))(
          *(_DWORD *)list_item.body,
          &list_item,
          *(_DWORD *)&list_item.body[8]);
      ++v6;
      v7 += 52;
    }
    while ( v6 < (v5[1] - *v5) / 52 );
    v2 = thisa;
  }
  Scaleform::GFx::Movie::Invoke(
    v2->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.set_ignored_list",
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
