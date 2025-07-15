void __thiscall SpeedTree::CTreeCell::ComputeExtents(SpeedTree::CTreeCell *this)
{
  SpeedTree::Vec3 *Center; // eax
  struct SpeedTree::Vec3 v3; // [esp+48h] [ebp-D4h] BYREF
  float m_fCullingRadius; // [esp+ACh] [ebp-70h]
  SpeedTree::CExtents *p_m_cExtents; // [esp+E4h] [ebp-38h]
  SpeedTree::Vec3 *p_m_cMax; // [esp+E8h] [ebp-34h]
  struct SpeedTree::Vec3 v7; // [esp+ECh] [ebp-30h] BYREF
  int i; // [esp+F8h] [ebp-24h]
  int v9; // [esp+FCh] [ebp-20h] BYREF
  const struct SpeedTree::CInstance *Instances; // [esp+100h] [ebp-1Ch]
  SpeedTree::CCellBaseTreeItr v11; // [esp+104h] [ebp-18h] BYREF
  int v12; // [esp+118h] [ebp-4h]

  p_m_cExtents = &this->m_cExtents;
  this->m_cExtents.m_cMin.x = 3.4028235e38;
  p_m_cExtents->m_cMin.y = 3.4028235e38;
  p_m_cExtents->m_cMin.z = 3.4028235e38;
  p_m_cMax = &p_m_cExtents->m_cMax;
  p_m_cExtents->m_cMax.x = -3.4028235e38;
  p_m_cMax->y = -3.4028235e38;
  p_m_cMax->z = -3.4028235e38;
  SpeedTree::CCellInstances::FirstBaseTree(&this->m_cCellInstances, &v11);
  v12 = 0;
  while ( SpeedTree::CCellBaseTreeItr::TreePtr(&v11) )
  {
    v9 = 0;
    Instances = SpeedTree::CCellInstances::GetInstances(&this->m_cCellInstances, &v11, &v9);
    for ( i = 0; i < v9; ++i )
    {
      m_fCullingRadius = Instances[i].m_fCullingRadius;
      SpeedTree::CExtents::ExpandAround(&this->m_cExtents, &Instances[i].m_vGeometricCenter, m_fCullingRadius);
    }
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::iterator_base::operator++((int *)&v11);
  }
  this->m_vCenter = *SpeedTree::CExtents::GetCenter(&this->m_cExtents, &v7);
  Center = SpeedTree::CExtents::GetCenter(&this->m_cExtents, &v3);
  this->m_fCullRadius = SpeedTree::Vec3::Distance(Center, &this->m_cExtents.m_cMin);
}
