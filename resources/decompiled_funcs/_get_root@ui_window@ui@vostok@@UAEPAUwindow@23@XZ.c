vostok::ui::ui_window *__thiscall vostok::ui::ui_window::get_root(vostok::ui::ui_window *this)
{
  vostok::ui::ui_window *result; // eax

  result = this;
  if ( this->m_parent )
    return (vostok::ui::ui_window *)this->m_parent->get_root(this->m_parent);
  return result;
}
