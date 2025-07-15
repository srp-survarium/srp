void __thiscall survarium::game::on_fullscreen_alttab(survarium::game *this, bool first)
{
  vostok::render::res_render_output::goto_fullscreen(
    (vostok::render::res_render_output *)this,
    this->m_render_output_window.m_object[42].m_parent_resources.m_lock);
}
