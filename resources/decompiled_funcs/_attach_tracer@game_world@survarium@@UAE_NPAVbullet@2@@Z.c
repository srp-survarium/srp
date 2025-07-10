char __thiscall survarium::game_world::attach_tracer(
        survarium::game_world *this,
        vostok::render::tracer_model_instance *bullet)
{
  unsigned __int16 v3; // ax
  vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *v4; // ecx
  vostok::math::float4x4 v6; // [esp+10h] [ebp-40h] BYREF

  if ( (_S6_9 & 1) == 0 )
  {
    _S6_9 |= 1u;
    qmemcpy((void *)&initial_tracer_matrix, vostok::math::float4x4::identity(&v6), sizeof(initial_tracer_matrix));
  }
  v3 = s_tracer_idx % (unsigned int)((int)((int)this->m_memory_type_data - this->m_construct_thread_id) >> 3);
  v4 = (vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *)(this->m_construct_thread_id + 8 * v3);
  HIWORD(bullet->m_current_quality_level) = v3;
  v4->m_object = bullet;
  vostok::render::scene_renderer::add_tracer(
    *(vostok::render::scene_renderer **)(this[-1].m_input_mode + 148),
    *(vostok::render::scene_renderer **)(*(_DWORD *)(this[-1].m_input_mode + 148) + 16),
    (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)&this[-1].m_enemies_for_team_1._M_impl._M_finish,
    v4 + 1);
  ++s_tracer_idx;
  return 1;
}
