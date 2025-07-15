int __userpurge vostok::math::cuboid::test_inexact@<eax>(
        vostok::math::cuboid *this@<ecx>,
        vostok::math::aabb_plane *a2@<eax>,
        const vostok::math::aabb *aabb)
{
  vostok::math::aabb_plane *v3; // esi
  vostok::math::aabb_plane *v4; // edi
  unsigned int v5; // ebx
  __int32 v6; // eax

  v3 = a2;
  v4 = a2 + 6;
  v5 = 0;
  do
  {
    v6 = vostok::math::aabb_plane::test(v3, aabb) - 1;
    if ( v6 )
    {
      if ( v6 == 1 )
        return 2;
    }
    else
    {
      ++v5;
    }
    ++v3;
  }
  while ( v3 != v4 );
  if ( v5 >= 6 )
    return 1;
  else
    return 3;
}
