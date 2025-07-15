void __thiscall survarium::options_gamma_selector::revert(survarium::options_gamma_selector *this)
{
  vostok::render::scene_renderer *v2; // ecx

  this->m_current_value = this->m_source_value;
  survarium::options_item_base::revert(this);
  vostok::render::scene_renderer::set_gamma_correction_factor(
    v2,
    *(boost::function<void __cdecl(void)> **)((char *)&dword_200060
                                            + (unsigned int)this->m_parent_tab->m_game->m_active_scene->m_game->m_renderer),
    COERCE_BOOST_FUNCTION_VOID_CDECL_VOID_(this->m_current_value));
}
