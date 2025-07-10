void __userpurge vostok::math::cuboid::cuboid(const vostok::math::plane (*planes)[6]@<eax>, vostok::math::cuboid *this)
{
  vostok::math::cuboid *v2; // esi

  v2 = this;
  do
  {
    *(_QWORD *)&v2->m_planes[0].plane.normal.x = *(_QWORD *)&(*planes)[0].normal.x;
    *(_QWORD *)&v2->m_planes[0].plane.vector.elements[2] = *(_QWORD *)&(*planes)[0].vector.elements[2];
    vostok::math::aabb_plane::normalize(v2->m_planes);
    v2 = (vostok::math::cuboid *)((char *)v2 + 20);
    planes = (const vostok::math::plane (*)[6])((char *)planes + 16);
  }
  while ( v2 != &this[1] );
}
