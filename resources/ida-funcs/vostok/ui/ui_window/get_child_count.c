int __thiscall vostok::ui::ui_window::get_child_count(vostok::ui::ui_window *this)
{
  return this->m_children._M_impl._M_finish - this->m_children._M_impl._M_start;
}
