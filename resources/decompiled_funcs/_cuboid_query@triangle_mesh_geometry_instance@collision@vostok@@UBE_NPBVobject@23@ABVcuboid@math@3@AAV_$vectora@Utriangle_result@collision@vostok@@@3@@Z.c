int __thiscall vostok::collision::triangle_mesh_geometry_instance::cuboid_query(
        vostok::collision::triangle_mesh_geometry_instance *this,
        const vostok::collision::object *object,
        const vostok::math::cuboid *cuboid,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  vostok::collision::triangle_mesh_geometry_vtbl *v5; // ebx
  int v6; // eax
  vostok::math::cuboid v8; // [esp+10h] [ebp-78h] BYREF

  v5 = this->m_triangle_mesh->__vftable;
  vostok::math::cuboid::cuboid(&v8, cuboid, &this->m_inverted_matrix);
  return ((int (__thiscall *)(const vostok::collision::triangle_mesh_geometry *, const vostok::collision::object *, int, vostok::vectora<vostok::collision::triangle_result> *))v5->cuboid_query)(
           this->m_triangle_mesh,
           object,
           v6,
           triangles);
}
