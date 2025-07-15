void __userpurge vostok::animation::mixing::binary_tree_expression_simplifier::process_null_weight(
        vostok::animation::mixing::binary_tree_expression_simplifier *this@<edi>,
        const vostok::animation::mixing::binary_tree_expression_simplifier *left_simplifier@<ecx>,
        const vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *a3@<esi>,
        const vostok::animation::mixing::binary_tree_expression_simplifier *operation,
        const vostok::animation::mixing::binary_tree_expression_simplifier *right_simplifier)
{
  vostok::animation::mixing::binary_tree_weight_node *m_object; // edx
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *p_m_result_weight; // ebx
  float m_weight; // xmm0_4
  vostok::animation::mixing::binary_tree_base_node *v8; // ecx
  bool v9; // zf
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> v10; // ebx
  vostok::animation::mixing::binary_tree_weight_node *v11; // eax
  vostok::animation::mixing::binary_tree_weight_node *v12; // ecx
  vostok::animation::mixing::binary_tree_weight_node *v13; // edx
  float v14; // xmm0_4
  vostok::animation::mixing::binary_tree_base_node *v15; // ecx
  vostok::animation::mixing::binary_tree_weight_node *v16; // ecx
  vostok::animation::mixing::binary_tree_weight_node *v17; // eax
  const vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *v18; // [esp-Ch] [ebp-Ch]
  const vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *v19; // [esp-Ch] [ebp-Ch]

  m_object = left_simplifier->m_result_weight.m_object;
  p_m_result_weight = (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&left_simplifier->m_result_weight;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_weight = m_object->m_weight;
    if ( m_weight == 0.0 )
    {
      ++m_object->m_reference_count;
      v8 = this->m_result.m_object;
      this->m_result.m_object = m_object;
      if ( v8 )
      {
        v9 = v8->m_reference_count-- == 1;
        if ( v9 )
          ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v8->~vostok::animation::mixing::binary_tree_base_node)(
            v8,
            0);
      }
      v10.m_object = p_m_result_weight->m_object;
      v11 = 0;
      if ( v10.m_object )
      {
        v11 = (vostok::animation::mixing::binary_tree_weight_node *)v10.m_object;
        ++v10.m_object->m_reference_count;
      }
      v12 = this->m_result_weight.m_object;
      this->m_result_weight.m_object = v11;
      if ( v12 )
      {
        v9 = v12->m_reference_count-- == 1;
        if ( v9 )
        {
LABEL_11:
          ((void (__thiscall *)(vostok::animation::mixing::binary_tree_weight_node *, _DWORD))v12->~vostok::animation::mixing::binary_tree_base_node)(
            v12,
            0);
          return;
        }
      }
      return;
    }
    if ( m_weight == *(float *)&clear_value )
    {
      vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
        &operation->m_result,
        a3);
      vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
        (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&operation->m_result_weight,
        v18);
      return;
    }
  }
  v13 = operation->m_result_weight.m_object;
  if ( v13
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v14 = v13->m_weight;
    if ( v14 == 0.0 )
    {
      ++v13->m_reference_count;
      v15 = this->m_result.m_object;
      this->m_result.m_object = v13;
      if ( v15 )
      {
        v9 = v15->m_reference_count-- == 1;
        if ( v9 )
          ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v15->~vostok::animation::mixing::binary_tree_base_node)(
            v15,
            0);
      }
      v16 = operation->m_result_weight.m_object;
      v17 = 0;
      if ( v16 )
      {
        v17 = operation->m_result_weight.m_object;
        ++v16->m_reference_count;
      }
      v12 = this->m_result_weight.m_object;
      this->m_result_weight.m_object = v17;
      if ( v12 )
      {
        v9 = v12->m_reference_count-- == 1;
        if ( v9 )
          goto LABEL_11;
      }
    }
    else if ( v14 == *(float *)&clear_value )
    {
      vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
        &left_simplifier->m_result,
        a3);
      vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
        p_m_result_weight,
        v19);
    }
  }
}
