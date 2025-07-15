void __userpurge survarium::grenade_set::preview(survarium::grenade_set *this@<ecx>, int a2@<eax>, bool on)
{
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v5; // esi
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // eax
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // eax
  vostok::render::scene_renderer *v8; // [esp-10h] [ebp-98h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v9; // [esp-Ch] [ebp-94h]
  vostok::math::float4x4 shadow_transform; // [esp+8h] [ebp-80h] BYREF
  vostok::math::float4x4 transform; // [esp+48h] [ebp-40h] BYREF

  if ( on )
  {
    survarium::grenade_set::preview_transform(this, a2, &transform, &shadow_transform);
    v4 = *(const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 368);
    v5 = *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 372);
    v6 = v4 + 66;
    v9 = v5 + 1;
    v8 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + v5[40].m_object->m_fat_it.m_type);
    if ( BYTE1(v6->m_object->m_lods[0].m_emitter_instance_list.m_size) )
      vostok::render::scene_renderer::update_model(v6, v8, v9, &transform, &shadow_transform);
    else
      vostok::render::scene_renderer::add_model(v6, v8, v9, &transform, &shadow_transform);
  }
  else
  {
    v7 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(a2 + 368) + 264);
    if ( BYTE1(v7->m_object->m_lods[0].m_emitter_instance_list.m_size) )
      vostok::render::scene_renderer::remove_model(
        v7,
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 372) + 160) + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(a2 + 372) + 4));
  }
}
