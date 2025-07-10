void __thiscall vostok::ui::ui_window::remove_all_children(vostok::ui::ui_window *this)
{
  vostok::vectora<vostok::ui::window *> *p_m_children; // esi
  vostok::ui::window **v3; // eax

  p_m_children = &this->m_children;
  if ( this->m_children._M_impl._M_start != this->m_children._M_impl._M_finish )
  {
    do
    {
      v3 = (vostok::ui::window **)stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::back(&p_m_children->_M_impl);
      this->remove_child(this, *v3);
    }
    while ( p_m_children->_M_impl._M_start != p_m_children->_M_impl._M_finish );
  }
}
