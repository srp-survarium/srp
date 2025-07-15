char __userpurge vostok::ui::ui_text_edit::on_keyb_action@<al>(
        vostok::ui::ui_text_edit *this@<ecx>,
        const vostok::ui::shift_state *a2@<esi>,
        vostok::ui::window *w,
        int p1,
        vostok::input::enum_keyboard_action p2)
{
  void **M_finish; // eax
  void **M_start; // ebp
  vostok::ui::base_edit_action *v10; // esi
  vostok::timing::timer *p_m_timer; // ecx
  const vostok::ui::shift_state *v12; // [esp-8h] [ebp-14h]
  vostok::ui::base_edit_action **it_e; // [esp+8h] [ebp-4h]
  bool result; // [esp+18h] [ebp+Ch]

  if ( p2 == kb_key_hold )
    return 1;
  M_finish = this->m_edit_actions._M_impl._M_finish;
  M_start = this->m_edit_actions._M_impl._M_start;
  this->m_last_action = 0;
  it_e = (vostok::ui::base_edit_action **)M_finish;
  result = 0;
  if ( M_start != M_finish )
  {
    v12 = a2;
    do
    {
      v10 = (vostok::ui::base_edit_action *)*M_start;
      if ( *((_DWORD *)*M_start + 2) == p1
        && vostok::ui::base_edit_action::similar(
             (vostok::ui::base_edit_action *)&this->m_shift_state,
             (int)v10,
             p2,
             (unsigned __int8 *)&this->m_shift_state,
             v12) )
      {
        result = v10->execute(v10, p2);
        if ( result )
        {
          p_m_timer = &this->m_ui_world->m_timer;
          this->m_last_action = v10;
          this->m_last_action_time = vostok::timing::timer::get_elapsed_sec(p_m_timer);
        }
      }
      ++M_start;
    }
    while ( M_start != (void **)it_e );
  }
  return result;
}
