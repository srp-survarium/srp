void __userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::merge_weight_asynchronous_groups(
        vostok::animation::mixing::n_ary_tree_animation_node *const from_begin@<eax>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *a2@<ecx>,
        const vostok::animation::base_interpolator *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *from_end,
        vostok::animation::mixing::n_ary_tree_animation_node *const to_begin,
        vostok::animation::mixing::n_ary_tree_animation_node *const to_end)
{
  const boost::function<unsigned char __cdecl(void const *)> *v8; // eax
  vostok::animation::comparison_result_enum v9; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v10; // ecx
  _BYTE v11[28]; // [esp-14h] [ebp-34h]
  _DWORD v12[3]; // [esp+10h] [ebp-10h] BYREF
  char v13; // [esp+1Ch] [ebp-4h]

  v12[2] = 0;
  v8 = (const boost::function<unsigned char __cdecl(void const *)> *)this[20].__vftable;
  v12[0] = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v12[1] = v8;
  v13 = 0;
  if ( !from_begin )
    goto LABEL_14;
  while ( from_end )
  {
    v9 = vostok::animation::mixing::n_ary_tree_node_comparer::compare(
           (vostok::animation::mixing::n_ary_tree_node_comparer *)from_begin,
           (int)v12,
           from_end,
           *(vostok::animation::mixing::n_ary_tree_base_node **)&v11[20]);
    *(_DWORD *)&v11[16] = 0;
    if ( v9 == equal )
    {
      *(_DWORD *)&v11[12] = 0;
      *(_DWORD *)&v11[8] = from_end;
      *(_DWORD *)&v11[4] = from_begin;
      *(_DWORD *)v11 = this;
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::change_animation(
        v10,
        *(const vostok::animation::mixing::animation_interval *)v11);
      from_begin = from_begin->m_next_weight_animation;
      goto LABEL_8;
    }
    if ( v9 != less )
    {
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation(
        v10,
        this,
        (vostok::animation::mixing::n_ary_tree_animation_node *const)from_end,
        0);
LABEL_8:
      from_end = (vostok::animation::mixing::n_ary_tree_subtraction_node *)from_end[5].__vftable;
      goto LABEL_9;
    }
    *(_QWORD *)&v11[8] = (unsigned int)this;
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_animation(
      from_begin,
      *(const vostok::animation::mixing::animation_interval *)&v11[8]);
    from_begin = from_begin->m_next_weight_animation;
LABEL_9:
    if ( !from_begin )
      goto LABEL_14;
  }
  do
  {
    *(_DWORD *)&v11[16] = 0;
    *(_QWORD *)&v11[8] = (unsigned int)this;
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_animation(
      from_begin,
      *(const vostok::animation::mixing::animation_interval *)&v11[8]);
    from_begin = from_begin->m_next_weight_animation;
  }
  while ( from_begin );
LABEL_14:
  while ( from_end )
  {
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation(
      a2,
      this,
      (vostok::animation::mixing::n_ary_tree_animation_node *const)from_end,
      0);
    from_end = (vostok::animation::mixing::n_ary_tree_subtraction_node *)from_end[5].__vftable;
  }
}
