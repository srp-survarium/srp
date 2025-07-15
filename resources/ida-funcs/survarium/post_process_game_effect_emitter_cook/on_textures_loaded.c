void __thiscall survarium::post_process_game_effect_emitter_cook::on_textures_loaded(
        survarium::post_process_game_effect_emitter_cook *this,
        vostok::resources::queries_result *data,
        const vostok::configs::binary_config_value *config)
{
  survarium::post_process_game_effect_emitter_cook::finish_query(this, data->m_parent_query, config, data);
}
