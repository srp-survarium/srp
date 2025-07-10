int __thiscall vostok::collision::triangle_mesh_geometry_instance::cuboid_test(
        vostok::collision::triangle_mesh_geometry_instance *this,
        const vostok::math::cuboid *cuboid)
{
  vostok::collision::triangle_mesh_geometry_vtbl *v3; // ebx
  int v4; // eax
  vostok::math::cuboid v6; // [esp+10h] [ebp-78h] BYREF

  v3 = this->m_triangle_mesh->__vftable;
  vostok::math::cuboid::cuboid(&v6, cuboid, &this->m_inverted_matrix);
  return ((int (__thiscall *)(const vostok::collision::triangle_mesh_geometry *, int))v3->cuboid_test)(
           this->m_triangle_mesh,
           v4);
}
