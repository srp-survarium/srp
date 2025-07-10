const IceMaths::IndexedTriangle *__thiscall vostok::collision::triangle_mesh_geometry::indices(
        vostok::collision::triangle_mesh_geometry *this,
        unsigned int triangle_id)
{
  return &this->m_mesh->mTris[triangle_id];
}
