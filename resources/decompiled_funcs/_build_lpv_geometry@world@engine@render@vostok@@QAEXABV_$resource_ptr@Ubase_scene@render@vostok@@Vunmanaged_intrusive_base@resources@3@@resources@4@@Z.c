void __thiscall vostok::render::engine::world::build_lpv_geometry(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene)
{
  ((void (__thiscall *)(vostok::resources::resource_link **, unsigned int *))scene->m_object[1].m_children_resources.m_last->next_link)(
    &scene->m_object[1].m_children_resources.m_last,
    &scene->m_object[3].m_memory_usage_self.size);
}
