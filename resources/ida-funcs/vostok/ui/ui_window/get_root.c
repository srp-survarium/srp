vostok::ui::ui_window *__thiscall vostok::ui::ui_window::get_root(vostok::ui::ui_window *this)
{
  if ( this->m_parent )
    return (vostok::ui::ui_window *)this->m_parent->get_root(this->m_parent);
  else
    return this;
}
