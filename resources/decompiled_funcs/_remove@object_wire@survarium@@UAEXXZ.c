void __thiscall survarium::object_wire::remove(survarium::object_wire *this)
{
  survarium::base_game_scene *m_game_scene; // eax
  vostok::render::scene_renderer *m_scene; // [esp-Ch] [ebp-Ch]

  if ( this->m_visual.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      m_game_scene = this->m_game_scene;
      m_scene = m_game_scene->m_game->m_renderer->m_scene;
      vostok::render::scene_renderer::remove_model(m_scene, m_scene, &m_game_scene->m_render_scene, &this->m_visual);
    }
  }
}
