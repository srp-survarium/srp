void __thiscall vostok::console_impl::on_deactivate(vostok::console_impl *this)
{
  vostok::ui::window *v2; // eax
  vostok::ui::window *v3; // eax

  v2 = this->m_text_edit->w(this->m_text_edit);
  v2->set_focused(v2, 0);
  v3 = this->m_ui_view->w(this->m_ui_view);
  v3->set_focused(v3, 0);
  this->m_active = 0;
}
