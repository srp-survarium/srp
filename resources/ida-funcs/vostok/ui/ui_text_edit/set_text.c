void __thiscall vostok::ui::ui_text_edit::set_text(vostok::ui::ui_text_edit *this, char *str)
{
  vostok::buffer_string *p_M_data; // ebx
  char *m_begin; // eax
  unsigned int v5; // kr00_4
  vostok::ui::ui_window *m_cursor_color_low; // ecx
  char *v7; // edi
  char *v8; // eax
  char *v9; // eax
  int v10; // eax
  unsigned int v11; // eax
  vostok::ui::undo_ *M_start; // edi
  vostok::ui::undo_ __x; // [esp+10h] [ebp-8h] BYREF

  p_M_data = (vostok::buffer_string *)&this->m_children._M_impl._M_end_of_storage._M_data;
  if ( _stricmp((const char *)this->m_children._M_impl._M_end_of_storage._M_data, str) )
  {
    m_begin = p_M_data->m_begin;
    p_M_data->m_end = p_M_data->m_begin;
    *m_begin = 0;
    v5 = strlen(str);
    m_cursor_color_low = (vostok::ui::ui_window *)LOWORD(this->m_cursor_color);
    if ( v5 <= (unsigned int)m_cursor_color_low )
    {
      v9 = p_M_data->m_begin;
      if ( p_M_data->m_begin != str )
      {
        p_M_data->m_end = v9;
        *v9 = 0;
        vostok::buffer_string::operator+=(p_M_data, str);
      }
    }
    else
    {
      v7 = vostok::strings::duplicate<vostok::memory::base_allocator>(str);
      v7[LOWORD(this->m_cursor_color)] = 0;
      v8 = p_M_data->m_begin;
      if ( p_M_data->m_begin != v7 )
      {
        p_M_data->m_end = v8;
        *v8 = 0;
        vostok::buffer_string::operator+=(p_M_data, v7);
      }
      m_cursor_color_low = (vostok::ui::ui_window *)this->vostok::ui::ui_text<vostok::ui::dynamic_text>::vostok::ui::ui_window::vostok::ui::window::__vftable;
      if ( v7 )
        ((void (__thiscall *)(vostok::ui::ui_window *, char *))m_cursor_color_low->draw)(m_cursor_color_low, v7);
    }
    vostok::ui::ui_window::emit_event(
      m_cursor_color_low,
      ev_text_changed,
      (vostok::ui::window *)&this->vostok::ui::ui_text<vostok::ui::dynamic_text>,
      0,
      0);
    v10 = (unsigned __int16)(LOWORD(p_M_data->m_end) - LOWORD(p_M_data->m_begin));
    if ( HIWORD(this->m_cursor_color) > (unsigned __int16)v10 )
      (*(void (__thiscall **)(vostok::ui::shift_state *, int, _DWORD))(*(_DWORD *)&this[-1].m_shift_state.m_data.d + 4))(
        &this[-1].m_shift_state,
        v10,
        0);
    if ( !HIBYTE(this->m_sel_start) )
    {
      v11 = (((int)this->m_undo_history._M_impl._M_start - LODWORD(this->m_last_action_time)) >> 3) + 1;
      __x = 0;
      stlp_std::vector<vostok::ui::undo_,vostok::vectora_allocator<void *>>::resize(
        (stlp_std::vector<vostok::ui::undo_,vostok::vectora_allocator<void *> > *)&this->m_last_action_time,
        v11,
        &__x);
      M_start = this->m_undo_history._M_impl._M_start;
      M_start[-1].text = vostok::strings::duplicate<vostok::memory::base_allocator>(p_M_data->m_begin);
      this->m_undo_history._M_impl._M_start[-1].caret = HIWORD(this->m_cursor_color);
      if ( !LOBYTE(this->m_sel_end) )
        vostok::ui::clear_history_container(
          (vostok::vectora<vostok::ui::undo_> *)&this->m_undo_history._M_impl._M_end_of_storage._M_data,
          (vostok::memory::base_allocator *)this->vostok::ui::ui_text<vostok::ui::dynamic_text>::vostok::ui::ui_window::vostok::ui::window::__vftable);
    }
  }
}
