void __thiscall btBoxShape::getPlane(btBoxShape *this, btVector3 *planeNormal, btVector3 *planeSupport, int i)
{
  btBoxShape_vtbl *v5; // eax
  int v6; // [esp+10h] [ebp-30h] BYREF
  unsigned __int64 v7; // [esp+14h] [ebp-2Ch]
  int v8; // [esp+1Ch] [ebp-24h]
  int v9; // [esp+20h] [ebp-20h] BYREF
  unsigned __int64 v10; // [esp+24h] [ebp-1Ch]
  btVector3 v11; // [esp+30h] [ebp-10h] BYREF

  this->getPlaneEquation(this, (btVector4 *)&v9, i);
  v6 = v9;
  v7 = v10;
  v8 = 0;
  planeNormal->mVec128.m128_i32[0] = v9;
  *(unsigned __int64 *)((char *)planeNormal->mVec128.m128_u64 + 4) = v7;
  planeNormal->mVec128.m128_i32[3] = v8;
  v6 = planeNormal->mVec128.m128_i32[0] ^ _mask__NegFloat_;
  LODWORD(v7) = planeNormal->mVec128.m128_i32[1] ^ _mask__NegFloat_;
  v5 = this->__vftable;
  HIDWORD(v7) = planeNormal->mVec128.m128_i32[2] ^ _mask__NegFloat_;
  v8 = 0;
  *planeSupport = (btVector3)v5->localGetSupportingVertex(this, &v11, (const btVector3 *)&v6)->mVec128;
}
