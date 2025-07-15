vostok::animation::mixing::n_ary_tree_animation_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_driving_animation@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_animation_node *new_driving_animation_in_previous_target@<eax>,
        fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> new_weight_driving_animation)
{
  vostok::animation::mixing::n_ary_tree_animation_node *m_pthis; // ebx
  vostok::mutable_buffer *m_buffer; // eax
  char *m_data; // edx
  int v8; // ecx
  stlp_std::pair<unsigned int,unsigned int> v10; // [esp+18h] [ebp-1Ch] BYREF
  vostok::animation::mixing::animation_interval v11; // [esp+20h] [ebp-14h] BYREF

  m_pthis = (vostok::animation::mixing::n_ary_tree_animation_node *)new_weight_driving_animation.m_Closure.m_pthis;
  vostok::animation::mixing::computed_operands_count(
    new_driving_animation_in_previous_target,
    (int)this->m_animated_object_resolver,
    &v10,
    (int)new_weight_driving_animation.m_Closure.m_pthis);
  new_weight_driving_animation.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v10.second;
  LOBYTE(v11.m_start_time) = m_pthis->m_is_transitting_to_zero;
  v11.m_first_view_animation.m_object = (vostok::resources::managed_resource *)vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation(
                                                                                 m_pthis,
                                                                                 (unsigned int *)&v11.m_start_time,
                                                                                 (const vostok::animation::base_interpolator *)this,
                                                                                 new_driving_animation_in_previous_target,
                                                                                 0,
                                                                                 v10.first,
                                                                                 &new_weight_driving_animation,
                                                                                 &v11,
                                                                                 (unsigned int *)&v11.m_third_view_animation,
                                                                                 (float *)&v11.m_animation_id,
                                                                                 SLOBYTE(v11.m_start_time),
                                                                                 (vostok::animation::mixing::n_ary_tree_animation_node *)1);
  m_buffer = this->m_buffer;
  m_data = m_buffer->m_data;
  v8 = 4 * (int)&new_weight_driving_animation.m_Closure.m_pthis[v10.first];
  m_buffer->m_data += v8;
  m_buffer->m_size -= v8;
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_operands(
    (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)&m_data[v8],
    (vostok::animation::mixing::n_ary_tree_addition_node *)this,
    new_driving_animation_in_previous_target,
    (vostok::animation::mixing::n_ary_tree_base_node **)m_pthis,
    (vostok::animation::mixing::n_ary_tree_base_node **)&m_data[4 * LODWORD(v11.m_start_time)],
    (vostok::animation::mixing::n_ary_tree_base_node **)&m_data[v8],
    LODWORD(v11.m_start_time) != 0);
  return vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node(
           this,
           new_driving_animation_in_previous_target->m_animation_state,
           (vostok::animation::mixing::n_ary_tree_animation_node *)v11.m_first_view_animation.m_object,
           (unsigned int)v11.m_third_view_animation.m_object,
           *(float *)&v11.m_animation_id,
           0);
}


