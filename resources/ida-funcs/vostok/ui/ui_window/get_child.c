vostok::ui::window *__thiscall vostok::ui::ui_window::get_child(vostok::ui::ui_window *this, unsigned int idx)
{
  return (vostok::ui::window *)this->m_children._M_impl._M_start[idx];
}
