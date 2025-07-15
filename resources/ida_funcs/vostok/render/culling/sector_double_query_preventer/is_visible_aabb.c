char __userpurge vostok::render::culling::sector_double_query_preventer::is_visible_aabb@<al>(
        vostok::render::culling::sector_double_query_preventer *this@<ecx>,
        int a2@<eax>,
        const vostok::math::aabb *bbox,
        const unsigned __int16 *sectors_begin,
        const unsigned __int16 *sectors_end)
{
  const unsigned __int16 *v5; // ebx
  vostok::math::cuboid *v6; // ecx
  float x; // ebp
  int v8; // edi
  int v9; // esi

  v5 = sectors_begin;
  if ( sectors_begin == sectors_end )
    return 0;
  v6 = *(vostok::math::cuboid **)(a2 + 4);
  x = v6->m_planes[0].plane.normal.x;
  while ( 1 )
  {
    v8 = *(_DWORD *)(LODWORD(x) + 12 * *v5 + 4);
    v9 = *(_DWORD *)(LODWORD(x) + 12 * *v5);
    if ( v9 != v8 )
      break;
LABEL_6:
    if ( ++v5 == sectors_end )
      return 0;
  }
  while ( vostok::math::cuboid::test_inexact(v6, bbox) == intersection_outside )
  {
    v9 += 120;
    if ( v9 == v8 )
      goto LABEL_6;
  }
  return 1;
}
