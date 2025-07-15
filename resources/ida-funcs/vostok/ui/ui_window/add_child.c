void __userpurge vostok::ui::ui_window::add_child(
        vostok::ui::ui_window *this@<ecx>,
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > w)
{
  void **M_start; // esi

  M_start = w._M_start;
  (*((void (__thiscall **)(void **, vostok::ui::ui_window *))*w._M_start + 9))(w._M_start, this);
  (*((void (__thiscall **)(void **, void **))*M_start + 12))(M_start, w._M_finish);
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::push_back(
    &w,
    (stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *> > *)&this->m_children);
}
