void __thiscall survarium::lobby_menu::fill_inventory_labels(survarium::lobby_menu *this, survarium::lobby_menu *thisa)
{
  survarium::flash_movie_resource *m_object; // ecx
  survarium::ui_label *v3; // esi
  const char *label; // edi
  survarium::text_translator *p_m_text_translator; // eax
  int v6; // ecx
  int v7; // [esp+28h] [ebp-44Ch]
  survarium::flash_value label_translate; // [esp+2Ch] [ebp-448h] BYREF
  survarium::flash_value labels; // [esp+44h] [ebp-430h] BYREF
  int v10; // [esp+5Ch] [ebp-418h] BYREF
  int v11; // [esp+60h] [ebp-414h]
  wchar_t *v12; // [esp+64h] [ebp-410h]
  wchar_t label_w[512]; // [esp+74h] [ebp-400h] BYREF

  m_object = thisa->m_lobby_menu_ui.m_object;
  *(_DWORD *)labels.body = 0;
  *(_DWORD *)&labels.body[4] = 0;
  Scaleform::GFx::Movie::CreateObject(m_object->movie->m_movie, (Scaleform::GFx::Value *)&labels, 0, 0, 0);
  v3 = survarium::lobby_labels;
  v7 = 73;
  do
  {
    label = v3->label;
    p_m_text_translator = &thisa->m_game->m_text_translator;
    *(_DWORD *)label_translate.body = 0;
    *(_DWORD *)&label_translate.body[4] = 0;
    survarium::text_translator::translate_text(p_m_text_translator, label, label_w);
    v6 = 0;
    v10 = 0;
    v11 = 7;
    v12 = label_w;
    if ( (label_translate.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)label_translate.body + 8))(
        *(_DWORD *)label_translate.body,
        &label_translate,
        *(_DWORD *)&label_translate.body[8]);
      v6 = v10;
      *(_DWORD *)label_translate.body = 0;
    }
    *(_DWORD *)&label_translate.body[4] = 7;
    *(_DWORD *)&label_translate.body[8] = label_w;
    if ( (v11 & 0x40) != 0 )
      (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v6 + 8))(v6, &v10, v12);
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)labels.body + 20))(
      *(_DWORD *)labels.body,
      *(_DWORD *)&labels.body[8],
      v3->name,
      &label_translate,
      (labels.body[4] & 0x8F) == 10);
    if ( (label_translate.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)label_translate.body + 8))(
        *(_DWORD *)label_translate.body,
        &label_translate,
        *(_DWORD *)&label_translate.body[8]);
    ++v3;
    --v7;
  }
  while ( v7 );
  Scaleform::GFx::Movie::Invoke(
    thisa->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.set_localization_data",
    0,
    (const Scaleform::GFx::Value *)&labels,
    1u);
  if ( (labels.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)labels.body + 8))(
      *(_DWORD *)labels.body,
      &labels,
      *(_DWORD *)&labels.body[8]);
}
