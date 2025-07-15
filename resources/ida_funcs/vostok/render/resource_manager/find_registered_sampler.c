ID3D11SamplerState *__usercall vostok::render::resource_manager::find_registered_sampler@<eax>(
        vostok::render::resource_manager *this@<eax>,
        const char *name@<edi>)
{
  stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> *M_finish; // ebx
  stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> *M_start; // esi
  const char *m_begin; // eax
  int v5; // eax

  M_finish = this->m_samplers_registry._M_impl._M_finish;
  M_start = this->m_samplers_registry._M_impl._M_start;
  if ( M_start == M_finish )
    return 0;
  while ( 1 )
  {
    m_begin = M_start->first.m_begin;
    if ( M_start->first.m_begin )
    {
      v5 = name ? strcmp(m_begin, name) : *m_begin != 0;
    }
    else
    {
      if ( !name )
        return M_start->second;
      v5 = -(*name != 0);
    }
    if ( !v5 )
      break;
    if ( ++M_start == M_finish )
      return 0;
  }
  return M_start->second;
}
