void __thiscall survarium::damage_zone_core_cook::on_resources_loaded(
        survarium::damage_zone_core_cook *this,
        vostok::resources::queries_result *data,
        const vostok::configs::binary_config_value *cfg)
{
  survarium::damage_zone_core_cook::create_resource(
    this,
    (int *)this,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)data->m_parent_query,
    cfg,
    data);
}
