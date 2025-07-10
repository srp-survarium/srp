void __usercall vostok::render::effect_compiler::shader_cache_info::shader_cache_info(
        vostok::render::effect_compiler::shader_cache_info *this@<esi>,
        const vostok::render::effect_compiler::shader_cache_info *__that@<edi>)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  char *v5; // edx
  char *v6; // ecx
  char *v7; // ebp
  char *v8; // edx
  char *v9; // ecx
  char *v10; // ebp

  m_begin = (unsigned __int8 *)__that->vertex_shader_name.m_string.m_begin;
  v3 = __that->vertex_shader_name.m_string.m_end - __that->vertex_shader_name.m_string.m_begin;
  this->vertex_shader_name.m_string.m_max_end = &this->vertex_shader_name.m_separator;
  v4 = v3;
  this->vertex_shader_name.m_string.m_begin = this->vertex_shader_name.m_string.m_buffer;
  this->vertex_shader_name.m_string.m_end = this->vertex_shader_name.m_string.m_buffer;
  memcpy((unsigned __int8 *)this->vertex_shader_name.m_string.m_buffer, m_begin, v3);
  this->vertex_shader_name.m_string.m_end += v4;
  *this->vertex_shader_name.m_string.m_end = 0;
  this->vertex_shader_name.m_separator = 47;
  v5 = __that->pixel_shader_name.m_string.m_begin;
  v6 = (char *)(__that->pixel_shader_name.m_string.m_end - v5);
  this->pixel_shader_name.m_string.m_max_end = &this->pixel_shader_name.m_separator;
  v7 = v6;
  this->pixel_shader_name.m_string.m_begin = this->pixel_shader_name.m_string.m_buffer;
  this->pixel_shader_name.m_string.m_end = this->pixel_shader_name.m_string.m_buffer;
  memcpy((unsigned __int8 *)this->pixel_shader_name.m_string.m_buffer, (unsigned __int8 *)v5, (unsigned int)v6);
  this->pixel_shader_name.m_string.m_end += (unsigned int)v7;
  *this->pixel_shader_name.m_string.m_end = 0;
  this->pixel_shader_name.m_separator = 47;
  v8 = __that->geometry_shader_name.m_string.m_begin;
  v9 = (char *)(__that->geometry_shader_name.m_string.m_end - v8);
  this->geometry_shader_name.m_string.m_max_end = &this->geometry_shader_name.m_separator;
  v10 = v9;
  this->geometry_shader_name.m_string.m_begin = this->geometry_shader_name.m_string.m_buffer;
  this->geometry_shader_name.m_string.m_end = this->geometry_shader_name.m_string.m_buffer;
  memcpy((unsigned __int8 *)this->geometry_shader_name.m_string.m_buffer, (unsigned __int8 *)v8, (unsigned int)v9);
  this->geometry_shader_name.m_string.m_end += (unsigned int)v10;
  *this->geometry_shader_name.m_string.m_end = 0;
  this->geometry_shader_name.m_separator = 47;
  this->configuration = __that->configuration;
}
