void __userpurge vostok::render::engine::world::remove_environment_probe(
        vostok::render::engine::world *this@<ecx>,
        vostok::memory::detail::call_destructor_predicate *a2@<edi>,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        unsigned int id)
{
  vostok::render::scene::remove_environment_probe(
    (vostok::render::find_environment_probe_predicate)id,
    a2,
    (vostok::render::scene *)in_scene->m_object);
}
