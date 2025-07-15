void __thiscall vostok::collision::colliders::aabb_geometry::test_primitive(
        vostok::collision::colliders::aabb_geometry *this,
        float **triangle_id,
        unsigned int a3)
{
  vostok::collision::colliders::aabb_geometry *v3; // ecx

  if ( vostok::collision::colliders::aabb_geometry::test_triangle(this, triangle_id, a3) )
    vostok::collision::colliders::aabb_geometry::add_triangle(v3, (int)triangle_id, a3);
}
