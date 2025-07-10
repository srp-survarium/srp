void __usercall survarium::base_game_scene::hide_text_manager(survarium::base_game_scene *this@<ecx>, int a2@<eax>)
{
  vostok::render::game::renderer::hide_text_manager(
    *(vostok::render::game::renderer **)(*(_DWORD *)(a2 + 168) + 148),
    *(const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> **)(*(_DWORD *)(a2 + 168) + 148),
    (survarium::flash_text_manager *)(a2 + 8));
}
