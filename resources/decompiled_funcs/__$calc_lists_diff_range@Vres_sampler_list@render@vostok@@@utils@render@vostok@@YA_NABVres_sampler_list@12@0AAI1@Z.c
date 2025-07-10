bool __cdecl vostok::render::utils::calc_lists_diff_range<vostok::render::res_sampler_list>(
        const vostok::render::res_sampler_list *first,
        ID3D11SamplerState *const *second,
        unsigned int *min,
        unsigned int *max)
{
  vostok::sound::sound_world *v5; // esi
  vostok::sound::sound_world *v6; // edi
  vostok::sound::sound_world *v7; // ebx
  vostok::sound::sound_world *v8; // eax
  unsigned int v9; // eax
  unsigned int v11; // eax
  ID3D11SamplerState *const *end_oth; // [esp+18h] [ebp+8h]

  v5 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)first->m_samplers._M_impl._M_start);
  v6 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)first->m_samplers._M_impl._M_finish);
  v7 = boost::get_pointer<vostok::sound::sound_scene>(*((vostok::sound::sound_world **)second + 1));
  v8 = boost::get_pointer<vostok::sound::sound_scene>(*((vostok::sound::sound_world **)second + 2));
  *max = 0;
  end_oth = (ID3D11SamplerState *const *)v8;
  for ( *min = 0; v5 != v6; v7 = (vostok::sound::sound_world *)((char *)v7 + 4) )
  {
    if ( v7 == v8 )
      break;
    if ( v5->__vftable != v8->__vftable )
      break;
    ++*min;
    v5 = (vostok::sound::sound_world *)((char *)v5 + 4);
  }
  if ( (((*((_DWORD *)second + 2) - *((_DWORD *)second + 1))
       ^ ((char *)first->m_samplers._M_impl._M_finish - (char *)first->m_samplers._M_impl._M_start))
      & 0xFFFFFFFC) != 0 )
  {
    v9 = vostok::math::max(
           first->m_samplers._M_impl._M_finish - first->m_samplers._M_impl._M_start,
           (*((_DWORD *)second + 2) - *((_DWORD *)second + 1)) >> 2);
    *max = v9;
    return *min != v9;
  }
  else
  {
    if ( v5 != v6 )
    {
      v11 = *min + 1;
      do
      {
        if ( v7 == (vostok::sound::sound_world *)end_oth )
          break;
        if ( v5->__vftable != (vostok::sound::sound_world_vtbl *)*end_oth )
          *max = v11;
        v5 = (vostok::sound::sound_world *)((char *)v5 + 4);
        v7 = (vostok::sound::sound_world *)((char *)v7 + 4);
        ++v11;
      }
      while ( v5 != v6 );
    }
    return *min != *max;
  }
}
