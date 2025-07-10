void __thiscall survarium::lobby_menu::reset_account_money(survarium::lobby_menu *this, survarium::lobby_menu *thisa)
{
  survarium::flash_movie_resource *m_object; // ecx
  survarium::game *m_game; // eax
  char *v4; // eax
  unsigned int generic_money; // esi
  unsigned int premium_money; // esi
  survarium::flash_value account_info_property; // [esp+48h] [ebp-234h] BYREF
  survarium::flash_value account_info; // [esp+60h] [ebp-21Ch] BYREF
  unsigned int pConvertedChars; // [esp+78h] [ebp-204h] BYREF
  wchar_t an[256]; // [esp+7Ch] [ebp-200h] BYREF

  m_object = thisa->m_lobby_menu_ui.m_object;
  *(_DWORD *)account_info.body = 0;
  *(_DWORD *)&account_info.body[4] = 0;
  Scaleform::GFx::Movie::CreateObject(m_object->movie->m_movie, (Scaleform::GFx::Value *)&account_info, 0, 0, 0);
  m_game = thisa->m_game;
  *(_DWORD *)account_info_property.body = 0;
  *(_DWORD *)&account_info_property.body[4] = 0;
  v4 = (char *)m_game->m_network_client->lobby_client(m_game->m_network_client);
  pConvertedChars = 0;
  mbstowcs_s(&pConvertedChars, an, 0x100u, v4, 0xFFFFFFFF);
  survarium::flash_value::SetStringW(&account_info_property, an);
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)account_info.body
                                                                                       + 20))(
    *(_DWORD *)account_info.body,
    *(_DWORD *)&account_info.body[8],
    "nickname",
    &account_info_property,
    (account_info.body[4] & 0x8F) == 10);
  generic_money = thisa->m_game->m_network_client->lobby_client(thisa->m_game->m_network_client)->m_account_money.generic_money;
  if ( (account_info_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)account_info_property.body + 8))(
      *(_DWORD *)account_info_property.body,
      &account_info_property,
      *(_DWORD *)&account_info_property.body[8]);
    *(_DWORD *)account_info_property.body = 0;
  }
  *(_DWORD *)&account_info_property.body[4] = 4;
  *(_DWORD *)&account_info_property.body[8] = generic_money;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)account_info.body
                                                                                       + 20))(
    *(_DWORD *)account_info.body,
    *(_DWORD *)&account_info.body[8],
    "generic_money",
    &account_info_property,
    (account_info.body[4] & 0x8F) == 10);
  premium_money = thisa->m_game->m_network_client->lobby_client(thisa->m_game->m_network_client)->m_account_money.premium_money;
  if ( (account_info_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)account_info_property.body + 8))(
      *(_DWORD *)account_info_property.body,
      &account_info_property,
      *(_DWORD *)&account_info_property.body[8]);
    *(_DWORD *)account_info_property.body = 0;
  }
  *(_DWORD *)&account_info_property.body[4] = 4;
  *(_DWORD *)&account_info_property.body[8] = premium_money;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)account_info.body
                                                                                       + 20))(
    *(_DWORD *)account_info.body,
    *(_DWORD *)&account_info.body[8],
    "premium_money",
    &account_info_property,
    (account_info.body[4] & 0x8F) == 10);
  Scaleform::GFx::Movie::Invoke(
    thisa->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.setPlayerInfo",
    0,
    (const Scaleform::GFx::Value *)&account_info,
    1u);
  if ( (account_info_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)account_info_property.body + 8))(
      *(_DWORD *)account_info_property.body,
      &account_info_property,
      *(_DWORD *)&account_info_property.body[8]);
    *(_DWORD *)account_info_property.body = 0;
  }
  *(_DWORD *)&account_info_property.body[4] = 0;
  if ( (account_info.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)account_info.body + 8))(
      *(_DWORD *)account_info.body,
      &account_info,
      *(_DWORD *)&account_info.body[8]);
}
