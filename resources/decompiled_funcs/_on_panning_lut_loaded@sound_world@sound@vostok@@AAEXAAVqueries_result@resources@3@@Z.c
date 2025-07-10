void __thiscall vostok::sound::sound_world::on_panning_lut_loaded(
        vostok::sound::sound_world *this,
        vostok::resources::queries_result *queries)
{
  vostok::resources::resource_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base> *object; // [esp+14h] [ebp-44h]
  vostok::resources::query_result_for_user *v4; // [esp+40h] [ebp-18h]
  vostok::resources::resource_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base> result; // [esp+4Ch] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> src_ptr; // [esp+50h] [ebp-8h] BYREF
  char v7; // [esp+57h] [ebp-1h]

  v7 = 0;
  v4 = vostok::resources::queries_result::operator[](queries, 0);
  boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
    &src_ptr,
    &v4->m_unmanaged_resource);
  object = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
             &result,
             &src_ptr);
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    &this->m_panning_lut,
    object);
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&result);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&src_ptr);
}
