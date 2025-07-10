void __thiscall vostok::render::engine::world::populate_speedtree_forest(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene)
{
  vostok::render::speedtree_forest::populate_forest(
    (vostok::render::speedtree_forest *)in_scene->m_object,
    (vostok::render::speedtree_forest *)LODWORD(in_scene->m_object[3].m_current_satisfaction));
}
