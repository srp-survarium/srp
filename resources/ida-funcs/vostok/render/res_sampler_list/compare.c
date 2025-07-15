int __usercall vostok::render::res_sampler_list::compare@<eax>(
        vostok::render::res_sampler_list *this@<edx>,
        const vostok::render::res_sampler_list *base@<eax>)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  ID3D11SamplerState **m_begin; // edx
  char *v6; // eax
  unsigned int v7; // edi

  if ( ((((char *)this->m_samplers.m_end - (char *)this->m_samplers.m_begin)
       ^ ((char *)base->m_samplers.m_end - (char *)base->m_samplers.m_begin))
      & 0xFFFFFFFC) == 0 )
    goto LABEL_6;
  if ( this->m_samplers.m_end - this->m_samplers.m_begin < (unsigned int)(base->m_samplers.m_end
                                                                        - base->m_samplers.m_begin) )
    return -1;
  if ( this->m_samplers.m_end - this->m_samplers.m_begin > (unsigned int)(base->m_samplers.m_end
                                                                        - base->m_samplers.m_begin) )
    return 1;
LABEL_6:
  v3 = base->m_samplers.m_end - base->m_samplers.m_begin;
  v4 = 0;
  if ( !v3 )
    return 0;
  m_begin = this->m_samplers.m_begin;
  v6 = (char *)((char *)base->m_samplers.m_begin - (char *)m_begin);
  while ( 1 )
  {
    v7 = *(unsigned int *)((char *)m_begin + (_DWORD)v6);
    if ( (unsigned int)*m_begin < v7 )
      return -1;
    if ( (unsigned int)*m_begin > v7 )
      break;
    ++v4;
    ++m_begin;
    if ( v4 >= v3 )
      return 0;
  }
  return 1;
}


int __usercall vostok::render::res_sampler_list::compare@<eax>(
        vostok::render::res_sampler_list *this@<ecx>,
        const vostok::fixed_vector<vostok::render::sampler_slot,16> *base@<eax>)
{
  vostok::render::sampler_slot *m_begin; // esi
  unsigned int v3; // eax
  unsigned int v5; // ebx
  ID3D11SamplerState **v6; // ecx
  ID3D11SamplerState **i; // edx

  m_begin = base->m_begin;
  v3 = base->m_end - base->m_begin;
  if ( this->m_samplers.m_end - this->m_samplers.m_begin == v3 )
    goto LABEL_6;
  if ( this->m_samplers.m_end - this->m_samplers.m_begin < v3 )
    return -1;
  if ( this->m_samplers.m_end - this->m_samplers.m_begin > v3 )
    return 1;
LABEL_6:
  v5 = 0;
  if ( !v3 )
    return 0;
  v6 = this->m_samplers.m_begin;
  for ( i = &m_begin->state; ; i += 21 )
  {
    if ( *v6 < *i )
      return -1;
    if ( *v6 > *i )
      break;
    ++v5;
    ++v6;
    if ( v5 >= v3 )
      return 0;
  }
  return 1;
}
