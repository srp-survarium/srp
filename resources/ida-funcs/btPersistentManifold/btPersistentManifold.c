btPersistentManifold *__userpurge btPersistentManifold::btPersistentManifold@<eax>(
        btPersistentManifold *this@<ecx>,
        int a2@<esi>,
        void *body0,
        void *body1,
        int __formal,
        float contactBreakingThreshold,
        float contactProcessingThreshold)
{
  btManifoldPoint *v7; // edi
  int i; // ebx

  *(_DWORD *)a2 = 1025;
  v7 = (btManifoldPoint *)(a2 + 16);
  for ( i = 3; i >= 0; --i )
    btManifoldPoint::btManifoldPoint(v7++);
  *(_DWORD *)(a2 + 1176) = 0;
  *(_DWORD *)(a2 + 1168) = body0;
  *(_DWORD *)(a2 + 1180) = __formal;
  *(_DWORD *)(a2 + 1172) = body1;
  *(float *)(a2 + 1184) = contactBreakingThreshold;
  return (btPersistentManifold *)a2;
}
