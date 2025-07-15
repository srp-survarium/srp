void __thiscall vostok::console_impl::on_activate(vostok::console_impl *this)
{
  vostok::ui::window *v2; // eax

  v2 = this->m_text_edit->w(this->m_text_edit);
  v2->set_focused(v2, 1);
  this->m_active = 1;
}
