int __userpurge vostok::collision::colliders::convex_geometry::intersects_aabb@<eax>(
        const Opcode::AABBNoLeafNode *node@<eax>,
        vostok::collision::colliders::convex_geometry *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float x; // xmm0_4
  float v6; // xmm2_4
  const vostok::math::convex *m_convex; // eax
  vostok::math::aabb_plane *M_start; // ebx
  vostok::math::aabb_plane *M_finish; // edi
  int i; // esi
  int v11; // eax
  vostok::math::aabb v13; // [esp+4h] [ebp-34h] BYREF
  vostok::math::float3 v14; // [esp+1Ch] [ebp-1Ch] BYREF
  vostok::math::float3 v15; // [esp+28h] [ebp-10h] BYREF
  unsigned int v16; // [esp+40h] [ebp+8h]

  y = node->mAABB.mCenter.y;
  z = node->mAABB.mCenter.z;
  v14.x = node->mAABB.mCenter.x;
  x = node->mAABB.mExtents.x;
  *(_QWORD *)&v14.elements[1] = __PAIR64__(LODWORD(z), LODWORD(y));
  v6 = node->mAABB.mExtents.z;
  *(_QWORD *)&v15.x = __PAIR64__(LODWORD(node->mAABB.mExtents.y), LODWORD(x));
  v15.z = v6;
  vostok::math::create_aabb_center_radius(&v15, &v14, &v13);
  m_convex = this->m_convex;
  M_start = m_convex->m_planes._M_impl._M_start;
  v16 = 0;
  M_finish = m_convex->m_planes._M_impl._M_finish;
  for ( i = (int)m_convex->m_planes._M_impl._M_start; (vostok::math::aabb_plane *)i != M_finish; i += 20 )
  {
    v11 = vostok::math::aabb_plane::test((vostok::math::aabb_plane *)&v13, i) - 1;
    if ( v11 )
    {
      if ( v11 == 1 )
        return 2;
    }
    else
    {
      ++v16;
    }
  }
  return v16 < M_finish - M_start ? 3 : 1;
}
