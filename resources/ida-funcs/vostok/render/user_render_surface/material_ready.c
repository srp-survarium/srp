void __thiscall vostok::render::user_render_surface::material_ready(
        vostok::render::user_render_surface *this,
        vostok::particle::particle_system_instance_impl *data,
        vostok::render::material_effects_instance_cook_data *cook_data,
        char *material_name)
{
  vostok::memory::doug_lea_allocator *m_lock; // ecx
  vostok::particle::particle_system_instance_impl *v6; // ecx
  vostok::render::render_surface *v7; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp-8h] [ebp-14h] BYREF
  char *v9; // [esp-4h] [ebp-10h]
  const char *v10; // [esp+0h] [ebp-Ch]
  const char *v11; // [esp+4h] [ebp-8h]
  unsigned int v12; // [esp+8h] [ebp-4h]

  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::material_effects_instance_cook_data>(
    vostok::render::g_allocator,
    &cook_data,
    v10,
    v11,
    v12);
  m_lock = (vostok::memory::doug_lea_allocator *)data->m_parent_resources.m_lock;
  if ( m_lock == (vostok::memory::doug_lea_allocator *)1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_lods[1].m_emitter_instance_list);
    v9 = material_name;
    v8.m_object = v6;
    vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
      &v8,
      data);
    vostok::render::render_surface::set_material_effects(
      v7,
      (vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base>)this,
      (const char *)v8.m_object,
      v9);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  }
  if ( material_name )
    vostok::memory::doug_lea_allocator::free_impl(
      m_lock,
      (int)vostok::render::g_allocator,
      material_name,
      v10,
      v11,
      v12);
}
