void __thiscall vostok::ui::ui_window::tick(vostok::ui::ui_window *this)
{
  void **M_finish; // ebx
  void **i; // esi
  void *v3; // edi

  M_finish = this->m_children._M_impl._M_finish;
  for ( i = this->m_children._M_impl._M_start; i != M_finish; ++i )
  {
    v3 = *i;
    if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)*i + 20))(*i) )
      (*(void (__thiscall **)(void *))(*(_DWORD *)v3 + 28))(v3);
  }
}
