void __thiscall survarium::object_wire::remove(survarium::object_wire *this)
{
  if ( this->m_visual.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      vostok::render::scene_renderer::remove_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_visual,
        *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)this->m_game_scene->m_game->m_renderer),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_scene->m_render_scene);
  }
}
