stlp_std::priv::_Rb_tree_node_base *__cdecl stlp_std::priv::_Rb_global<bool>::_M_increment(
        stlp_std::priv::_Rb_tree_node_base *_M_node)
{
  stlp_std::priv::_Rb_tree_node_base *v1; // ecx
  stlp_std::priv::_Rb_tree_node_base *result; // eax
  stlp_std::priv::_Rb_tree_node_base *i; // ecx

  v1 = _M_node;
  result = _M_node->_M_right;
  if ( result )
  {
    for ( i = result->_M_left; i; i = i->_M_left )
      result = i;
  }
  else
  {
    result = _M_node->_M_parent;
    if ( _M_node == result->_M_right )
    {
      do
      {
        v1 = result;
        result = result->_M_parent;
      }
      while ( v1 == result->_M_right );
    }
    if ( v1->_M_right == result )
      return v1;
  }
  return result;
}
