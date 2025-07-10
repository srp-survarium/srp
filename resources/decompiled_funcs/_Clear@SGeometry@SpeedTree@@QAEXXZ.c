void __thiscall SpeedTree::SGeometry::Clear(SpeedTree::SGeometry *this)
{
  SpeedTree::st_delete_array<SpeedTree::SMaterial>(&this->m_pMaterials);
  SpeedTree::st_delete_array<SpeedTree::SIndexedTriangles>(&this->m_pCompositeIndexedLods);
  SpeedTree::st_delete_array<SpeedTree::SLeafCards>(&this->m_pLeafCardLods);
}
