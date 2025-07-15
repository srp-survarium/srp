void __thiscall vostok::sound::sound_scene::set_graph(
        vostok::sound::sound_scene *this,
        vostok::resources::resource_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base> *graph)
{
  vostok::render::culling::portal_sector_structure **v2; // eax
  vostok::resources::resource_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base> *p_m_graph; // [esp+4h] [ebp-28h]
  vostok::render::culling::portal_sector_structure *v4; // [esp+14h] [ebp-18h]
  vostok::intrusive_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp+28h] [ebp-4h] BYREF

  p_m_graph = &this->m_graph;
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>(
    &v5,
    graph);
  v4 = *v2;
  *v2 = p_m_graph->m_object;
  p_m_graph->m_object = v4;
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v5);
}
