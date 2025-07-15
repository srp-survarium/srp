void __userpurge survarium::lobby_menu::set_online_stats(
        unsigned int maintenance_remain@<eax>,
        survarium::flash_value *a2@<ecx>,
        survarium::lobby_menu *this,
        unsigned int players,
        unsigned int matches)
{
  survarium::flash_value *v5; // ecx
  survarium::text_translator *v6; // ecx
  survarium::text_translator *p_m_text_translator; // eax
  char v8[512]; // [esp+10h] [ebp-434h] BYREF
  char v9[512]; // [esp+210h] [ebp-234h] BYREF
  survarium::flash_value v10; // [esp+410h] [ebp-34h] BYREF
  Scaleform::GFx::Value pargs; // [esp+428h] [ebp-1Ch] BYREF

  this->m_maintenance_remain = maintenance_remain;
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetUInt(a2, (int)&pargs, matches);
  Scaleform::GFx::Movie::Invoke(this->m_lobby_menu_ui.m_object->movie->m_movie, "root.set_games_online", 0, &pargs, 1u);
  survarium::flash_value::SetUInt(v5, (int)&pargs, players);
  Scaleform::GFx::Movie::Invoke(
    this->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.set_players_online",
    0,
    &pargs,
    1u);
  if ( this->m_maintenance_remain < 0x3C )
  {
    p_m_text_translator = &this->m_game->m_text_translator;
    *(_DWORD *)v10.body = 0;
    *(_DWORD *)&v10.body[4] = 0;
    survarium::text_translator::translate_text(v6, (int)p_m_text_translator, "st_server_maintenance", v9);
    vostok::sprintf<512>((char (*)[512])v8, "%s :%dm", v9, this->m_maintenance_remain);
    survarium::flash_value::SetString(&v10, v8);
    Scaleform::GFx::Movie::Invoke(
      this->m_lobby_menu_ui.m_object->movie->m_movie,
      "root.set_warning_text",
      0,
      (const Scaleform::GFx::Value *)&v10,
      1u);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v10);
  }
  survarium::lobby_menu::update_play_button_lock((survarium::lobby_menu *)v6, (int)this);
  Scaleform::GFx::Value::~Value(&pargs);
}