vostok::animation::mixing::n_ary_tree_animation_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_driving_animation@<eax>(
        vostok::animation::mixing::n_ary_tree_animation_node *animation@<eax>,
        fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> this)
{
  fastdelegate::detail::GenericClass *m_pthis; // ebx
  const vostok::animation::base_interpolator *m_weight_interpolator; // ecx
  BOOL v5; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // eax
  vostok::animation::base_interpolator v7; // eax
  unsigned int v8; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v9; // eax
  float v10; // xmm0_4
  int *v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // edi
  vostok::animation::mixing::n_ary_tree_base_node **v15; // eax
  vostok::animation::mixing::n_ary_tree_base_node **v16; // edi
  vostok::animation::mixing::n_ary_tree_base_node *v17; // ecx
  bool v18; // al
  vostok::animation::mixing::n_ary_tree_node_cloner *v19; // ecx
  vostok::animation::mixing::n_ary_tree_addition_node *v20; // esi
  unsigned int v21; // eax
  fastdelegate::detail::GenericClass *v22; // ecx
  const vostok::animation::base_interpolator *v23; // esi
  vostok::animation::mixing::n_ary_tree_node_cloner *v24; // ecx
  const vostok::animation::base_interpolator *v25; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v26; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v27; // eax
  const vostok::animation::base_interpolator *v29; // esi
  vostok::animation::mixing::n_ary_tree_node_cloner *v30; // ecx
  const vostok::animation::base_interpolator *v31; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v32; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v33; // eax
  fastdelegate::detail::GenericClass *v34; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v35; // eax
  fastdelegate::detail::GenericClass *v36; // ecx
  vostok::animation::mixing::n_ary_tree_node_comparer v37; // [esp+0h] [ebp-5Ch]
  bool v38; // [esp+10h] [ebp-4Ch]
  float v39; // [esp+10h] [ebp-4Ch]
  float v40; // [esp+10h] [ebp-4Ch]
  float v41; // [esp+14h] [ebp-48h]
  _DWORD v42[2]; // [esp+20h] [ebp-3Ch] BYREF
  int v43; // [esp+28h] [ebp-34h]
  char v44; // [esp+2Ch] [ebp-30h]
  _DWORD v45[3]; // [esp+30h] [ebp-2Ch] BYREF
  vostok::animation::mixing::n_ary_tree_animation_node *v46; // [esp+3Ch] [ebp-20h]
  vostok::animation::mixing::n_ary_tree_node_comparer __comp; // [esp+40h] [ebp-1Ch] BYREF
  vostok::animation::mixing::n_ary_tree_base_node **__last; // [esp+50h] [ebp-Ch] BYREF
  const vostok::animation::base_interpolator *interpolator; // [esp+54h] [ebp-8h]

  m_pthis = this.m_Closure.m_pthis;
  m_weight_interpolator = animation->m_weight_interpolator;
  v5 = 0;
  v6 = animation + 1;
  interpolator = m_weight_interpolator;
  *(_DWORD *)&__comp.m_compare_dynamic_members = v6;
  if ( animation->m_operands_count )
  {
    v5 = (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v6->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
          + 3))(v6->__vftable) != 0;
    m_weight_interpolator = interpolator;
  }
  v7.__vftable = m_weight_interpolator->__vftable;
  this.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v5;
  v8 = animation->m_operands_count
     + (((double (__thiscall *)(const vostok::animation::base_interpolator *))v7.transition_time)(m_weight_interpolator) != 0.0)
     - v5;
  v9 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation(
         animation,
         (unsigned int *)&__last,
         (const vostok::animation::base_interpolator *)m_pthis,
         animation,
         0,
         v8,
         &this,
         (const vostok::animation::mixing::animation_interval *)&__comp.result,
         (unsigned int *)&__comp,
         (float *)&__comp.m_animated_object_resolver,
         0,
         (vostok::animation::mixing::n_ary_tree_animation_node *)1);
  v10 = s_bm_current_air_resistance;
  v46 = v9;
  v11 = *(int **)&m_pthis[68];
  v12 = *v11;
  v13 = (int)&this.m_Closure.m_pthis[v8];
  v14 = *(_DWORD *)&__comp.m_compare_dynamic_members;
  v13 *= 4;
  *v11 += v13;
  v11[1] -= v13;
  v43 = 0;
  this.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)(v12 + 4 * (_DWORD)__last);
  v45[1] = interpolator;
  v42[1] = *(_DWORD *)&m_pthis[80];
  v15 = (vostok::animation::mixing::n_ary_tree_base_node **)(v14 + 4 * animation->m_operands_count);
  v16 = (vostok::animation::mixing::n_ary_tree_base_node **)(v14 + 4 * __comp.result);
  v45[0] = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
  *(float *)&v45[2] = v10;
  v42[0] = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v44 = 0;
  __last = v15;
  if ( v16 == v15 )
  {
LABEL_9:
    v23 = interpolator;
    if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))interpolator->transition_time)(interpolator) != 0.0 )
    {
      v25 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v24, (int)&m_pthis[32], v23, v38);
      v27 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
              v26,
              (int)m_pthis,
              v25,
              v39,
              v41);
      *(_DWORD *)this.m_Closure.m_pthis = v27;
    }
  }
  else
  {
    while ( 1 )
    {
      v17 = *v16;
      v43 = 0;
      v17->accept(
        v17,
        (vostok::animation::mixing::n_ary_tree_double_dispatcher *)v42,
        (vostok::animation::mixing::n_ary_tree_base_node *)v45);
      if ( v43 == 2 )
        break;
      v18 = (*v16)->is_time_scale(*v16);
      v19 = (vostok::animation::mixing::n_ary_tree_node_cloner *)*v16;
      v20 = (vostok::animation::mixing::n_ary_tree_addition_node *)&m_pthis[32];
      if ( v18 )
        v21 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
                v19,
                v20,
                (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)LODWORD(s_bm_current_air_resistance));
      else
        v21 = (unsigned int)vostok::animation::mixing::n_ary_tree_node_cloner::clone(v19, v20);
      v22 = this.m_Closure.m_pthis;
      this.m_Closure.m_pthis += 4;
      ++v16;
      *(_DWORD *)v22 = v21;
      if ( v16 == __last )
        goto LABEL_9;
    }
    v29 = interpolator;
    if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))interpolator->transition_time)(interpolator) != 0.0 )
    {
      v31 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v30, (int)&m_pthis[32], v29, v38);
      v33 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
              v32,
              (int)m_pthis,
              v31,
              v40,
              v41);
      v34 = this.m_Closure.m_pthis;
      this.m_Closure.m_pthis += 4;
      *(_DWORD *)v34 = v33;
    }
    for ( ; v16 != __last; *(_DWORD *)v36 = v35 )
    {
      v35 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
              (vostok::animation::mixing::n_ary_tree_node_cloner *)*v16,
              (vostok::animation::mixing::n_ary_tree_addition_node *)&m_pthis[32]);
      v36 = this.m_Closure.m_pthis;
      this.m_Closure.m_pthis += 4;
      ++v16;
    }
  }
  v37.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  *(_QWORD *)&v37.m_animated_object_resolver = *(unsigned int *)&m_pthis[80];
  v37.m_compare_dynamic_members = 0;
  stlp_std::sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_node_comparer>(
    __last,
    *(vostok::animation::mixing::n_ary_tree_base_node ***)&__comp.m_compare_dynamic_members,
    v37);
  return vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node(
           (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)m_pthis,
           0,
           v46,
           (unsigned int)__comp.__vftable,
           *(float *)&__comp.m_animated_object_resolver,
           1);
}
