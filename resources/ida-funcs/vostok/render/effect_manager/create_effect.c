void __usercall vostok::render::effect_manager::create_effect<vostok::render::capsule_light_effect>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::capsule_light_effect>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::capsule_light_effect>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::capsule_light_effect>'::`2'::descriptor_object.__vftable = (vostok::render::capsule_light_effect_vtbl *)&stru_9649F4.m_name.m_string.m_buffer[152];
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::capsule_light_effect>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::capsule_light_effect>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::capsule_light_effect>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_aberration>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_aberration>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_aberration>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_aberration>'::`2'::descriptor_object.__vftable = (vostok::render::effect_aberration_vtbl *)&vostok::render::effect_aberration::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_aberration>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_aberration>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_aberration>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_volume>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_volume>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_volume>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_volume>'::`2'::descriptor_object.__vftable = (vostok::render::effect_ambient_volume_vtbl *)&stru_9642F8.m_name.m_string.m_buffer[72];
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_volume>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_volume>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_volume>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_apply_decal>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_apply_decal>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_apply_decal>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_apply_decal>'::`2'::descriptor_object.__vftable = (vostok::render::effect_apply_decal_vtbl *)&stru_963F84.m_desc_3d.BindFlags;
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_apply_decal>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_apply_decal>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_apply_decal>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_apply_distortion>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_apply_distortion>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_apply_distortion>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_apply_distortion>'::`2'::descriptor_object.__vftable = (vostok::render::effect_apply_distortion_vtbl *)&vostok::render::effect_apply_distortion::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_apply_distortion>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_apply_distortion>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_apply_distortion>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_clouds>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_clouds>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_clouds>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_clouds>'::`2'::descriptor_object.__vftable = (vostok::render::effect_clouds_vtbl *)&stru_965008.m_bind;
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_clouds>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_clouds>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_clouds>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_clouds_god_rays>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_clouds_god_rays>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_clouds_god_rays>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_clouds_god_rays>'::`2'::descriptor_object.__vftable = (vostok::render::effect_clouds_god_rays_vtbl *)&stru_965008.m_desc.SampleDesc.Quality;
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_clouds_god_rays>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_clouds_god_rays>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_clouds_god_rays>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_copy_depth_rt>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_copy_depth_rt>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_copy_depth_rt>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_copy_depth_rt>'::`2'::descriptor_object.__vftable = (vostok::render::effect_copy_depth_rt_vtbl *)&stru_963F84.m_desc.MipLevels;
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_copy_depth_rt>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_copy_depth_rt>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_copy_depth_rt>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_copy_image>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_copy_image>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_copy_image>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_copy_image>'::`2'::descriptor_object.__vftable = (vostok::render::effect_copy_image_vtbl *)&vostok::render::effect_copy_image::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_copy_image>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_copy_image>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_copy_image>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_decal_mask>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_decal_mask>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_decal_mask>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_decal_mask>'::`2'::descriptor_object.__vftable = (vostok::render::effect_decal_mask_vtbl *)&stru_963F84.m_desc_3d.Depth;
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_decal_mask>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_decal_mask>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_decal_mask>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_eye_adaptation>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_eye_adaptation>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_eye_adaptation>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_eye_adaptation>'::`2'::descriptor_object.__vftable = (vostok::render::effect_eye_adaptation_vtbl *)&vostok::render::effect_eye_adaptation::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_eye_adaptation>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_eye_adaptation>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_eye_adaptation>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_fill_sky_ao_map>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_fill_sky_ao_map>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_fill_sky_ao_map>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_fill_sky_ao_map>'::`2'::descriptor_object.__vftable = (vostok::render::effect_fill_sky_ao_map_vtbl *)&vostok::render::effect_fill_sky_ao_map::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_fill_sky_ao_map>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_fill_sky_ao_map>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_fill_sky_ao_map>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_gather_bloom>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_gather_bloom>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_gather_bloom>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_gather_bloom>'::`2'::descriptor_object.__vftable = (vostok::render::effect_gather_bloom_vtbl *)&vostok::render::effect_gather_bloom::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_gather_bloom>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_gather_bloom>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_gather_bloom>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_gather_luminance>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_gather_luminance>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_gather_luminance>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_gather_luminance>'::`2'::descriptor_object.__vftable = (vostok::render::effect_gather_luminance_vtbl *)&vostok::render::effect_gather_luminance::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_gather_luminance>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_gather_luminance>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_gather_luminance>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_god_rays>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_god_rays>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_god_rays>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_god_rays>'::`2'::descriptor_object.__vftable = (vostok::render::effect_god_rays_vtbl *)&vostok::render::effect_god_rays::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_god_rays>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_god_rays>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_god_rays>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_grass_trample>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_grass_trample>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_grass_trample>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_grass_trample>'::`2'::descriptor_object.__vftable = (vostok::render::effect_grass_trample_vtbl *)&vostok::render::effect_grass_trample::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_grass_trample>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_grass_trample>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_grass_trample>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_hiz_occlusion>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_hiz_occlusion>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_hiz_occlusion>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_hiz_occlusion>'::`2'::descriptor_object.__vftable = (vostok::render::effect_hiz_occlusion_vtbl *)&stru_967C04.m_desc;
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_hiz_occlusion>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_hiz_occlusion>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_hiz_occlusion>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_lens_flares>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_lens_flares>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_lens_flares>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_lens_flares>'::`2'::descriptor_object.__vftable = (vostok::render::effect_lens_flares_vtbl *)&vostok::render::effect_lens_flares::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_lens_flares>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_lens_flares>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_lens_flares>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_light_mask>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_light_mask>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_light_mask>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_light_mask>'::`2'::descriptor_object.__vftable = (vostok::render::effect_light_mask_vtbl *)&stru_9642F8.m_name.m_string.m_buffer[24];
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_light_mask>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_light_mask>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_light_mask>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_motion_blur>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_motion_blur>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_motion_blur>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_motion_blur>'::`2'::descriptor_object.__vftable = (vostok::render::effect_motion_blur_vtbl *)&vostok::render::effect_motion_blur::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_motion_blur>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_motion_blur>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_motion_blur>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_fxaa>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_fxaa>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_fxaa>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_fxaa>'::`2'::descriptor_object.__vftable = (vostok::render::effect_post_process_fxaa_vtbl *)&vostok::render::effect_post_process_fxaa::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_fxaa>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_fxaa>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_fxaa>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_mlaa>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_mlaa>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_mlaa>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_mlaa>'::`2'::descriptor_object.__vftable = (vostok::render::effect_post_process_mlaa_vtbl *)&vostok::render::effect_post_process_mlaa::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_mlaa>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_mlaa>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_mlaa>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_sraa>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_sraa>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_sraa>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_sraa>'::`2'::descriptor_object.__vftable = (vostok::render::effect_post_process_sraa_vtbl *)&vostok::render::effect_post_process_sraa::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_sraa>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_sraa>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_sraa>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_rain>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_rain>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_rain>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_rain>'::`2'::descriptor_object.__vftable = (vostok::render::effect_rain_vtbl *)&vostok::render::effect_rain::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_rain>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_rain>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_rain>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_read_cloud_base>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_read_cloud_base>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_read_cloud_base>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_read_cloud_base>'::`2'::descriptor_object.__vftable = (vostok::render::effect_read_cloud_base_vtbl *)&stru_965008.m_desc.MipLevels;
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_read_cloud_base>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_read_cloud_base>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_read_cloud_base>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_reflection_mask>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_reflection_mask>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_reflection_mask>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_reflection_mask>'::`2'::descriptor_object.__vftable = (vostok::render::effect_reflection_mask_vtbl *)&stru_9642F8.m_name.m_string.m_buffer[88];
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_reflection_mask>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_reflection_mask>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_reflection_mask>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_lighting>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_lighting>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_lighting>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_lighting>'::`2'::descriptor_object.__vftable = (vostok::render::effect_resolve_lighting_vtbl *)&stru_964DF4.m_name.m_string.m_buffer[160];
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_lighting>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_lighting>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_lighting>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_particles>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_particles>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_particles>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_particles>'::`2'::descriptor_object.__vftable = (vostok::render::effect_resolve_particles_vtbl *)&vostok::render::effect_resolve_particles::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_particles>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_particles>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_particles>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>'::`2'::descriptor_object.__vftable = (vostok::render::effect_shadow_map_vtbl *)&stru_963F84.m_name.m_string.m_buffer[156];
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_simple_fog>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_simple_fog>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_simple_fog>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_simple_fog>'::`2'::descriptor_object.__vftable = (vostok::render::effect_simple_fog_vtbl *)&vostok::render::effect_simple_fog::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_simple_fog>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_simple_fog>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_simple_fog>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_skylight>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_skylight>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_skylight>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_skylight>'::`2'::descriptor_object.__vftable = (vostok::render::effect_skylight_vtbl *)&stru_9642F8.m_name.m_string.m_buffer[40];
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_skylight>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_skylight>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_skylight>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_accumulation>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_accumulation>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_accumulation>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_accumulation>'::`2'::descriptor_object.__vftable = (vostok::render::effect_ssao_accumulation_vtbl *)&vostok::render::effect_ssao_accumulation::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_accumulation>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_accumulation>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_accumulation>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_filter4x4>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_filter4x4>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_filter4x4>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_filter4x4>'::`2'::descriptor_object.__vftable = (vostok::render::effect_ssao_filter4x4_vtbl *)&vostok::render::effect_ssao_filter4x4::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_filter4x4>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_filter4x4>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_filter4x4>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_sun>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_sun>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_sun>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_sun>'::`2'::descriptor_object.__vftable = (vostok::render::effect_sun_vtbl *)&vostok::render::effect_sun::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_sun>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_sun>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_sun>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_system_colored>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_system_colored>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_system_colored>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_system_colored>'::`2'::descriptor_object.__vftable = (vostok::render::effect_system_colored_vtbl *)&vostok::render::effect_system_colored::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_system_colored>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_system_colored>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_system_colored>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_system_line>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_system_line>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_system_line>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_system_line>'::`2'::descriptor_object.__vftable = (vostok::render::effect_system_line_vtbl *)&vostok::render::effect_system_line::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_system_line>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_system_line>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_system_line>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_translucency>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_translucency>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_translucency>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_translucency>'::`2'::descriptor_object.__vftable = (vostok::render::effect_translucency_vtbl *)&stru_964DF4.m_name.m_string.m_buffer[92];
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_translucency>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_translucency>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_translucency>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_wet_surface>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_wet_surface>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_wet_surface>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_wet_surface>'::`2'::descriptor_object.__vftable = (vostok::render::effect_wet_surface_vtbl *)&stru_963F84.m_name.m_string.m_buffer[172];
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_wet_surface>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_wet_surface>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_wet_surface>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_wireframe_colored>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_wireframe_colored>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_wireframe_colored>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_wireframe_colored>'::`2'::descriptor_object.__vftable = (vostok::render::effect_wireframe_colored_vtbl *)&vostok::render::effect_wireframe_colored::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_wireframe_colored>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_wireframe_colored>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_wireframe_colored>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::scr_quad_effect>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::scr_quad_effect>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::scr_quad_effect>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::scr_quad_effect>'::`2'::descriptor_object.__vftable = (vostok::render::scr_quad_effect_vtbl *)&vostok::render::scr_quad_effect::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::scr_quad_effect>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::scr_quad_effect>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::scr_quad_effect>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_blur<3>>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<3>>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<3>>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<3>>'::`2'::descriptor_object.__vftable = (vostok::render::effect_blur<3>_vtbl *)&vostok::render::effect_blur<3>::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<3>>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<3>>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<3>>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_blur<5>>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<5>>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<5>>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<5>>'::`2'::descriptor_object.__vftable = (vostok::render::effect_blur<5>_vtbl *)&vostok::render::effect_blur<5>::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<5>>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<5>>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<5>>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_blur<7>>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<7>>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<7>>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<7>>'::`2'::descriptor_object.__vftable = (vostok::render::effect_blur<7>_vtbl *)&vostok::render::effect_blur<7>::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<7>>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<7>>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<7>>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_blur<9>>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<9>>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<9>>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<9>>'::`2'::descriptor_object.__vftable = (vostok::render::effect_blur<9>_vtbl *)&vostok::render::effect_blur<9>::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<9>>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<9>>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<9>>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_blur<17>>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<17>>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<17>>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<17>>'::`2'::descriptor_object.__vftable = (vostok::render::effect_blur<17>_vtbl *)&vostok::render::effect_blur<17>::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<17>>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<17>>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<17>>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_blur<21>>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<21>>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<21>>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<21>>'::`2'::descriptor_object.__vftable = (vostok::render::effect_blur<21>_vtbl *)&vostok::render::effect_blur<21>::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<21>>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<21>>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<21>>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_blur<25>>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<25>>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<25>>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<25>>'::`2'::descriptor_object.__vftable = (vostok::render::effect_blur<25>_vtbl *)&vostok::render::effect_blur<25>::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<25>>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<25>>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<25>>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::effect_blur<13>>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<13>>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<13>>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_blur<13>>'::`2'::descriptor_object.__vftable = (vostok::render::effect_blur<13>_vtbl *)&vostok::render::effect_blur<13>::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<13>>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<13>>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::effect_blur<13>>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<1>>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<1>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<1>>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<1>>'::`2'::descriptor_object.__vftable = (vostok::render::obb_light_effect<1>_vtbl *)&vostok::render::obb_light_effect<1>::`vftable';
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<1>>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<1>>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<1>>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<0>>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<0>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<0>>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<0>>'::`2'::descriptor_object.__vftable = (vostok::render::obb_light_effect<0>_vtbl *)&stru_9649F4.m_desc_valid;
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<0>>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<0>>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::obb_light_effect<0>>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<1>>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<1>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<1>>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<1>>'::`2'::descriptor_object.__vftable = (vostok::render::spot_light_effect<1>_vtbl *)&stru_9649F4.m_surface;
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<1>>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<1>>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<1>>'::`2'::descriptor_object,
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


void __usercall vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<0>>(
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

  if ( (`vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<0>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<0>>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<0>>'::`2'::descriptor_object.__vftable = (vostok::render::spot_light_effect<0>_vtbl *)&stru_9649F4.m_name.m_string.m_buffer[248];
    atexit(`vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<0>>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
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
    v5 = (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)vostok::render::effect_manager::create_new_effect((vostok::render::effect_manager *)&descriptor, (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this, &descriptor, (const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *)&`vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<0>>'::`2'::descriptor_object, (unsigned int)&out_data_crc);
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
      &`vostok::render::effect_manager::create_effect<vostok::render::spot_light_effect<0>>'::`2'::descriptor_object,
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
