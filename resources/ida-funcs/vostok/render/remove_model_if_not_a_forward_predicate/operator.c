bool __usercall vostok::render::remove_model_if_not_a_forward_predicate::operator()@<al>(
        const vostok::render::render_surface_instance *const surface@<eax>,
        vostok::render::render_surface *a2@<ecx>)
{
  vostok::render::material_effects *material_effects; // ebx
  bool v3; // bl
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp+Ch] [ebp-4h] BYREF

  v5.m_object = 0;
  material_effects = vostok::render::render_surface::get_material_effects(a2, (int)surface->m_render_surface);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v5,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&material_effects->m_effects[16]);
  v3 = !v5.m_object || material_effects->draw_to_gbuffer;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
  return v3;
}
