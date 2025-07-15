void __thiscall survarium::lobby_menu::fill_friend_list(survarium::lobby_menu *this, survarium::lobby_menu *thisa)
{
  survarium::lobby_menu *v2; // ebp
  const vostok::vectora<survarium::account_list_item> *v3; // eax
  survarium::flash_movie_resource *m_object; // edx
  Scaleform::GFx::Movie *m_movie; // ecx
  const vostok::vectora<survarium::account_list_item> *v6; // edi
  survarium::account_list_item *M_start; // esi
  unsigned int v8; // edx
  int v9; // edi
  survarium::flash_movie_resource *v10; // eax
  unsigned int account_id; // ebp
  int v12; // ecx
  int v13; // esi
  unsigned int v14; // ebp
  int v15; // ecx
  bool v16; // cf
  char *m_begin; // [esp+68h] [ebp-488h]
  survarium::flash_value value; // [esp+84h] [ebp-46Ch] BYREF
  survarium::flash_value list_item; // [esp+9Ch] [ebp-454h] BYREF
  unsigned int i; // [esp+B4h] [ebp-43Ch]
  unsigned int pConvertedChars; // [esp+B8h] [ebp-438h] BYREF
  const vostok::vectora<survarium::account_list_item> *players_list; // [esp+BCh] [ebp-434h]
  survarium::flash_value array_value; // [esp+C0h] [ebp-430h] BYREF
  int v24; // [esp+D8h] [ebp-418h] BYREF
  int v25; // [esp+DCh] [ebp-414h]
  wchar_t *v26; // [esp+E0h] [ebp-410h]
  wchar_t player_name_w[512]; // [esp+F0h] [ebp-400h] BYREF

  v2 = thisa;
  v3 = (const vostok::vectora<survarium::account_list_item> *)thisa->m_game->m_network_client->messaging_client(thisa->m_game->m_network_client);
  m_object = thisa->m_lobby_menu_ui.m_object;
  *(_DWORD *)array_value.body = 0;
  *(_DWORD *)&array_value.body[4] = 0;
  m_movie = m_object->movie->m_movie;
  v6 = v3 + 20;
  players_list = v3 + 20;
  Scaleform::GFx::Movie::CreateArray(m_movie, (Scaleform::GFx::Value *)&array_value);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  M_start = v6->_M_impl._M_start;
  v8 = (int)((unsigned __int64)(1321528399LL * ((char *)v6->_M_impl._M_finish - (char *)v6->_M_impl._M_start)) >> 32) >> 4;
  i = 0;
  if ( v8 + (v8 >> 31) )
  {
    v9 = 0;
    do
    {
      v10 = v2->m_lobby_menu_ui.m_object;
      *(_DWORD *)list_item.body = 0;
      *(_DWORD *)&list_item.body[4] = 0;
      Scaleform::GFx::Movie::CreateObject(v10->movie->m_movie, (Scaleform::GFx::Value *)&list_item, 0, 0, 0);
      account_id = M_start[v9].account_id;
      if ( (value.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)value.body + 8))(
          *(_DWORD *)value.body,
          &value,
          *(_DWORD *)&value.body[8]);
        *(_DWORD *)value.body = 0;
      }
      *(_DWORD *)&value.body[4] = 4;
      *(_DWORD *)&value.body[8] = account_id;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)list_item.body
                                                                                           + 20))(
        *(_DWORD *)list_item.body,
        *(_DWORD *)&list_item.body[8],
        "id",
        &value,
        (list_item.body[4] & 0x8F) == 10);
      m_begin = M_start[v9].account_name.m_begin;
      pConvertedChars = 0;
      mbstowcs_s(&pConvertedChars, player_name_w, 0x200u, m_begin, 0xFFFFFFFF);
      v12 = 0;
      v24 = 0;
      v25 = 7;
      v26 = player_name_w;
      if ( (value.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)value.body + 8))(
          *(_DWORD *)value.body,
          &value,
          *(_DWORD *)&value.body[8]);
        v12 = v24;
        *(_DWORD *)value.body = 0;
      }
      *(_DWORD *)&value.body[4] = 7;
      *(_DWORD *)&value.body[8] = player_name_w;
      if ( (v25 & 0x40) != 0 )
        (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v12 + 8))(v12, &v24, v26);
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
      v13 = M_start[v9].online ? 0 : 2;
      if ( (value.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)value.body + 8))(
          *(_DWORD *)value.body,
          &value,
          *(_DWORD *)&value.body[8]);
        *(_DWORD *)value.body = 0;
      }
      *(_DWORD *)&value.body[4] = 4;
      *(_DWORD *)&value.body[8] = v13;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)list_item.body
                                                                                           + 20))(
        *(_DWORD *)list_item.body,
        *(_DWORD *)&list_item.body[8],
        "status",
        &value,
        (list_item.body[4] & 0x8F) == 10);
      v14 = i;
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
      M_start = players_list->_M_impl._M_start;
      v15 = (char *)players_list->_M_impl._M_finish - (char *)players_list->_M_impl._M_start;
      ++v9;
      i = v14 + 1;
      v16 = v14 + 1 < v15 / 52;
      v2 = thisa;
    }
    while ( v16 );
  }
  Scaleform::GFx::Movie::Invoke(
    v2->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.set_friends_list",
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
