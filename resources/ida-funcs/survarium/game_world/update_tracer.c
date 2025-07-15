void __thiscall survarium::game_world::update_tracer(
        survarium::game_world *this,
        survarium::bullet *bullet,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        unsigned int length)
{
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  unsigned __int16 m_tracer_idx; // [esp+Ch] [ebp-54h]
  vostok::render::scene_renderer *v10; // [esp+10h] [ebp-50h]
  vostok::math::float3 scale; // [esp+14h] [ebp-4Ch] BYREF
  vostok::math::float4x4 v12; // [esp+20h] [ebp-40h] BYREF

  m_tracer_idx = bullet->m_tracer_idx;
  if ( m_tracer_idx != 0xFFFF )
  {
    v10 = *(vostok::render::scene_renderer **)&this->m_third_person_game_effect_presenters[10964];
    vostok::math::create_translation(position, &v12);
    *(_QWORD *)&v12.lines[2].x = *(_QWORD *)&direction->x;
    v12.k.z = direction->z;
    v6 = (float)(v12.k.x * 0.0) - (float)(v12.k.z * 0.0);
    v7 = v12.k.z - (float)(v12.k.y * 0.0);
    v8 = (float)(v12.k.y * 0.0) - v12.k.x;
    v12.i.x = v7;
    v12.i.y = v6;
    v12.i.z = v8;
    v12.j.x = (float)(v8 * v12.k.y) - (float)(v6 * v12.k.z);
    v12.j.y = (float)(v12.k.z * v7) - (float)(v8 * v12.k.x);
    v12.j.z = (float)(v6 * v12.k.x) - (float)(v12.k.y * v7);
    scale.x = s_bm_current_air_resistance;
    *(_QWORD *)&scale.elements[1] = __PAIR64__(length, LODWORD(s_bm_current_air_resistance));
    vostok::math::float4x4::set_scale(&v12, &scale);
    vostok::render::scene_renderer::update_tracer(
      v10,
      *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float4x4 const &>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > > **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)&this[-1].m_third_person_game_effect_presenters[11180] + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this[-1].m_third_person_game_effect_presenters[11024],
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10->m_channel
    + 2 * m_tracer_idx,
      &v12);
  }
}
