SpeedTree::SHorizontalBillboard *__thiscall SpeedTree::SHorizontalBillboard::SHorizontalBillboard(
        SpeedTree::SHorizontalBillboard *this)
{
  SpeedTree::Vec3 *v1; // edx
  int v3; // [esp+Ch] [ebp-Ch]
  SpeedTree::Vec3 *i; // [esp+10h] [ebp-8h]
  __int16 j; // [esp+14h] [ebp-4h]
  __int16 k; // [esp+14h] [ebp-4h]

  this->m_bPresent = 0;
  v3 = 4;
  for ( i = this->m_avCoords; --v3 >= 0; ++i )
  {
    i->x = 0.0;
    i->y = 0.0;
    i->z = 0.0;
  }
  this->m_vTexCoordsShader.x = 0.0;
  this->m_vTexCoordsShader.y = 0.0;
  this->m_vTexCoordsShader.z = 0.0;
  this->m_vTexCoordsShader.w = 1.0;
  for ( j = 0; j < 4; ++j )
  {
    this->m_avCoords[j].x = -1.0;
    v1 = &this->m_avCoords[j];
    v1->y = -1.0;
    v1->z = -1.0;
  }
  for ( k = 0; k < 8; ++k )
    this->m_afTexCoords[k] = -1.0;
  return this;
}
