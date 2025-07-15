int __thiscall survarium::base_player::recompute_damage_collision_bones(
        survarium::base_player *this,
        _DWORD *initiator)
{
  unsigned int m_current_time_in_ms; // ecx
  unsigned int v5; // ebx
  void *v6; // esp
  survarium::interactive_object *m_current_active_object; // ecx
  survarium::interactive_object_vtbl *v8; // eax
  survarium::interactive_object *v9; // ecx
  survarium::interactive_object_vtbl *v10; // eax
  int v11; // eax
  int v12; // esi
  void *v13; // esp
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v15; // ecx
  vostok::collision::animated_object *v16; // ecx
  boost::_bi::bind_t<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,boost::_mfi::mf1<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,survarium::animations_registry,unsigned short>,boost::_bi::list2<boost::_bi::value<survarium::animations_registry *>,boost::arg<1> > > v17; // [esp-8h] [ebp-ECh]
  const vostok::math::float4x4 *v18[4]; // [esp+0h] [ebp-E4h] BYREF
  char v19[64]; // [esp+10h] [ebp-D4h] BYREF
  char v20[64]; // [esp+50h] [ebp-94h] BYREF
  int v21[8]; // [esp+90h] [ebp-54h] BYREF
  boost::_bi::bind_t<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,boost::_mfi::mf1<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,survarium::animations_registry,unsigned short>,boost::_bi::list2<boost::_bi::value<survarium::animations_registry *>,boost::arg<1> > > v22[4]; // [esp+B0h] [ebp-34h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v23; // [esp+D0h] [ebp-14h] BYREF
  vostok::math::float4x4 *v24; // [esp+D4h] [ebp-10h]
  int v25; // [esp+D8h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v26; // [esp+DCh] [ebp-8h] BYREF
  unsigned int v27; // [esp+ECh] [ebp+8h]

  v25 = 0;
  if ( !this->m_is_alive )
    return 2;
  if ( initiator && *(_BYTE *)(initiator[18] + 4) == this->id )
    return 0;
  m_current_time_in_ms = this->m_current_time_in_ms;
  if ( this->m_recompute_damage_collision_bones_time_in_ms == m_current_time_in_ms )
    return 2;
  this->m_recompute_damage_collision_bones_time_in_ms = m_current_time_in_ms;
  v5 = *(_DWORD *)(*(int *)((char *)&dword_10E28 + (_DWORD)this) + 264)
     - (*(_DWORD *)(*(int *)((char *)&dword_10E28 + (_DWORD)this) + 280)
      - (*(int *)((char *)&dword_10E28 + (_DWORD)this)
       + 272))
     / 28;
  v6 = alloca(v5 << 6);
  m_current_active_object = this->m_current_active_object;
  v8 = m_current_active_object->__vftable;
  v24 = (vostok::math::float4x4 *)v18;
  if ( v8->get_skeleton(
         m_current_active_object,
         (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)&v26)->m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v9 = this->m_current_active_object;
    v10 = v9->__vftable;
    v25 = 1;
    v11 = (int)v10->get_skeleton(
                 v9,
                 (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)&v23);
    v12 = *(_DWORD *)(*(_DWORD *)v11 + 264) - (*(_DWORD *)(*(_DWORD *)v11 + 280) - (*(_DWORD *)v11 + 272)) / 28;
    v27 = v12;
  }
  else
  {
    v27 = 1;
    v12 = 1;
  }
  if ( (v25 & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v23);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
  v13 = alloca(v12 << 6);
  v21[0] = 0;
  v26.m_object = (vostok::particle::particle_system_instance_impl *)v18;
  v17.l_.a1_.t_ = &survarium::g_animations_registry;
  v17.f_.f_ = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *(__thiscall *)(survarium::animations_registry *, vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *, unsigned __int16))survarium::animations_registry::third_view_animation;
  boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl (unsigned short)>::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl (unsigned short)>(
    (boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *)&survarium::g_animations_registry,
    v22,
    v17,
    (int)v18[0]);
  this->m_current_active_object->compute_bones_matrices(
    this->m_current_active_object,
    (const vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)((char *)&dword_10E28 + (_DWORD)this),
    v24,
    v5,
    (vostok::math::float4x4 *)v19,
    (vostok::math::float4x4 *)v20,
    v27,
    (vostok::math::float4x4 *const)v26.m_object,
    &this->m_animation_player,
    (const boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *)v22,
    (const boost::function<void __cdecl(vostok::math::float4x4 *,unsigned int)> *)v21,
    2u);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v14,
    (int *)v22);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v15, v21);
  vostok::collision::animated_object::update(v16, *(_DWORD **)((char *)&dword_10E78 + (_DWORD)this), v24, v18[0]);
  return 1;
}
