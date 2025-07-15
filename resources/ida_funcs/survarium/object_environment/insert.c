void __thiscall survarium::object_environment::insert(survarium::object_environment *this)
{
  const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_game_scene; // eax
  vostok::render::scene_renderer *v2; // [esp-Ch] [ebp-Ch]

  m_game_scene = (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)this->m_game_scene;
  v2 = *(vostok::render::scene_renderer **)(m_game_scene[42].m_object->grm_satisfaction_tree_hook.color_ + 16);
  vostok::render::scene_renderer::set_post_process(
    v2,
    (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)v2,
    m_game_scene + 2);
}
