void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_olta>(
        vostok::render::effect_manager *this@<ecx>,
        vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *out_effect@<eax>)
{
  void *v4; // esp
  vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  vostok::render::custom_config *v6; // eax
  int v7; // [esp-3E8h] [ebp-418h] BYREF
  vostok::render::effect_options_descriptor empty_desc; // [esp+Ch] [ebp-24h] BYREF
  unsigned int out_data_crc; // [esp+24h] [ebp-Ch] BYREF
  vostok::render::effect_descriptor descriptor; // [esp+28h] [ebp-8h] BYREF
  unsigned int crc; // [esp+2Ch] [ebp-4h] BYREF

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_olta>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_olta>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_olta>'::`2'::descriptor_object.__vftable = (vostok::render::effect_olta_vtbl *)&vostok::render::effect_olta::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_olta>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
  }
  v4 = alloca(1024);
  empty_desc.data = (unsigned __int8 *)&v7;
  empty_desc.type = 3;
  empty_desc.count = 0;
  empty_desc.bytes = 0;
  empty_desc.id = 0;
  empty_desc.destroyer = 0;
  empty_desc.memory_size = 1024;
  crc = 0;
  if ( this->force_sync )
  {
    vostok::render::create_custom_config_impl_vostok::render::effect_options_descriptor__0(
      &empty_desc,
      &out_data_crc,
      (bool)&crc);
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_olta>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
    vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>::operator=(
      v5,
      &out_effect->m_object);
    if ( descriptor.__vftable
      && !_InterlockedExchangeAdd(
            (volatile signed __int32 *)&descriptor.__vftable[17].should_recompile_when_global_changes,
            0xFFFFFFFF) )
    {
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)&descriptor.__vftable[17].should_recompile_when_global_changes,
        (vostok::resources::unmanaged_resource *)descriptor.__vftable);
    }
  }
  else
  {
    vostok::render::create_custom_config_impl_vostok::render::effect_options_descriptor__0(
      &empty_desc,
      &out_data_crc,
      (bool)&crc);
    vostok::render::effect_manager::create_new_effect(
      this,
      out_effect,
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_olta>'::`2'::descriptor_object,
      (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&out_data_crc,
      crc);
  }
  v6 = (vostok::render::custom_config *)out_data_crc;
  if ( out_data_crc )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)out_data_crc, 0xFFFFFFFF) )
      vostok::render::custom_config::destroy(v6, v6);
  }
}
