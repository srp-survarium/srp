void __thiscall survarium::game_world::remove_decal(survarium::game_world *this, unsigned int id)
{
  vostok::render::scene_renderer::remove_decal(
    *(vostok::render::scene_renderer **)(this[-1].m_input_mode + 148),
    *(vostok::render::scene_renderer **)(*(_DWORD *)(this[-1].m_input_mode + 148) + 16),
    (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)&this[-1].m_enemies_for_team_1._M_impl._M_finish,
    id);
}
