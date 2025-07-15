void __usercall survarium::lobby_menu::on_profile_arrived(
        survarium::lobby_menu *this@<ecx>,
        unsigned __int8 profile_id@<al>)
{
  survarium::flash_movie_resource *m_object; // eax
  survarium::flash_value profile_id_value; // [esp+0h] [ebp-1Ch] BYREF

  if ( this->m_selected_profile == profile_id )
  {
    *(_DWORD *)&profile_id_value.body[8] = profile_id;
    m_object = this->m_lobby_menu_ui.m_object;
    *(_DWORD *)profile_id_value.body = 0;
    *(_DWORD *)&profile_id_value.body[4] = 4;
    Scaleform::GFx::Movie::Invoke(
      m_object->movie->m_movie,
      "_root.player_profile.selectProfile",
      0,
      (const Scaleform::GFx::Value *)&profile_id_value,
      1u);
    if ( (profile_id_value.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)profile_id_value.body + 8))(
        *(_DWORD *)profile_id_value.body,
        &profile_id_value,
        *(_DWORD *)&profile_id_value.body[8]);
  }
}
