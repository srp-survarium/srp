void __thiscall vostok::sound::panning_lut_cook::translate_query(
        vostok::sound::panning_lut_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *v2; // eax
  vostok::sound::panning_lut *v3; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp-Ch] [ebp-4Ch] BYREF
  const vostok::resources::memory_type *v5; // [esp-8h] [ebp-48h]
  unsigned int v6; // [esp-4h] [ebp-44h]
  vostok::sound::panning_lut *v7; // [esp+0h] [ebp-40h]
  vostok::sound::panning_lut *v8; // [esp+4h] [ebp-3Ch]
  vostok::sound::panning_lut_cook *thisa; // [esp+8h] [ebp-38h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v10; // [esp+Ch] [ebp-34h]
  vostok::resources::memory_type *v11; // [esp+24h] [ebp-1Ch]
  int v12; // [esp+28h] [ebp-18h]
  vostok::sound::panning_lut *v13; // [esp+30h] [ebp-10h]
  vostok::sound::panning_lut *lut; // [esp+34h] [ebp-Ch]
  vostok::variant<32> *user_data; // [esp+38h] [ebp-8h]
  unsigned __int8 channels_num; // [esp+3Fh] [ebp-1h] BYREF

  thisa = this;
  user_data = parent->m_user_data;
  channels_num = 2;
  if ( user_data )
    vostok::variant<32>::try_get<unsigned char>(user_data, &channels_num);
  v2 = type_info::name(&vostok::sound::panning_lut `RTTI Type Descriptor', &__type_info_root_node);
  lut = (vostok::sound::panning_lut *)vostok::resources::allocate_unmanaged_memory(0x4908u, v2);
  if ( lut )
  {
    v13 = lut;
    vostok::sound::panning_lut::panning_lut(lut, channels_num);
    v7 = v3;
    v8 = v3;
  }
  else
  {
    v8 = 0;
  }
  lut = v8;
  if ( v8 )
  {
    v6 = 18696;
    v5 = &vostok::resources::nocache_memory;
    v10 = &v4;
    v4.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v4,
      (vostok::configs::binary_config *)lut);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      parent,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v4.m_object,
      v5,
      v6);
    vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
  }
  else
  {
    v11 = &vostok::resources::unmanaged_memory;
    v12 = 18696;
    parent->m_out_of_memory.type = &vostok::resources::unmanaged_memory;
    parent->m_out_of_memory.size = 18696;
    vostok::resources::query_result_for_cook::finish_query(parent, result_out_of_memory, assert_on_fail_true);
  }
}
