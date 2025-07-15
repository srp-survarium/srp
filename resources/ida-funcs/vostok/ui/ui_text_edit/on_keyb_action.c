bool __thiscall vostok::ui::ui_text_edit::on_keyb_action(
        vostok::ui::ui_text_edit *this,
        vostok::ui::window *w,
        int p1,
        vostok::input::enum_keyboard_action p2)
{
  void **M_start; // eax
  void **M_finish; // ecx
  vostok::ui::base_edit_action *v8; // edi
  vostok::input::enum_keyboard_action m_key_action; // eax
  vostok::ui::shift_state::data_storage v10; // dl
  vostok::ui::shift_state::data_storage v11; // cl
  char v12; // al
  char v13; // al
  char v14; // dl
  vostok::timing::timer *v15; // ecx
  vostok::timing::timer *p_m_timer; // eax
  void **v17; // [esp+4h] [ebp-Ch]
  void **v18; // [esp+8h] [ebp-8h]
  bool i; // [esp+Fh] [ebp-1h]

  if ( p2 == kb_key_hold )
    return 1;
  M_start = this->m_edit_actions._M_impl._M_start;
  M_finish = this->m_edit_actions._M_impl._M_finish;
  this->m_last_action = 0;
  v18 = M_start;
  v17 = M_finish;
  for ( i = 0; M_start != v17; v18 = M_start )
  {
    v8 = (vostok::ui::base_edit_action *)*M_start;
    if ( *((_DWORD *)*M_start + 2) == p1 )
    {
      m_key_action = v8->m_key_action;
      if ( m_key_action == kb_key_unknown || m_key_action == p2 )
      {
        v10.d = (vostok::ui::shift_state::data_storage::<unnamed_type_d>)v8->m_shift_state.m_data;
        v11.d = (vostok::ui::shift_state::data_storage::<unnamed_type_d>)this->m_shift_state.m_data;
        v12 = (v10.dummy >> 2) & 3;
        if ( ((v11.dummy >> 2) & 3) == v12 || v12 == 2 )
        {
          v13 = (v10.dummy >> 4) & 3;
          if ( ((v11.dummy >> 4) & 3) == v13 || v13 == 2 )
          {
            v14 = v10.dummy & 3;
            if ( (v11.dummy & 3) == v14 || v14 == 2 )
            {
              i = v8->execute(v8, p2);
              if ( i )
              {
                p_m_timer = &this->m_ui_world->m_timer;
                this->m_last_action = v8;
                this->m_last_action_time = vostok::timing::timer::get_elapsed_sec(v15, (int)p_m_timer);
              }
            }
          }
        }
      }
    }
    M_start = v18 + 1;
  }
  return i;
}
