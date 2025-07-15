bool __thiscall vostok::collision::triangle_mesh_geometry::aabb_query(
        vostok::collision::triangle_mesh_geometry *this,
        const vostok::collision::object *object,
        const vostok::math::aabb *aabb,
        vostok::buffer_vector<vostok::collision::triangle_result> *triangles)
{
  int v4; // eax
  vostok::collision::colliders::aabb_geometry v6; // [esp+0h] [ebp-50h] BYREF

  vostok::collision::colliders::aabb_geometry::aabb_geometry(aabb, triangles, &v6, this, object);
  return *(_BYTE *)(v4 + 4);
}
