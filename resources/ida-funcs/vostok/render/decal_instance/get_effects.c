const vostok::render::material_effects *__usercall vostok::render::decal_instance::get_effects@<eax>(
        vostok::render::decal_instance *this@<ecx>,
        int a2@<eax>)
{
  vostok::particle::particle_system_instance_impl *v2; // esi
  vostok::render::material_effects *material_effects; // esi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp+4h] [ebp-4h] BYREF

  v5.m_object = 0;
  v2 = *(vostok::particle::particle_system_instance_impl **)(a2 + 68);
  if ( v2 )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
    v5.m_object = v2;
    _InterlockedExchangeAdd(&v2->m_reference_count, 1u);
    material_effects = vostok::render::material_effects_instance::get_material_effects(
                         (vostok::render::material_effects_instance *)v2,
                         decal_vertex_input_type);
  }
  else
  {
    material_effects = *(vostok::render::material_effects **)&s_system_renderer_buffer.m_family[2].orig_name.m_buffer[44];
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
  return material_effects;
}
