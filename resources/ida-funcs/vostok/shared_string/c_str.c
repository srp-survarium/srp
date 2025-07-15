vostok::strings::shared::profile *__thiscall vostok::shared_string::c_str(vostok::shared_string *this)
{
  if ( this->m_pointer.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    return this->m_pointer.m_object + 1;
  }
  else
  {
    return 0;
  }
}
