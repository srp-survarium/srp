void __usercall vostok::render::res_sampler_list::rebind(vostok::render::res_sampler_list *this@<ecx>, int a2@<esi>)
{
  unsigned int v2; // edi
  int v3; // ebx
  ID3D11SamplerState *registered_sampler; // eax

  v2 = 0;
  if ( (*(_DWORD *)(a2 + 8) - *(_DWORD *)(a2 + 4)) >> 2 )
  {
    v3 = 0;
    do
    {
      registered_sampler = vostok::render::resource_manager::find_registered_sampler(
                             (vostok::render::resource_manager *)this,
                             (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                             *(const char **)(*(_DWORD *)(a2 + 144) + v3));
      this = *(vostok::render::res_sampler_list **)(a2 + 4);
      *(&this->m_reference_count + v2++) = (unsigned int)registered_sampler;
      v3 += 44;
    }
    while ( v2 < (*(_DWORD *)(a2 + 8) - *(_DWORD *)(a2 + 4)) >> 2 );
  }
}
