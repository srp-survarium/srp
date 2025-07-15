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


void __usercall vostok::render::effect_compiler::shader_cache_info::shader_cache_info(
        vostok::render::effect_compiler::shader_cache_info *this@<ecx>,
        int a2@<eax>)
{
  *(_BYTE *)(a2 + 272) = 47;
  *(_DWORD *)a2 = a2 + 12;
  *(_DWORD *)(a2 + 4) = a2 + 12;
  *(_DWORD *)(a2 + 8) = a2 + 272;
  *(_BYTE *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 288) = 0;
  *(_BYTE *)(a2 + 548) = 47;
  *(_DWORD *)(a2 + 276) = a2 + 288;
  *(_DWORD *)(a2 + 280) = a2 + 288;
  *(_DWORD *)(a2 + 284) = a2 + 548;
  *(_BYTE *)(a2 + 564) = 0;
  *(_DWORD *)(a2 + 552) = a2 + 564;
  *(_DWORD *)(a2 + 556) = a2 + 564;
  *(_DWORD *)(a2 + 560) = a2 + 824;
  *(_BYTE *)(a2 + 824) = 47;
  *(_DWORD *)(a2 + 840) = 0;
  *(_DWORD *)(a2 + 832) = 0;
  *(_DWORD *)(a2 + 836) = 0;
  *(_DWORD *)(a2 + 844) = 0;
  *(_BYTE *)(a2 + 840) = 4;
}
