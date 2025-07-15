void __thiscall vostok::render::skeleton_combined_cook_data::model_def::~model_def(
        vostok::render::skeleton_combined_cook_data::model_def *this)
{
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::configs::binary_config *v3; // eax
  vostok::configs::binary_config *v4; // eax

  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&this->converted_model);
  m_object = this->material_effects.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->material_effects.m_object->vostok::resources::unmanaged_intrusive_base,
      this->material_effects.m_object);
  v3 = this->export_properties_config.m_object;
  if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->export_properties_config.m_object->vostok::resources::unmanaged_intrusive_base,
      this->export_properties_config.m_object);
  v4 = this->owner_model_config.m_object;
  if ( v4 )
  {
    if ( !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->owner_model_config.m_object->vostok::resources::unmanaged_intrusive_base,
        this->owner_model_config.m_object);
  }
}
