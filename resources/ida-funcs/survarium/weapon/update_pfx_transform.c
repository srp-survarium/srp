void __usercall survarium::weapon::update_pfx_transform(survarium::weapon *this@<ecx>, int a2@<esi>)
{
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v2; // eax
  unsigned __int8 v3; // bl
  boost::_bi::bind_t<void,boost::_mfi::mf6<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float4x4 const &,vostok::math::float4x4 const &,bool,bool>,boost::_bi::list7<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1>,boost::arg<2>,boost::_bi::value<bool>,boost::_bi::value<bool> > > *v4; // edi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *i; // ebp
  int v6; // eax
  bool v7; // [esp+0h] [ebp-Ch]

  v2 = *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 1672);
  v3 = 0;
  v4 = *(boost::_bi::bind_t<void,boost::_mfi::mf6<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float4x4 const &,vostok::math::float4x4 const &,bool,bool>,boost::_bi::list7<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1>,boost::arg<2>,boost::_bi::value<bool>,boost::_bi::value<bool> > > **)((char *)&dword_200060 + v2[40].m_object->m_fat_it.m_type);
  for ( i = v2 + 1; v3 < *(_BYTE *)(a2 + 1504); ++v3 )
  {
    v6 = 4 * v3;
    if ( *(_DWORD *)(*(_DWORD *)(v6 + *(_DWORD *)(a2 + 1496)) + 744) )
      vostok::render::scene_renderer::update_particle_system_instance(
        (vostok::render::scene_renderer *)(v6 + *(_DWORD *)(a2 + 1496)),
        v4,
        i,
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(v6 + *(_DWORD *)(a2 + 1496)),
        (const vostok::math::float4x4 *)(a2 + 1152),
        (vostok::math::float4x4 *)(a2 + 1152),
        v7);
  }
}
