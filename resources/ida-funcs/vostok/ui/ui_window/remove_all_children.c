void __thiscall vostok::ui::ui_window::remove_all_children(vostok::ui::ui_window *this)
{
  while ( this->m_children._M_impl._M_start != this->m_children._M_impl._M_finish )
    this->remove_child(this, (vostok::ui::window *)*((_DWORD *)this->m_children._M_impl._M_finish - 1));
}
