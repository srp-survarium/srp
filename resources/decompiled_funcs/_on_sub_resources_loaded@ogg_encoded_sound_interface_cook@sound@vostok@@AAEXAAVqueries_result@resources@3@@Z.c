void __thiscall vostok::sound::ogg_encoded_sound_interface_cook::on_sub_resources_loaded(
        vostok::sound::ogg_encoded_sound_interface_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_user *v2; // eax
  const char *v3; // eax
  vostok::resources::managed_resource *v4; // eax
  vostok::resources::query_result_for_cook *v5; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp-Ch] [ebp-7Ch] BYREF
  const vostok::resources::memory_type *v7; // [esp-8h] [ebp-78h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v8[3]; // [esp-4h] [ebp-74h] BYREF
  vostok::resources::managed_resource *v9; // [esp+8h] [ebp-68h]
  vostok::sound::ogg_encoded_sound_interface_cook *thisa; // [esp+Ch] [ebp-64h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v11; // [esp+18h] [ebp-58h]
  vostok::resources::memory_type *v12; // [esp+38h] [ebp-38h]
  int v13; // [esp+3Ch] [ebp-34h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v14; // [esp+40h] [ebp-30h]
  volatile int *value; // [esp+44h] [ebp-2Ch]
  vostok::sound::ogg_encoded_sound_interface *v16; // [esp+5Ch] [ebp-14h]
  char v17; // [esp+63h] [ebp-Dh]
  vostok::resources::query_result_for_cook *parent; // [esp+64h] [ebp-Ch]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ogg_raw_file; // [esp+68h] [ebp-8h] BYREF
  vostok::sound::ogg_encoded_sound_interface *encoded_sound; // [esp+6Ch] [ebp-4h]

  thisa = this;
  v17 = 0;
  parent = data->m_parent_query;
  v2 = vostok::resources::queries_result::operator[](data, 0);
  vostok::resources::query_result_for_user::get_managed_resource(v2, &ogg_raw_file);
  v3 = type_info::name(&vostok::sound::ogg_encoded_sound_interface `RTTI Type Descriptor', &__type_info_root_node);
  encoded_sound = (vostok::sound::ogg_encoded_sound_interface *)vostok::resources::allocate_unmanaged_memory(0x418u, v3);
  if ( encoded_sound )
  {
    v16 = encoded_sound;
    v14 = v8;
    v8[0].m_object = 0;
    if ( ogg_raw_file.m_object )
    {
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(v14);
      v14->m_object = ogg_raw_file.m_object;
      if ( v14->m_object )
      {
        value = &v14->m_object->m_reference_count;
        vostok::threading::multi_threading_policy::increment<long volatile>(value);
      }
    }
    vostok::sound::ogg_encoded_sound_interface::ogg_encoded_sound_interface(v16, v8[0]);
    v8[2].m_object = v4;
    v8[1].m_object = v4;
    v9 = v4;
  }
  else
  {
    v9 = 0;
  }
  if ( encoded_sound )
  {
    v8[0].m_object = (vostok::resources::managed_resource *)1048;
    v7 = &vostok::resources::nocache_memory;
    v11 = &v6;
    v6.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v6,
      (vostok::configs::binary_config *)encoded_sound);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      parent,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v6.m_object,
      v7,
      (unsigned int)v8[0].m_object);
    vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&ogg_raw_file);
  }
  else
  {
    v12 = &vostok::resources::unmanaged_memory;
    v13 = 1048;
    v5 = parent;
    parent->m_out_of_memory.type = &vostok::resources::unmanaged_memory;
    v5->m_out_of_memory.size = 1048;
    vostok::resources::query_result_for_cook::finish_query(parent, result_out_of_memory, assert_on_fail_true);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&ogg_raw_file);
  }
}
