bool __thiscall vostok::collision::triangle_mesh_geometry::aabb_query(
        vostok::collision::triangle_mesh_geometry *this,
        const vostok::collision::object *object,
        const vostok::math::aabb *aabb,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  int v4; // eax
  vostok::collision::colliders::aabb_geometry v6; // [esp+8h] [ebp-50h] BYREF

  vostok::collision::colliders::aabb_geometry::aabb_geometry(&v6, this, object, aabb, triangles);
  return *(_BYTE *)(v4 + 4);
}
