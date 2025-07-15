void __thiscall survarium::game::on_alttab(survarium::game *this, bool activate)
{
  vostok::render::res_render_output::on_alttab(
    (vostok::render::res_render_output *)this,
    (int)this->m_render_output_window.m_object[42].m_sub_fat.m_object,
    activate);
}
