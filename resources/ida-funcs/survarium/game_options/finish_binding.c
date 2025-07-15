void __usercall survarium::game_options::finish_binding(survarium::game_options *this@<ecx>, int a2@<esi>)
{
  survarium::base_game_scene *v2; // ecx

  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 16) + 264) + 4),
    "root.end_keybind",
    0,
    0,
    0);
  survarium::base_game_scene::show_movie(
    (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)(a2 + 20),
    v2,
    *(survarium::base_game_scene **)(a2 + 12));
  *(_DWORD *)(a2 + 56) = 64;
}
