void __userpurge vostok::animation::mixing::n_ary_tree::remove_animation(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::animation::mixing::n_ary_tree_animation_node **i,
        vostok::animation::mixing::n_ary_tree_animation_node *j)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // eax
  vostok::animation::mixing::n_ary_tree_animation_node **p_m_next_time_animation; // edx
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v7; // ebp
  _DWORD *v8; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_next_weight_animation; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v10; // ecx

  v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)a2[2];
  p_m_next_time_animation = (vostok::animation::mixing::n_ary_tree_animation_node **)(a2 + 2);
  v6 = 0;
  v7 = j;
  if ( v4 )
  {
    while ( v4 != *i )
    {
      v6 = v4;
      v4 = v4->m_next_time_animation;
      if ( !v4 )
        goto LABEL_8;
    }
    if ( v6 )
      p_m_next_time_animation = &v6->m_next_time_animation;
    *p_m_next_time_animation = v4->m_next_time_animation;
  }
LABEL_8:
  v8 = *i;
  if ( v7 )
    v7->m_next_weight_animation = (vostok::animation::mixing::n_ary_tree_animation_node *)v8[10];
  else
    a2[1] = v8[10];
  j = (vostok::animation::mixing::n_ary_tree_animation_node *)&vostok::animation::mixing::n_ary_tree_destroyer::`vftable';
  (*(void (__thiscall **)(_DWORD *, vostok::animation::mixing::n_ary_tree_animation_node **))(*v8 + 8))(v8, &j);
  if ( v7 )
  {
    m_next_weight_animation = v7->m_next_weight_animation;
    --a2[7];
    *i = m_next_weight_animation;
  }
  else
  {
    v10 = (vostok::animation::mixing::n_ary_tree_animation_node *)a2[1];
    --a2[7];
    *i = v10;
  }
}
