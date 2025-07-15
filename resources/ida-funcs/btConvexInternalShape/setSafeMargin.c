void __usercall btConvexInternalShape::setSafeMargin(
        btConvexInternalShape *this@<esi>,
        const btVector3 *halfExtents@<eax>)
{
  float v2; // xmm0_4
  int v3; // ecx
  double v4; // st6
  float v5; // [esp+4h] [ebp-4h]
  float v6; // [esp+4h] [ebp-4h]

  v2 = halfExtents->mVec128.m128_f32[1];
  if ( v2 <= halfExtents->mVec128.m128_f32[0] )
  {
    if ( halfExtents->mVec128.m128_f32[2] > v2 )
    {
      v3 = 1;
      goto LABEL_7;
    }
  }
  else if ( halfExtents->mVec128.m128_f32[2] > halfExtents->mVec128.m128_f32[0] )
  {
    v3 = 0;
    goto LABEL_7;
  }
  v3 = 2;
LABEL_7:
  v5 = halfExtents->mVec128.m128_f32[v3] * 0.1;
  v4 = ((double (__thiscall *)(btConvexInternalShape *, _DWORD))this->getMargin)(this, LODWORD(v5));
  if ( v4 > v6 )
    ((void (__thiscall *)(btConvexInternalShape *, _DWORD))this->setMargin)(this, LODWORD(v6));
}
