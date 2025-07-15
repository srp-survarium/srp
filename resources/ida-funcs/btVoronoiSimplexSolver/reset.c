void __usercall btVoronoiSimplexSolver::reset(btVoronoiSimplexSolver *this@<ecx>, int a2@<eax>)
{
  *(_BYTE *)(a2 + 324) = 0;
  *(_DWORD *)a2 = 0;
  *(_BYTE *)(a2 + 384) = 1;
  strcpy((char *)(a2 + 304), "k\v^]k\v^]k\v^]");
  *(_BYTE *)(a2 + 317) = 0;
  *(_WORD *)(a2 + 318) = 0;
  *(_BYTE *)(a2 + 372) = 0;
  *(_DWORD *)(a2 + 356) = 0;
  *(_DWORD *)(a2 + 360) = 0;
  *(_DWORD *)(a2 + 364) = 0;
  *(_DWORD *)(a2 + 368) = 0;
  *(_WORD *)(a2 + 352) &= 0xFFF0u;
}
