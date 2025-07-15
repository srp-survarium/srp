void __thiscall vostok::sound::wav_encoded_sound_interface_cook::on_file_loaded(
        vostok::sound::wav_encoded_sound_interface_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_user *v2; // eax
  const char *v3; // eax
  vostok::resources::managed_resource *v4; // eax
  vostok::resources::query_result_for_cook *v5; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp-Ch] [ebp-78h] BYREF
  const vostok::resources::memory_type *v7; // [esp-8h] [ebp-74h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v8[3]; // [esp-4h] [ebp-70h] BYREF
  vostok::resources::managed_resource *v9; // [esp+8h] [ebp-64h]
  vostok::sound::wav_encoded_sound_interface_cook *thisa; // [esp+Ch] [ebp-60h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v11; // [esp+18h] [ebp-54h]
  vostok::resources::memory_type *v12; // [esp+38h] [ebp-34h]
  int v13; // [esp+3Ch] [ebp-30h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v14; // [esp+40h] [ebp-2Ch]
  volatile int *value; // [esp+44h] [ebp-28h]
  vostok::sound::wav_encoded_sound_interface *v16; // [esp+5Ch] [ebp-10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> wav_raw_file; // [esp+60h] [ebp-Ch] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+64h] [ebp-8h]
  vostok::sound::wav_encoded_sound_interface *encoded_sound; // [esp+68h] [ebp-4h]

  thisa = this;
  parent = data->m_parent_query;
  if ( vostok::resources::queries_result::is_successful(data) )
  {
    v2 = vostok::resources::queries_result::operator[](data, 0);
    vostok::resources::query_result_for_user::get_managed_resource(v2, &wav_raw_file);
    v3 = type_info::name(&vostok::sound::wav_encoded_sound_interface `RTTI Type Descriptor', &__type_info_root_node);
    encoded_sound = (vostok::sound::wav_encoded_sound_interface *)vostok::resources::allocate_unmanaged_memory(
                                                                    0x130u,
                                                                    v3);
    if ( encoded_sound )
    {
      v16 = encoded_sound;
      v14 = v8;
      v8[0].m_object = 0;
      if ( wav_raw_file.m_object )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(v14);
        v14->m_object = wav_raw_file.m_object;
        if ( v14->m_object )
        {
          value = &v14->m_object->m_reference_count;
          vostok::threading::multi_threading_policy::increment<long volatile>(value);
        }
      }
      vostok::sound::wav_encoded_sound_interface::wav_encoded_sound_interface(v16, v8[0]);
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
      v8[0].m_object = (vostok::resources::managed_resource *)304;
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
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&wav_raw_file);
    }
    else
    {
      v12 = &vostok::resources::unmanaged_memory;
      v13 = 304;
      v5 = parent;
      parent->m_out_of_memory.type = &vostok::resources::unmanaged_memory;
      v5->m_out_of_memory.size = 304;
      vostok::resources::query_result_for_cook::finish_query(parent, result_out_of_memory, assert_on_fail_true);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&wav_raw_file);
    }
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
  }
}
