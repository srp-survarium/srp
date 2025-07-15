void __userpurge vostok::render::stage_particles::stage_particles(
        vostok::render::stage_particles *this@<edi>,
        vostok::render::renderer_context *in_context@<ecx>,
        vostok::render::renderer *in_renderer,
        vostok::render::effect_manager *in_stage_mode)
{
  vostok::render::effect_manager *v4; // ecx
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v5; // esi
  vostok::shared_string *v6; // ecx
  vostok::render::backend *v7; // ecx

  vostok::render::stage::stage(this, in_context, in_renderer);
  v4 = in_stage_mode;
  v5 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
  this->__vftable = (vostok::render::stage_particles_vtbl *)&vostok::render::stage_particles::`vftable';
  this->m_sh_particle_sprite.m_object = 0;
  this->m_sh_particle_beamtrail.m_object = 0;
  this->m_resolve_particles_effect.m_object = 0;
  this->m_g_particle_sprite.m_object = 0;
  this->m_g_subuv_particle_sprite.m_object = 0;
  this->m_g_particle_beamtrail.m_object = 0;
  this->m_stage_mode = (vostok::render::stage_particles::stage_mode)v4;
  vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_particles>(
    v4,
    v5,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_resolve_particles_effect);
  vostok::shared_string::shared_string(
    v6,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&in_renderer,
    "particle_screen_divider");
  this->m_c_particle_screen_divider = vostok::render::backend::register_constant_host(
                                        v7,
                                        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                        (const vostok::shared_string *)&in_renderer,
                                        0);
  if ( in_renderer )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)in_renderer, 0xFFFFFFFF) )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_renderer);
  }
}
