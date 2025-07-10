void __thiscall vostok::console_impl::~console_impl(vostok::console_impl *this)
{
  vostok::ui::world *m_ui_world; // eax
  vostok::ui::dialog *m_ui_dialog; // ecx
  void (__thiscall **p_destroy_window)(vostok::ui::world *, int); // edi
  int v5; // eax
  void (__thiscall **v6)(vostok::ui::world *, vostok::ui::window *); // edi
  vostok::ui::window *v7; // eax
  void **M_start; // edi
  void **i; // ebp
  void (__thiscall **v10)(vostok::ui::world *, vostok::ui::window *); // ebx
  int v11; // eax
  void **v12; // edi
  const void **j; // ebx

  m_ui_world = this->m_ui_world;
  m_ui_dialog = this->m_ui_dialog;
  this->__vftable = (vostok::console_impl_vtbl *)&vostok::console_impl::`vftable';
  p_destroy_window = (void (__thiscall **)(vostok::ui::world *, int))&m_ui_world->destroy_window;
  v5 = m_ui_dialog->w(m_ui_dialog);
  (*p_destroy_window)(this->m_ui_world, v5);
  v6 = &this->m_ui_world->destroy_window;
  v7 = this->m_ui_tips_view_hl->w(this->m_ui_tips_view_hl);
  (*v6)(this->m_ui_world, v7);
  M_start = this->m_text_items._M_impl._M_start;
  for ( i = this->m_text_items._M_impl._M_finish; M_start != i; ++M_start )
  {
    v10 = &this->m_ui_world->destroy_window;
    v11 = (*(int (__thiscall **)(void *))(*(_DWORD *)*M_start + 28))(*M_start);
    (*v10)(this->m_ui_world, (vostok::ui::window *)v11);
  }
  v12 = (void **)this->m_executed_history._M_impl._M_start;
  for ( j = this->m_executed_history._M_impl._M_finish; v12 != (void **)j; ++v12 )
  {
    if ( *v12 )
      this->m_allocator->call_free(this->m_allocator, *v12);
  }
  if ( this->m_tips._M_impl._M_start )
    this->m_tips._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_tips._M_impl._M_end_of_storage.m_allocator,
      this->m_tips._M_impl._M_start);
  if ( this->m_executed_history._M_impl._M_start )
    this->m_executed_history._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_executed_history._M_impl._M_end_of_storage.m_allocator,
      this->m_executed_history._M_impl._M_start);
  if ( this->m_text_items._M_impl._M_start )
    this->m_text_items._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_text_items._M_impl._M_end_of_storage.m_allocator,
      this->m_text_items._M_impl._M_start);
}
