unsigned int __thiscall vostok::collision::triangle_mesh_geometry::index_count(
        vostok::collision::triangle_mesh_geometry *this)
{
  return 3 * this->m_mesh->mNbTris;
}
