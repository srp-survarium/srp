void __thiscall vostok::sound::destroy_sound_instance_proxy_order::~destroy_sound_instance_proxy_order(
        vostok::sound::destroy_sound_instance_proxy_order *this)
{
  this->__vftable = (vostok::sound::destroy_sound_instance_proxy_order_vtbl *)&vostok::sound::destroy_sound_instance_proxy_order::`vftable';
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_sound_scene);
  this->__vftable = (vostok::sound::destroy_sound_instance_proxy_order_vtbl *)&vostok::sound::sound_order::`vftable';
}
