void __thiscall vostok::ui::ui_text<vostok::ui::dynamic_text>::set_text(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this,
        char *text)
{
  char *m_begin; // eax
  vostok::ui::dynamic_text *p_m_text; // ecx
  char *v5; // eax

  m_begin = this->m_text.m_text.m_begin;
  p_m_text = &this->m_text;
  if ( !m_begin || strcmp(m_begin, text) )
  {
    v5 = p_m_text->m_text.m_begin;
    if ( p_m_text->m_text.m_begin != text )
    {
      p_m_text->m_text.m_end = v5;
      *v5 = 0;
      vostok::buffer_string::operator+=(&p_m_text->m_text, text);
    }
    vostok::ui::ui_window::emit_event(
      (vostok::ui::ui_window *)p_m_text,
      ev_text_changed,
      &this->vostok::ui::ui_window,
      0,
      0);
  }
}


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
