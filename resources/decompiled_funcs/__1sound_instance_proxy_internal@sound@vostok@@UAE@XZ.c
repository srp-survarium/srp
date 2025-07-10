void __thiscall vostok::sound::sound_instance_proxy_internal::~sound_instance_proxy_internal(
        vostok::sound::sound_instance_proxy_internal *this)
{
  this->__vftable = (vostok::sound::sound_instance_proxy_internal_vtbl *)&vostok::sound::sound_instance_proxy_internal::`vftable';
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&this->m_sound_emitter);
  this->__vftable = (vostok::sound::sound_instance_proxy_internal_vtbl *)&vostok::sound::sound_instance_proxy::`vftable';
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_callback);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
