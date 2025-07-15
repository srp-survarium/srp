void __userpurge vostok::animation::mixing::n_ary_tree_comparer::new_weight_driving_animation(
        vostok::animation::mixing::n_ary_tree_comparer *this@<esi>,
        vostok::animation::mixing::n_ary_tree_animation_node *new_weight_driving_animation@<edi>,
        vostok::animation::mixing::n_ary_tree_animation_node *new_driving_animation_in_previous_target)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v3; // ebx
  bool v4; // al
  vostok::animation::mixing::animation_state *m_animation_state; // ecx
  vostok::animation::mixing::animation_state *v6; // eax
  bool v7; // al
  stlp_std::pair<unsigned int,unsigned int> v8; // [esp+4h] [ebp-18h] BYREF
  unsigned int v9; // [esp+Ch] [ebp-10h] BYREF
  unsigned int v10; // [esp+10h] [ebp-Ch] BYREF
  int v11; // [esp+14h] [ebp-8h] BYREF

  v3 = new_driving_animation_in_previous_target;
  if ( new_driving_animation_in_previous_target->m_weight_driving_animation )
    this->m_equal = 0;
  if ( new_weight_driving_animation->m_override_existing_animation
    && new_weight_driving_animation->m_animation_state->animation_time != v3->m_animation_state->animation_time )
  {
    this->m_equal = 0;
  }
  v3->m_weight_interpolator->accept(
    v3->m_weight_interpolator,
    (vostok::animation::interpolator_comparer *)&v11,
    new_weight_driving_animation->m_weight_interpolator);
  v4 = this->m_equal && !v11;
  this->m_equal = v4;
  if ( new_weight_driving_animation->m_override_existing_animation )
  {
    v7 = 0;
    if ( v4 )
    {
      m_animation_state = v3->m_animation_state;
      v6 = new_weight_driving_animation->m_animation_state;
      if ( m_animation_state->animation_interval_id == v6->animation_interval_id
        && m_animation_state->animation_interval_time == v6->animation_interval_time )
      {
        v7 = 1;
      }
    }
    this->m_equal = v7;
  }
  vostok::animation::mixing::computed_operands_count(v3, &v8, (int)new_weight_driving_animation);
  new_driving_animation_in_previous_target = (vostok::animation::mixing::n_ary_tree_animation_node *)v8.second;
  vostok::animation::mixing::n_ary_tree_comparer::new_animation(
    &v10,
    this,
    new_weight_driving_animation,
    (unsigned int *)&new_driving_animation_in_previous_target,
    &v9,
    (const void *)1);
  this->m_needed_buffer_size += 4 * ((_DWORD)new_driving_animation_in_previous_target + v8.first);
  vostok::animation::mixing::n_ary_tree_comparer::add_operands(v3, this, new_weight_driving_animation, v10 != 0);
}


void __userpurge vostok::animation::mixing::n_ary_tree_comparer::new_weight_driving_animation(
        vostok::animation::mixing::n_ary_tree_animation_node *animation@<eax>,
        BOOL this)
{
  vostok::animation::mixing::n_ary_tree_comparer *v2; // ebx
  bool v4; // zf
  const vostok::animation::base_interpolator *m_weight_interpolator; // edi
  double v6; // st6
  unsigned int v7; // edi
  const vostok::animation::base_interpolator *v8; // ecx
  float v9; // xmm0_4
  const boost::function<unsigned char __cdecl(void const *)> *m_animated_object_resolver; // eax
  vostok::animation::mixing::n_ary_tree_comparer **v11; // edi
  vostok::animation::mixing::n_ary_tree_comparer **v12; // esi
  vostok::animation::mixing::n_ary_tree_comparer *v13; // ecx
  _DWORD v14[2]; // [esp+10h] [ebp-2Ch] BYREF
  int v15; // [esp+18h] [ebp-24h]
  char v16; // [esp+1Ch] [ebp-20h]
  _DWORD v17[3]; // [esp+20h] [ebp-1Ch] BYREF
  unsigned int v18; // [esp+2Ch] [ebp-10h] BYREF
  BOOL v19; // [esp+30h] [ebp-Ch] BYREF
  const vostok::animation::base_interpolator *v20; // [esp+34h] [ebp-8h]

  v2 = (vostok::animation::mixing::n_ary_tree_comparer *)this;
  *(_BYTE *)(this + 36) = 0;
  v4 = animation->m_operands_count == 0;
  m_weight_interpolator = animation->m_weight_interpolator;
  v20 = m_weight_interpolator;
  this = !v4
      && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
          + 3))(animation[1].__vftable) != 0;
  v19 = this;
  v6 = ((double (__thiscall *)(const vostok::animation::base_interpolator *))m_weight_interpolator->transition_time)(m_weight_interpolator);
  v7 = (v6 != 0.0) + animation->m_operands_count - this;
  vostok::animation::mixing::n_ary_tree_comparer::new_animation(
    &v18,
    v2,
    animation,
    (unsigned int *)&v19,
    (unsigned int *)&this,
    (const void *)1);
  v8 = v20;
  v15 = 0;
  v9 = s_bm_current_air_resistance;
  m_animated_object_resolver = v2->m_animated_object_resolver;
  v2->m_needed_buffer_size += 4 * (v19 + v7);
  v14[1] = m_animated_object_resolver;
  v11 = (vostok::animation::mixing::n_ary_tree_comparer **)(&animation[1].__vftable + animation->m_operands_count);
  v12 = (vostok::animation::mixing::n_ary_tree_comparer **)(&animation[1].__vftable + this);
  v17[0] = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
  v17[1] = v8;
  *(float *)&v17[2] = v9;
  v14[0] = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v16 = 0;
  if ( v12 == v11 )
  {
LABEL_8:
    if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))v8->transition_time)(v8) != 0.0 )
    {
      v2->m_needed_buffer_size += 44;
      v2->m_equal = 0;
    }
  }
  else
  {
    while ( 1 )
    {
      v13 = *v12;
      v15 = 0;
      ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_comparer *, _DWORD *, _DWORD *))LODWORD(v13->m_animated_objects->transform.i.y))(
        v13,
        v14,
        v17);
      if ( v15 == 2 )
        break;
      vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(*v12++, (int)v2);
      if ( v12 == v11 )
      {
        v8 = v20;
        goto LABEL_8;
      }
    }
    if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))v20->transition_time)(v20) != 0.0 )
    {
      v2->m_needed_buffer_size += 44;
      v2->m_equal = 0;
    }
    while ( v12 != v11 )
      vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(*v12++, (int)v2);
  }
}
