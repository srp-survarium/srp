void __thiscall vostok::render::resource_manager::register_sampler(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *name,
        ID3D11SamplerState *sampler)
{
  unsigned __int8 *v3; // edx
  unsigned __int8 *v4; // eax
  bool v5; // zf
  int v6; // esi
  stlp_std::priv::_Impl_vector<stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> > > *v7; // ecx
  stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> *M_finish; // esi
  unsigned __int8 *m_begin; // edx
  unsigned int v10; // ecx
  unsigned int v11; // ebx
  const stlp_std::__false_type *v12; // [esp+0h] [ebp-ACh]
  unsigned int v13; // [esp+4h] [ebp-A8h]
  bool v14; // [esp+8h] [ebp-A4h]
  stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> __x; // [esp+Ch] [ebp-A0h] BYREF
  unsigned __int8 *v16; // [esp+5Ch] [ebp-50h]
  unsigned __int8 *v17; // [esp+60h] [ebp-4Ch]
  unsigned __int8 *v18; // [esp+64h] [ebp-48h]
  unsigned __int8 src[64]; // [esp+68h] [ebp-44h] BYREF
  char v20; // [esp+A8h] [ebp-4h] BYREF

  v3 = src;
  v4 = src;
  v16 = src;
  v17 = src;
  v18 = (unsigned __int8 *)&v20;
  src[0] = 0;
  if ( this )
  {
    if ( LOBYTE(this->sh_created) )
    {
      do
      {
        if ( v4 >= v18 )
          break;
        *v4 = this->sh_created;
        v4 = v17 + 1;
        this = (vostok::render::resource_manager *)((char *)this + 1);
        v5 = LOBYTE(this->sh_created) == 0;
        ++v17;
      }
      while ( !v5 );
    }
    *v4 = 0;
    v4 = v17;
    v3 = v16;
  }
  v6 = v4 - v3;
  __x.first.m_begin = __x.first.m_buffer;
  __x.first.m_max_end = (char *)&__x.second;
  memcpy((unsigned __int8 *)__x.first.m_buffer, v3, v4 - v3);
  __x.first.m_end = &__x.first.m_buffer[v6];
  *__x.first.m_end = 0;
  M_finish = name->m_samplers_registry._M_impl._M_finish;
  __x.second = sampler;
  if ( M_finish == name->m_samplers_registry._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *>>>::_M_insert_overflow_aux(
      v7,
      (int)&name->m_samplers_registry,
      M_finish,
      &__x,
      v12,
      v13,
      v14);
  }
  else
  {
    if ( M_finish )
    {
      m_begin = (unsigned __int8 *)__x.first.m_begin;
      v10 = __x.first.m_end - __x.first.m_begin;
      M_finish->first.m_max_end = (char *)&M_finish->second;
      v11 = v10;
      M_finish->first.m_begin = M_finish->first.m_buffer;
      M_finish->first.m_end = M_finish->first.m_buffer;
      memcpy((unsigned __int8 *)M_finish->first.m_buffer, m_begin, v10);
      M_finish->first.m_end += v11;
      *M_finish->first.m_end = 0;
      M_finish->second = __x.second;
    }
    ++name->m_samplers_registry._M_impl._M_finish;
  }
}
