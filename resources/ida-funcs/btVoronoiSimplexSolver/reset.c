void __usercall btVoronoiSimplexSolver::reset(btVoronoiSimplexSolver *this@<ecx>, int a2@<eax>)
{
  int v2; // eax

  *(float *)(a2 + 304) = FLOAT_9_9999998e17;
  *(float *)(a2 + 308) = FLOAT_9_9999998e17;
  *(float *)(a2 + 312) = FLOAT_9_9999998e17;
  *(_BYTE *)(a2 + 324) = 0;
  *(_DWORD *)a2 = 0;
  *(_BYTE *)(a2 + 384) = 1;
  *(_DWORD *)(a2 + 316) = 0;
  v2 = a2 + 336;
  *(_BYTE *)(v2 + 36) = 0;
  *(_DWORD *)(v2 + 20) = 0;
  *(_DWORD *)(v2 + 24) = 0;
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 32) = 0;
  *(_WORD *)(v2 + 16) &= 0xFFF0u;
}
