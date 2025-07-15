void __thiscall survarium::game_world::update_tracer(
        survarium::game_world *this,
        unsigned __int16 tracer_idx,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        unsigned int length)
{
  float z; // edx
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  vostok::math::float3 scale; // [esp+Ch] [ebp-4Ch] BYREF
  vostok::math::float4x4 m; // [esp+18h] [ebp-40h] BYREF

  vostok::math::create_translation(&m, position);
  z = direction->z;
  *(_QWORD *)&m.lines[2].x = *(_QWORD *)&direction->x;
  m.k.z = z;
  v7 = z - (float)(m.k.y * 0.0);
  v8 = (float)(m.k.x * 0.0) - (float)(z * 0.0);
  scale.y = v8;
  scale.x = v7;
  v9 = (float)(m.k.y * 0.0) - m.k.x;
  *(_QWORD *)&m.i.x = *(_QWORD *)&scale.x;
  scale.x = (float)(v9 * m.k.y) - (float)(v8 * z);
  scale.y = (float)(z * v7) - (float)(v9 * m.k.x);
  *(_QWORD *)&m.lines[1].x = *(_QWORD *)&scale.x;
  LODWORD(scale.x) = clear_value;
  *(_QWORD *)&scale.elements[1] = __PAIR64__(length, (unsigned int)clear_value);
  m.i.z = v9;
  m.j.z = (float)(v8 * m.k.x) - (float)(m.k.y * v7);
  vostok::math::float4x4::set_scale(&m, &scale);
  vostok::render::scene_renderer::update_tracer(
    (vostok::render::scene_renderer *)this[-1].m_input_mode,
    *(vostok::render::scene_renderer **)(*(_DWORD *)(this[-1].m_input_mode + 148) + 16),
    (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)&this[-1].m_enemies_for_team_1._M_impl._M_finish,
    (const vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *)(this->m_construct_thread_id + 8 * tracer_idx + 4),
    &m);
}
