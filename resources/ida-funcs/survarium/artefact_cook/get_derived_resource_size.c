unsigned int __thiscall survarium::artefact_cook::get_derived_resource_size(
        survarium::artefact_cook *this,
        const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *config)
{
  vostok::configs::binary_config_value *v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax

  v3 = vostok::configs::binary_config_value::operator[](config->m_object->m_root, "data");
  v4 = (char *)vostok::configs::binary_config_value::operator[](v3, "type")->data.pointer - 3;
  if ( !v4 )
    return 856;
  v5 = v4 - 3;
  if ( !v5 )
    return 584;
  v6 = v5 - 1;
  if ( !v6 )
    return 3552;
  if ( v6 == (char *)1 )
    return 512;
  return survarium::artefact_core_cook::get_derived_resource_size(this, config);
}
