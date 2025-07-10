void __cdecl stlp_std::priv::_Rb_global<bool>::_Rotate_left(
        stlp_std::priv::_Rb_tree_node_base *__x,
        stlp_std::priv::_Rb_tree_node_base **__root)
{
  stlp_std::priv::_Rb_tree_node_base *M_right; // eax
  stlp_std::priv::_Rb_tree_node_base *M_left; // edx
  stlp_std::priv::_Rb_tree_node_base *M_parent; // edx

  M_right = __x->_M_right;
  __x->_M_right = M_right->_M_left;
  M_left = M_right->_M_left;
  if ( M_left )
    M_left->_M_parent = __x;
  M_right->_M_parent = __x->_M_parent;
  if ( __x == *__root )
  {
    *__root = M_right;
    M_right->_M_left = __x;
    __x->_M_parent = M_right;
  }
  else
  {
    M_parent = __x->_M_parent;
    if ( __x == M_parent->_M_left )
      M_parent->_M_left = M_right;
    else
      M_parent->_M_right = M_right;
    M_right->_M_left = __x;
    __x->_M_parent = M_right;
  }
}
