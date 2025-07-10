void __thiscall vostok::sound::single_sound_cook::on_sub_resources_loaded(
        vostok::sound::single_sound_cook *this,
        vostok::resources::queries_result *data)
{
  const char *v2; // eax
  vostok::resources::unmanaged_resource *v3; // ecx
  vostok::sound::single_sound *v4; // eax
  vostok::resources::query_result_for_cook *v5; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v6; // [esp-Ch] [ebp-9Ch] BYREF
  const vostok::resources::memory_type *v7; // [esp-8h] [ebp-98h]
  unsigned int v8; // [esp-4h] [ebp-94h]
  vostok::sound::single_sound *v9; // [esp+0h] [ebp-90h]
  vostok::sound::single_sound *v10; // [esp+4h] [ebp-8Ch]
  vostok::sound::single_sound_cook *thisa; // [esp+8h] [ebp-88h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v12; // [esp+20h] [ebp-70h]
  vostok::resources::memory_type *v13; // [esp+38h] [ebp-58h]
  int v14; // [esp+3Ch] [ebp-54h]
  vostok::sound::sound_spl *v15; // [esp+40h] [ebp-50h]
  vostok::configs::binary_config *v16; // [esp+44h] [ebp-4Ch]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v17; // [esp+48h] [ebp-48h]
  vostok::resources::managed_resource *v18; // [esp+4Ch] [ebp-44h]
  vostok::resources::managed_resource *m_object; // [esp+50h] [ebp-40h]
  vostok::resources::query_result_for_user *v20; // [esp+54h] [ebp-3Ch]
  vostok::sound::encoded_sound_interface *object; // [esp+58h] [ebp-38h]
  vostok::resources::query_result_for_user *v22; // [esp+5Ch] [ebp-34h]
  int v23; // [esp+60h] [ebp-30h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v24; // [esp+68h] [ebp-28h] BYREF
  vostok::sound::single_sound *v25; // [esp+6Ch] [ebp-24h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v26; // [esp+70h] [ebp-20h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v27; // [esp+74h] [ebp-1Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v28; // [esp+78h] [ebp-18h] BYREF
  vostok::resources::resource_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base> spl_curve; // [esp+7Ch] [ebp-14h] BYREF
  vostok::sound::single_sound *new_sound; // [esp+80h] [ebp-10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> rms; // [esp+84h] [ebp-Ch] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+88h] [ebp-8h]
  vostok::resources::resource_ptr<vostok::sound::encoded_sound_with_qualities,vostok::resources::unmanaged_intrusive_base> encoded_sound; // [esp+8Ch] [ebp-4h] BYREF

  thisa = this;
  v23 = 0;
  parent = data->m_parent_query;
  if ( vostok::resources::queries_result::is_successful(data) )
  {
    v22 = vostok::resources::queries_result::operator[](data, 0);
    boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
      &v28,
      &v22->m_unmanaged_resource);
    object = (vostok::sound::encoded_sound_interface *)v28.m_object;
    vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&encoded_sound,
      (vostok::sound::encoded_sound_interface *)v28.m_object);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v28);
    v20 = vostok::resources::queries_result::operator[](data, 1u);
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
      &v27,
      &v20->m_managed_resource);
    m_object = v27.m_object;
    v18 = v27.m_object;
    rms.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &rms,
      v27.m_object);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v27);
    v17 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, 2u);
    v26.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v26,
      v17 + 55);
    v16 = v26.m_object;
    v15 = (vostok::sound::sound_spl *)v26.m_object;
    spl_curve.m_object = 0;
    vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &spl_curve.vostok::intrusive_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>,
      (vostok::sound::sound_spl *)v26.m_object);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v26);
    v2 = type_info::name(&vostok::sound::single_sound `RTTI Type Descriptor', &__type_info_root_node);
    new_sound = (vostok::sound::single_sound *)vostok::resources::allocate_unmanaged_memory(0x128u, v2);
    if ( new_sound )
    {
      v25 = new_sound;
      v24.m_object = 0;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        &v24,
        0);
      v23 |= 1u;
      vostok::sound::single_sound::single_sound(
        v25,
        &encoded_sound,
        &rms,
        (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&v24,
        &spl_curve);
      v9 = v4;
      v3 = v4;
      v10 = v4;
    }
    else
    {
      v10 = 0;
    }
    new_sound = v10;
    if ( (v23 & 1) != 0 )
    {
      v23 &= ~1u;
      vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v24);
    }
    if ( new_sound )
    {
      v8 = 296;
      v7 = &vostok::resources::nocache_memory;
      v6.m_object = v3;
      v12 = &v6;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v6,
        (vostok::configs::binary_config *)new_sound);
      vostok::resources::query_result_for_cook::set_unmanaged_resource(parent, v6, v7, v8);
      vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
      vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&spl_curve);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&rms);
      vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&encoded_sound);
    }
    else
    {
      v13 = &vostok::resources::unmanaged_memory;
      v14 = 296;
      v5 = parent;
      parent->m_out_of_memory.type = &vostok::resources::unmanaged_memory;
      v5->m_out_of_memory.size = 296;
      vostok::resources::query_result_for_cook::finish_query(parent, result_out_of_memory, assert_on_fail_true);
      vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&spl_curve);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&rms);
      vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&encoded_sound);
    }
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
  }
}
