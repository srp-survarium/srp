void __usercall vostok::animation::mixing::n_ary_tree_weight_calculator::remove_transition(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this@<eax>,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node@<edi>)
{
  unsigned int m_start_time_in_ms; // ebp
  vostok::animation::mixing::n_ary_tree_base_node *m_from; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation; // ecx
  vostok::animation::mixing::n_ary_tree_weight_transition_node **v6; // eax
  vostok::animation::mixing::n_ary_tree_weight_transition_node **v7; // edx
  vostok::animation::mixing::n_ary_tree_weight_transition_node **v8; // ecx
  vostok::animation::mixing::n_ary_tree_weight_transition_node **i; // ecx
  float value; // [esp+0h] [ebp-14h]
  vostok::animation::mixing::n_ary_tree_destroyer destroyer; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_weight == 0.0 )
  {
    m_start_time_in_ms = node->m_start_time_in_ms;
    value = ((double (__thiscall *)(const vostok::animation::base_interpolator *))node->m_interpolator->transition_time)(node->m_interpolator)
          * 1000.0;
    this->m_weight_transition_ended_time_in_ms = m_start_time_in_ms + vostok::math::floor(value);
    this->m_null_weight_found = 1;
  }
  if ( this->m_animation )
  {
    this->m_result = node->m_to;
    m_from = node->m_from;
    destroyer.__vftable = (vostok::animation::mixing::n_ary_tree_destroyer_vtbl *)&vostok::animation::mixing::n_ary_tree_destroyer::`vftable';
    m_from->accept(m_from, &destroyer);
    ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_weight_transition_node *, _DWORD))node->~vostok::animation::mixing::n_ary_tree_base_node)(
      node,
      0);
    if ( this->m_recursion_level == 1 )
    {
      m_animation = this->m_animation;
      v6 = (vostok::animation::mixing::n_ary_tree_weight_transition_node **)&m_animation[1];
      if ( this->m_weight == *(float *)&clear_value )
      {
        v7 = &v6[m_animation->m_operands_count];
        v8 = (vostok::animation::mixing::n_ary_tree_weight_transition_node **)&m_animation[1];
        if ( v6 != v7 )
        {
          do
          {
            if ( *v6 != node )
              *v6++ = *v8;
            ++v8;
          }
          while ( v8 != v7 );
        }
        --this->m_animation->m_operands_count;
      }
      else
      {
        for ( i = &v6[m_animation->m_operands_count]; v6 != i; ++v6 )
        {
          if ( *v6 == node )
            *v6 = (vostok::animation::mixing::n_ary_tree_weight_transition_node *)this->m_result;
        }
      }
    }
  }
  else
  {
    this->m_result = 0;
  }
}
