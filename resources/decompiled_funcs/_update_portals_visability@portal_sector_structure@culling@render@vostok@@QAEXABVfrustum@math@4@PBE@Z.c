void __userpurge vostok::render::culling::portal_sector_structure::update_portals_visability(
        vostok::render::culling::portal_sector_structure *this@<ecx>,
        int a2@<esi>,
        const vostok::math::frustum *f,
        const unsigned __int8 *oclusion_results)
{
  int v4; // ecx
  int i; // eax
  int v6; // ecx
  bool v7; // zf
  vostok::collision::triangle_result *M_start; // eax
  vostok::collision::triangle_result *M_finish; // edi
  vostok::collision::triangle_result *v10; // ecx
  unsigned int v11; // eax
  vostok::vectora<vostok::collision::triangle_result> triangles; // [esp+10h] [ebp-14h] BYREF

  v4 = *(_DWORD *)(a2 + 276);
  for ( i = *(_DWORD *)(a2 + 272); i != v4; i += 76 )
    *(_BYTE *)(i + 72) = 0;
  v6 = *(_DWORD *)(a2 + 304);
  triangles._M_impl._M_end_of_storage.m_allocator = *(vostok::memory::base_allocator **)(a2 + 264);
  triangles._M_impl._M_start = 0;
  triangles._M_impl._M_finish = 0;
  triangles._M_impl._M_end_of_storage._M_data = 0;
  v7 = (*(unsigned __int8 (__thiscall **)(int, _DWORD, const vostok::math::frustum *, vostok::vectora<vostok::collision::triangle_result> *))(*(_DWORD *)v6 + 64))(
         v6,
         0,
         f,
         &triangles) == 0;
  M_start = triangles._M_impl._M_start;
  if ( !v7 )
  {
    M_finish = triangles._M_impl._M_finish;
    v10 = triangles._M_impl._M_start;
    if ( triangles._M_impl._M_start != triangles._M_impl._M_finish )
    {
      do
      {
        v11 = v10->triangle_id >> 1;
        ++v10;
        *(_BYTE *)(76 * v11 + *(_DWORD *)(a2 + 272) + 72) = oclusion_results[v11] != 0;
      }
      while ( v10 != M_finish );
      M_start = triangles._M_impl._M_start;
    }
  }
  if ( M_start )
    triangles._M_impl._M_end_of_storage.m_allocator->call_free(triangles._M_impl._M_end_of_storage.m_allocator, M_start);
}
