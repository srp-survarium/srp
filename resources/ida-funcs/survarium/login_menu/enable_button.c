void __usercall survarium::login_menu::enable_button(survarium::login_menu *this@<edx>, char value@<al>)
{
  survarium::flash_movie_resource *m_object; // eax
  survarium::flash_value sign_in_button_enable; // [esp+0h] [ebp-18h] BYREF

  sign_in_button_enable.body[8] = value;
  m_object = this->m_login_menu_ui.m_object;
  *(_DWORD *)sign_in_button_enable.body = 0;
  *(_DWORD *)&sign_in_button_enable.body[4] = 2;
  Scaleform::GFx::Movie::SetVariable(
    m_object->movie->m_movie,
    "root.sign_in_btn.enabled",
    (const Scaleform::GFx::Value *)&sign_in_button_enable,
    SV_Sticky);
  if ( (sign_in_button_enable.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)sign_in_button_enable.body + 8))(
      *(_DWORD *)sign_in_button_enable.body,
      &sign_in_button_enable,
      *(_DWORD *)&sign_in_button_enable.body[8]);
}
