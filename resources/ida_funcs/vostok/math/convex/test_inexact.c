int __userpurge vostok::math::convex::test_inexact@<eax>(
        vostok::math::convex *this@<ecx>,
        vostok::math::aabb_plane **a2@<eax>,
        const vostok::math::aabb *aabb)
{
  vostok::math::aabb_plane *v3; // ebx
  vostok::math::aabb_plane *v4; // edi
  vostok::math::aabb_plane *v5; // esi
  unsigned int i; // ebp
  __int32 v7; // eax

  v3 = *a2;
  v4 = a2[1];
  v5 = *a2;
  for ( i = 0; v5 != v4; ++v5 )
  {
    v7 = vostok::math::aabb_plane::test(v5, aabb) - 1;
    if ( v7 )
    {
      if ( v7 == 1 )
        return 2;
    }
    else
    {
      ++i;
    }
  }
  return i < v4 - v3 ? 3 : 1;
}
