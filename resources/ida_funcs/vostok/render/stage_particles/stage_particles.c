void __usercall vostok::render::stage_particles::stage_particles(
        vostok::render::stage_particles *this@<esi>,
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>)
{
  survarium::game_action_id *M_start; // edx

  M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  this->m_context = context;
  this->m_renderer = in_renderer;
  this->__vftable = (vostok::render::stage_particles_vtbl *)&vostok::render::stage_particles::`vftable';
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->m_sh_particle_sprite.m_object = 0;
  this->m_sh_particle_beamtrail.m_object = 0;
  this->m_resolve_particles_effect.m_object = 0;
  this->m_g_particle_sprite.m_object = 0;
  this->m_g_subuv_particle_sprite.m_object = 0;
  this->m_g_particle_beamtrail.m_object = 0;
  this->m_enabled = *((_BYTE *)M_start + 254);
  vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_particles>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_resolve_particles_effect);
}
