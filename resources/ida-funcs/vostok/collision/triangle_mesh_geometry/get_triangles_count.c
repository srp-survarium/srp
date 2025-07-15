unsigned int __thiscall vostok::collision::triangle_mesh_geometry::get_triangles_count(
        vostok::collision::triangle_mesh_geometry *this,
        const vostok::math::convex *bounding_convex)
{
  vostok::collision::colliders::convex_geometry v3; // [esp+0h] [ebp-Ch] BYREF

  v3.m_geometry = this;
  v3.m_convex = bounding_convex;
  v3.m_result = 0;
  vostok::collision::colliders::convex_geometry::query(&v3, this->m_root);
  return v3.m_result;
}
