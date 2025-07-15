void __thiscall vostok::console_impl::~console_impl(vostok::console_impl *this)
{
  vostok::ui::world *m_ui_world; // eax
  vostok::ui::dialog *m_ui_dialog; // ecx
  void (__thiscall **p_destroy_window)(vostok::ui::world *, int); // edi
  int v5; // eax
  void (__thiscall **v6)(vostok::ui::world *, vostok::ui::window *); // edi
  vostok::ui::window *v7; // eax
  vostok::memory::base_allocator *m_allocator; // ecx
  vostok::vectora<vostok::ui::text *> *p_m_text_items; // edi
  void **M_start; // ebx
  void (__thiscall **v11)(vostok::ui::world *, vostok::ui::window *); // edi
  int v12; // eax
  const void **v13; // ebx
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *v14; // ecx
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *v15; // ecx
  const void **i; // [esp+Ch] [ebp-8h]
  void **M_finish; // [esp+10h] [ebp-4h]

  m_ui_world = this->m_ui_world;
  m_ui_dialog = this->m_ui_dialog;
  this->__vftable = (vostok::console_impl_vtbl *)&vostok::console_impl::`vftable';
  p_destroy_window = (void (__thiscall **)(vostok::ui::world *, int))&m_ui_world->destroy_window;
  v5 = m_ui_dialog->w(m_ui_dialog);
  (*p_destroy_window)(this->m_ui_world, v5);
  v6 = &this->m_ui_world->destroy_window;
  v7 = this->m_ui_tips_view_hl->w(this->m_ui_tips_view_hl);
  (*v6)(this->m_ui_world, v7);
  p_m_text_items = &this->m_text_items;
  M_start = this->m_text_items._M_impl._M_start;
  M_finish = this->m_text_items._M_impl._M_finish;
  if ( M_start != M_finish )
  {
    do
    {
      v11 = &this->m_ui_world->destroy_window;
      v12 = (*(int (__thiscall **)(void *))(*(_DWORD *)*M_start + 28))(*M_start);
      (*v11)(this->m_ui_world, (vostok::ui::window *)v12);
      ++M_start;
    }
    while ( M_start != M_finish );
    p_m_text_items = &this->m_text_items;
  }
  v13 = this->m_executed_history._M_impl._M_start;
  for ( i = this->m_executed_history._M_impl._M_finish; v13 != i; ++v13 )
  {
    m_allocator = this->m_allocator;
    if ( *v13 )
      m_allocator->call_free(
        m_allocator,
        (void *)*v13,
        "vostok::console_impl::~console_impl",
        ".\\console_impl.cpp",
        119u);
  }
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(
    (stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *)m_allocator,
    (int)&this->m_tips);
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(
    v14,
    (int)&this->m_executed_history);
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
    v15,
    (int)p_m_text_items);
}
