vostok::animation::mixing::expression *__thiscall vostok::animation::skeleton_animation_scene_operator::make_animation_expression(
        vostok::animation::skeleton_animation_scene_operator *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer)
{
  stlp_std::pair<vostok::animation::skeleton_animation_scene_node_base *,vostok::animation::skeleton_animation_scene_operator_link *> *M_start; // eax
  vostok::animation::skeleton_animation_scene_node_base *v5; // ecx
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx
  unsigned int *p_m_reference_count; // eax
  vostok::animation::mixing::binary_tree_base_node *v8; // ecx
  bool v9; // zf
  vostok::animation::mixing::binary_tree_base_node *v10; // ecx
  vostok::animation::skeleton_animation_scene_node_base *first; // [esp+1Ch] [ebp-7Ch]
  unsigned int i; // [esp+1Ch] [ebp-7Ch]
  vostok::animation::mixing::expression v14; // [esp+20h] [ebp-78h] BYREF
  vostok::animation::mixing::expression v15; // [esp+28h] [ebp-70h] BYREF
  vostok::animation::mixing::expression other; // [esp+30h] [ebp-68h] BYREF
  vostok::animation::mixing::expression v17; // [esp+38h] [ebp-60h] BYREF
  vostok::animation::mixing::expression v18; // [esp+40h] [ebp-58h] BYREF
  vostok::animation::mixing::weight_lexeme v19; // [esp+48h] [ebp-50h] BYREF
  vostok::animation::mixing::weight_lexeme v20; // [esp+70h] [ebp-28h] BYREF

  M_start = this->m_children._M_impl._M_start;
  first = M_start->first;
  vostok::animation::mixing::weight_lexeme::weight_lexeme(
    &v19,
    buffer,
    M_start->second->m_weight_interpolator,
    M_start->second->m_weight);
  vostok::animation::mixing::expression::expression((vostok::animation::mixing::expression *)&v19, (int)&v18);
  first->make_animation_expression(first, &v15, buffer);
  vostok::animation::mixing::operator*(&v15, &v18, (int)result);
  for ( i = 1; i < this->m_children._M_impl._M_finish - this->m_children._M_impl._M_start; ++i )
  {
    vostok::animation::mixing::weight_lexeme::weight_lexeme(
      &v20,
      buffer,
      this->m_children._M_impl._M_start->second->m_weight_interpolator,
      this->m_children._M_impl._M_start[i].second->m_weight);
    vostok::animation::mixing::expression::expression((vostok::animation::mixing::expression *)&v20, (int)&v17);
    v5 = this->m_children._M_impl._M_start[i].first;
    v5->make_animation_expression(v5, &v14, buffer);
    vostok::animation::mixing::operator*(&v14, &v17, (int)&other);
    vostok::animation::mixing::expression::operator+=<vostok::animation::mixing::expression>(result, &other);
    m_object = other.m_node.m_object;
    if ( other.m_node.m_object )
    {
      --other.m_node.m_object->m_reference_count;
      if ( !m_object->m_reference_count )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
          m_object,
          0);
    }
    if ( v14.m_node.m_object )
    {
      p_m_reference_count = &v14.m_node.m_object->m_reference_count;
      --v14.m_node.m_object->m_reference_count;
      if ( !*p_m_reference_count )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v14.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
          v14.m_node.m_object,
          0);
    }
    v8 = v17.m_node.m_object;
    if ( v17.m_node.m_object )
    {
      --v17.m_node.m_object->m_reference_count;
      if ( !v8->m_reference_count )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v8->~vostok::animation::mixing::binary_tree_base_node)(
          v8,
          0);
    }
  }
  if ( v15.m_node.m_object )
  {
    v9 = v15.m_node.m_object->m_reference_count-- == 1;
    if ( v9 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v15.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        v15.m_node.m_object,
        0);
  }
  v10 = v18.m_node.m_object;
  if ( v18.m_node.m_object )
  {
    v9 = v18.m_node.m_object->m_reference_count-- == 1;
    if ( v9 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v10->~vostok::animation::mixing::binary_tree_base_node)(
        v10,
        0);
  }
  return result;
}
