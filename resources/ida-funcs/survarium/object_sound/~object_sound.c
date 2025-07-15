void __thiscall survarium::object_sound::~object_sound(survarium::object_sound *this)
{
  this->__vftable = (survarium::object_sound_vtbl *)&survarium::object_sound::`vftable';
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::dec(&this->m_sound_instance);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_sound_emitter);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
