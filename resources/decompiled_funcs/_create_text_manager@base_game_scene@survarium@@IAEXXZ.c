void __usercall survarium::base_game_scene::create_text_manager(survarium::base_game_scene *this@<ecx>, int a2@<edi>)
{
  Scaleform::GFx::Loader **v2; // ebx
  survarium::base_game_scene *v3; // ecx
  survarium::flash_text_manager *v4; // esi
  survarium::flash_text_manager *v5; // eax
  survarium::flash_text_manager *v6; // esi
  unsigned int *v7; // eax

  v2 = *(Scaleform::GFx::Loader ***)(*(_DWORD *)(a2 + 168) + 956);
  v4 = (survarium::flash_text_manager *)operator new(0x10u);
  if ( v4 )
  {
    survarium::flash_text_manager::flash_text_manager(v4, *v2);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  *(_DWORD *)(a2 + 164) = v6;
  v7 = (unsigned int *)survarium::base_game_scene::output_window_size(v3, a2);
  survarium::flash_text_manager::set_viewport(v6, *v7, v7[1]);
  vostok::render::game::renderer::show_text_manager(
    (vostok::render::game::renderer *)(a2 + 8),
    *(const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> **)(*(_DWORD *)(a2 + 168) + 148),
    (survarium::flash_text_manager *)(a2 + 8));
}
