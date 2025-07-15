vostok::animation::mixing::n_ary_tree_animation_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_animation@<eax>(
        vostok::animation::mixing::n_ary_tree_animation_node *animation@<eax>,
        const vostok::animation::mixing::animation_interval this)
{
  vostok::resources::managed_resource *m_object; // ebx
  vostok::resources::managed_resource *v3; // esi
  vostok::resources::managed_resource *m_uid; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *j; // eax
  _DWORD *v10; // eax
  unsigned int v11; // ecx
  vostok::animation::mixing::n_ary_tree_node_cloner **v12; // esi
  vostok::resources::managed_resource *v13; // eax
  char v14; // al
  vostok::animation::mixing::n_ary_tree_node_cloner *v15; // ecx
  vostok::animation::mixing::n_ary_tree_addition_node *v16; // esi
  vostok::animation::mixing::n_ary_tree_base_node *v17; // eax
  vostok::resources::managed_resource *v18; // ecx
  unsigned int m_time_synchronization_group_id; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *i; // eax
  vostok::resources::managed_resource *v21; // eax
  vostok::resources::managed_resource *v22; // edx
  unsigned int m_animation_id; // esi
  _DWORD *m_thread_id; // eax
  unsigned int v25; // ecx
  unsigned int v26; // eax
  float m_length; // ecx
  volatile int v28; // eax
  _DWORD *v29; // esi
  bool v30; // zf
  BOOL v31; // eax
  unsigned int v32; // ecx
  volatile int v33; // eax
  vostok::resources::managed_resource *v34; // edx
  volatile int v35; // eax
  float v36; // edx
  int v37; // esi
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v38; // ecx
  void (__thiscall *v39)(struct vostok::animation::mixing::n_ary_tree_n_ary_operation_node *); // eax
  vostok::animation::mixing::n_ary_tree_node_cloner **v40; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v41; // eax
  float m_start_time; // ecx
  volatile int v43; // eax
  vostok::animation::mixing::n_ary_tree_node_cloner *v44; // ecx
  const vostok::animation::base_interpolator *v45; // eax
  const vostok::animation::base_interpolator *v46; // eax
  unsigned int v47; // ecx
  vostok::resources::managed_resource *v48; // eax
  char v49; // al
  volatile int v50; // eax
  vostok::resources::managed_resource *v51; // ecx
  unsigned int v52; // ecx
  vostok::resources::managed_resource *v53; // eax
  float v54; // xmm0_4
  unsigned int v55; // [esp-4h] [ebp-38h]
  float v56; // [esp+0h] [ebp-34h]
  bool v57; // [esp+8h] [ebp-2Ch]
  unsigned int v58; // [esp+18h] [ebp-1Ch] BYREF
  float v59; // [esp+1Ch] [ebp-18h] BYREF
  vostok::animation::mixing::animation_interval v60; // [esp+20h] [ebp-14h] BYREF

  m_object = this.m_first_view_animation.m_object;
  v3 = this.m_third_view_animation.m_object;
  if ( this.m_third_view_animation.m_object )
  {
    m_uid = (vostok::resources::managed_resource *)this.m_third_view_animation.m_object->m_uid;
    this.m_first_view_animation.m_object = m_uid;
  }
  else
  {
    this.m_first_view_animation.m_object = (vostok::resources::managed_resource *)animation->m_weight_interpolator;
    m_uid = this.m_first_view_animation.m_object;
  }
  if ( ((double (__thiscall *)(vostok::resources::managed_resource *))m_uid->decrease_quality)(m_uid) == 0.0 )
    return 0;
  if ( !animation->m_is_transitting_to_zero || LOBYTE(this.m_animation_id) )
  {
    this.m_animation_id = !animation->m_time_driving_animation
                       && animation->m_operands_count
                       && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
                           + 3))(animation[1].__vftable);
    m_time_synchronization_group_id = animation->m_time_synchronization_group_id;
    LOBYTE(this.m_third_view_animation.m_object) = 1;
    if ( m_time_synchronization_group_id != -1 )
    {
      for ( i = (vostok::animation::mixing::n_ary_tree_animation_node *)m_object->m_parent_resources.m_first->quality_value;
            i;
            i = i->m_next_time_animation )
      {
        if ( i->m_time_synchronization_group_id == m_time_synchronization_group_id )
        {
          if ( i != animation )
          {
            this.m_animation_id = 0;
            LOBYTE(this.m_third_view_animation.m_object) = 0;
          }
          break;
        }
      }
    }
    v21 = (vostok::resources::managed_resource *)vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation(
                                                   animation,
                                                   (unsigned int *)&this.m_third_view_animation,
                                                   (const vostok::animation::base_interpolator *)m_object,
                                                   animation,
                                                   (vostok::animation::mixing::n_ary_tree_animation_node *)v3,
                                                   1u,
                                                   (fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *)&this.m_animation_id,
                                                   &v60,
                                                   &v58,
                                                   &v59,
                                                   1,
                                                   (vostok::animation::mixing::n_ary_tree_animation_node *)this.m_third_view_animation.m_object);
    v22 = this.m_third_view_animation.m_object;
    m_animation_id = this.m_animation_id;
    v60.m_third_view_animation.m_object = v21;
    m_thread_id = (_DWORD *)m_object->m_parent_resources.m_thread_id;
    LODWORD(v60.m_length) = *m_thread_id + 4 * (int)this.m_third_view_animation.m_object;
    v25 = 4 * this.m_animation_id + 4;
    *m_thread_id += v25;
    m_thread_id[1] -= v25;
    if ( (unsigned int)v22 < m_animation_id )
    {
      v26 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
              (vostok::animation::mixing::n_ary_tree_node_cloner *)animation[1].__vftable,
              (vostok::animation::mixing::n_ary_tree_addition_node *)&m_object->vostok::uid_object<vostok::resources::resource_children>,
              (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)LODWORD(s_bm_current_air_resistance));
      m_length = v60.m_length;
      LODWORD(v60.m_length) += 4;
      *(_DWORD *)LODWORD(m_length) = v26;
    }
    v28 = m_object->m_parent_resources.m_thread_id;
    v29 = *(_DWORD **)v28;
    *(_DWORD *)v28 += 20;
    *(_DWORD *)(v28 + 4) -= 20;
    v30 = animation->m_operands_count == 0;
    v60.m_animation_id = (unsigned int)v29;
    v31 = !v30
       && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
           + 3))(animation[1].__vftable);
    v32 = animation->m_operands_count - v31;
    if ( v32 )
    {
      if ( v32 == 1 )
      {
        v49 = (*((int (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
               + 3))(animation[1].__vftable);
        this.m_third_view_animation.m_object = (vostok::resources::managed_resource *)vostok::animation::mixing::n_ary_tree_node_cloner::clone(
                                                                                        *((vostok::animation::mixing::n_ary_tree_node_cloner **)&animation[1].__vftable
                                                                                        + (v49 != 0)),
                                                                                        (vostok::animation::mixing::n_ary_tree_addition_node *)&m_object->vostok::uid_object<vostok::resources::resource_children>);
      }
      else
      {
        v33 = m_object->m_parent_resources.m_thread_id;
        v34 = *(vostok::resources::managed_resource **)v33;
        *(_DWORD *)v33 += 8;
        *(_DWORD *)(v33 + 4) -= 8;
        this.m_third_view_animation.m_object = v34;
        if ( v34 )
        {
          v34->type = v32;
          v34->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::managed_resource_vtbl *)&vostok::animation::mixing::n_ary_tree_multiplication_node::`vftable';
        }
        v35 = m_object->m_parent_resources.m_thread_id;
        v36 = *(float *)v35;
        v37 = v32;
        *(_DWORD *)v35 += 4 * v32;
        *(_DWORD *)(v35 + 4) -= 4 * v32;
        v38 = animation[1].__vftable;
        v39 = v38->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node;
        v60.m_start_time = v36;
        v40 = (vostok::animation::mixing::n_ary_tree_node_cloner **)(&animation[1].__vftable
                                                                   + ((*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v39
                                                                       + 3))(v38) != 0));
        this.m_animation_id = (unsigned int)v40;
        v60.m_first_view_animation.m_object = (vostok::resources::managed_resource *)&v40[v37];
        if ( v40 != &v40[v37] )
        {
          while ( 1 )
          {
            v41 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
                    *v40,
                    (vostok::animation::mixing::n_ary_tree_addition_node *)&m_object->vostok::uid_object<vostok::resources::resource_children>);
            m_start_time = v60.m_start_time;
            this.m_animation_id += 4;
            LODWORD(v60.m_start_time) += 4;
            *(_DWORD *)LODWORD(m_start_time) = v41;
            if ( (vostok::resources::managed_resource *)this.m_animation_id == v60.m_first_view_animation.m_object )
              break;
            v40 = (vostok::animation::mixing::n_ary_tree_node_cloner **)this.m_animation_id;
          }
        }
      }
      v29 = (_DWORD *)v60.m_animation_id;
    }
    else
    {
      v50 = m_object->m_parent_resources.m_thread_id;
      v51 = *(vostok::resources::managed_resource **)v50;
      *(_DWORD *)v50 += 12;
      *(_DWORD *)(v50 + 4) -= 12;
      this.m_third_view_animation.m_object = v51;
      if ( v51 )
      {
        v52 = v60.m_third_view_animation.m_object->m_uid;
        v53 = this.m_third_view_animation.m_object;
        v54 = s_bm_current_air_resistance;
        this.m_third_view_animation.m_object->__vftable = (vostok::resources::managed_resource_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
        v53->type = v52;
        *(float *)&v53->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = v54;
      }
    }
    v43 = m_object->m_parent_resources.m_thread_id;
    v44 = *(vostok::animation::mixing::n_ary_tree_node_cloner **)v43;
    *(_DWORD *)v43 += 12;
    *(_DWORD *)(v43 + 4) -= 12;
    this.m_animation_id = (unsigned int)v44;
    if ( v44 )
    {
      v45 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
              v44,
              (int)&m_object->vostok::uid_object<vostok::resources::resource_children>,
              (const vostok::animation::base_interpolator *)this.m_first_view_animation.m_object,
              v57);
      v44 = (vostok::animation::mixing::n_ary_tree_node_cloner *)this.m_animation_id;
      *(_DWORD *)this.m_animation_id = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v44->m_result = (vostok::animation::mixing::n_ary_tree_base_node *)v45;
      v44->m_constructor = 0;
    }
    if ( v29 )
    {
      v60.m_first_view_animation.m_object = (vostok::resources::managed_resource *)m_object->m_class_id;
      v46 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
              v44,
              (int)&m_object->vostok::uid_object<vostok::resources::resource_children>,
              (const vostok::animation::base_interpolator *)this.m_first_view_animation.m_object,
              v57);
      v29[1] = this.m_third_view_animation.m_object;
      v47 = this.m_animation_id;
      v29[3] = v46;
      v48 = v60.m_first_view_animation.m_object;
      *v29 = &vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
      v29[2] = v47;
      v29[4] = v48;
    }
    v56 = v59;
    v55 = v58;
    *(_DWORD *)LODWORD(v60.m_length) = v29;
    return vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node(
             (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)m_object,
             animation->m_animation_state,
             (vostok::animation::mixing::n_ary_tree_animation_node *)v60.m_third_view_animation.m_object,
             v55,
             v56,
             0);
  }
  else
  {
    this.m_animation_id = animation->m_operands_count
                       && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
                           + 3))(animation[1].__vftable);
    v7 = animation->m_time_synchronization_group_id;
    v8 = animation->m_operands_count - this.m_animation_id;
    LOBYTE(this.m_first_view_animation.m_object) = 1;
    if ( v7 != -1 )
    {
      for ( j = (vostok::animation::mixing::n_ary_tree_animation_node *)m_object->m_parent_resources.m_first->quality_value;
            j;
            j = j->m_next_time_animation )
      {
        if ( j->m_time_synchronization_group_id == v7 )
        {
          if ( j != animation )
          {
            this.m_animation_id = 0;
            LOBYTE(this.m_first_view_animation.m_object) = 0;
          }
          break;
        }
      }
    }
    LODWORD(v60.m_start_time) = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation(
                                  animation,
                                  (unsigned int *)&this.m_third_view_animation,
                                  (const vostok::animation::base_interpolator *)m_object,
                                  animation,
                                  (vostok::animation::mixing::n_ary_tree_animation_node *)this.m_third_view_animation.m_object,
                                  v8,
                                  (fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *)&this.m_animation_id,
                                  &this,
                                  &v60.m_animation_id,
                                  (float *)&v60.m_third_view_animation,
                                  1,
                                  (vostok::animation::mixing::n_ary_tree_animation_node *)this.m_first_view_animation.m_object);
    v10 = (_DWORD *)m_object->m_parent_resources.m_thread_id;
    this.m_third_view_animation.m_object = (vostok::resources::managed_resource *)(*v10
                                                                                 + 4
                                                                                 * (int)this.m_third_view_animation.m_object);
    v11 = 4 * (v8 + this.m_animation_id);
    *v10 += v11;
    v10[1] -= v11;
    v12 = (vostok::animation::mixing::n_ary_tree_node_cloner **)(&animation[1].__vftable
                                                               + (int)this.m_first_view_animation.m_object);
    v13 = (vostok::resources::managed_resource *)(&animation[1].__vftable + animation->m_operands_count);
    this.m_animation_id = (unsigned int)v12;
    this.m_first_view_animation.m_object = v13;
    if ( v12 != (vostok::animation::mixing::n_ary_tree_node_cloner **)v13 )
    {
      while ( 1 )
      {
        v14 = ((int (__thiscall *)(vostok::animation::mixing::n_ary_tree_node_cloner *))(*v12)->visit)(*v12);
        v15 = *v12;
        v16 = (vostok::animation::mixing::n_ary_tree_addition_node *)&m_object->vostok::uid_object<vostok::resources::resource_children>;
        v17 = v14
            ? (vostok::animation::mixing::n_ary_tree_base_node *)vostok::animation::mixing::n_ary_tree_node_cloner::clone(
                                                                   v15,
                                                                   v16,
                                                                   (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)LODWORD(s_bm_current_air_resistance))
            : vostok::animation::mixing::n_ary_tree_node_cloner::clone(v15, v16);
        v18 = this.m_third_view_animation.m_object;
        this.m_animation_id += 4;
        this.m_third_view_animation.m_object = (vostok::resources::managed_resource *)((char *)this.m_third_view_animation.m_object
                                                                                     + 4);
        v18->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::managed_resource_vtbl *)v17;
        if ( (vostok::resources::managed_resource *)this.m_animation_id == this.m_first_view_animation.m_object )
          break;
        v12 = (vostok::animation::mixing::n_ary_tree_node_cloner **)this.m_animation_id;
      }
    }
    return vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node(
             (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)m_object,
             animation->m_animation_state,
             (vostok::animation::mixing::n_ary_tree_animation_node *)LODWORD(v60.m_start_time),
             v60.m_animation_id,
             *(float *)&v60.m_third_view_animation.m_object,
             0);
  }
}
