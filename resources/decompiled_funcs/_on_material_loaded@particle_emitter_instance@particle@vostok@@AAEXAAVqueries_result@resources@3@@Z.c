void __thiscall vostok::particle::particle_emitter_instance::on_material_loaded(
        vostok::particle::particle_emitter_instance *this,
        vostok::resources::queries_result *result)
{
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v2; // eax
  vostok::resources::query_result_for_user *v3; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  vostok::memory::pthreads3_allocator *v5; // eax
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v7; // [esp+14h] [ebp-4h] BYREF

  if ( vostok::resources::queries_result::is_successful(result) )
  {
    v2 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](result, 0);
    unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                           v3,
                           v2,
                           (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v7);
    vostok::particle::particle_emitter_instance::change_material(
      this,
      (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
  }
  if ( this->m_cook_data_to_delete )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    vostok::memory::delete_helper<vostok::memory::pthreads3_allocator,vostok::render::material_effects_instance_cook_data>(
      v5,
      &this->m_cook_data_to_delete);
  }
}
