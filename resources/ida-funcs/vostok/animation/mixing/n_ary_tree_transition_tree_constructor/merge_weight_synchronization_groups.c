void __thiscall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::merge_weight_synchronization_groups(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        const vostok::animation::base_interpolator *from_begin,
        vostok::animation::mixing::n_ary_tree_animation_node *from_end,
        vostok::animation::mixing::n_ary_tree_animation_node *to_begin,
        vostok::animation::mixing::n_ary_tree_animation_node *to_end,
        vostok::animation::mixing::n_ary_tree_animation_node *new_weight_driving_animation,
        __int64 is_new_driving_animation)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v7; // eax
  int v9; // esi
  void *v10; // esp
  vostok::animation::mixing::n_ary_tree_animation_node **v11; // edi
  _DWORD *v12; // ecx
  const boost::function<unsigned char __cdecl(void const *)> *v13; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v15; // ecx
  int v16; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v17; // ecx
  _BYTE v18[28]; // [esp-14h] [ebp-40h] BYREF
  vostok::animation::mixing::animation_comparer_predicate v19; // [esp+10h] [ebp-1Ch] BYREF
  vostok::animation::mixing::animation_comparer_predicate v20; // [esp+18h] [ebp-14h] BYREF
  _BYTE *v21; // [esp+24h] [ebp-8h]
  char v22; // [esp+37h] [ebp+Bh]
  vostok::animation::mixing::n_ary_tree_animation_node **v23; // [esp+3Ch] [ebp+10h]

  v7 = from_end;
  v9 = 0;
  while ( v7 != to_begin )
  {
    v7 = v7->m_next_weight_animation;
    ++v9;
  }
  v20.m_animated_object_resolver = (const boost::function<unsigned char __cdecl(void const *)> *)from_begin[20].__vftable;
  v20.m_use_synchronized_animations = 0;
  v20.m_use_overriding_animations = 1;
  v22 = 0;
  v10 = alloca(4 * v9);
  v11 = (vostok::animation::mixing::n_ary_tree_animation_node **)&v18[20];
  v21 = &v18[20];
  if ( from_end != to_begin )
  {
    do
    {
      if ( vostok::animation::mixing::animation_comparer_predicate::operator()(
             &v20,
             from_end,
             (vostok::animation::mixing::n_ary_tree_animation_node *)is_new_driving_animation) )
      {
        v12 = v21;
        v21 += 4;
        *v12 = from_end;
      }
      else
      {
        v22 = 1;
      }
      from_end = from_end->m_next_weight_animation;
    }
    while ( from_end != to_begin );
    if ( v22 )
      --v9;
  }
  v13 = (const boost::function<unsigned char __cdecl(void const *)> *)from_begin[20].__vftable;
  LOWORD(v21) = 256;
  v23 = (vostok::animation::mixing::n_ary_tree_animation_node **)&v18[4 * v9 + 20];
  stlp_std::sort<vostok::animation::mixing::n_ary_tree_animation_node * *,vostok::animation::mixing::animation_comparer_less_predicate>(
    (vostok::animation::mixing::n_ary_tree_animation_node **)&v18[20],
    v23,
    (vostok::animation::mixing::animation_comparer_less_predicate)__PAIR64__((unsigned int)v21, (unsigned int)v13));
  v15 = *(vostok::animation::mixing::n_ary_tree_transition_tree_constructor **)&v18[16];
  v19.m_animated_object_resolver = (const boost::function<unsigned char __cdecl(void const *)> *)from_begin[20].__vftable;
  v19.m_use_synchronized_animations = 0;
  v19.m_use_overriding_animations = 1;
  if ( &v18[20] != (_BYTE *)v23 )
  {
    while ( 1 )
    {
      if ( to_end == new_weight_driving_animation )
      {
LABEL_22:
        while ( v11 != v23 )
        {
          *(_QWORD *)&v18[12] = is_new_driving_animation;
          *(_DWORD *)&v18[8] = from_begin;
          vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_animation(
            *v11++,
            *(const vostok::animation::mixing::animation_interval *)&v18[8]);
        }
        goto LABEL_25;
      }
      v16 = vostok::animation::mixing::animation_comparer_predicate::operator()(&v19, *v11, to_end);
      if ( !v16 )
        break;
      if ( v16 != 1 )
      {
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation(
          v17,
          from_begin,
          to_end,
          (vostok::animation::mixing::n_ary_tree_animation_node *)is_new_driving_animation);
LABEL_18:
        to_end = to_end->m_next_weight_animation;
        goto LABEL_19;
      }
      *(_QWORD *)&v18[12] = is_new_driving_animation;
      *(_DWORD *)&v18[8] = from_begin;
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_animation(
        *v11++,
        *(const vostok::animation::mixing::animation_interval *)&v18[8]);
LABEL_19:
      if ( v11 == v23 )
        goto LABEL_22;
    }
    *(_QWORD *)&v18[12] = is_new_driving_animation;
    *(_DWORD *)&v18[8] = to_end;
    *(_DWORD *)&v18[4] = *v11;
    *(_DWORD *)v18 = from_begin;
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::change_animation(
      v17,
      *(const vostok::animation::mixing::animation_interval *)v18);
    ++v11;
    goto LABEL_18;
  }
LABEL_25:
  while ( to_end != new_weight_driving_animation )
  {
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation(
      v15,
      from_begin,
      to_end,
      (vostok::animation::mixing::n_ary_tree_animation_node *)is_new_driving_animation);
    to_end = to_end->m_next_weight_animation;
  }
}
