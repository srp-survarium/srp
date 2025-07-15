void __userpurge vostok::render::engine::world::remove_decal(
        vostok::render::engine::world *this@<ecx>,
        vostok::memory::detail::call_destructor_predicate *a2@<ebp>,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        vostok::render::scene *id)
{
  vostok::render::scene::remove_decal(id, (int)in_scene->m_object, a2);
}
