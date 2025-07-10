void __thiscall vostok::sound::ogg_sound_cook::on_sub_resources_loaded(
        vostok::sound::ogg_sound_cook *this,
        vostok::resources::queries_result *data)
{
  const char *v2; // eax
  vostok::resources::unmanaged_resource *v3; // ecx
  int v4; // eax
  vostok::resources::query_result_for_cook *v5; // edx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v6; // [esp-Ch] [ebp-88h] BYREF
  const vostok::resources::memory_type *v7; // [esp-8h] [ebp-84h]
  unsigned int v8; // [esp-4h] [ebp-80h]
  int v9; // [esp+0h] [ebp-7Ch]
  int v10; // [esp+4h] [ebp-78h]
  vostok::sound::ogg_sound_cook *thisa; // [esp+8h] [ebp-74h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v12; // [esp+1Ch] [ebp-60h]
  vostok::resources::memory_type *v13; // [esp+30h] [ebp-4Ch]
  int v14; // [esp+34h] [ebp-48h]
  vostok::resources::managed_resource *v15; // [esp+3Ch] [ebp-40h]
  vostok::resources::managed_resource *v16; // [esp+40h] [ebp-3Ch]
  vostok::resources::query_result_for_user *v17; // [esp+44h] [ebp-38h]
  vostok::sound::sound_spl *object; // [esp+4Ch] [ebp-30h]
  vostok::configs::binary_config *m_object; // [esp+50h] [ebp-2Ch]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v20; // [esp+54h] [ebp-28h]
  vostok::sound::ogg_sound *v21; // [esp+5Ch] [ebp-20h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v22; // [esp+60h] [ebp-1Ch] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v23; // [esp+64h] [ebp-18h] BYREF
  char v24; // [esp+6Bh] [ebp-11h]
  vostok::resources::resource_ptr<vostok::sound::ogg_file_contents,vostok::resources::unmanaged_intrusive_base> file_contents; // [esp+6Ch] [ebp-10h] BYREF
  vostok::sound::ogg_sound *new_sound; // [esp+70h] [ebp-Ch]
  vostok::resources::query_result_for_cook *parent; // [esp+74h] [ebp-8h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> rms_ptr; // [esp+78h] [ebp-4h] BYREF

  thisa = this;
  v24 = 0;
  parent = data->m_parent_query;
  v20 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, 0);
  v23.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v23,
    v20 + 55);
  m_object = v23.m_object;
  object = (vostok::sound::sound_spl *)v23.m_object;
  file_contents.m_object = 0;
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&file_contents,
    (vostok::sound::sound_spl *)v23.m_object);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v23);
  v17 = vostok::resources::queries_result::operator[](data, 1u);
  v22.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v22,
    &v17->m_managed_resource);
  v16 = v22.m_object;
  v15 = v22.m_object;
  rms_ptr.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &rms_ptr,
    v22.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v22);
  v2 = type_info::name(&vostok::sound::ogg_sound `RTTI Type Descriptor', &__type_info_root_node);
  new_sound = (vostok::sound::ogg_sound *)vostok::resources::allocate_unmanaged_memory(0x110u, v2);
  if ( new_sound )
  {
    v21 = new_sound;
    vostok::sound::ogg_sound::ogg_sound(new_sound, &file_contents, &rms_ptr);
    v9 = v4;
    v10 = v4;
  }
  else
  {
    v10 = 0;
  }
  if ( new_sound )
  {
    v8 = 272;
    v7 = &vostok::resources::nocache_memory;
    v6.m_object = v3;
    v12 = &v6;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v6,
      (vostok::configs::binary_config *)new_sound);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(parent, v6, v7, v8);
    vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&rms_ptr);
    vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&file_contents);
  }
  else
  {
    v13 = &vostok::resources::unmanaged_memory;
    v14 = 272;
    v5 = parent;
    parent->m_out_of_memory.type = &vostok::resources::unmanaged_memory;
    v5->m_out_of_memory.size = 272;
    vostok::resources::query_result_for_cook::finish_query(parent, result_out_of_memory, assert_on_fail_true);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&rms_ptr);
    vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&file_contents);
  }
}
