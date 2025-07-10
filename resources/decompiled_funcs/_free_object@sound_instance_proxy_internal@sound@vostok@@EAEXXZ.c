void __thiscall vostok::sound::sound_instance_proxy_internal::free_object(
        vostok::sound::sound_instance_proxy_internal *this)
{
  vostok::sound::sound_order *v1; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v2; // [esp-4h] [ebp-48h] BYREF
  vostok::sound::destroy_sound_instance_proxy_order *v3; // [esp+0h] [ebp-44h]
  vostok::sound::sound_order *v4; // [esp+4h] [ebp-40h]
  vostok::sound::sound_instance_proxy_internal *thisa; // [esp+8h] [ebp-3Ch]
  vostok::configs::binary_config *object; // [esp+Ch] [ebp-38h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // [esp+10h] [ebp-34h]
  vostok::sound::destroy_sound_instance_proxy_order *v8; // [esp+28h] [ebp-1Ch]
  vostok::memory::base_allocator *allocator; // [esp+2Ch] [ebp-18h]
  vostok::sound::destroy_sound_instance_proxy_order *v10; // [esp+3Ch] [ebp-8h]
  vostok::sound::destroy_sound_instance_proxy_order *order; // [esp+40h] [ebp-4h]

  thisa = this;
  _InterlockedExchange(&this->m_destruction_pending, 1);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_callback);
  allocator = vostok::sound::world_user::get_allocator(thisa->m_user);
  v8 = (vostok::sound::destroy_sound_instance_proxy_order *)vostok::memory::base_allocator::malloc_impl(
                                                              allocator,
                                                              0x1Cu);
  v10 = v8;
  if ( v8 )
  {
    object = (vostok::configs::binary_config *)thisa->m_scene;
    v7 = &v2;
    v2.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v2,
      object);
    vostok::sound::destroy_sound_instance_proxy_order::destroy_sound_instance_proxy_order(
      v10,
      thisa->m_user,
      thisa,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v2.m_object);
    v4 = v1;
    v3 = (vostok::sound::destroy_sound_instance_proxy_order *)v1;
  }
  else
  {
    v3 = 0;
  }
  order = v3;
  vostok::sound::world_user::add_order(thisa->m_user, v3);
}
