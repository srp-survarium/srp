void __userpurge vostok::render::stage_apply_distortion::stage_apply_distortion(
        vostok::render::stage_apply_distortion *this@<edi>,
        vostok::render::renderer_context *context@<ecx>,
        vostok::render::renderer *in_renderer)
{
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v3; // esi
  vostok::render::effect_manager *v4; // ecx
  vostok::render::effect_manager *v5; // ecx

  vostok::render::stage::stage(this, context, in_renderer);
  v3 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
  this->__vftable = (vostok::render::stage_apply_distortion_vtbl *)&vostok::render::stage_apply_distortion::`vftable';
  this->m_sh_apply_distortion.m_object = 0;
  this->m_olta_effect.m_object = 0;
  vostok::render::effect_manager::create_effect<vostok::render::effect_apply_distortion>(
    v4,
    v3,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_sh_apply_distortion);
  vostok::render::effect_manager::create_effect<vostok::render::effect_olta>(
    v5,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_olta_effect);
}
