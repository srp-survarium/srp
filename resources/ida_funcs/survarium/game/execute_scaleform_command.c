void __thiscall survarium::game::execute_scaleform_command(
        survarium::game *this,
        survarium::scaleform_render_command command)
{
  vostok::render::game::renderer::execute_scaleform_command(
    (vostok::render::game::renderer *)this->m_ui_world,
    (survarium::scaleform_render_command)this->m_ui_world);
}
