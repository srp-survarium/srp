void __thiscall survarium::lobby_menu::show_disconnected_message(
        survarium::lobby_menu *this,
        survarium::lobby_menu *b_show,
        bool b_showa)
{
  survarium::flash_movie_resource *m_object; // ecx
  survarium::flash_movie_resource *v4; // edx
  survarium::flash_value window_id; // [esp+10h] [ebp-478h] BYREF
  survarium::flash_value v[4]; // [esp+28h] [ebp-460h] BYREF
  wchar_t message_txt[512]; // [esp+88h] [ebp-400h] BYREF

  if ( b_showa )
  {
    `vector constructor iterator'(
      v[0].body,
      0x18u,
      4,
      (void *(__thiscall *)(void *))survarium::flash_value::flash_value);
    if ( (v[0].body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)v[0].body + 8))(
        *(_DWORD *)v[0].body,
        v,
        *(_DWORD *)&v[0].body[8]);
      *(_DWORD *)v[0].body = 0;
    }
    *(_DWORD *)&v[0].body[4] = 4;
    *(_DWORD *)&v[0].body[8] = 13;
    survarium::flash_value::SetString(&v[1], "noclose");
    survarium::text_translator::translate_text(
      &b_show->m_game->m_text_translator,
      "st_disconnected_from_lobby",
      message_txt);
    survarium::flash_value::SetStringW(&v[2], message_txt);
    if ( (v[3].body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)v[3].body + 8))(
        *(_DWORD *)v[3].body,
        &v[3],
        *(_DWORD *)&v[3].body[8]);
      *(_DWORD *)v[3].body = 0;
    }
    m_object = b_show->m_message_ui.m_object;
    *(_DWORD *)&v[3].body[4] = 2;
    v[3].body[8] = 1;
    Scaleform::GFx::Movie::Invoke(m_object->movie->m_movie, "root.showMessage", 0, (const Scaleform::GFx::Value *)v, 4u);
    `vector destructor iterator'(v[0].body, 0x18u, 4, (void (__thiscall *)(void *))survarium::flash_value::~flash_value);
  }
  else
  {
    v4 = b_show->m_message_ui.m_object;
    *(_DWORD *)window_id.body = 0;
    *(_DWORD *)&window_id.body[4] = 4;
    *(_DWORD *)&window_id.body[8] = 13;
    Scaleform::GFx::Movie::Invoke(v4->movie->m_movie, "root.close", 0, (const Scaleform::GFx::Value *)&window_id, 1u);
    if ( (window_id.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)window_id.body + 8))(
        *(_DWORD *)window_id.body,
        &window_id,
        *(_DWORD *)&window_id.body[8]);
  }
}
