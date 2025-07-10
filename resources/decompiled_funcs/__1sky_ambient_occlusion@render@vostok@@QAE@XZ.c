void __thiscall vostok::render::sky_ambient_occlusion::~sky_ambient_occlusion(
        vostok::render::sky_ambient_occlusion *this)
{
  vostok::render::res_texture *m_object; // eax

  m_object = this->m_texture.m_object;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this, this->m_texture.m_object);
  }
}
