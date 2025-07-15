void __thiscall vostok::render::skeleton_combined_cook_data::~skeleton_combined_cook_data(
        vostok::render::skeleton_combined_cook_data *this,
        vostok::render::skeleton_combined_cook_data *thisa)
{
  vostok::render::skeleton_combined_cook_data::model_def *p_models_count; // esi
  int i; // edi
  vostok::configs::binary_config *m_object; // eax
  vostok::animation::skeleton *v5; // eax

  p_models_count = (vostok::render::skeleton_combined_cook_data::model_def *)&thisa->models_count;
  for ( i = 7; i >= 0; --i )
    vostok::render::skeleton_combined_cook_data::model_def::~model_def(--p_models_count);
  m_object = thisa->model_config.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->model_config.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->model_config.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&thisa->bind_pose);
  v5 = thisa->skeleton.m_object;
  if ( v5 )
  {
    if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &thisa->skeleton.m_object->vostok::resources::unmanaged_intrusive_base,
        thisa->skeleton.m_object);
  }
}
