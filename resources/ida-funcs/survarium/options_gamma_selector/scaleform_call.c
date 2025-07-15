void __thiscall survarium::options_gamma_selector::scaleform_call(
        survarium::options_gamma_selector *this,
        survarium::flash_function_handler_params *params)
{
  vostok::render::scene_renderer *v3; // ecx

  survarium::options_item_float::scaleform_call(this, params);
  vostok::render::scene_renderer::set_gamma_correction_factor(
    v3,
    *(boost::function<void __cdecl(void)> **)((char *)&dword_200060
                                            + (unsigned int)this->m_parent_tab->m_game->m_active_scene->m_game->m_renderer),
    COERCE_BOOST_FUNCTION_VOID_CDECL_VOID_(this->m_current_value));
}
