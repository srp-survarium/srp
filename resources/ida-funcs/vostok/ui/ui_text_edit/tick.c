void __thiscall vostok::ui::ui_text_edit::tick(vostok::ui::ui_text_edit *this)
{
  int v2; // eax
  vostok::timing::timer *v3; // ecx
  vostok::timing::timer *v4; // ecx
  double elapsed_sec; // st7
  vostok::memory::base_allocator *m_allocator; // ecx
  float v7; // [esp+4h] [ebp-4h]

  vostok::ui::ui_window::tick((vostok::ui::ui_window *)this);
  v2 = (*(int (__thiscall **)(unsigned __int16 *))(*(_DWORD *)&this[-1].m_sel_start + 20))(&this[-1].m_sel_start);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v2 + 56))(v2)
    && this->m_edit_actions._M_impl._M_end_of_storage.m_allocator )
  {
    v7 = *(float *)&this->m_edit_actions._M_impl._M_end_of_storage._M_data + 0.30000001;
    if ( vostok::timing::timer::get_elapsed_sec(v3, this->m_mode + 64) > v7 )
    {
      elapsed_sec = vostok::timing::timer::get_elapsed_sec(v4, this->m_mode + 64);
      m_allocator = this->m_edit_actions._M_impl._M_end_of_storage.m_allocator;
      *(float *)&this->m_edit_actions._M_impl._M_end_of_storage._M_data = elapsed_sec - 0.2;
      ((void (__thiscall *)(vostok::memory::base_allocator *, int))m_allocator->initialize)(m_allocator, 3);
    }
  }
}
