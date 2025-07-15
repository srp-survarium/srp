vostok::animation::mixing::n_ary_tree_animation_node *__thiscall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        const vostok::animation::base_interpolator *animation,
        vostok::animation::mixing::n_ary_tree_animation_node *const weight_driving_animation,
        vostok::animation::mixing::n_ary_tree_animation_node *a4)
{
  const vostok::animation::base_interpolator *m_weight_interpolator; // eax
  unsigned int m_operands_count; // edi
  vostok::animation::mixing::n_ary_tree_base_node **v7; // esi
  unsigned int v8; // edi
  vostok::mutable_buffer *v9; // eax
  char *m_data; // edx
  float v11; // xmm0_4
  int v12; // ecx
  const vostok::animation::base_interpolator *v13; // ecx
  fastdelegate::detail::GenericClass *v14; // eax
  fastdelegate::detail::GenericClass *v15; // edi
  int v16; // ecx
  char v17; // al
  vostok::animation::mixing::n_ary_tree_node_cloner *v18; // ecx
  vostok::animation::mixing::n_ary_tree_addition_node *v19; // esi
  unsigned int v20; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v21; // ecx
  vostok::animation::mixing::n_ary_tree_node_cloner *v22; // ecx
  const vostok::animation::base_interpolator *v23; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v24; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v25; // eax
  vostok::animation::mixing::n_ary_tree_node_cloner *v27; // ecx
  const vostok::animation::base_interpolator *v28; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v29; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v30; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v31; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v32; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v33; // ecx
  vostok::animation::mixing::n_ary_tree_node_comparer v34; // [esp+0h] [ebp-5Ch]
  bool v35; // [esp+10h] [ebp-4Ch]
  float v36; // [esp+10h] [ebp-4Ch]
  float v37; // [esp+10h] [ebp-4Ch]
  float v38; // [esp+14h] [ebp-48h]
  _DWORD v39[2]; // [esp+20h] [ebp-3Ch] BYREF
  int v40; // [esp+28h] [ebp-34h]
  char v41; // [esp+2Ch] [ebp-30h]
  _DWORD v42[3]; // [esp+30h] [ebp-2Ch] BYREF
  vostok::animation::mixing::n_ary_tree_animation_node *v43; // [esp+3Ch] [ebp-20h]
  vostok::animation::mixing::n_ary_tree_node_comparer __comp; // [esp+40h] [ebp-1Ch] BYREF
  vostok::animation::mixing::n_ary_tree_animation_node *v45; // [esp+50h] [ebp-Ch]
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> __last; // [esp+54h] [ebp-8h] BYREF
  const vostok::animation::base_interpolator *interpolator; // [esp+64h] [ebp+8h]

  if ( a4 )
    m_weight_interpolator = a4->m_weight_interpolator;
  else
    m_weight_interpolator = weight_driving_animation->m_weight_interpolator;
  m_operands_count = weight_driving_animation->m_operands_count;
  v7 = (vostok::animation::mixing::n_ary_tree_base_node **)&weight_driving_animation[1];
  interpolator = m_weight_interpolator;
  *(_DWORD *)&__comp.m_compare_dynamic_members = m_operands_count;
  v45 = weight_driving_animation + 1;
  if ( m_operands_count && (*v7)->is_time_scale(*v7) )
    --m_operands_count;
  v8 = (((double (__thiscall *)(const vostok::animation::base_interpolator *))interpolator->transition_time)(interpolator) != 0.0)
     + m_operands_count;
  __last.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)(*(_DWORD *)&__comp.m_compare_dynamic_members
                                                                 && (*v7)->is_time_scale(*v7));
  v43 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation(
          weight_driving_animation,
          (unsigned int *)&a4,
          animation,
          weight_driving_animation,
          a4,
          v8,
          &__last,
          (const vostok::animation::mixing::animation_interval *)&__comp.result,
          (unsigned int *)&__comp,
          (float *)&__comp.m_animated_object_resolver,
          0,
          (vostok::animation::mixing::n_ary_tree_animation_node *)1);
  if ( !__last.m_Closure.m_pthis && *(_DWORD *)&__comp.m_compare_dynamic_members )
    __last.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)(*v7)->is_time_scale(*v7);
  v9 = (vostok::mutable_buffer *)animation[17].__vftable;
  m_data = v9->m_data;
  v11 = s_bm_current_air_resistance;
  v12 = 4 * (int)&__last.m_Closure.m_pthis[v8];
  v9->m_data += v12;
  v9->m_size -= v12;
  v13 = interpolator;
  v40 = 0;
  a4 = (vostok::animation::mixing::n_ary_tree_animation_node *)&m_data[4 * (_DWORD)a4];
  v39[1] = animation[20].__vftable;
  v14 = (fastdelegate::detail::GenericClass *)&v7[weight_driving_animation->m_operands_count];
  v15 = (fastdelegate::detail::GenericClass *)&v7[__comp.result];
  v42[0] = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
  v42[1] = interpolator;
  *(float *)&v42[2] = v11;
  v39[0] = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v41 = 0;
  __last.m_Closure.m_pthis = v14;
  if ( v15 == v14 )
  {
LABEL_21:
    if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))v13->transition_time)(v13) != 0.0 )
    {
      v23 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v22, (int)&animation[8], interpolator, v35);
      v25 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
              v24,
              (int)animation,
              v23,
              v36,
              v38);
      a4->__vftable = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)v25;
