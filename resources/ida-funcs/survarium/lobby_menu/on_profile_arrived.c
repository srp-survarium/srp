void __usercall survarium::lobby_menu::on_profile_arrived(
        survarium::lobby_menu *this@<edi>,
        unsigned __int8 profile_idx@<al>,
        survarium::flash_value *a3@<ecx>)
{
  Scaleform::GFx::Value pargs; // [esp+8h] [ebp-18h] BYREF

  if ( this->m_selected_profile_idx == profile_idx )
  {
    pargs.pObjectInterface = 0;
    pargs.Type = VT_Undefined;
    survarium::flash_value::SetUInt(a3, (int)&pargs, profile_idx);
    Scaleform::GFx::Movie::Invoke(
      this->m_lobby_menu_ui.m_object->movie->m_movie,
      "_root.player_profile.selectProfile",
      0,
      &pargs,
      1u);
    Scaleform::GFx::Value::~Value(&pargs);
  }
}
