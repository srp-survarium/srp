void __userpurge vostok::render::stage_decals_accumulate::stage_decals_accumulate(
        vostok::render::stage_decals_accumulate *this@<edi>,
        vostok::render::renderer_context *context@<ecx>,
        vostok::render::renderer *in_renderer)
{
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v3; // esi
  vostok::render::effect_manager *v4; // ecx
  vostok::render::effect_manager *v5; // ecx

  vostok::render::stage::stage(this, context, in_renderer);
  v3 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
  this->__vftable = (vostok::render::stage_decals_accumulate_vtbl *)&vostok::render::stage_decals_accumulate::`vftable';
  this->m_opaque_geometry_mask_effect.m_object = 0;
  this->m_apply_decal_effect.m_object = 0;
  vostok::render::effect_manager::create_effect<vostok::render::effect_decal_mask>(
    v4,
    v3,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_opaque_geometry_mask_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_apply_decal>(
    v5,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_apply_decal_effect);
}
