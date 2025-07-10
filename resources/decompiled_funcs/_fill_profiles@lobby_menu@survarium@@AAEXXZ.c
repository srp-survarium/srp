void __thiscall survarium::lobby_menu::fill_profiles(survarium::lobby_menu *this, survarium::lobby_menu *thisa)
{
  int v2; // eax
  survarium::flash_movie_resource *m_object; // edx
  int v4; // esi
  unsigned __int8 v5; // al
  int v6; // edi
  char *v7; // esi
  survarium::flash_movie_resource *v8; // eax
  int v9; // ecx
  survarium::flash_value profile_item_property; // [esp+54h] [ebp-468h] BYREF
  int v11; // [esp+6Ch] [ebp-450h]
  survarium::flash_value profile_item; // [esp+70h] [ebp-44Ch] BYREF
  unsigned int pConvertedChars; // [esp+88h] [ebp-434h] BYREF
  survarium::flash_value profiles_array; // [esp+8Ch] [ebp-430h] BYREF
  int v15; // [esp+A4h] [ebp-418h] BYREF
  int v16; // [esp+A8h] [ebp-414h]
  wchar_t *v17; // [esp+ACh] [ebp-410h]
  wchar_t profile_name_w[512]; // [esp+BCh] [ebp-400h] BYREF

  v2 = (int)thisa->m_game->m_network_client->lobby_client(thisa->m_game->m_network_client);
  m_object = thisa->m_lobby_menu_ui.m_object;
  *(_DWORD *)profiles_array.body = 0;
  *(_DWORD *)&profiles_array.body[4] = 0;
  v4 = v2;
  Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&profiles_array);
  v5 = *(_BYTE *)(v4 + 604);
  *(_DWORD *)profile_item_property.body = 0;
  *(_DWORD *)&profile_item_property.body[4] = 0;
  if ( v5 )
  {
    v6 = 0;
    v7 = (char *)(v4 + 616);
    v11 = v5;
    do
    {
      v8 = thisa->m_lobby_menu_ui.m_object;
      *(_DWORD *)profile_item.body = 0;
      *(_DWORD *)&profile_item.body[4] = 0;
      Scaleform::GFx::Movie::CreateObject(v8->movie->m_movie, (Scaleform::GFx::Value *)&profile_item, 0, 0, 0);
      pConvertedChars = 0;
      mbstowcs_s(&pConvertedChars, profile_name_w, 0x200u, v7, 0xFFFFFFFF);
      v9 = 0;
      v15 = 0;
      v16 = 7;
      v17 = profile_name_w;
      if ( (profile_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)profile_item_property.body + 8))(
          *(_DWORD *)profile_item_property.body,
          &profile_item_property,
          *(_DWORD *)&profile_item_property.body[8]);
        v9 = v15;
        *(_DWORD *)profile_item_property.body = 0;
      }
      *(_DWORD *)&profile_item_property.body[4] = 7;
      *(_DWORD *)&profile_item_property.body[8] = profile_name_w;
      if ( (v16 & 0x40) != 0 )
        (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v9 + 8))(v9, &v15, v17);
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)profile_item.body
                                                                                           + 20))(
        *(_DWORD *)profile_item.body,
        *(_DWORD *)&profile_item.body[8],
        "name",
        &profile_item_property,
        (profile_item.body[4] & 0x8F) == 10);
      if ( (profile_item_property.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)profile_item_property.body + 8))(
          *(_DWORD *)profile_item_property.body,
          &profile_item_property,
          *(_DWORD *)&profile_item_property.body[8]);
        *(_DWORD *)profile_item_property.body = 0;
      }
      *(_DWORD *)&profile_item_property.body[4] = 3;
      *(_DWORD *)&profile_item_property.body[8] = 1;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)profile_item.body
                                                                                           + 20))(
        *(_DWORD *)profile_item.body,
        *(_DWORD *)&profile_item.body[8],
        "icon",
        &profile_item_property,
        (profile_item.body[4] & 0x8F) == 10);
      (*(void (__thiscall **)(_DWORD, _DWORD, int, survarium::flash_value *))(**(_DWORD **)profiles_array.body + 52))(
        *(_DWORD *)profiles_array.body,
        *(_DWORD *)&profiles_array.body[8],
        v6,
        &profile_item);
      if ( (profile_item.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)profile_item.body + 8))(
          *(_DWORD *)profile_item.body,
          &profile_item,
          *(_DWORD *)&profile_item.body[8]);
      ++v6;
      v7 += 440;
      --v11;
    }
    while ( v11 );
  }
  Scaleform::GFx::Movie::Invoke(
    thisa->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.player_profile.setupProfiles",
    0,
    (const Scaleform::GFx::Value *)&profiles_array,
    1u);
  if ( (profile_item_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)profile_item_property.body + 8))(
      *(_DWORD *)profile_item_property.body,
      &profile_item_property,
      *(_DWORD *)&profile_item_property.body[8]);
    *(_DWORD *)profile_item_property.body = 0;
  }
  *(_DWORD *)&profile_item_property.body[4] = 0;
  if ( (profiles_array.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)profiles_array.body + 8))(
      *(_DWORD *)profiles_array.body,
      &profiles_array,
      *(_DWORD *)&profiles_array.body[8]);
}
