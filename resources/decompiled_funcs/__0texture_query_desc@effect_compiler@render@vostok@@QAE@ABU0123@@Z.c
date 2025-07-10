void __usercall vostok::render::effect_compiler::texture_query_desc::texture_query_desc(
        vostok::render::effect_compiler::texture_query_desc *this@<esi>,
        const vostok::render::effect_compiler::texture_query_desc *__that@<edi>)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // ebx

  m_begin = (unsigned __int8 *)__that->m_query_physicaly_path.m_begin;
  v3 = __that->m_query_physicaly_path.m_end - __that->m_query_physicaly_path.m_begin;
  this->m_query_physicaly_path.m_max_end = (char *)&this->m_mip_level_cut;
  v4 = v3;
  this->m_query_physicaly_path.m_begin = this->m_query_physicaly_path.m_buffer;
  this->m_query_physicaly_path.m_end = this->m_query_physicaly_path.m_buffer;
  memcpy((unsigned __int8 *)this->m_query_physicaly_path.m_buffer, m_begin, v3);
  this->m_query_physicaly_path.m_end += v4;
  *this->m_query_physicaly_path.m_end = 0;
  this->m_mip_level_cut = __that->m_mip_level_cut;
  this->m_num_last_mips_used = __that->m_num_last_mips_used;
}
