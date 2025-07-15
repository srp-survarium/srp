char *__thiscall vostok::ui::ui_text<vostok::ui::dynamic_text>::get_text(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this)
{
  return this->m_text.m_text.m_begin;
}


vostok::strings::shared::profile *__thiscall vostok::ui::ui_text<vostok::ui::static_text>::get_text(
        vostok::ui::ui_text<vostok::ui::static_text> *this)
{
  vostok::strings::shared::profile *m_object; // eax

  m_object = this->m_text.m_text.m_pointer.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    return m_object + 1;
  }
  else
  {
    return 0;
  }
}
