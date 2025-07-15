void __userpurge vostok::animation::mixing::n_ary_tree_comparer::merge_trees(
        const vostok::animation::mixing::n_ary_tree *from@<eax>,
        vostok::animation::mixing::n_ary_tree_comparer *this,
        const vostok::animation::mixing::n_ary_tree *to)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_weight_root; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // esi
  vostok::animation::mixing::n_ary_tree_subtraction_node *v5; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // edi
  vostok::animation::mixing::n_ary_tree_subtraction_node_vtbl *v7; // eax
  const boost::function<unsigned char __cdecl(void const *)> *m_animated_object_resolver; // edx
  vostok::animation::mixing::n_ary_tree_animation_node *v9; // eax
  unsigned int m_weight_synchronization_group_id; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // eax
  unsigned int v12; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v13; // eax
  unsigned int v14; // esi
  unsigned int v15; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v16; // eax
  unsigned int v17; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *v18; // eax
  unsigned int v19; // edi
  vostok::animation::mixing::n_ary_tree_comparer *v20; // [esp+Ch] [ebp-4h]
  vostok::animation::mixing::n_ary_tree_animation_node *v21; // [esp+Ch] [ebp-4h]

  m_weight_root = (vostok::animation::mixing::n_ary_tree_comparer *)from->m_weight_root;
  v20 = m_weight_root;
  v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)m_weight_root;
  do
  {
    if ( (const boost::function<unsigned char __cdecl(void const *)> *)v4->m_weight_synchronization_group_id != m_weight_root[1].m_animated_object_resolver )
      break;
    v4 = v4->m_next_weight_animation;
  }
  while ( v4 );
  v5 = (vostok::animation::mixing::n_ary_tree_subtraction_node *)to->m_weight_root;
  v6 = (vostok::animation::mixing::n_ary_tree_animation_node *)v5;
  do
  {
    if ( (vostok::animation::mixing::n_ary_tree_subtraction_node_vtbl *)v6->m_weight_synchronization_group_id != v5[7].__vftable )
      break;
    v6 = v6->m_next_weight_animation;
  }
  while ( v6 );
  while ( v5 )
  {
    v7 = v5[7].__vftable;
    m_animated_object_resolver = m_weight_root[1].m_animated_object_resolver;
    if ( m_animated_object_resolver < (const boost::function<unsigned char __cdecl(void const *)> *)v7 )
    {
      vostok::animation::mixing::n_ary_tree_comparer::remove_weight_synchronization_group(
        m_weight_root,
        this,
        (vostok::animation::mixing::n_ary_tree_animation_node *)m_weight_root,
        v4);
      v20 = (vostok::animation::mixing::n_ary_tree_comparer *)v4;
      if ( !v4 )
        goto LABEL_37;
      v9 = v4;
      m_weight_synchronization_group_id = v4->m_weight_synchronization_group_id;
      do
      {
        if ( v9->m_weight_synchronization_group_id != m_weight_synchronization_group_id )
          break;
        v9 = v9->m_next_weight_animation;
      }
      while ( v9 );
      v4 = v9;
      goto LABEL_30;
    }
    if ( m_animated_object_resolver <= (const boost::function<unsigned char __cdecl(void const *)> *)v7 )
    {
      vostok::animation::mixing::n_ary_tree_comparer::change_weight_synchronization_group(
        this,
        v5,
        (vostok::animation::mixing::n_ary_tree_animation_node *)m_weight_root,
        v4,
        v6);
      v20 = (vostok::animation::mixing::n_ary_tree_comparer *)v4;
      if ( v4 )
      {
        v13 = v4;
        v14 = v4->m_weight_synchronization_group_id;
        do
        {
          if ( v13->m_weight_synchronization_group_id != v14 )
            break;
          v13 = v13->m_next_weight_animation;
        }
        while ( v13 );
        v4 = v13;
      }
      v5 = (vostok::animation::mixing::n_ary_tree_subtraction_node *)v6;
      if ( !v6 )
        goto LABEL_30;
      v11 = v6;
      v15 = v6->m_weight_synchronization_group_id;
      do
      {
        if ( v11->m_weight_synchronization_group_id != v15 )
          break;
        v11 = v11->m_next_weight_animation;
      }
      while ( v11 );
      goto LABEL_29;
    }
    vostok::animation::mixing::n_ary_tree_comparer::add_weight_synchronization_group(
      m_weight_root,
      this,
      (vostok::animation::mixing::n_ary_tree_animation_node *)v5,
      v6);
    v5 = (vostok::animation::mixing::n_ary_tree_subtraction_node *)v6;
    if ( v6 )
    {
      v11 = v6;
      v12 = v6->m_weight_synchronization_group_id;
      do
      {
        if ( v11->m_weight_synchronization_group_id != v12 )
          break;
        v11 = v11->m_next_weight_animation;
      }
      while ( v11 );
LABEL_29:
      v6 = v11;
    }
LABEL_30:
    m_weight_root = v20;
    if ( !v20 )
      break;
  }
  if ( m_weight_root )
  {
    while ( 1 )
    {
      this->m_equal = 0;
      vostok::animation::mixing::n_ary_tree_comparer::remove_weight_synchronization_group(
        m_weight_root,
        this,
        (vostok::animation::mixing::n_ary_tree_animation_node *)m_weight_root,
        v4);
      v21 = v4;
      if ( !v4 )
        break;
      v16 = v4;
      v17 = v4->m_weight_synchronization_group_id;
      do
      {
        if ( v16->m_weight_synchronization_group_id != v17 )
          break;
        v16 = v16->m_next_weight_animation;
      }
      while ( v16 );
      m_weight_root = (vostok::animation::mixing::n_ary_tree_comparer *)v21;
      v4 = v16;
    }
  }
LABEL_37:
  if ( v5 )
  {
    while ( 1 )
    {
      this->m_equal = 0;
      vostok::animation::mixing::n_ary_tree_comparer::add_weight_synchronization_group(
        m_weight_root,
        this,
        (vostok::animation::mixing::n_ary_tree_animation_node *)v5,
        v6);
      v5 = (vostok::animation::mixing::n_ary_tree_subtraction_node *)v6;
      if ( !v6 )
        break;
      v18 = v6;
      v19 = v6->m_weight_synchronization_group_id;
      do
      {
        if ( v18->m_weight_synchronization_group_id != v19 )
          break;
        v18 = v18->m_next_weight_animation;
      }
      while ( v18 );
      v6 = v18;
    }
  }
}
