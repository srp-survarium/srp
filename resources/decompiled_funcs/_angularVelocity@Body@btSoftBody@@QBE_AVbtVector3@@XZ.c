btVector3 *__usercall btSoftBody::Body::angularVelocity@<eax>(
        btSoftBody::Body *this@<ecx>,
        btVector3 *a2@<eax>,
        int *a3@<edx>)
{
  int v3; // ecx
  int v4; // ecx

  v3 = a3[1];
  if ( v3 )
  {
    a2->mVec128.m128_u64[0] = *(_QWORD *)(v3 + 336);
    a2->mVec128.m128_u64[1] = *(_QWORD *)(v3 + 344);
  }
  else
  {
    v4 = *a3;
    if ( *a3 )
    {
      a2->mVec128.m128_u64[0] = *(_QWORD *)(v4 + 352);
      a2->mVec128.m128_u64[1] = *(_QWORD *)(v4 + 360);
    }
    else
    {
      a2->mVec128.m128_i32[0] = 0;
      a2->mVec128.m128_i32[1] = 0;
      a2->mVec128.m128_i32[2] = 0;
      a2->mVec128.m128_i32[3] = 0;
    }
  }
  return a2;
}
