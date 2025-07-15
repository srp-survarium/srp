void __usercall survarium::game_options::finish_binding(survarium::game_options *this@<ecx>, int a2@<esi>)
{
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 12) + 264) + 4),
    "root.end_keybind",
    0,
    0,
    0);
  survarium::base_game_scene::show_movie(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 16),
    *(survarium::base_game_scene **)(a2 + 48));
  *(_DWORD *)(a2 + 60) = 72;
}
