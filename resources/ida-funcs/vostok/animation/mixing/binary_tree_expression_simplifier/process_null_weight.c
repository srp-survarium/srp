void __userpurge vostok::animation::mixing::binary_tree_expression_simplifier::process_null_weight(
        vostok::animation::mixing::binary_tree_expression_simplifier *this@<edi>,
        const vostok::animation::mixing::binary_tree_expression_simplifier *left_simplifier@<eax>,
        const stlp_std::multiplies<float> *operation,
        const vostok::animation::mixing::binary_tree_expression_simplifier *right_simplifier)
{
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *p_m_result_weight; // ebx
  vostok::animation::mixing::binary_tree_weight_node *m_object; // ecx
  float m_weight; // xmm0_4
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *v8; // ecx
  int v9; // ecx
  float v10; // xmm0_4
  const stlp_std::multiplies<float> *v11; // [esp+8h] [ebp+8h]

  p_m_result_weight = &left_simplifier->m_result_weight;
  m_object = left_simplifier->m_result_weight.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_weight = m_object->m_weight;
    if ( m_weight == 0.0 )
    {
      vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
        (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)m_object,
        (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)&this->m_result);
LABEL_13:
      v8 = p_m_result_weight;
      goto LABEL_14;
    }
    if ( m_weight == s_bm_current_air_resistance )
    {
      vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
        (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&operation[8],
        (vostok::animation::mixing::binary_tree_weight_node **)&this->m_result);
      v8 = (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&operation[12];
      goto LABEL_14;
    }
  }
  v9 = *(_DWORD *)&operation[12].stlp_std::binary_function<float,float,float>;
  v11 = operation + 12;
  if ( v9
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v10 = *(float *)(v9 + 24);
    if ( v10 != 0.0 )
    {
      if ( v10 != s_bm_current_air_resistance )
        return;
      vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
        (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&left_simplifier->m_result,
        (vostok::animation::mixing::binary_tree_weight_node **)&this->m_result);
      goto LABEL_13;
    }
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)v9,
      (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)&this->m_result);
    v8 = (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)v11;
LABEL_14:
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
      v8,
      &this->m_result_weight.m_object);
  }
}
