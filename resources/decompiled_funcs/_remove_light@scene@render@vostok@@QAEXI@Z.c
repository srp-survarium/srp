void __usercall vostok::render::scene::remove_light(vostok::render::scene *this@<ecx>, unsigned int id@<eax>)
{
  vostok::render::lights_db::remove_light((vostok::render::lights_db *)this, this->m_lights.m_object, id);
}
