void __thiscall vostok::particle::particle_action_light::init(
        vostok::particle::particle_action_light *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float __formal)
{
  P->particle_light_id = ++vostok::particle::g_particle_lights_id;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))instance->m_engine->add_light)(
    P->particle_light_id,
    this->m_enable_shadows,
    this->m_static_shadows,
    this->m_shadow_transparency,
    this->m_shadow_map_size_index);
}
