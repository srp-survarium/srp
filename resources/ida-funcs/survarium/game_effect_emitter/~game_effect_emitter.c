void __thiscall survarium::game_effect_emitter::~game_effect_emitter(survarium::game_effect_emitter *this)
{
  this->__vftable = (survarium::game_effect_emitter_vtbl *)&survarium::game_effect_emitter::`vftable';
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_emitter);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
