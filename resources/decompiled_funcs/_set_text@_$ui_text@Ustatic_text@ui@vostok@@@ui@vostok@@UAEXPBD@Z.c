void __thiscall vostok::ui::ui_text<vostok::ui::static_text>::set_text(
        vostok::ui::ui_text<vostok::ui::static_text> *this,
        const char *text)
{
  vostok::strings::shared::profile *m_object; // ecx
  vostok::ui::static_text *p_m_text; // edi
  const char *v5; // ecx
  vostok::ui::ui_window *v6; // ecx

  m_object = this->m_text.m_text.m_pointer.m_object;
  p_m_text = &this->m_text;
  if ( !m_object
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    || m_object == (vostok::strings::shared::profile *)-16
    || (!p_m_text->m_text.m_pointer.m_object ? (v5 = 0) : (v5 = (const char *)&p_m_text->m_text.m_pointer.m_object[1]),
        strcmp(v5, text)) )
  {
    vostok::ui::static_text::set(p_m_text);
    vostok::ui::ui_window::emit_event(v6, ev_text_changed, &this->vostok::ui::ui_window, 0, 0);
  }
}
