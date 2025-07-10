void __userpurge survarium::chat_handler::set_local_player_name(
        char *account_name@<eax>,
        survarium::chat_handler *this)
{
  unsigned int pConvertedChars; // [esp+Ch] [ebp-21Ch] BYREF
  survarium::flash_value local_player_name; // [esp+10h] [ebp-218h] BYREF
  wchar_t an[256]; // [esp+28h] [ebp-200h] BYREF

  pConvertedChars = 0;
  mbstowcs_s(&pConvertedChars, an, 0x100u, account_name, 0xFFFFFFFF);
  *(_DWORD *)local_player_name.body = 0;
  *(_DWORD *)&local_player_name.body[4] = 0;
  survarium::flash_value::SetStringW(&local_player_name, an);
  Scaleform::GFx::Movie::Invoke(
    this->m_chat_ui.m_object->movie->m_movie,
    "root.set_local_player",
    0,
    (const Scaleform::GFx::Value *)&local_player_name,
    1u);
  if ( (local_player_name.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)local_player_name.body + 8))(
      *(_DWORD *)local_player_name.body,
      &local_player_name,
      *(_DWORD *)&local_player_name.body[8]);
}
