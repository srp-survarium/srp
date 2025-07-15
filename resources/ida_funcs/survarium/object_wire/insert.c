void __thiscall survarium::object_wire::insert(survarium::object_wire *this)
{
  if ( this->m_visual.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      vostok::render::scene_renderer::add_model(
        (vostok::render::scene_renderer *)&this->m_game_scene->m_render_scene,
        (int)this->m_game_scene->m_game->m_renderer->m_scene,
        &this->m_game_scene->m_render_scene,
        &this->m_visual,
        &this->m_transform);
  }
}
