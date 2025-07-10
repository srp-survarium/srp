btPersistentManifold *__userpurge btPersistentManifold::btPersistentManifold@<eax>(
        btPersistentManifold *this@<ecx>,
        int a2@<esi>,
        void *body0,
        void *body1,
        int __formal,
        float contactBreakingThreshold,
        float contactProcessingThreshold)
{
  *(_DWORD *)a2 = 1025;
  `vector constructor iterator'(
    (char *)(a2 + 16),
    0x120u,
    4,
    (void *(__thiscall *)(void *))btManifoldPoint::btManifoldPoint);
  *(_DWORD *)(a2 + 1180) = __formal;
  *(_DWORD *)(a2 + 1168) = body0;
  *(_DWORD *)(a2 + 1172) = body1;
  *(_DWORD *)(a2 + 1176) = 0;
  *(float *)(a2 + 1184) = contactBreakingThreshold;
  return (btPersistentManifold *)a2;
}
