int __userpurge vostok::math::cuboid::test_inexact@<eax>(
        vostok::math::cuboid *this@<ecx>,
        int a2@<eax>,
        vostok::math::aabb_plane *aabb)
{
  int v3; // edi
  unsigned int v4; // ebx
  int v5; // esi
  int v6; // eax

  v3 = a2 + 120;
  v4 = 0;
  v5 = a2;
  do
  {
    v6 = vostok::math::aabb_plane::test(aabb, v5) - 1;
    if ( v6 )
    {
      if ( v6 == 1 )
        return 2;
    }
    else
    {
      ++v4;
    }
    v5 += 20;
  }
  while ( v5 != v3 );
  if ( v4 < 6 )
    return 3;
  return 1;
}
