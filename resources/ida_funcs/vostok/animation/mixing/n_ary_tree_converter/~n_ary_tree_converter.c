void __thiscall vostok::animation::mixing::n_ary_tree_converter::~n_ary_tree_converter(
        vostok::animation::mixing::n_ary_tree_converter *this)
{
  vostok::animation::mixing::binary_tree_base_node *m_object; // eax

  m_object = this->m_root.m_object;
  if ( this->m_root.m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))this->m_root.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        this->m_root.m_object,
        0);
  }
}
