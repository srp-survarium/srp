void __cdecl stlp_std::priv::_Rb_global<bool>::_Rotate_right(
        stlp_std::priv::_Rb_tree_node_base *__x,
        stlp_std::priv::_Rb_tree_node_base **__root)
{
  stlp_std::priv::_Rb_tree_node_base *M_left; // eax
  stlp_std::priv::_Rb_tree_node_base *M_right; // edx
  stlp_std::priv::_Rb_tree_node_base *M_parent; // edx

  M_left = __x->_M_left;
  __x->_M_left = M_left->_M_right;
  M_right = M_left->_M_right;
  if ( M_right )
    M_right->_M_parent = __x;
  M_left->_M_parent = __x->_M_parent;
  if ( __x == *__root )
  {
    *__root = M_left;
    M_left->_M_right = __x;
    __x->_M_parent = M_left;
  }
  else
  {
    M_parent = __x->_M_parent;
    if ( __x == M_parent->_M_right )
      M_parent->_M_right = M_left;
    else
      M_parent->_M_left = M_left;
    M_left->_M_right = __x;
    __x->_M_parent = M_left;
  }
}
