void __thiscall SpeedTree::CInstance::ComputeCullParameters(
        SpeedTree::CInstance *this,
        const struct SpeedTree::CCore *a2)
{
  SpeedTree::Vec3 *v2; // eax
  float v3; // [esp+8h] [ebp-17Ch]
  struct SpeedTree::Vec3 v5; // [esp+58h] [ebp-12Ch] BYREF
  struct SpeedTree::Vec3 *Center; // [esp+64h] [ebp-120h]
  float v7; // [esp+68h] [ebp-11Ch]
  float v8; // [esp+6Ch] [ebp-118h]
  float v9; // [esp+70h] [ebp-114h]
  float v10; // [esp+148h] [ebp-3Ch]
  float v11; // [esp+14Ch] [ebp-38h]
  float v12; // [esp+150h] [ebp-34h]
  struct SpeedTree::Vec3 v13; // [esp+154h] [ebp-30h] BYREF
  SpeedTree::CExtents vIn; // [esp+160h] [ebp-24h] BYREF
  int v15; // [esp+180h] [ebp-4h]

  vIn = a2->m_cExtents;
  v15 = 0;
  SpeedTree::CExtents::Scale(&vIn, this->m_fScale);
  v3 = (double)this->m_nRotation / 255.0 * 6.2831855;
  SpeedTree::CExtents::Rotate(&vIn, v3);
  Center = SpeedTree::CExtents::GetCenter(&vIn, &v13);
  v7 = this->m_vPos.x + Center->x;
  v8 = this->m_vPos.y + Center->y;
  v9 = this->m_vPos.z + Center->z;
  v10 = v7;
  v11 = v8;
  v12 = v9;
  this->m_vGeometricCenter.x = v7;
  this->m_vGeometricCenter.y = v11;
  this->m_vGeometricCenter.z = v12;
  v2 = SpeedTree::CExtents::GetCenter(&vIn, &v5);
  this->m_fCullingRadius = SpeedTree::Vec3::Distance(v2, &vIn.m_cMin);
}
