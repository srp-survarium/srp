void __userpurge vostok::render::scene::add_light(
        vostok::render::scene *this@<ecx>,
        vostok::render::light_props *props@<eax>,
        unsigned int id)
{
  vostok::render::lights_db::add_light((int)this, id, this->m_lights.m_object, props);
}
