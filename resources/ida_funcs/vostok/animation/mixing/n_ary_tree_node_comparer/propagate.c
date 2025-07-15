void __userpurge vostok::animation::mixing::n_ary_tree_node_comparer::propagate<vostok::animation::mixing::n_ary_tree_addition_node>(
        vostok::animation::mixing::n_ary_tree_addition_node *left@<ecx>,
        vostok::animation::mixing::n_ary_tree_addition_node *right@<eax>,
        vostok::animation::mixing::n_ary_tree_node_comparer *this)
{
  vostok::animation::mixing::n_ary_tree_addition_node *v4; // esi
  vostok::animation::mixing::n_ary_tree_addition_node *v5; // edi
  vostok::animation::mixing::n_ary_tree_addition_node *v6; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *const *j_e; // [esp+14h] [ebp+4h]

  v4 = left + 1;
  v5 = right + 1;
  v6 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)left + 4 * left->m_operands_count + 8);
  j_e = (vostok::animation::mixing::n_ary_tree_base_node *const *)(&right[1].__vftable + right->m_operands_count);
  if ( &left[1] == v6 )
    goto LABEL_5;
  while ( v5 != (vostok::animation::mixing::n_ary_tree_addition_node *)j_e )
  {
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_addition_node_vtbl *, vostok::animation::mixing::n_ary_tree_node_comparer *, vostok::animation::mixing::n_ary_tree_addition_node_vtbl *))v4->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 1))(
      v4->__vftable,
      this,
      v5->__vftable);
    if ( this->result )
      return;
    v4 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)v4 + 4);
    v5 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)v5 + 4);
    if ( v4 == v6 )
      goto LABEL_5;
  }
  if ( v4 == v6 )
  {
LABEL_5:
    if ( v5 != (vostok::animation::mixing::n_ary_tree_addition_node *)j_e )
      this->result = less;
  }
  else
  {
    this->result = more;
  }
}
