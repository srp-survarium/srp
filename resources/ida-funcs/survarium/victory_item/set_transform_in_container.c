void __userpurge survarium::victory_item::set_transform_in_container(
        survarium::victory_item *this@<ecx>,
        _DWORD *a2@<esi>,
        const vostok::math::float3 *position,
        const vostok::math::float3 *rotation)
{
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // eax
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v5; // edi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // ebx
  int v8; // eax
  const vostok::math::float4x4 *v9; // eax
  vostok::math::float4x4 *v10; // edi
  vostok::math::float4x4 *v11; // eax
  vostok::render::scene_renderer *v12; // [esp+Ch] [ebp-C4h]
  vostok::math::float4x4 v13; // [esp+10h] [ebp-C0h] BYREF
  vostok::math::float4x4 v14; // [esp+50h] [ebp-80h] BYREF
  _BYTE v15[64]; // [esp+90h] [ebp-40h] BYREF

  v4 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2[119] + 264);
  if ( BYTE1(v4->m_object->m_lods[0].m_emitter_instance_list.m_size) )
    vostok::render::scene_renderer::remove_model(
      v4,
      *(vostok::render::scene_renderer **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(a2[120] + 160) + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2[120] + 4));
  v5 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)a2[118];
  if ( !BYTE1(v5[66].m_object->m_lods[0].m_emitter_instance_list.m_size) )
  {
    v6 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)a2[120];
    v7 = v6 + 1;
    v12 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + v6[40].m_object->m_fat_it.m_type);
    v8 = (*(int (__thiscall **)(_DWORD *))(*a2 + 24))(a2);
    v9 = (const vostok::math::float4x4 *)(*(int (__thiscall **)(_DWORD *, float *, int))(*a2 + 24))(a2, &v13.c.w, v8);
    vostok::render::scene_renderer::add_model(v5 + 66, v12, v7, v9, &v13);
  }
  v10 = vostok::math::create_translation(position, &v14);
  v11 = vostok::math::create_rotation(rotation, (int)v10, (int)v15);
  vostok::math::mul4x3(v10, v11, &v13);
  vostok::render::scene_renderer::update_model(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2[118] + 264),
    *(vostok::render::scene_renderer **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(a2[120] + 160) + 172)),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2[120] + 4),
    &v13,
    &v13);
}
