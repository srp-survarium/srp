void __usercall survarium::base_game_scene::show_text_manager(
        survarium::base_game_scene *this@<edi>,
        survarium::flash_text_manager *tm@<eax>,
        survarium::base_game_scene *a3@<ecx>)
{
  unsigned int *v4; // eax

  v4 = (unsigned int *)survarium::base_game_scene::output_window_size(a3, (int)this);
  survarium::flash_text_manager::set_viewport(tm, *v4, v4[1]);
  vostok::render::game::renderer::show_text_manager(
    (vostok::render::game::renderer *)this->m_game,
    (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)this->m_game->m_renderer,
    (survarium::flash_text_manager *)&this->m_render_scene_view);
}
