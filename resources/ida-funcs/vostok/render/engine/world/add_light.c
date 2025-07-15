void __userpurge vostok::render::engine::world::add_light(
        vostok::render::engine::world *this@<ecx>,
        long double a2@<esi:edi>,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        unsigned int id,
        vostok::render::light_props *props)
{
  vostok::render::lights_db::add_light(
    id,
    a2,
    *(vostok::render::lights_db **)((char *)&dword_8B9660 + (unsigned int)in_scene->m_object),
    props);
}
