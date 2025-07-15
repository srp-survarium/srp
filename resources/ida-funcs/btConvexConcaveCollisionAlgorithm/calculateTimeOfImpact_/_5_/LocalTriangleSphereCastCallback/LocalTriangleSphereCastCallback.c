int __userpurge btConvexConcaveCollisionAlgorithm::calculateTimeOfImpact_::_5_::LocalTriangleSphereCastCallback::LocalTriangleSphereCastCallback@<eax>(
        int result@<eax>,
        _DWORD *a2@<edx>,
        int a3@<xmm0>,
        const btTransform *from)
{
  *(_DWORD *)result = &`btConvexConcaveCollisionAlgorithm::calculateTimeOfImpact'::`5'::LocalTriangleSphereCastCallback::`vftable';
  *(btTransform *)(result + 16) = *from;
  *(_DWORD *)(result + 80) = *a2;
  *(_DWORD *)(result + 84) = a2[1];
  *(_DWORD *)(result + 88) = a2[2];
  *(_DWORD *)(result + 92) = a2[3];
  *(_DWORD *)(result + 96) = a2[4];
  *(_DWORD *)(result + 100) = a2[5];
  *(_DWORD *)(result + 104) = a2[6];
  *(_DWORD *)(result + 108) = a2[7];
  *(_DWORD *)(result + 112) = a2[8];
  *(_DWORD *)(result + 116) = a2[9];
  *(_DWORD *)(result + 120) = a2[10];
  *(_DWORD *)(result + 124) = a2[11];
  *(_DWORD *)(result + 128) = a2[12];
  *(_DWORD *)(result + 132) = a2[13];
  *(_DWORD *)(result + 136) = a2[14];
  *(_DWORD *)(result + 140) = a2[15];
  *(_DWORD *)(result + 208) = a3;
  *(float *)(result + 212) = s_bm_current_air_resistance;
  return result;
}
