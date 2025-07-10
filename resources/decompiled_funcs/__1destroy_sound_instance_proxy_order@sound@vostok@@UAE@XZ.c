void __thiscall vostok::sound::destroy_sound_instance_proxy_order::~destroy_sound_instance_proxy_order(
        vostok::sound::destroy_sound_instance_proxy_order *this)
{
  this->__vftable = (vostok::sound::destroy_sound_instance_proxy_order_vtbl *)&vostok::sound::destroy_sound_instance_proxy_order::`vftable';
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&this->m_sound_scene);
  vostok::sound::sound_order::~sound_order(this);
}
