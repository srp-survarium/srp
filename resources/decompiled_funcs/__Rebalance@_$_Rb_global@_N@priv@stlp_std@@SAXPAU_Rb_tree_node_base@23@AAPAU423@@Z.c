void __cdecl stlp_std::priv::_Rb_global<bool>::_Rebalance(
        stlp_std::priv::_Rb_tree_node_base *__x,
        stlp_std::priv::_Rb_tree_node_base **__root)
{
  stlp_std::priv::_Rb_tree_node_base *v2; // eax
  stlp_std::priv::_Rb_tree_node_base *M_parent; // ecx
  stlp_std::priv::_Rb_tree_node_base *v4; // esi
  stlp_std::priv::_Rb_tree_node_base *M_left; // edx
  stlp_std::priv::_Rb_tree_node_base *M_right; // ecx
  stlp_std::priv::_Rb_tree_node_base *v7; // edx
  stlp_std::priv::_Rb_tree_node_base *v8; // edx
  stlp_std::priv::_Rb_tree_node_base *v9; // ecx
  stlp_std::priv::_Rb_tree_node_base *v10; // edx
  stlp_std::priv::_Rb_tree_node_base *v11; // esi
  stlp_std::priv::_Rb_tree_node_base *v12; // esi
  stlp_std::priv::_Rb_tree_node_base *v13; // ecx
  stlp_std::priv::_Rb_tree_node_base *v14; // edx
  stlp_std::priv::_Rb_tree_node_base *v15; // edx
  stlp_std::priv::_Rb_tree_node_base *v16; // esi
  stlp_std::priv::_Rb_tree_node_base *v17; // esi

  v2 = __x;
  __x->_M_color = 0;
  if ( __x == *__root )
  {
    (*__root)->_M_color = 1;
    return;
  }
  while ( 1 )
  {
    M_parent = v2->_M_parent;
    if ( M_parent->_M_color )
      break;
    v4 = M_parent->_M_parent;
    M_left = v4->_M_left;
    if ( M_parent == M_left )
    {
      M_left = v4->_M_right;
      if ( !M_left || M_left->_M_color )
      {
        if ( v2 == M_parent->_M_right )
        {
          v2 = v2->_M_parent;
          M_right = M_parent->_M_right;
          v2->_M_right = M_right->_M_left;
          v7 = M_right->_M_left;
          if ( v7 )
            v7->_M_parent = v2;
          M_right->_M_parent = v2->_M_parent;
          if ( v2 == *__root )
          {
            *__root = M_right;
          }
          else
          {
            v8 = v2->_M_parent;
            if ( v2 == v8->_M_left )
              v8->_M_left = M_right;
            else
              v8->_M_right = M_right;
          }
          M_right->_M_left = v2;
          v2->_M_parent = M_right;
        }
        v2->_M_parent->_M_color = 1;
        v2->_M_parent->_M_parent->_M_color = 0;
        v9 = v2->_M_parent->_M_parent;
        v10 = v9->_M_left;
        v9->_M_left = v10->_M_right;
        v11 = v10->_M_right;
        if ( v11 )
          v11->_M_parent = v9;
        v10->_M_parent = v9->_M_parent;
        if ( v9 == *__root )
        {
          *__root = v10;
          v10->_M_right = v9;
        }
        else
        {
          v12 = v9->_M_parent;
          if ( v9 == v12->_M_right )
            v12->_M_right = v10;
          else
            v12->_M_left = v10;
          v10->_M_right = v9;
        }
LABEL_43:
        v9->_M_parent = v10;
        goto LABEL_44;
      }
    }
    else if ( !M_left || M_left->_M_color )
    {
      if ( v2 == M_parent->_M_left )
      {
        v2 = v2->_M_parent;
        v13 = M_parent->_M_left;
        v2->_M_left = v13->_M_right;
        v14 = v13->_M_right;
        if ( v14 )
          v14->_M_parent = v2;
        v13->_M_parent = v2->_M_parent;
        if ( v2 == *__root )
        {
          *__root = v13;
        }
        else
        {
          v15 = v2->_M_parent;
          if ( v2 == v15->_M_right )
            v15->_M_right = v13;
          else
            v15->_M_left = v13;
        }
        v13->_M_right = v2;
        v2->_M_parent = v13;
      }
      v2->_M_parent->_M_color = 1;
      v2->_M_parent->_M_parent->_M_color = 0;
      v9 = v2->_M_parent->_M_parent;
      v10 = v9->_M_right;
      v9->_M_right = v10->_M_left;
      v16 = v10->_M_left;
      if ( v16 )
        v16->_M_parent = v9;
      v10->_M_parent = v9->_M_parent;
      if ( v9 == *__root )
      {
        *__root = v10;
      }
      else
      {
        v17 = v9->_M_parent;
        if ( v9 == v17->_M_left )
          v17->_M_left = v10;
        else
          v17->_M_right = v10;
      }
      v10->_M_left = v9;
      goto LABEL_43;
    }
    M_parent->_M_color = 1;
    M_left->_M_color = 1;
    v2->_M_parent->_M_parent->_M_color = 0;
    v2 = v2->_M_parent->_M_parent;
LABEL_44:
    if ( v2 == *__root )
    {
      (*__root)->_M_color = 1;
      return;
    }
  }
  (*__root)->_M_color = 1;
}
