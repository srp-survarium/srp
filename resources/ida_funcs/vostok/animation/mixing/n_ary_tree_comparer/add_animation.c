void __usercall vostok::animation::mixing::n_ary_tree_comparer::add_animation(
        vostok::animation::mixing::n_ary_tree_comparer *this@<edi>,
        vostok::animation::mixing::n_ary_tree_animation_node *animation@<ecx>,
        vostok::animation::mixing::n_ary_tree_animation_node *const weight_driving_animation@<eax>)
{
  const vostok::animation::base_interpolator *m_weight_interpolator; // eax
  unsigned int v5; // ebp
  unsigned int v6; // ebx
  BOOL v7; // eax
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl **v8; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl **i; // esi
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v10; // ecx
  void (__thiscall *v11)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, _DWORD *); // edx
  const vostok::animation::base_interpolator *v12; // [esp+Ch] [ebp-20h]
  unsigned int time_scale_operands_count; // [esp+10h] [ebp-1Ch] BYREF
  unsigned int operands_offset[2]; // [esp+14h] [ebp-18h] BYREF
  _DWORD v15[4]; // [esp+1Ch] [ebp-10h] BYREF

  this->m_equal = 0;
  if ( weight_driving_animation )
    m_weight_interpolator = weight_driving_animation->m_weight_interpolator;
  else
    m_weight_interpolator = animation->m_weight_interpolator;
  v12 = m_weight_interpolator;
  v5 = (((double (__thiscall *)(const vostok::animation::base_interpolator *))m_weight_interpolator->transition_time)(m_weight_interpolator) != 0.0)
     + animation->m_operands_count;
  time_scale_operands_count = 0;
  vostok::animation::mixing::n_ary_tree_comparer::new_animation(
    operands_offset,
    (vostok::animation::mixing::n_ary_tree_comparer *)&time_scale_operands_count,
    this,
    animation,
    &time_scale_operands_count);
  v6 = operands_offset[0];
  v7 = !v5
    || !operands_offset[0]
    || !(*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
         + 3))(animation[1].__vftable);
  if ( !(time_scale_operands_count + v7) )
    --v5;
  this->m_needed_buffer_size += 4 * v5;
  v8 = &animation[1].__vftable + animation->m_operands_count;
  for ( i = &animation[1].__vftable + v6; i != v8; ++i )
  {
    v10 = *i;
    v11 = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, _DWORD *))*((_DWORD *)(*i)->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node + 2);
    operands_offset[1] = (unsigned int)&vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
    v15[0] = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
    v15[1] = this;
    v15[2] = 0;
    v11(v10, v15);
  }
  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))v12->transition_time)(v12) != 0.0 )
  {
    this->m_needed_buffer_size += 44;
    this->m_equal = 0;
  }
}
