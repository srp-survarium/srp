void __usercall vostok::animation::mixing::n_ary_tree_weight_calculator::remove_transition(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this@<eax>,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node@<edi>)
{
  unsigned int m_start_time_in_ms; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *m_from; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation; // ecx
  _DWORD *v6; // eax
  unsigned int m_operands_count; // ecx
  _DWORD *v8; // ebx
  _DWORD *i; // edx
  _DWORD *v10; // ecx
  float v11; // [esp+0h] [ebp-10h]
  void **v12; // [esp+Ch] [ebp-4h] BYREF

  if ( this->m_weight == 0.0 )
  {
    m_start_time_in_ms = node->m_start_time_in_ms;
    v11 = ((double (__thiscall *)(const vostok::animation::base_interpolator *))node->m_interpolator->transition_time)(node->m_interpolator)
        * 1000.0;
    this->m_weight_transition_ended_time_in_ms = m_start_time_in_ms + vostok::math::floor(v11);
    this->m_null_weight_found = 1;
  }
  if ( this->m_animation )
  {
    this->m_result = node->m_to;
    m_from = node->m_from;
    v12 = &vostok::animation::mixing::n_ary_tree_destroyer::`vftable';
    m_from->accept(m_from, (vostok::animation::mixing::n_ary_tree_visitor *)&v12);
    ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_weight_transition_node *, _DWORD))node->~vostok::animation::mixing::n_ary_tree_base_node)(
      node,
      0);
    if ( this->m_recursion_level == 1 )
    {
      m_animation = this->m_animation;
      v6 = &m_animation[1].__vftable;
      m_operands_count = m_animation->m_operands_count;
      if ( this->m_weight == s_bm_current_air_resistance )
      {
        v8 = &v6[m_operands_count];
        for ( i = v6; i != v8; ++i )
        {
          if ( (vostok::animation::mixing::n_ary_tree_weight_transition_node *)*i != node )
            *v6++ = *i;
        }
        this->m_result->accept(this->m_result, (vostok::animation::mixing::n_ary_tree_visitor *)&v12);
        --this->m_animation->m_operands_count;
      }
      else
      {
        v10 = &v6[m_operands_count];
        while ( v6 != v10 )
        {
          if ( (vostok::animation::mixing::n_ary_tree_weight_transition_node *)*v6 == node )
            *v6 = this->m_result;
          ++v6;
        }
      }
    }
  }
  else
  {
    this->m_result = 0;
  }
}
