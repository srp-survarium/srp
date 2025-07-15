void __thiscall vostok::ui::ui_window::remove_child(vostok::ui::ui_window *this, vostok::ui::window *w)
{
  void **M_finish; // edx
  vostok::vectora<vostok::ui::window *> *p_m_children; // esi
  void **M_start; // eax
  int i; // ecx
  vostok::memory::base_allocator *m_allocator; // esi
  _BYTE *v7; // edi

  M_finish = this->m_children._M_impl._M_finish;
  p_m_children = &this->m_children;
  M_start = this->m_children._M_impl._M_start;
  for ( i = ((char *)M_finish - (char *)M_start) >> 4; i > 0; --i )
  {
    if ( *M_start == w )
      goto LABEL_17;
    if ( *++M_start == w )
      goto LABEL_17;
    if ( *++M_start == w )
      goto LABEL_17;
    if ( *++M_start == w )
      goto LABEL_17;
    ++M_start;
  }
  switch ( M_finish - M_start )
  {
    case 1:
      goto LABEL_15;
    case 2:
LABEL_13:
      if ( *M_start == w )
        goto LABEL_17;
      ++M_start;
LABEL_15:
      if ( *M_start == w )
        goto LABEL_17;
      break;
    case 3:
      if ( *M_start == w )
        goto LABEL_17;
      ++M_start;
      goto LABEL_13;
  }
  M_start = M_finish;
LABEL_17:
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::erase(&p_m_children->_M_impl, M_start);
  if ( w->get_orphan(w) )
  {
    m_allocator = this->m_allocator;
    v7 = __RTCastToVoid((void **)&w->__vftable);
    ((void (__thiscall *)(vostok::ui::window *, _DWORD))w->~vostok::ui::window)(w, 0);
    m_allocator->call_free(m_allocator, v7, "vostok::ui::ui_window::remove_child", ".\\ui_window.cpp", 83u);
  }
  else
  {
    w->set_parent(w, 0);
  }
}
