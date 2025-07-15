void __thiscall survarium::victory_item::reset_bone_matrices(
        survarium::victory_item *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a2)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  int v3; // esi
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_distance_low; // edi
  const vostok::math::float4x4 *v5; // eax
  unsigned int v6; // edi
  void *v7; // esp
  vostok::math::float4x4 *v8; // eax
  _DWORD v9[6]; // [esp-8h] [ebp-ACh] BYREF
  _BYTE v10[64]; // [esp+10h] [ebp-94h] BYREF
  vostok::math::float4x4 v11; // [esp+50h] [ebp-54h] BYREF
  vostok::buffer_vector<vostok::math::float4x4> v12; // [esp+90h] [ebp-14h] BYREF
  vostok::render::scene_renderer *v13; // [esp+9Ch] [ebp-8h]

  m_object = a2.m_object;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &a2,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(LODWORD(a2.m_object->m_lods[6].m_time_fade_in) + 4));
  v3 = *(_DWORD *)(*(_DWORD *)(LODWORD(m_object->m_lods[6].m_time_fade_in) + 160) + 172);
  m_distance_low = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)LODWORD(m_object->m_lods[6].m_distance);
  v13 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + v3);
  v9[0] = ((int (__thiscall *)(vostok::particle::particle_system_instance_impl *, _BYTE *))m_object->is_increasing_quality)(
            m_object,
            v10);
  v5 = (const vostok::math::float4x4 *)((int (__thiscall *)(vostok::particle::particle_system_instance_impl *))m_object->is_increasing_quality)(m_object);
  vostok::render::scene_renderer::update_model(m_distance_low + 66, v13, &a2, v5, &v11);
  v6 = *(_DWORD *)(*(_DWORD *)&m_object->m_lods[5].m_emitter_instance_list.gap4 + 264)
     - (*(_DWORD *)(*(_DWORD *)&m_object->m_lods[5].m_emitter_instance_list.gap4 + 280)
      - (*(_DWORD *)&m_object->m_lods[5].m_emitter_instance_list.gap4
       + 272))
     / 28;
  v13 = (vostok::render::scene_renderer *)(v6 << 6);
  v7 = alloca(v6 << 6);
  v12.m_begin = (vostok::math::float4x4 *)v9;
  v12.m_end = (vostok::math::float4x4 *)v9;
  v12.m_max_end = (vostok::math::float4x4 *)&v9[16 * v6];
  v8 = vostok::math::float4x4::identity(v12.m_max_end, &v11);
  vostok::buffer_vector<vostok::math::float4x4>::resize(v6, &v12, v8);
  (*(void (__thiscall **)(_DWORD, vostok::math::float4x4 *, unsigned int))(**(_DWORD **)(LODWORD(m_object->m_lods[6].m_distance)
                                                                                       + 264)
                                                                         + 56))(
    *(_DWORD *)(LODWORD(m_object->m_lods[6].m_distance) + 264),
    v12.m_begin,
    v6);
  vostok::render::scene_renderer::update_skeleton(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(LODWORD(m_object->m_lods[6].m_distance) + 264),
    *(vostok::memory::base_allocator **)((char *)&dword_200060 + v3),
    v12.m_begin,
    v12.m_begin,
    v6);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
}
