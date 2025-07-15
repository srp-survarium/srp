void __thiscall survarium::generic_anomaly_core_cook::on_artefacts_loaded(
        survarium::generic_anomaly_core_cook *this,
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *data,
        vostok::resources::queries_result *config)
{
  survarium::generic_anomaly_core_cook::proceed_to_create_resource(
    this,
    (vostok::resources::query_result_for_cook *)this,
    (const vostok::configs::binary_config_value *)data[8].m_object,
    config,
    data);
}
