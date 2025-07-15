void __usercall vostok::collision::colliders::convex_geometry::convex_geometry(
        vostok::collision::colliders::convex_geometry *this@<esi>,
        const vostok::collision::triangle_mesh_geometry *geometry@<eax>,
        const vostok::math::convex *convex@<ecx>)
{
  this->m_convex = convex;
  this->m_geometry = geometry;
  this->m_result = 0;
  vostok::collision::colliders::convex_geometry::query(this, geometry->m_root);
}
