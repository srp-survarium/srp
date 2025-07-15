bool __thiscall vostok::render::environment_probe::is_valid_textures(vostok::render::environment_probe *this)
{
  vostok::render::res_texture *m_object; // eax
  vostok::render::res_texture *v2; // eax
  bool result; // al

  m_object = this->m_texture_diffuse.m_object;
  result = 0;
  if ( m_object )
  {
    if ( m_object->m_loaded )
    {
      if ( m_object->m_sh_res_view )
      {
        v2 = this->m_texture.m_object;
        if ( v2 )
        {
          if ( v2->m_loaded && v2->m_sh_res_view )
            return 1;
        }
      }
    }
  }
  return result;
}
