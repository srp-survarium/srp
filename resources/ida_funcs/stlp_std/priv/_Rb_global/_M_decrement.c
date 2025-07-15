stlp_std::priv::_Rb_tree_node_base *__cdecl stlp_std::priv::_Rb_global<bool>::_M_decrement(
        stlp_std::priv::_Rb_tree_node_base *_M_node)
{
  stlp_std::priv::_Rb_tree_node_base *result; // eax
  stlp_std::priv::_Rb_tree_node_base *i; // ecx
  stlp_std::priv::_Rb_tree_node_base *v3; // ecx

  if ( !_M_node->_M_color && _M_node->_M_parent->_M_parent == _M_node )
    return _M_node->_M_right;
  result = _M_node->_M_left;
  if ( result )
  {
    for ( i = result->_M_right; i; i = i->_M_right )
      result = i;
  }
  else
  {
    result = _M_node->_M_parent;
    if ( _M_node == result->_M_left )
    {
      do
      {
        v3 = result;
        result = result->_M_parent;
      }
      while ( v3 == result->_M_left );
    }
  }
  return result;
}