LABEL_23:
      v7 = (vostok::animation::mixing::n_ary_tree_base_node **)v45;
    }
  }
  else
  {
    while ( 1 )
    {
      v16 = *(_DWORD *)v15;
      v40 = 0;
      (*(void (__thiscall **)(int, _DWORD *, _DWORD *))(*(_DWORD *)v16 + 4))(v16, v39, v42);
      if ( v40 == 2 )
        break;
      v17 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)v15 + 12))(*(_DWORD *)v15);
      v18 = *(vostok::animation::mixing::n_ary_tree_node_cloner **)v15;
      v19 = (vostok::animation::mixing::n_ary_tree_addition_node *)&animation[8];
      if ( v17 )
        v20 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
                v18,
                v19,
                (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)LODWORD(s_bm_current_air_resistance));
      else
        v20 = (unsigned int)vostok::animation::mixing::n_ary_tree_node_cloner::clone(v18, v19);
      v21 = a4;
      a4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)a4 + 4);
      v7 = (vostok::animation::mixing::n_ary_tree_base_node **)v45;
      v15 += 4;
      v21->__vftable = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)v20;
      if ( v15 == __last.m_Closure.m_pthis )
      {
        v13 = interpolator;
        goto LABEL_21;
      }
    }
    if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))interpolator->transition_time)(interpolator) != 0.0 )
    {
      v28 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v27, (int)&animation[8], interpolator, v35);
      v30 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
              v29,
              (int)animation,
              v28,
              v37,
              v38);
      v31 = a4;
      a4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)a4 + 4);
      v7 = (vostok::animation::mixing::n_ary_tree_base_node **)v45;
      v31->__vftable = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)v30;
    }
    if ( v15 != __last.m_Closure.m_pthis )
    {
      do
      {
        v32 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
                *(vostok::animation::mixing::n_ary_tree_node_cloner **)v15,
                (vostok::animation::mixing::n_ary_tree_addition_node *)&animation[8]);
        v33 = a4;
        a4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)a4 + 4);
        v15 += 4;
        v33->__vftable = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)v32;
      }
      while ( v15 != __last.m_Closure.m_pthis );
      goto LABEL_23;
    }
  }
  v34.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  *(_QWORD *)&v34.m_animated_object_resolver = (unsigned int)animation[20].__vftable;
  v34.m_compare_dynamic_members = 0;
  stlp_std::sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_node_comparer>(
    (vostok::animation::mixing::n_ary_tree_base_node **)__last.m_Closure.m_pthis,
    v7,
    v34);
  return vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node(
           (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)animation,
           weight_driving_animation->m_animation_state,
           v43,
           (unsigned int)__comp.__vftable,
           *(float *)&__comp.m_animated_object_resolver,
           1);
}
