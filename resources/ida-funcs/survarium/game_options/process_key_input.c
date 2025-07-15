char __thiscall survarium::game_options::process_key_input(
        survarium::game_options *this,
        survarium::game_options *dik,
        int _dik)
{
  survarium::game_action_id *M_start; // ecx
  survarium::game_action_id m_waiting_for_bind_action; // edi
  survarium::game_action_id *M_finish; // eax
  survarium::game_action_id *i; // esi
  survarium::game_options *v8; // ecx
  const stlp_std::__false_type *v9; // [esp+0h] [ebp-438h]
  unsigned int v10; // [esp+4h] [ebp-434h]
  bool v11; // [esp+8h] [ebp-430h]
  survarium::key_bind_descr *__x; // [esp+Ch] [ebp-42Ch]
  const char **__xa; // [esp+Ch] [ebp-42Ch]
  int v14; // [esp+10h] [ebp-428h]
  int v15; // [esp+10h] [ebp-428h]
  char *left; // [esp+14h] [ebp-424h]
  survarium::game_action_id action_id; // [esp+18h] [ebp-420h]
  survarium::key_binder *m_key_binder; // [esp+1Ch] [ebp-41Ch]
  survarium::flash_value v19; // [esp+20h] [ebp-418h] BYREF
  char _Dst[512]; // [esp+38h] [ebp-400h] BYREF
  char _Src[512]; // [esp+238h] [ebp-200h] BYREF

  if ( _dik != 1 )
  {
    m_key_binder = dik->m_game->m_key_binder;
    left = (char *)survarium::key_binder::dik_to_keyname((survarium::key_binder *)this, _dik);
    if ( !left )
      return 0;
    M_start = dik->m_conflicted_action_ids._M_impl._M_start;
    if ( M_start != dik->m_conflicted_action_ids._M_impl._M_finish )
      dik->m_conflicted_action_ids._M_impl._M_finish = M_start;
    __x = survarium::key_bind_descriptions;
    v14 = 41;
    do
    {
      m_waiting_for_bind_action = dik->m_waiting_for_bind_action;
      action_id = __x->action_id;
      if ( m_waiting_for_bind_action != __x->action_id && !vostok::strings::compare(left, __x->new_binded_key.m_begin) )
      {
        M_start = (survarium::game_action_id *)action_id;
        if ( (m_key_binder->m_key_bindings[action_id].m_action->key_group
            & m_key_binder->m_key_bindings[m_waiting_for_bind_action].m_action->key_group) != 0 )
        {
          M_finish = dik->m_conflicted_action_ids._M_impl._M_finish;
          if ( M_finish == dik->m_conflicted_action_ids._M_impl._M_end_of_storage._M_data )
          {
            stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_insert_overflow_aux(
              &dik->m_conflicted_action_ids._M_impl,
              M_finish,
              (vostok::memory::doug_lea_allocator **)__x,
              v9,
              v10,
              v11);
          }
          else
          {
            if ( M_finish )
              *M_finish = action_id;
            ++dik->m_conflicted_action_ids._M_impl._M_finish;
          }
        }
      }
      ++__x;
      --v14;
    }
    while ( v14 );
    if ( dik->m_conflicted_action_ids._M_impl._M_start != dik->m_conflicted_action_ids._M_impl._M_finish )
    {
      *(_DWORD *)v19.body = 0;
      *(_DWORD *)&v19.body[4] = 0;
      dik->m_conflicted_key_name = left;
      dik->m_conflicted_action_to_bind = dik->m_waiting_for_bind_action;
      survarium::text_translator::translate_text(
        (survarium::text_translator *)M_start,
        (int)&dik->m_game->m_text_translator,
        "st_conflict_message",
        _Dst);
      strcat_s(_Dst, 0x200u, "\n");
      for ( i = dik->m_conflicted_action_ids._M_impl._M_start; i != dik->m_conflicted_action_ids._M_impl._M_finish; ++i )
      {
        __xa = &survarium::key_bind_descriptions[0].str_description;
        v15 = 41;
        do
        {
          if ( *(const char **)i == *(__xa - 1) )
            survarium::text_translator::translate_text(
              (survarium::text_translator *)__xa,
              (int)&dik->m_game->m_text_translator,
              (char *)*__xa,
              _Src);
          __xa += 26;
          --v15;
        }
        while ( v15 );
        strcat_s(_Dst, 0x200u, "\"");
        strcat_s(_Dst, 0x200u, _Src);
        strcat_s(_Dst, 0x200u, "\"");
        if ( i != dik->m_conflicted_action_ids._M_impl._M_finish - 1 )
          strcat_s(_Dst, 0x200u, ",\n");
      }
      survarium::flash_value::SetString(&v19, _Dst);
      Scaleform::GFx::Movie::Invoke(
        dik->m_options_ui.m_object->movie->m_movie,
        "root.show_reassign_message",
        0,
        (const Scaleform::GFx::Value *)&v19,
        1u);
      survarium::game_options::finish_binding(v8, (int)dik);
      Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v19);
      return 0;
    }
    survarium::game_options::assign_binding(dik->m_waiting_for_bind_action, dik, left);
  }
  return 1;
}
