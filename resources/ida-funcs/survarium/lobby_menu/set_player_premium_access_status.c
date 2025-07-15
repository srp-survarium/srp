void __userpurge survarium::lobby_menu::set_player_premium_access_status(
        unsigned int hours_left@<eax>,
        survarium::lobby_menu *this,
        const bool has_premium_status)
{
  survarium::flash_value *v4; // ecx
  survarium::flash_value *v5; // ecx
  int v6; // edx
  survarium::text_translator *p_m_text_translator; // eax
  survarium::flash_value *v8; // ecx
  Scaleform::GFx::Value *v9; // esi
  int i; // edi
  char v11[512]; // [esp+10h] [ebp-2B0h] BYREF
  char _Dest[128]; // [esp+210h] [ebp-B0h] BYREF
  survarium::flash_value v13; // [esp+290h] [ebp-30h] BYREF
  survarium::flash_value v14; // [esp+2A8h] [ebp-18h] BYREF
  char vars0; // [esp+2C0h] [ebp+0h] BYREF
  unsigned __int8 v16; // [esp+2CFh] [ebp+Fh]

  v4 = &v13;
  do
  {
    survarium::flash_value::flash_value(v4);
    v4 = v5 + 1;
  }
  while ( v6 - 1 >= 0 );
  memset(_Dest, 0, sizeof(_Dest));
  if ( has_premium_status )
  {
    v4 = (survarium::flash_value *)24;
    v16 = ((unsigned __int8)(hours_left / 0x18) == 0) + 1;
  }
  else
  {
    v16 = 0;
  }
  p_m_text_translator = &this->m_game->m_text_translator;
  if ( hours_left )
  {
    if ( hours_left >= 0x18 )
    {
      survarium::text_translator::translate_text(
        (survarium::text_translator *)v4,
        (int)p_m_text_translator,
        "st_day_short",
        v11);
      sprintf_s<128>((char (*)[128])_Dest, "%d %s", (unsigned __int16)(hours_left / 0x18), v11);
    }
    else
    {
      survarium::text_translator::translate_text(
        (survarium::text_translator *)v4,
        (int)p_m_text_translator,
        "st_hour_short",
        v11);
      sprintf_s<128>((char (*)[128])_Dest, "%d %s", hours_left, v11);
    }
  }
  else
  {
    survarium::text_translator::translate_text(
      (survarium::text_translator *)v4,
      (int)p_m_text_translator,
      "st_less_then_hour",
      v11);
    sprintf_s<128>((char (*)[128])_Dest, (char *)&stru_7F9BE8.allocator, v11);
  }
  survarium::flash_value::SetUInt(v8, (int)&v13, v16);
  survarium::flash_value::SetString(&v14, _Dest);
  Scaleform::GFx::Movie::Invoke(
    this->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.set_premium_state",
    0,
    (const Scaleform::GFx::Value *)&v13,
    2u);
  v9 = (Scaleform::GFx::Value *)&vars0;
  for ( i = 1; i >= 0; --i )
    Scaleform::GFx::Value::~Value(--v9);
}
