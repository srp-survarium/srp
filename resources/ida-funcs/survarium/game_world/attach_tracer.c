void __thiscall survarium::game_world::attach_tracer(
        survarium::game_world *this,
        vostok::particle::particle_system_instance_impl *bullet)
{
  unsigned __int16 v3; // dx
  vostok::render::scene_renderer *v4; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v5; // eax
  vostok::particle::particle_system_instance_impl *m_object; // edx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // eax
  vostok::math::float4x4 v8; // [esp+10h] [ebp-40h] BYREF

  if ( (_S9_6 & 1) == 0 )
  {
    _S9_6 |= 1u;
    qmemcpy(&m_0, vostok::math::float4x4::identity((vostok::math::float4x4 *)this, &v8), sizeof(m_0));
  }
  v3 = s_tracer_idx++
     % (unsigned int)((*(_DWORD *)&this->m_third_person_game_effect_presenters[10968]
                     - *(_DWORD *)&this->m_third_person_game_effect_presenters[10964]) >> 3);
  v4 = (vostok::render::scene_renderer *)v3;
  v5 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)&this->m_third_person_game_effect_presenters[10964] + 8 * v3);
  m_object = v5->m_object;
  HIWORD(bullet->grm_satisfaction_tree_hook.parent_) = (_WORD)v4;
  v5->m_object = bullet;
  v7 = v5 + 1;
  if ( m_object )
  {
    HIWORD(m_object->grm_satisfaction_tree_hook.parent_) = -1;
    vostok::render::scene_renderer::update_tracer(
      (vostok::render::scene_renderer *)0xFFFF,
      *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float4x4 const &>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > > **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)&this[-1].m_third_person_game_effect_presenters[11180] + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this[-1].m_third_person_game_effect_presenters[11024],
      v7,
      &m_0);
  }
  else
  {
    vostok::render::scene_renderer::add_tracer(
      v4,
      *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float4x4 const &>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > > **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)&this[-1].m_third_person_game_effect_presenters[11180] + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this[-1].m_third_person_game_effect_presenters[11024],
      v7);
  }
}
