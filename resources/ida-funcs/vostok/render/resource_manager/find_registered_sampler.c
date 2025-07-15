ID3D11SamplerState *__userpurge vostok::render::resource_manager::find_registered_sampler@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        const char *name)
{
  int v3; // esi
  int v4; // edi

  v3 = *(int *)((char *)&dword_93A84 + a2);
  v4 = *(int *)((char *)&dword_93A88 + a2);
  while ( 1 )
  {
    if ( v3 == v4 )
      return 0;
    if ( !vostok::detail::strcmp_s(*(const char **)v3, name) )
      break;
    v3 += 80;
  }
  return *(ID3D11SamplerState **)(v3 + 76);
}
