vostok::animation::mixing::expression *__userpurge vostok::animation::mixing::expression::operator+=<vostok::animation::mixing::expression const>@<eax>(
        vostok::animation::mixing::expression *this@<ecx>,
        vostok::animation::mixing::expression *a2@<eax>,
        const vostok::animation::mixing::expression *other)
{
  vostok::animation::mixing::expression *v4; // edi
  vostok::animation::mixing::expression v7; // [esp+8h] [ebp-8h] BYREF

  v4 = vostok::animation::mixing::operator+(a2, other, &v7);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)v4,
    (vostok::animation::mixing::binary_tree_weight_node **)a2);
  a2->m_lexeme = v4->m_lexeme;
  if ( v7.m_node.m_object )
  {
    if ( v7.m_node.m_object->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v7.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        v7.m_node.m_object,
        0);
  }
  return a2;
}


vostok::animation::mixing::expression *__userpurge vostok::animation::mixing::expression::operator+=<vostok::animation::mixing::animation_lexeme>@<eax>(
        vostok::animation::mixing::expression *this@<ecx>,
        vostok::animation::mixing::expression *a2@<eax>,
        vostok::animation::mixing::animation_lexeme *other)
{
  vostok::animation::mixing::animation_lexeme *v4; // ebx
  int v7; // [esp+Ch] [ebp-8h] BYREF

  v4 = vostok::animation::mixing::operator+<vostok::animation::mixing::animation_lexeme>(
         a2,
         (vostok::animation::mixing::animation_lexeme *)this,
         (vostok::animation::mixing::animation_lexeme *)&v7,
         other);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)v4,
    (vostok::animation::mixing::binary_tree_weight_node **)a2);
  a2->m_lexeme = (vostok::animation::mixing::base_lexeme *)v4->m_next_weight;
  if ( v7 )
  {
    if ( (*(_DWORD *)(v7 + 16))-- == 1 )
      (**(void (__thiscall ***)(int, _DWORD))v7)(v7, 0);
  }
  return a2;
}


vostok::animation::mixing::expression *__usercall vostok::animation::mixing::expression::operator+=<vostok::animation::mixing::expression>@<eax>(
        vostok::animation::mixing::expression *this@<ecx>,
        vostok::animation::mixing::expression *other@<eax>)
{
  vostok::animation::mixing::binary_tree_weight_node *m_object; // edi
  vostok::animation::mixing::binary_tree_weight_node *v4; // ecx
  vostok::animation::mixing::base_lexeme *m_lexeme; // eax
  vostok::animation::mixing::addition_lexeme *v6; // eax
  vostok::animation::mixing::expression *v7; // eax
  vostok::animation::mixing::addition_lexeme v10; // [esp+8h] [ebp-2Ch] BYREF
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> v11; // [esp+2Ch] [ebp-8h] BYREF
  vostok::animation::mixing::base_lexeme *v12; // [esp+30h] [ebp-4h]

  m_object = (vostok::animation::mixing::binary_tree_weight_node *)this->m_node.m_object;
  if ( this->m_node.m_object && this->m_lexeme )
  {
    if ( other->m_node.m_object && other->m_lexeme )
    {
      vostok::animation::mixing::addition_lexeme::addition_lexeme(&v10, other, this);
      v7 = (vostok::animation::mixing::expression *)vostok::animation::mixing::addition_lexeme::cloned_in_buffer(v6);
      vostok::animation::mixing::expression::expression(
        v7,
        (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)&v11);
      vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v10.m_right);
      vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v10.m_left);
      m_object = v11.m_object;
      goto LABEL_11;
    }
    ++m_object->m_reference_count;
    m_lexeme = this->m_lexeme;
    v11.m_object = m_object;
  }
  else
  {
    v4 = (vostok::animation::mixing::binary_tree_weight_node *)other->m_node.m_object;
    m_object = 0;
    v11.m_object = 0;
    if ( v4 )
    {
      m_object = v4;
      ++v4->m_reference_count;
      v11.m_object = v4;
    }
    m_lexeme = other->m_lexeme;
  }
  v12 = m_lexeme;
LABEL_11:
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    &v11,
    (vostok::animation::mixing::binary_tree_weight_node **)this);
  this->m_lexeme = v12;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_weight_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
        m_object,
        0);
  }
  return this;
}
