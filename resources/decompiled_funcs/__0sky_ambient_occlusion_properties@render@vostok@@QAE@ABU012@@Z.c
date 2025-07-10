void __usercall vostok::render::sky_ambient_occlusion_properties::sky_ambient_occlusion_properties(
        vostok::render::sky_ambient_occlusion_properties *this@<esi>,
        const vostok::render::sky_ambient_occlusion_properties *__that@<edi>)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // ebx

  m_begin = (unsigned __int8 *)__that->texture_name.m_begin;
  v3 = __that->texture_name.m_end - __that->texture_name.m_begin;
  this->texture_name.m_max_end = (char *)&this->location;
  v4 = v3;
  this->texture_name.m_begin = this->texture_name.m_buffer;
  this->texture_name.m_end = this->texture_name.m_buffer;
  memcpy((unsigned __int8 *)this->texture_name.m_buffer, m_begin, v3);
  this->texture_name.m_end += v4;
  *this->texture_name.m_end = 0;
  this->location = __that->location;
  this->width = __that->width;
  this->height = __that->height;
  this->depth = __that->depth;
  this->enabled = __that->enabled;
  this->texture_invalidated = __that->texture_invalidated;
}
