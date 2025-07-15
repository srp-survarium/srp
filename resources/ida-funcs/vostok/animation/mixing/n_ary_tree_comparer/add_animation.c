void __usercall vostok::animation::mixing::n_ary_tree_comparer::add_animation(
        vostok::animation::mixing::n_ary_tree_comparer *this@<edi>,
        vostok::animation::mixing::n_ary_tree_animation_node *animation@<ecx>,
        vostok::animation::mixing::n_ary_tree_animation_node *const weight_driving_animation@<eax>)
{
  const vostok::animation::base_interpolator *m_weight_interpolator; // eax
  unsigned int m_operands_count; // ebx
  unsigned int v6; // ebx
  vostok::animation::mixing::n_ary_tree_comparer **v7; // ebx
  vostok::animation::mixing::n_ary_tree_comparer **i; // esi
  unsigned int v9; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v10; // [esp+10h] [ebp-10h] BYREF
  unsigned int v11; // [esp+14h] [ebp-Ch]
  const vostok::animation::base_interpolator *v12; // [esp+18h] [ebp-8h]
  BOOL v13; // [esp+1Ch] [ebp-4h] BYREF

  this->m_equal = 0;
  if ( weight_driving_animation )
    m_weight_interpolator = weight_driving_animation->m_weight_interpolator;
  else
    m_weight_interpolator = animation->m_weight_interpolator;
  m_operands_count = animation->m_operands_count;
  v12 = m_weight_interpolator;
  v13 = m_operands_count;
  if ( m_operands_count
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(animation[1].__vftable) )
  {
    --m_operands_count;
  }
  v11 = m_operands_count
      + (((double (__thiscall *)(const vostok::animation::base_interpolator *))v12->transition_time)(v12) != 0.0);
  v13 = v13
     && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
         + 3))(animation[1].__vftable);
  vostok::animation::mixing::n_ary_tree_comparer::new_animation(
    &v9,
    this,
    animation,
    (unsigned int *)&v13,
    &v10,
    (const void *)1);
  v6 = v13;
  if ( !v13 && animation->m_operands_count )
    v6 = (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
          + 3))(animation[1].__vftable) != 0;
  this->m_needed_buffer_size += 4 * (v11 + v6);
  v7 = (vostok::animation::mixing::n_ary_tree_comparer **)(&animation[1].__vftable + animation->m_operands_count);
  for ( i = (vostok::animation::mixing::n_ary_tree_comparer **)(&animation[1].__vftable + v10); i != v7; ++i )
    vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(*i, (int)this);
  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))v12->transition_time)(v12) != 0.0 )
  {
    this->m_needed_buffer_size += 44;
    this->m_equal = 0;
  }
}
