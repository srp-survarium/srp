void __usercall vostok::animation::mixing::expression::expression(
        vostok::animation::mixing::expression *this@<ecx>,
        vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **a2@<eax>)
{
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *v3; // edi
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *v4; // eax

  *a2 = 0;
  v3 = (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)vostok::animation::mixing::addition_lexeme::cloned_in_buffer((vostok::animation::mixing::addition_lexeme *)this);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    v3,
    a2);
  if ( v3 )
    v4 = v3 + 7;
  else
    v4 = 0;
  a2[1] = v4;
}


void __userpurge vostok::animation::mixing::expression::expression(
        vostok::animation::mixing::expression *this@<ecx>,
        vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **a2@<eax>,
        vostok::animation::mixing::animation_lexeme *lexeme)
{
  vostok::animation::mixing::animation_lexeme *v4; // edi
  vostok::animation::mixing::base_lexeme *v5; // eax

  *a2 = 0;
  v4 = vostok::animation::mixing::animation_lexeme::cloned_in_buffer(
         (vostok::animation::mixing::animation_lexeme *)this,
         lexeme);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)v4,
    a2);
  if ( v4 )
    v5 = &v4->vostok::animation::mixing::base_lexeme;
  else
    v5 = 0;
  a2[1] = (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)v5;
}


void __usercall vostok::animation::mixing::expression::expression(
        vostok::animation::mixing::expression *this@<ecx>,
        int a2@<eax>)
{
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *v3; // edi
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *v4; // eax

  *(_DWORD *)a2 = 0;
  v3 = (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)vostok::animation::mixing::weight_lexeme::cloned_in_buffer((vostok::animation::mixing::weight_lexeme *)this);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    v3,
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)a2);
  if ( v3 )
    v4 = v3 + 8;
  else
    v4 = 0;
  *(_DWORD *)(a2 + 4) = v4;
}


void __usercall vostok::animation::mixing::expression::expression(
        vostok::animation::mixing::expression *this@<eax>,
        const vostok::animation::mixing::expression *__that@<edx>)
{
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx

  this->m_node.m_object = 0;
  m_object = __that->m_node.m_object;
  if ( __that->m_node.m_object )
  {
    this->m_node.m_object = m_object;
    ++m_object->m_reference_count;
  }
  this->m_lexeme = __that->m_lexeme;
}
