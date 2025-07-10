void __usercall vostok::animation::mixing::n_ary_tree_cloner::propagate<vostok::animation::mixing::n_ary_tree_multiplication_node>(
        vostok::animation::mixing::n_ary_tree_cloner *this@<edi>,
        vostok::animation::mixing::n_ary_tree_multiplication_node *node@<edx>)
{
  char *m_data; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v3; // ebp
  vostok::mutable_buffer *m_buffer; // eax
  unsigned int v5; // ecx
  vostok::mutable_buffer *v6; // eax
  vostok::animation::mixing::n_ary_tree_multiplication_node *v7; // esi
  vostok::animation::mixing::n_ary_tree_multiplication_node *v8; // ebx
  int v9; // ebp
  vostok::animation::mixing::n_ary_tree_base_node *v10; // [esp+Ch] [ebp-4h]

  m_data = this->m_constructor->m_buffer->m_data;
  if ( m_data )
  {
    *(_DWORD *)m_data = &vostok::animation::mixing::n_ary_tree_n_ary_operation_node::`vftable';
    v3 = (vostok::animation::mixing::n_ary_tree_base_node *)m_data;
    *((_DWORD *)m_data + 1) = node->m_operands_count;
    *(_DWORD *)m_data = &vostok::animation::mixing::n_ary_tree_multiplication_node::`vftable';
    v10 = (vostok::animation::mixing::n_ary_tree_base_node *)m_data;
  }
  else
  {
    v10 = 0;
    v3 = 0;
  }
  m_buffer = this->m_constructor->m_buffer;
  m_buffer->m_data += 8;
  m_buffer->m_size -= 8;
  v5 = 4 * node->m_operands_count;
  v6 = this->m_constructor->m_buffer;
  v6->m_data += v5;
  v6->m_size -= v5;
  v7 = node + 1;
  v8 = (vostok::animation::mixing::n_ary_tree_multiplication_node *)((char *)node + v5 + 8);
  if ( &node[1] == v8 )
  {
    this->m_result = v3;
  }
  else
  {
    v9 = (char *)v3 - (char *)node;
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_multiplication_node_vtbl *, vostok::animation::mixing::n_ary_tree_cloner *))v7->~vostok::animation::mixing::n_ary_tree_multiplication_node
       + 2))(
        v7->__vftable,
        this);
      *(vostok::animation::mixing::n_ary_tree_multiplication_node_vtbl **)((char *)&v7->__vftable + v9) = (vostok::animation::mixing::n_ary_tree_multiplication_node_vtbl *)this->m_result;
      v7 = (vostok::animation::mixing::n_ary_tree_multiplication_node *)((char *)v7 + 4);
    }
    while ( v7 != v8 );
    this->m_result = v10;
  }
}
