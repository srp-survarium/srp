void __thiscall SpeedTree::CExtents::ExpandAround(SpeedTree::CExtents *this, const struct SpeedTree::Vec3 *a2)
{
  float v2; // [esp+0h] [ebp-1Ch]
  float v3; // [esp+4h] [ebp-18h]
  float v4; // [esp+8h] [ebp-14h]
  float z; // [esp+Ch] [ebp-10h]
  float y; // [esp+10h] [ebp-Ch]
  float x; // [esp+14h] [ebp-8h]

  if ( this->m_cMin.x <= (double)a2->x )
    x = this->m_cMin.x;
  else
    x = a2->x;
  this->m_cMin.x = x;
  if ( this->m_cMin.y <= (double)a2->y )
    y = this->m_cMin.y;
  else
    y = a2->y;
  this->m_cMin.y = y;
  if ( this->m_cMin.z <= (double)a2->z )
    z = this->m_cMin.z;
  else
    z = a2->z;
  this->m_cMin.z = z;
  if ( this->m_cMax.x >= (double)a2->x )
    v4 = this->m_cMax.x;
  else
    v4 = a2->x;
  this->m_cMax.x = v4;
  if ( this->m_cMax.y >= (double)a2->y )
    v3 = this->m_cMax.y;
  else
    v3 = a2->y;
  this->m_cMax.y = v3;
  if ( this->m_cMax.z >= (double)a2->z )
    v2 = this->m_cMax.z;
  else
    v2 = a2->z;
  this->m_cMax.z = v2;
}


void __thiscall SpeedTree::CExtents::ExpandAround(
        SpeedTree::CExtents *this,
        const struct SpeedTree::Vec3 *a2,
        float a3)
{
  float v3; // [esp+0h] [ebp-4Ch]
  float v4; // [esp+4h] [ebp-48h]
  float v5; // [esp+8h] [ebp-44h]
  float z; // [esp+Ch] [ebp-40h]
  float y; // [esp+10h] [ebp-3Ch]
  float x; // [esp+14h] [ebp-38h]
  float v9; // [esp+1Ch] [ebp-30h]
  float v10; // [esp+20h] [ebp-2Ch]
  float v11; // [esp+24h] [ebp-28h]
  float v12; // [esp+28h] [ebp-24h]
  float v13; // [esp+2Ch] [ebp-20h]
  float v14; // [esp+30h] [ebp-1Ch]

  v12 = a2->x - a3;
  v13 = a2->y - a3;
  v14 = a2->z - a3;
  v9 = a3 + a2->x;
  v10 = a3 + a2->y;
  v11 = a3 + a2->z;
  if ( this->m_cMin.x <= (double)v12 )
    x = this->m_cMin.x;
  else
    x = a2->x - a3;
  this->m_cMin.x = x;
  if ( this->m_cMin.y <= (double)v13 )
    y = this->m_cMin.y;
  else
    y = v13;
  this->m_cMin.y = y;
  if ( this->m_cMin.z <= (double)v14 )
    z = this->m_cMin.z;
  else
    z = v14;
  this->m_cMin.z = z;
  if ( this->m_cMax.x >= (double)v9 )
    v5 = this->m_cMax.x;
  else
    v5 = v9;
  this->m_cMax.x = v5;
  if ( this->m_cMax.y >= (double)v10 )
    v4 = this->m_cMax.y;
  else
    v4 = v10;
  this->m_cMax.y = v4;
  if ( this->m_cMax.z >= (double)v11 )
    v3 = this->m_cMax.z;
  else
    v3 = v11;
  this->m_cMax.z = v3;
}
