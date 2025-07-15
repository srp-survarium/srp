void __thiscall vostok::render::scene::particle_engine::remove_light(
        vostok::render::scene::particle_engine *this,
        unsigned int id)
{
  vostok::render::scene::remove_light(this->m_scene, id);
}
