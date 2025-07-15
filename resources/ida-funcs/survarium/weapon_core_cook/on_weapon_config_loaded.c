void __thiscall survarium::weapon_core_cook::on_weapon_config_loaded(
        survarium::weapon_core_cook *this,
        vostok::resources::queries_result *data)
{
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v2; // edi
  char *v3; // eax
  survarium::weapon_core *v4; // ecx
  vostok::configs::binary_config *v5; // eax
  vostok::configs::binary_config *v6; // ebx
  unsigned int v7; // eax
  vostok::resources::queries_result *m_object; // esi
  survarium::weapon_core_cook *v9; // ecx
  survarium::weapon_core_cook *v10; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<survarium::weapon_core *> > > v11; // [esp-10h] [ebp-28h] BYREF
  unsigned int v12; // [esp+8h] [ebp-10h]
  unsigned __int64 parent; // [esp+Ch] [ebp-Ch]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v14; // [esp+14h] [ebp-4h] BYREF

  v2 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)data;
  parent = __PAIR64__(data->m_parent_query, (unsigned int)this);
  v3 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)this,
         (int)survarium::g_allocator,
         0x670u,
         "weapon_core",
         (const char *const)v11.l_.a4_.t_,
         *((const char *const *)&v11.l_ + 3),
         v12);
  if ( v3 )
  {
    survarium::weapon_core::weapon_core(v4, (int)v3);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  if ( v6 == (vostok::configs::binary_config *)-1152 )
    v7 = 0;
  else
    survarium::portable_interactive_object_core::portable_interactive_object_core(
      (survarium::portable_interactive_object_core *)v4,
      (int)&v6[4].m_parent_resources.vostok::threading::simple_lock);
  v6[1].m_uid = v7;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v14,
    v2 + 75);
  m_object = (vostok::resources::queries_result *)v14.m_object;
  data = 0;
  if ( v14.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    data = m_object;
    _InterlockedExchangeAdd((volatile signed __int32 *)&m_object->m_queries[0].m_target_quality_level, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v14);
  v11.l_.a3_.t_.m_object = v6;
  v11.l_.a1_.t_ = v9;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11.l_,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  v11.f_.f_ = (void (__thiscall *__ptr64)(survarium::weapon_core_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>, survarium::weapon_core *))parent;
  survarium::weapon_core_cook::process_loading_weapon_core(v10, v11);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
}
