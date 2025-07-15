void __thiscall survarium::game_effect::~game_effect(survarium::game_effect *this)
{
  survarium::loose_ptr_base *v1; // ecx

  this->__vftable = (survarium::game_effect_vtbl *)&survarium::game_effect::`vftable';
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_emitter);
  survarium::loose_ptr_base::~loose_ptr_base(v1);
}
