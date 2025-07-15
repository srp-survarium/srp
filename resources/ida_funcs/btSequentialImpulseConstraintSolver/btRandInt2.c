unsigned int __fastcall btSequentialImpulseConstraintSolver::btRandInt2(
        btSequentialImpulseConstraintSolver *this,
        int a2)
{
  unsigned int v2; // eax

  v2 = 1664525 * *(_DWORD *)(a2 + 124) + 1013904223;
  *(_DWORD *)(a2 + 124) = v2;
  if ( this <= (btSequentialImpulseConstraintSolver *)&_sbh_sizeHeaderList )
  {
    v2 ^= HIWORD(v2);
    if ( (unsigned int)this <= 0x100 )
    {
      v2 ^= v2 >> 8;
      if ( (unsigned int)this <= 0x10 )
      {
        v2 ^= v2 >> 4;
        if ( (unsigned int)this <= 4 )
        {
          v2 ^= v2 >> 2;
          if ( (unsigned int)this <= 2 )
            v2 ^= v2 >> 1;
        }
      }
    }
  }
  return v2 % (unsigned int)this;
}
