void __userpurge vostok::animation::mixing::n_ary_tree_comparer::merge_trees(
        const vostok::animation::mixing::n_ary_tree *from@<eax>,
        vostok::animation::mixing::n_ary_tree_comparer *this,
        vostok::animation::mixing::n_ary_tree_comparer *to)
{
  vostok::animation::mixing::n_ary_tree_animation_node *m_weight_root; // edx
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // ebx
  vostok::animation::mixing::n_ary_tree_comparer *v5; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_animated_objects_end; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v7; // esi
  unsigned int m_weight_synchronization_group_id; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v9; // eax
  unsigned int v10; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node *i; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v13; // eax
  unsigned int v14; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *v15; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node *v16; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v17; // eax
  unsigned int v18; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *v19; // eax
  unsigned int v20; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v21; // eax
  unsigned int v22; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *v23; // eax
  unsigned int v24; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *i_end; // [esp+14h] [ebp-8h]
  vostok::animation::mixing::n_ary_tree_animation_node *i_begin; // [esp+18h] [ebp-4h]
  vostok::animation::mixing::n_ary_tree_animation_node *i_begina; // [esp+18h] [ebp-4h]

  m_weight_root = from->m_weight_root;
  i_begin = m_weight_root;
  v4 = m_weight_root;
  do
  {
    if ( v4->m_weight_synchronization_group_id != m_weight_root->m_weight_synchronization_group_id )
      break;
    v4 = v4->m_next_weight_animation;
  }
  while ( v4 );
  v5 = to;
  m_animated_objects_end = (vostok::animation::mixing::n_ary_tree_animation_node *)to->m_animated_objects_end;
  i_end = v4;
  v7 = m_animated_objects_end;
  do
  {
    if ( v7->m_weight_synchronization_group_id != m_animated_objects_end->m_weight_synchronization_group_id )
      break;
    v7 = v7->m_next_weight_animation;
  }
  while ( v7 );
  while ( m_animated_objects_end )
  {
    m_weight_synchronization_group_id = m_animated_objects_end->m_weight_synchronization_group_id;
    v5 = (vostok::animation::mixing::n_ary_tree_comparer *)m_weight_root->m_weight_synchronization_group_id;
    if ( (unsigned int)v5 >= m_weight_synchronization_group_id )
    {
      if ( (unsigned int)v5 <= m_weight_synchronization_group_id )
      {
        vostok::animation::mixing::n_ary_tree_comparer::change_weight_synchronization_group(
          m_animated_objects_end,
          this,
          m_weight_root,
          v4,
          v7);
        i_begin = v4;
        if ( v4 )
        {
          v19 = v4;
          v20 = v4->m_weight_synchronization_group_id;
          do
          {
            if ( v19->m_weight_synchronization_group_id != v20 )
              break;
            v19 = v19->m_next_weight_animation;
          }
          while ( v19 );
          i_end = v19;
          v4 = v19;
        }
        m_animated_objects_end = v7;
        if ( v7 )
        {
          v21 = v7;
          v22 = v7->m_weight_synchronization_group_id;
          do
          {
            if ( v21->m_weight_synchronization_group_id != v22 )
              break;
            v21 = v21->m_next_weight_animation;
          }
          while ( v21 );
          v7 = v21;
        }
        m_weight_root = i_begin;
        goto LABEL_15;
      }
      this->m_equal = 0;
      v15 = m_animated_objects_end->m_weight_synchronization_group_id != -1 ? m_animated_objects_end : 0;
      v16 = m_animated_objects_end;
      if ( m_animated_objects_end != v7 )
      {
        do
        {
          vostok::animation::mixing::n_ary_tree_comparer::add_animation(this, v16, v15);
          v16 = v16->m_next_weight_animation;
        }
        while ( v16 != v7 );
        m_weight_root = i_begin;
      }
      m_animated_objects_end = v7;
      if ( v7 )
      {
        v17 = v7;
        v18 = v7->m_weight_synchronization_group_id;
        do
        {
          if ( v17->m_weight_synchronization_group_id != v18 )
            break;
          v17 = v17->m_next_weight_animation;
        }
        while ( v17 );
        v7 = v17;
      }
    }
    else
    {
      vostok::animation::mixing::n_ary_tree_comparer::remove_weight_synchronization_group(v5, this, m_weight_root, v4);
      i_begin = v4;
      if ( !v4 )
        goto LABEL_16;
      v9 = v4;
      v10 = v4->m_weight_synchronization_group_id;
      do
      {
        if ( v9->m_weight_synchronization_group_id != v10 )
          break;
        v9 = v9->m_next_weight_animation;
      }
      while ( v9 );
      m_weight_root = i_begin;
      i_end = v9;
    }
    v4 = i_end;
LABEL_15:
    if ( !m_weight_root )
    {
LABEL_16:
      if ( m_animated_objects_end )
      {
        while ( 1 )
        {
          this->m_equal = 0;
          v11 = m_animated_objects_end->m_weight_synchronization_group_id != -1 ? m_animated_objects_end : 0;
          for ( i = m_animated_objects_end; i != v7; i = i->m_next_weight_animation )
            vostok::animation::mixing::n_ary_tree_comparer::add_animation(this, i, v11);
          m_animated_objects_end = v7;
          if ( !v7 )
            break;
          v13 = v7;
          v14 = v7->m_weight_synchronization_group_id;
          do
          {
            if ( v13->m_weight_synchronization_group_id != v14 )
              break;
            v13 = v13->m_next_weight_animation;
          }
          while ( v13 );
          v7 = v13;
        }
      }
      return;
    }
  }
  if ( m_weight_root )
  {
    while ( 1 )
    {
      this->m_equal = 0;
      vostok::animation::mixing::n_ary_tree_comparer::remove_weight_synchronization_group(v5, this, m_weight_root, v4);
      i_begina = v4;
      if ( !v4 )
        break;
      v23 = v4;
      v24 = v4->m_weight_synchronization_group_id;
      do
      {
        if ( v23->m_weight_synchronization_group_id != v24 )
          break;
        v23 = v23->m_next_weight_animation;
      }
      while ( v23 );
      m_weight_root = i_begina;
      v4 = v23;
    }
  }
}
