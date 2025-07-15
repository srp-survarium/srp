void __thiscall survarium::options_gamma_selector::revert(survarium::options_gamma_selector *this)
{
  vostok::render::scene_renderer *m_renderer; // ecx

  this->m_current_value = this->m_source_value;
  survarium::options_item_base::revert(this);
  m_renderer = (vostok::render::scene_renderer *)this->m_parent_tab->m_game->m_active_scene->m_game->m_renderer;
  vostok::render::scene_renderer::set_gamma_correction_factor(m_renderer, m_renderer->m_view.i.x);
}
