void __thiscall vostok::sound::encoded_sound_with_qualities::on_quality_loaded(
        vostok::sound::encoded_sound_with_qualities *this,
        vostok::resources::queries_result *resources)
{
  vostok::sound::panning_lut *v2; // ecx
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v3; // [esp-8h] [ebp-78h] BYREF
  unsigned int v4; // [esp-4h] [ebp-74h]
  vostok::sound::encoded_sound_with_qualities *thisa; // [esp+4h] [ebp-6Ch]
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // [esp+10h] [ebp-60h]
  vostok::sound::sound_spl *object; // [esp+2Ch] [ebp-44h]
  vostok::resources::unmanaged_resource *m_object; // [esp+38h] [ebp-38h]
  vostok::resources::query_result_for_user *v10; // [esp+3Ch] [ebp-34h]
  vostok::resources::query_result_for_user *v11; // [esp+48h] [ebp-28h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v12; // [esp+50h] [ebp-20h] BYREF
  char v13; // [esp+56h] [ebp-1Ah]
  char v14; // [esp+57h] [ebp-19h]
  vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> quality_child; // [esp+58h] [ebp-18h] BYREF
  unsigned int current_result_quality; // [esp+5Ch] [ebp-14h]
  int i; // [esp+60h] [ebp-10h]
  bool some_quality_loaded; // [esp+66h] [ebp-Ah]
  bool some_qualities_failed; // [esp+67h] [ebp-9h]
  unsigned int target_quality; // [esp+68h] [ebp-8h]
  bool increasing; // [esp+6Fh] [ebp-1h]

  thisa = this;
  v14 = 0;
  target_quality = this->m_target_quality_level;
  increasing = this->m_parent_query == 0;
  some_quality_loaded = 0;
  some_qualities_failed = 0;
  for ( i = vostok::resources::queries_result::size(resources) - 1; i >= 0; --i )
  {
    current_result_quality = i + target_quality;
    v11 = vostok::resources::queries_result::operator[](resources, i);
    if ( v11->m_error_type == error_type_unset && v11->m_create_resource_result != result_error )
    {
      v13 = 0;
      some_quality_loaded = 1;
      v10 = vostok::resources::queries_result::operator[](resources, i);
      boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
        &v12,
        &v10->m_unmanaged_resource);
      m_object = v12.m_object;
      object = (vostok::sound::sound_spl *)v12.m_object;
      quality_child.m_object = 0;
      vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        (vostok::intrusive_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&quality_child,
        (vostok::sound::sound_spl *)v12.m_object);
      vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v12);
      v4 = current_result_quality;
      v3.m_object = v2;
      v7 = &v3;
      vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v3,
        (const vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&quality_child);
      vostok::sound::encoded_sound_with_qualities::add_quality(
        thisa,
        (vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>)v3.m_object,
        v4);
      vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&quality_child);
    }
    else
    {
      some_qualities_failed = 1;
    }
  }
  if ( thisa->m_parent_query )
  {
    vostok::resources::query_result_for_cook::finish_query(
      thisa->m_parent_query,
      (vostok::resources::cook_base::result_enum)(some_quality_loaded ? result_success : result_error),
      assert_on_fail_true);
    thisa->m_parent_query = 0;
  }
  thisa->m_increasing_quality = 0;
}
