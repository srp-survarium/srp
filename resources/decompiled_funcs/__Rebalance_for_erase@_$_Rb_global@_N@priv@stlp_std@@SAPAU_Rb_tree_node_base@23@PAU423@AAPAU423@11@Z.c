stlp_std::priv::_Rb_tree_node_base *__cdecl stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
        stlp_std::priv::_Rb_tree_node_base *__z,
        stlp_std::priv::_Rb_tree_node_base **__root,
        stlp_std::priv::_Rb_tree_node_base **__leftmost,
        stlp_std::priv::_Rb_tree_node_base **__rightmost)
{
  stlp_std::priv::_Rb_tree_node_base *M_left; // esi
  stlp_std::priv::_Rb_tree_node_base *v5; // ebx
  stlp_std::priv::_Rb_tree_node_base *M_right; // ebp
  stlp_std::priv::_Rb_tree_node_base *M_parent; // esi
  stlp_std::priv::_Rb_tree_node_base *v8; // eax
  stlp_std::priv::_Rb_tree_node_base *k; // edx
  stlp_std::priv::_Rb_tree_node_base **v10; // edi
  stlp_std::priv::_Rb_tree_node_base *v11; // edx
  bool M_color; // dl
  stlp_std::priv::_Rb_tree_node_base *v13; // eax
  stlp_std::priv::_Rb_tree_node_base *v14; // eax
  stlp_std::priv::_Rb_tree_node_base *i; // edx
  stlp_std::priv::_Rb_tree_node_base *j; // ecx
  stlp_std::priv::_Rb_tree_node_base *v17; // eax
  stlp_std::priv::_Rb_tree_node_base *v18; // eax
  stlp_std::priv::_Rb_tree_node_base *v19; // eax
  stlp_std::priv::_Rb_tree_node_base *v20; // ecx
  stlp_std::priv::_Rb_tree_node_base *v21; // ecx
  stlp_std::priv::_Rb_tree_node_base *v22; // ecx
  stlp_std::priv::_Rb_tree_node_base *v23; // ecx
  stlp_std::priv::_Rb_tree_node_base *v24; // ecx
  stlp_std::priv::_Rb_tree_node_base *v25; // ecx
  stlp_std::priv::_Rb_tree_node_base *v26; // eax
  stlp_std::priv::_Rb_tree_node_base *v27; // eax
  stlp_std::priv::_Rb_tree_node_base *v28; // ecx
  stlp_std::priv::_Rb_tree_node_base *v29; // ecx
  stlp_std::priv::_Rb_tree_node_base *v30; // ecx
  stlp_std::priv::_Rb_tree_node_base *v31; // ecx
  stlp_std::priv::_Rb_tree_node_base *v32; // ecx
  stlp_std::priv::_Rb_tree_node_base *v33; // ecx
  stlp_std::priv::_Rb_tree_node_base *v34; // eax
  stlp_std::priv::_Rb_tree_node_base *result; // eax

  M_left = __z->_M_left;
  v5 = __z;
  if ( !M_left )
  {
    M_right = __z->_M_right;
LABEL_3:
    M_parent = v5->_M_parent;
    if ( M_right )
      M_right->_M_parent = M_parent;
    if ( *__root == __z )
    {
      *__root = M_right;
    }
    else
    {
      v13 = __z->_M_parent;
      if ( v13->_M_left == __z )
        v13->_M_left = M_right;
      else
        v13->_M_right = M_right;
    }
    if ( *__leftmost == __z )
    {
      if ( __z->_M_right )
      {
        v14 = M_right->_M_left;
        for ( i = M_right; v14; v14 = v14->_M_left )
          i = v14;
        *__leftmost = i;
      }
      else
      {
        *__leftmost = __z->_M_parent;
      }
    }
    if ( *__rightmost == __z )
    {
      if ( __z->_M_left )
      {
        v17 = M_right->_M_right;
        for ( j = M_right; v17; v17 = v17->_M_right )
          j = v17;
      }
      else
      {
        j = __z->_M_parent;
      }
      *__rightmost = j;
    }
    v10 = __root;
    goto LABEL_39;
  }
  v8 = __z->_M_right;
  if ( !v8 )
  {
    M_right = __z->_M_left;
    goto LABEL_3;
  }
  for ( k = v8->_M_left; k; k = k->_M_left )
    v8 = k;
  M_right = v8->_M_right;
  v5 = v8;
  if ( v8 == __z )
    goto LABEL_3;
  M_left->_M_parent = v8;
  v8->_M_left = __z->_M_left;
  if ( v8 == __z->_M_right )
  {
    M_parent = v8;
  }
  else
  {
    M_parent = v8->_M_parent;
    if ( M_right )
      M_right->_M_parent = M_parent;
    v8->_M_parent->_M_left = M_right;
    v8->_M_right = __z->_M_right;
    __z->_M_right->_M_parent = v8;
  }
  v10 = __root;
  if ( *__root == __z )
  {
    *__root = v8;
  }
  else
  {
    v11 = __z->_M_parent;
    if ( v11->_M_left == __z )
      v11->_M_left = v8;
    else
      v11->_M_right = v8;
  }
  v8->_M_parent = __z->_M_parent;
  M_color = v8->_M_color;
  v8->_M_color = __z->_M_color;
  __z->_M_color = M_color;
  v5 = __z;
LABEL_39:
  if ( !v5->_M_color )
    return v5;
  if ( M_right != *v10 )
  {
    while ( !M_right || M_right->_M_color )
    {
      v18 = M_parent->_M_left;
      if ( M_right == v18 )
      {
        v18 = M_parent->_M_right;
        if ( !v18->_M_color )
        {
          v18->_M_color = 1;
          v19 = M_parent->_M_right;
          M_parent->_M_color = 0;
          M_parent->_M_right = v19->_M_left;
          v20 = v19->_M_left;
          if ( v20 )
            v20->_M_parent = M_parent;
          v19->_M_parent = M_parent->_M_parent;
          if ( M_parent == *v10 )
          {
            *v10 = v19;
          }
          else
          {
            v21 = M_parent->_M_parent;
            if ( M_parent == v21->_M_left )
              v21->_M_left = v19;
            else
              v21->_M_right = v19;
          }
          v19->_M_left = M_parent;
          M_parent->_M_parent = v19;
          v18 = M_parent->_M_right;
        }
        v22 = v18->_M_left;
        if ( v22 && !v22->_M_color || (v23 = v18->_M_right) != 0 && !v23->_M_color )
        {
          v24 = v18->_M_right;
          if ( !v24 || v24->_M_color )
          {
            v25 = v18->_M_left;
            if ( v25 )
              v25->_M_color = 1;
            v18->_M_color = 0;
            stlp_std::priv::_Rb_global<bool>::_Rotate_right(v18, v10);
            v18 = M_parent->_M_right;
          }
          v18->_M_color = M_parent->_M_color;
          M_parent->_M_color = 1;
          v26 = v18->_M_right;
          if ( v26 )
            v26->_M_color = 1;
          stlp_std::priv::_Rb_global<bool>::_Rotate_left(M_parent, v10);
          break;
        }
      }
      else
      {
        if ( !v18->_M_color )
        {
          v18->_M_color = 1;
          v27 = M_parent->_M_left;
          M_parent->_M_color = 0;
          M_parent->_M_left = v27->_M_right;
          v28 = v27->_M_right;
          if ( v28 )
            v28->_M_parent = M_parent;
          v27->_M_parent = M_parent->_M_parent;
          if ( M_parent == *v10 )
          {
            *v10 = v27;
          }
          else
          {
            v29 = M_parent->_M_parent;
            if ( M_parent == v29->_M_right )
              v29->_M_right = v27;
            else
              v29->_M_left = v27;
          }
          v27->_M_right = M_parent;
          M_parent->_M_parent = v27;
          v18 = M_parent->_M_left;
        }
        v30 = v18->_M_right;
        if ( v30 && !v30->_M_color || (v31 = v18->_M_left) != 0 && !v31->_M_color )
        {
          v32 = v18->_M_left;
          if ( !v32 || v32->_M_color )
          {
            v33 = v18->_M_right;
            if ( v33 )
              v33->_M_color = 1;
            v18->_M_color = 0;
            stlp_std::priv::_Rb_global<bool>::_Rotate_left(v18, v10);
            v18 = M_parent->_M_left;
          }
          v18->_M_color = M_parent->_M_color;
          M_parent->_M_color = 1;
          v34 = v18->_M_left;
          if ( v34 )
            v34->_M_color = 1;
          stlp_std::priv::_Rb_global<bool>::_Rotate_right(M_parent, v10);
          break;
        }
      }
      M_right = M_parent;
      v18->_M_color = 0;
      M_parent = M_parent->_M_parent;
      if ( M_right == *v10 )
        break;
    }
  }
  result = v5;
  if ( M_right )
    M_right->_M_color = 1;
  return result;
}
