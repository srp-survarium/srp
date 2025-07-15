void __userpurge vostok::animation::bone_matrices_computer::bone_matrices_computer(
        vostok::animation::mixing::animation_state *animations@<ecx>,
        unsigned int animations_count@<eax>,
        vostok::animation::bone_matrices_computer *this,
        vostok::animation::mixing::animation_state *animated_object,
        const vostok::animation::skeleton *skeleton)
{
  vostok::animation::mixing::animation_state *v5; // edx
  vostok::animation::bone_matrices_computer *v6; // ebp
  unsigned int v7; // ebx
  vostok::animation::mixing::animation_state *v8; // eax
  unsigned int *p_animation_interval_id; // edi
  _DWORD *v10; // esi
  vostok::resources::managed_resource *m_object; // eax
  volatile signed __int32 *v12; // ecx
  const unsigned __int8 *m_data; // eax
  const unsigned __int8 *v14; // ecx
  const unsigned __int8 *v15; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v16; // [esp-4h] [ebp-24h]
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > other; // [esp+14h] [ebp-Ch] BYREF

  v5 = animated_object;
  v6 = this;
  this->m_animations_count = animations_count;
  v7 = 0;
  v8 = &animations[animations_count];
  v6->m_animated_object = v5;
  v6->m_skeleton = skeleton;
  v6->m_animations = animations;
  v6->m_layers_count = 0;
  v6->m_overweighting_detected = 0;
  animated_object = v8;
  if ( animations != v8 )
  {
    p_animation_interval_id = &animations->animation_interval_id;
    do
    {
      v10 = (_DWORD *)p_animation_interval_id[20];
      if ( (const void *const)v10[9] == v6->m_animated_object )
      {
        v7 = vostok::math::max(v7, v10[18]);
        m_object = vostok::animation::mixing::animation_interval::animation((vostok::animation::mixing::animation_interval *)(v10[4] + 12 * *p_animation_interval_id))->m_animation.m_object;
        v12 = 0;
        this = 0;
        if ( m_object )
        {
          v12 = (volatile signed __int32 *)m_object;
          this = (vostok::animation::bone_matrices_computer *)m_object;
          _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
        }
        v16.m_object = 0;
        if ( v12 )
        {
          v16.m_object = (vostok::resources::managed_resource *)v12;
          v12 += 55;
          _InterlockedExchangeAdd(v12, 1u);
        }
        vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
          (vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)v12,
          &other.m_resource,
          v16);
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&this);
        vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>::operator=(
          &other,
          (const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > **)p_animation_interval_id
        - 3,
          &other);
        if ( other.m_resource.m_object )
        {
          if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          {
            m_data = other.m_data;
            v14 = other.m_data - 8;
            _InterlockedExchangeAdd((volatile signed __int32 *)other.m_data - 2, 0xFFFFFFFF);
            v15 = m_data - 36;
            if ( *(_DWORD *)v15 )
            {
              if ( !*(_DWORD *)v14 )
              {
                _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)v15 + 40), 1u);
                *(_DWORD *)v15 = 0;
              }
            }
          }
        }
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&other.m_resource);
        v8 = animated_object;
      }
      p_animation_interval_id += 45;
    }
    while ( p_animation_interval_id - 23 != (unsigned int *)v8 );
  }
  v6->m_layers_count = v7 + 1;
}
