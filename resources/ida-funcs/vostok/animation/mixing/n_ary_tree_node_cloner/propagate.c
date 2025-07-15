void __usercall vostok::animation::mixing::n_ary_tree_node_cloner::propagate<vostok::animation::mixing::n_ary_tree_addition_node>(
        vostok::animation::mixing::n_ary_tree_node_cloner *this@<edi>,
        vostok::animation::mixing::n_ary_tree_addition_node *node@<edx>)
{
  char *m_data; // eax
  vostok::mutable_buffer *m_buffer; // eax
  vostok::mutable_buffer *v4; // eax
  unsigned int v5; // ecx
  vostok::animation::mixing::n_ary_tree_addition_node *v6; // esi
  vostok::animation::mixing::n_ary_tree_addition_node *v7; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *v8; // [esp+0h] [ebp-8h]
  int v9; // [esp+4h] [ebp-4h]

  m_data = this->m_constructor->m_buffer->m_data;
  if ( m_data )
  {
    *(_DWORD *)m_data = &vostok::animation::mixing::n_ary_tree_n_ary_operation_node::`vftable';
    *((_DWORD *)m_data + 1) = node->m_operands_count;
    *(_DWORD *)m_data = &vostok::animation::mixing::n_ary_tree_addition_node::`vftable';
    v8 = (vostok::animation::mixing::n_ary_tree_base_node *)m_data;
  }
  else
  {
    v8 = 0;
  }
  m_buffer = this->m_constructor->m_buffer;
  m_buffer->m_data += 8;
  m_buffer->m_size -= 8;
  v4 = this->m_constructor->m_buffer;
  v5 = 4 * node->m_operands_count;
  v4->m_data += v5;
  v4->m_size -= v5;
  v6 = node + 1;
  v7 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)node + v5 + 8);
  if ( &node[1] != v7 )
  {
    v9 = (char *)v8 - (char *)node;
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_addition_node_vtbl *, vostok::animation::mixing::n_ary_tree_node_cloner *))v6->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v6->__vftable,
        this);
      *(vostok::animation::mixing::n_ary_tree_addition_node_vtbl **)((char *)&v6->__vftable + v9) = (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)this->m_result;
      v6 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)v6 + 4);
    }
    while ( v6 != v7 );
  }
  this->m_result = v8;
}


void __usercall vostok::animation::mixing::n_ary_tree_node_cloner::propagate<vostok::animation::mixing::n_ary_tree_multiplication_node>(
        vostok::animation::mixing::n_ary_tree_node_cloner *this@<edi>,
        vostok::animation::mixing::n_ary_tree_multiplication_node *node@<edx>)
{
  char *m_data; // eax
  vostok::mutable_buffer *m_buffer; // eax
  vostok::mutable_buffer *v4; // eax
  unsigned int v5; // ecx
  vostok::animation::mixing::n_ary_tree_multiplication_node *v6; // esi
  vostok::animation::mixing::n_ary_tree_multiplication_node *v7; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *v8; // [esp+0h] [ebp-8h]
  int v9; // [esp+4h] [ebp-4h]

  m_data = this->m_constructor->m_buffer->m_data;
  if ( m_data )
  {
    *(_DWORD *)m_data = &vostok::animation::mixing::n_ary_tree_n_ary_operation_node::`vftable';
    *((_DWORD *)m_data + 1) = node->m_operands_count;
    *(_DWORD *)m_data = &vostok::animation::mixing::n_ary_tree_multiplication_node::`vftable';
    v8 = (vostok::animation::mixing::n_ary_tree_base_node *)m_data;
  }
  else
  {
    v8 = 0;
  }
  m_buffer = this->m_constructor->m_buffer;
  m_buffer->m_data += 8;
  m_buffer->m_size -= 8;
  v4 = this->m_constructor->m_buffer;
  v5 = 4 * node->m_operands_count;
  v4->m_data += v5;
  v4->m_size -= v5;
  v6 = node + 1;
  v7 = (vostok::animation::mixing::n_ary_tree_multiplication_node *)((char *)node + v5 + 8);
  if ( &node[1] != v7 )
  {
    v9 = (char *)v8 - (char *)node;
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_multiplication_node_vtbl *, vostok::animation::mixing::n_ary_tree_node_cloner *))v6->~vostok::animation::mixing::n_ary_tree_multiplication_node
       + 2))(
        v6->__vftable,
        this);
      *(vostok::animation::mixing::n_ary_tree_multiplication_node_vtbl **)((char *)&v6->__vftable + v9) = (vostok::animation::mixing::n_ary_tree_multiplication_node_vtbl *)this->m_result;
      v6 = (vostok::animation::mixing::n_ary_tree_multiplication_node *)((char *)v6 + 4);
    }
    while ( v6 != v7 );
  }
  this->m_result = v8;
}


void __usercall vostok::animation::mixing::n_ary_tree_node_cloner::propagate<vostok::animation::mixing::n_ary_tree_subtraction_node>(
        vostok::animation::mixing::n_ary_tree_node_cloner *this@<edi>,
        vostok::animation::mixing::n_ary_tree_subtraction_node *node@<edx>)
{
  char *m_data; // eax
  vostok::mutable_buffer *m_buffer; // eax
  vostok::mutable_buffer *v4; // eax
  unsigned int v5; // ecx
  vostok::animation::mixing::n_ary_tree_subtraction_node *v6; // esi
  vostok::animation::mixing::n_ary_tree_subtraction_node *v7; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *v8; // [esp+0h] [ebp-8h]
  int v9; // [esp+4h] [ebp-4h]

  m_data = this->m_constructor->m_buffer->m_data;
  if ( m_data )
  {
    *(_DWORD *)m_data = &vostok::animation::mixing::n_ary_tree_n_ary_operation_node::`vftable';
    *((_DWORD *)m_data + 1) = node->m_operands_count;
    *(_DWORD *)m_data = &vostok::animation::mixing::n_ary_tree_subtraction_node::`vftable';
    v8 = (vostok::animation::mixing::n_ary_tree_base_node *)m_data;
  }
  else
  {
    v8 = 0;
  }
  m_buffer = this->m_constructor->m_buffer;
  m_buffer->m_data += 8;
  m_buffer->m_size -= 8;
  v4 = this->m_constructor->m_buffer;
  v5 = 4 * node->m_operands_count;
  v4->m_data += v5;
  v4->m_size -= v5;
  v6 = node + 1;
  v7 = (vostok::animation::mixing::n_ary_tree_subtraction_node *)((char *)node + v5 + 8);
  if ( &node[1] != v7 )
  {
    v9 = (char *)v8 - (char *)node;
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_subtraction_node_vtbl *, vostok::animation::mixing::n_ary_tree_node_cloner *))v6->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v6->__vftable,
        this);
      *(vostok::animation::mixing::n_ary_tree_subtraction_node_vtbl **)((char *)&v6->__vftable + v9) = (vostok::animation::mixing::n_ary_tree_subtraction_node_vtbl *)this->m_result;
      v6 = (vostok::animation::mixing::n_ary_tree_subtraction_node *)((char *)v6 + 4);
    }
    while ( v6 != v7 );
  }
  this->m_result = v8;
}
