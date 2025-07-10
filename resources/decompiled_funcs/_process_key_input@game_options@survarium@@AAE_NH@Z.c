char __fastcall survarium::game_options::process_key_input(int a1, int dik, survarium::game_options *this)
{
  survarium::keyboard_key_descr *v3; // eax
  survarium::game_action_id *M_start; // ecx
  survarium::key_bind_descr *v5; // eax
  survarium::game_action_id m_waiting_for_bind_action; // edi
  unsigned int action_id; // ebx
  int key_group; // ecx
  survarium::game_action_id *M_finish; // eax
  bool v10; // zf
  survarium::game_action_id v11; // edx
  survarium::text_translator *p_m_text_translator; // eax
  survarium::game_action_id *i; // ebx
  const char **p_str_description; // esi
  int v15; // edx
  survarium::key_binder *v17; // [esp+0h] [ebp-838h]
  const stlp_std::__false_type *v18; // [esp+0h] [ebp-838h]
  unsigned int v19; // [esp+4h] [ebp-834h]
  bool v20; // [esp+8h] [ebp-830h]
  int v21; // [esp+10h] [ebp-828h]
  int v22; // [esp+10h] [ebp-828h]
  const char *key_name; // [esp+14h] [ebp-824h]
  survarium::key_bind_descr *__x; // [esp+18h] [ebp-820h]
  survarium::key_binder *binder; // [esp+1Ch] [ebp-81Ch]
  survarium::flash_value message_txt; // [esp+20h] [ebp-818h] BYREF
  wchar_t w_text[512]; // [esp+38h] [ebp-800h] BYREF
  wchar_t action_txt[512]; // [esp+438h] [ebp-400h] BYREF

  if ( dik != 1 )
  {
    binder = this->m_game->m_key_binder;
    v3 = survarium::key_binder::dik_to_ptr(dik, v17);
    if ( !v3 )
      return 0;
    key_name = v3->key_name;
    if ( !v3->key_name )
      return 0;
    M_start = this->m_conflicted_action_ids._M_impl._M_start;
    if ( M_start != this->m_conflicted_action_ids._M_impl._M_finish )
      this->m_conflicted_action_ids._M_impl._M_finish = M_start;
    v5 = survarium::key_bind_descriptions;
    __x = survarium::key_bind_descriptions;
    v21 = 33;
    do
    {
      m_waiting_for_bind_action = this->m_waiting_for_bind_action;
      action_id = v5->action_id;
      if ( m_waiting_for_bind_action != v5->action_id && !strcmp(key_name, v5->new_binded_key.m_begin) )
      {
        key_group = binder->m_key_bindings[action_id].m_action->key_group;
        if ( (key_group & binder->m_key_bindings[m_waiting_for_bind_action].m_action->key_group) != 0 )
        {
          M_finish = this->m_conflicted_action_ids._M_impl._M_finish;
          if ( M_finish == this->m_conflicted_action_ids._M_impl._M_end_of_storage._M_data )
          {
            stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_insert_overflow_aux(
              &this->m_conflicted_action_ids._M_impl,
              M_finish,
              (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)key_group,
              (survarium::damage_zone **)__x,
              v18,
              v19,
              v20);
          }
          else
          {
            if ( M_finish )
              *M_finish = action_id;
            ++this->m_conflicted_action_ids._M_impl._M_finish;
          }
        }
      }
      v5 = __x + 1;
      v10 = v21-- == 1;
      ++__x;
    }
    while ( !v10 );
    if ( this->m_conflicted_action_ids._M_impl._M_start != this->m_conflicted_action_ids._M_impl._M_finish )
    {
      v11 = this->m_waiting_for_bind_action;
      *(_DWORD *)message_txt.body = 0;
      *(_DWORD *)&message_txt.body[4] = 0;
      p_m_text_translator = &this->m_game->m_text_translator;
      this->m_conflicted_key_name = key_name;
      this->m_conflicted_action_to_bind = v11;
      survarium::text_translator::translate_text(p_m_text_translator, "st_conflict_message", w_text);
      wcscat_s(action_id, w_text, 0x400u, L"\n");
      for ( i = this->m_conflicted_action_ids._M_impl._M_start; i != this->m_conflicted_action_ids._M_impl._M_finish; ++i )
      {
        p_str_description = &survarium::key_bind_descriptions[0].str_description;
        v22 = 33;
        do
        {
          if ( *(const char **)i == *(p_str_description - 1) )
            survarium::text_translator::translate_text(&this->m_game->m_text_translator, *p_str_description, action_txt);
          p_str_description += 26;
          --v22;
        }
        while ( v22 );
        wcscat_s((unsigned int)i, w_text, 0x400u, L"\"");
        wcscat_s((unsigned int)i, w_text, 0x400u, action_txt);
        wcscat_s((unsigned int)i, w_text, 0x400u, L"\"");
        if ( i != this->m_conflicted_action_ids._M_impl._M_finish - 1 )
          wcscat_s((unsigned int)i, w_text, 0x400u, L",\n");
      }
      survarium::flash_value::SetStringW(&message_txt, w_text);
      Scaleform::GFx::Movie::Invoke(
        this->m_options_ui.m_object->movie->m_movie,
        "root.show_reassign_message",
        0,
        (const Scaleform::GFx::Value *)&message_txt,
        1u);
      Scaleform::GFx::Movie::Invoke(this->m_options_ui.m_object->movie->m_movie, "root.end_keybind", 0, 0, 0);
      survarium::base_game_scene::show_movie(&this->m_cursor_ui, this->m_parent_scene, this->m_parent_scene);
      v15 = *(_DWORD *)&message_txt.body[4] >> 6;
      this->m_waiting_for_bind_action = kLASTACTION;
      if ( (v15 & 1) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)message_txt.body + 8))(
          *(_DWORD *)message_txt.body,
          &message_txt,
          *(_DWORD *)&message_txt.body[8]);
      return 0;
    }
    survarium::game_options::assign_binding(key_name, this, this->m_waiting_for_bind_action);
  }
  return 1;
}
