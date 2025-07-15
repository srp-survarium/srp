void __thiscall survarium::lobby_menu::show_match_making(
        survarium::lobby_menu *this,
        survarium::lobby_menu *b_show,
        bool b_showa)
{
  survarium::flash_movie_resource *m_object; // eax
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *p_m_match_making_ui; // ebx
  survarium::flash_movie_resource *v5; // edx
  survarium::flash_movie_resource *v6; // edx
  const char *v7; // edi
  survarium::base_game_scene *v8; // ecx
  const char **p_label; // [esp+40h] [ebp-46Ch]
  int v10; // [esp+44h] [ebp-468h]
  int v11; // [esp+48h] [ebp-464h]
  survarium::flash_value text; // [esp+4Ch] [ebp-460h] BYREF
  survarium::flash_value label; // [esp+64h] [ebp-448h] BYREF
  survarium::flash_value label_member; // [esp+7Ch] [ebp-430h] BYREF
  survarium::flash_value labels_array; // [esp+94h] [ebp-418h] BYREF
  wchar_t label_txt[512]; // [esp+ACh] [ebp-400h] BYREF

  if ( b_show->m_is_in_match_making != b_showa )
  {
    if ( b_showa )
    {
      m_object = b_show->m_match_making_ui.m_object;
      b_show->m_level_loading_progress = 0.0;
      b_show->m_last_queries_count = 0;
      p_m_match_making_ui = &b_show->m_match_making_ui;
      m_object->movie->m_movie->Restart(m_object->movie->m_movie, 1);
      v5 = b_show->m_match_making_ui.m_object;
      *(_DWORD *)labels_array.body = 0;
      *(_DWORD *)&labels_array.body[4] = 0;
      Scaleform::GFx::Movie::CreateArray(v5->movie->m_movie, (Scaleform::GFx::Value *)&labels_array);
      v10 = 0;
      p_label = &survarium::match_making_labels[0].label;
      v11 = 7;
      do
      {
        v6 = p_m_match_making_ui->m_object;
        *(_DWORD *)label.body = 0;
        *(_DWORD *)&label.body[4] = 0;
        Scaleform::GFx::Movie::CreateObject(v6->movie->m_movie, (Scaleform::GFx::Value *)&label, 0, 0, 0);
        v7 = *(p_label - 1);
        *(_DWORD *)label_member.body = 0;
        *(_DWORD *)&label_member.body[4] = 0;
        survarium::flash_value::SetString(&label_member, v7);
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)label.body
                                                                                             + 20))(
          *(_DWORD *)label.body,
          *(_DWORD *)&label.body[8],
          "name",
          &label_member,
          (label.body[4] & 0x8F) == 10);
        survarium::text_translator::translate_text(&b_show->m_game->m_text_translator, *p_label, label_txt);
        survarium::flash_value::SetStringW(&label_member, label_txt);
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)label.body
                                                                                             + 20))(
          *(_DWORD *)label.body,
          *(_DWORD *)&label.body[8],
          "label",
          &label_member,
          (label.body[4] & 0x8F) == 10);
        (*(void (__thiscall **)(_DWORD, _DWORD, int, survarium::flash_value *))(**(_DWORD **)labels_array.body + 52))(
          *(_DWORD *)labels_array.body,
          *(_DWORD *)&labels_array.body[8],
          v10,
          &label);
        if ( (label_member.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)label_member.body + 8))(
            *(_DWORD *)label_member.body,
            &label_member,
            *(_DWORD *)&label_member.body[8]);
          *(_DWORD *)label_member.body = 0;
        }
        *(_DWORD *)&label_member.body[4] = 0;
        if ( (label.body[4] & 0x40) != 0 )
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)label.body + 8))(
            *(_DWORD *)label.body,
            &label,
            *(_DWORD *)&label.body[8]);
        p_label += 2;
        ++v10;
        --v11;
      }
      while ( v11 );
      Scaleform::GFx::Movie::Invoke(
        p_m_match_making_ui->m_object->movie->m_movie,
        "root.set_labels",
        0,
        (const Scaleform::GFx::Value *)&labels_array,
        1u);
      *(_DWORD *)text.body = 0;
      *(_DWORD *)&text.body[4] = 0;
      survarium::flash_value::SetStringW(&text, a0_0);
      Scaleform::GFx::Movie::Invoke(
        p_m_match_making_ui->m_object->movie->m_movie,
        "root.set_current_time",
        0,
        (const Scaleform::GFx::Value *)&text,
        1u);
      survarium::flash_value::SetStringW(&text, a0_0);
      Scaleform::GFx::Movie::Invoke(
        p_m_match_making_ui->m_object->movie->m_movie,
        "root.set_average_time",
        0,
        (const Scaleform::GFx::Value *)&text,
        1u);
      survarium::flash_value::SetStringW(&text, &word_96B534);
      Scaleform::GFx::Movie::Invoke(
        p_m_match_making_ui->m_object->movie->m_movie,
        "root.set_place",
        0,
        (const Scaleform::GFx::Value *)&text,
        1u);
      survarium::flash_value::SetStringW(&text, &word_96DFF0);
      Scaleform::GFx::Movie::Invoke(
        p_m_match_making_ui->m_object->movie->m_movie,
        "root.set_status",
        0,
        (const Scaleform::GFx::Value *)&text,
        1u);
      survarium::base_game_scene::show_movie(p_m_match_making_ui, v8, b_show);
      if ( (text.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)text.body + 8))(
          *(_DWORD *)text.body,
          &text,
          *(_DWORD *)&text.body[8]);
        *(_DWORD *)text.body = 0;
      }
      *(_DWORD *)&text.body[4] = 0;
      if ( (labels_array.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)labels_array.body + 8))(
          *(_DWORD *)labels_array.body,
          &labels_array,
          *(_DWORD *)&labels_array.body[8]);
      b_show->m_is_in_match_making = b_showa;
    }
    else
    {
      survarium::base_game_scene::hide_movie(b_show, &b_show->m_match_making_ui, (int)this);
      b_show->m_is_in_match_making = 0;
    }
  }
}
