void __thiscall btBoxShape::getPlane(btBoxShape *this, btVector3 *planeNormal, btVector3 *planeSupport, int i)
{
  btVector3 *(__thiscall *localGetSupportingVertex)(struct btBoxShape *, btVector3 *, const btVector3 *); // edx
  unsigned __int64 v6; // [esp+30h] [ebp-30h] BYREF
  float v7; // [esp+38h] [ebp-28h]
  int v8; // [esp+3Ch] [ebp-24h]
  unsigned __int64 v9; // [esp+40h] [ebp-20h] BYREF
  float v10; // [esp+48h] [ebp-18h]
  btVector3 v11; // [esp+50h] [ebp-10h] BYREF

  this->getPlaneEquation(this, (btVector4 *)&v9, i);
  v6 = v9;
  v7 = v10;
  planeNormal->mVec128.m128_u64[0] = v9;
  v8 = 0;
  planeNormal->mVec128.m128_u64[1] = LODWORD(v7);
  localGetSupportingVertex = this->localGetSupportingVertex;
  *(float *)&v6 = -planeNormal->mVec128.m128_f32[0];
  *((float *)&v6 + 1) = -planeNormal->mVec128.m128_f32[1];
  v7 = -planeNormal->mVec128.m128_f32[2];
  v8 = 0;
  *planeSupport = (btVector3)localGetSupportingVertex(this, &v11, (const btVector3 *)&v6)->mVec128;
}
