void __thiscall vostok::ui::ui_text_edit::set_text(vostok::ui::ui_text_edit *this, char *str)
{
  vostok::buffer_string *p_M_data; // ebx
  char *m_begin; // eax
  char *v5; // edi
  char *v6; // eax
  char *v7; // eax
  int v8; // eax
  char *v9; // eax
  vostok::ui::undo_ *M_start; // ebx
  vostok::ui::undo_ __x; // [esp+8h] [ebp-8h] BYREF

  p_M_data = (vostok::buffer_string *)&this->m_children._M_impl._M_end_of_storage._M_data;
  if ( _stricmp((char *)this->m_children._M_impl._M_end_of_storage._M_data, str) )
  {
    m_begin = p_M_data->m_begin;
    p_M_data->m_end = p_M_data->m_begin;
    *m_begin = 0;
    if ( strlen(str) <= LOWORD(this->m_cursor_color) )
    {
      v7 = p_M_data->m_begin;
      if ( p_M_data->m_begin != str )
      {
        p_M_data->m_end = v7;
        *v7 = 0;
        vostok::buffer_string::operator+=(p_M_data, str);
      }
    }
    else
    {
      v5 = vostok::strings::duplicate<vostok::memory::base_allocator>(str);
      v5[LOWORD(this->m_cursor_color)] = 0;
      v6 = p_M_data->m_begin;
      if ( p_M_data->m_begin != v5 )
      {
        p_M_data->m_end = v6;
        *v6 = 0;
        vostok::buffer_string::operator+=(p_M_data, v5);
      }
      if ( v5 )
        (*((void (__thiscall **)(vostok::ui::ui_window_vtbl *, char *, const char *, const char *, int))this->set_position
         + 6))(
          this->vostok::ui::ui_text<vostok::ui::dynamic_text>::vostok::ui::ui_window::vostok::ui::window::__vftable,
          v5,
          "vostok::ui::ui_text_edit::set_text",
          ".\\ui_text_edit.cpp",
          94);
    }
    vostok::ui::ui_window::process_event(
      (vostok::ui::ui_window *)5,
      (vostok::ui::ui_window *)&this->vostok::ui::ui_text<vostok::ui::dynamic_text>,
      0,
      0);
    v8 = (unsigned __int16)(LOWORD(p_M_data->m_end) - LOWORD(p_M_data->m_begin));
    if ( HIWORD(this->m_cursor_color) > (unsigned __int16)v8 )
      (*(void (__thiscall **)(vostok::ui::shift_state *, int, _DWORD))(*(_DWORD *)&this[-1].m_shift_state.m_data.d + 4))(
        &this[-1].m_shift_state,
        v8,
        0);
    if ( !HIBYTE(this->m_sel_start) )
    {
      __x.text = 0;
      *(_DWORD *)&__x.caret = 0;
      stlp_std::vector<vostok::ui::undo_,vostok::vectora_allocator<void *>>::resize(
        (stlp_std::vector<vostok::ui::undo_,vostok::vectora_allocator<void *> > *)&this->m_last_action_time,
        (((int)this->m_undo_history._M_impl._M_start - LODWORD(this->m_last_action_time)) >> 3) + 1,
        &__x);
      v9 = p_M_data->m_begin;
      M_start = this->m_undo_history._M_impl._M_start;
      M_start[-1].text = vostok::strings::duplicate<vostok::memory::base_allocator>(v9);
      this->m_undo_history._M_impl._M_start[-1].caret = HIWORD(this->m_cursor_color);
      if ( !LOBYTE(this->m_sel_end) )
        vostok::ui::clear_history_container(
          (vostok::vectora<vostok::ui::undo_> *)&this->m_undo_history._M_impl._M_end_of_storage._M_data,
          (vostok::memory::base_allocator *)this->vostok::ui::ui_text<vostok::ui::dynamic_text>::vostok::ui::ui_window::vostok::ui::window::__vftable);
    }
  }
}
