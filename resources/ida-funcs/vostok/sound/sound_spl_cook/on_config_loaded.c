void __thiscall vostok::sound::sound_spl_cook::on_config_loaded(
        vostok::sound::sound_spl_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::sound::sound_spl *v3; // eax
  const vostok::configs::binary_config_value *v4; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v5; // [esp-Ch] [ebp-84h] BYREF
  const vostok::resources::memory_type *v6; // [esp-8h] [ebp-80h]
  unsigned int v7; // [esp-4h] [ebp-7Ch]
  vostok::sound::sound_spl_cook *thisa; // [esp+0h] [ebp-78h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v9; // [esp+Ch] [ebp-6Ch]
  vostok::resources::unmanaged_resource *v10; // [esp+1Ch] [ebp-5Ch]
  vostok::sound::sound_spl *v11; // [esp+24h] [ebp-54h]
  char v12; // [esp+2Bh] [ebp-4Dh]
  vostok::configs::binary_config_value *m_root; // [esp+2Ch] [ebp-4Ch]
  vostok::configs::binary_config *v14; // [esp+30h] [ebp-48h]
  char v15; // [esp+37h] [ebp-41h]
  vostok::configs::binary_config *v16; // [esp+3Ch] [ebp-3Ch]
  vostok::configs::binary_config *m_object; // [esp+40h] [ebp-38h]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v18; // [esp+44h] [ebp-34h]
  vostok::resources::query_result_for_user *v19; // [esp+50h] [ebp-28h]
  vostok::sound::sound_spl *object; // [esp+54h] [ebp-24h]
  vostok::sound::sound_spl *v21; // [esp+5Ch] [ebp-1Ch]
  vostok::memory::base_allocator *v22; // [esp+60h] [ebp-18h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v23; // [esp+68h] [ebp-10h] BYREF
  vostok::sound::sound_spl *v24; // [esp+6Ch] [ebp-Ch]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> spl_config; // [esp+70h] [ebp-8h] BYREF
  vostok::resources::resource_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base> v26; // [esp+74h] [ebp-4h] BYREF

  thisa = this;
  v22 = vostok::resources::unmanaged_allocator();
  v21 = (vostok::sound::sound_spl *)vostok::memory::base_allocator::malloc_impl(v22, 0x128u);
  v24 = v21;
  if ( v21 )
  {
    vostok::sound::sound_spl::sound_spl(v24);
    object = v3;
  }
  else
  {
    object = 0;
  }
  v26.m_object = 0;
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v26.vostok::intrusive_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>,
    object);
  if ( vostok::resources::queries_result::is_successful(data) )
  {
    v18 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, 0);
    v23.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v23,
      v18 + 55);
    m_object = v23.m_object;
    v16 = v23.m_object;
    spl_config.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &spl_config,
      v23.m_object);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v23);
    v15 = 0;
    v14 = spl_config.m_object;
    m_root = spl_config.m_object->m_root;
    v12 = 0;
    v11 = v26.m_object;
    v4 = vostok::configs::binary_config_value::operator[](m_root, "spl");
    vostok::sound::sound_spl::load(v11, v4);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&spl_config);
    v10 = v26.m_object;
    v7 = 296;
    v6 = &vostok::resources::nocache_memory;
    v5.m_object = v26.m_object;
    v9 = &v5;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v5,
      (vostok::configs::binary_config *)v26.m_object);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(parent, v5, v6, v7);
    vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
    vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v26);
  }
  else
  {
    v19 = vostok::resources::queries_result::operator[](data, 0);
    vostok::resources::query_result_for_cook::finish_query(parent, v19->m_error_type, assert_on_fail_true);
    vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v26);
  }
}
