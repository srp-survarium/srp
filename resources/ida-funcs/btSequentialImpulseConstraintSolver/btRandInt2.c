unsigned int __usercall btSequentialImpulseConstraintSolver::btRandInt2@<eax>(
        btSequentialImpulseConstraintSolver *this@<ecx>,
        unsigned int n@<esi>)
{
  unsigned int v2; // eax

  v2 = 1664525 * this->m_btSeed2 + 1013904223;
  this->m_btSeed2 = v2;
  if ( n <= (unsigned int)&_sbh_sizeHeaderList )
  {
    v2 ^= HIWORD(v2);
    if ( n <= 0x100 )
    {
      v2 ^= v2 >> 8;
      if ( n <= 0x10 )
      {
        v2 ^= v2 >> 4;
        if ( n <= 4 )
        {
          v2 ^= v2 >> 2;
          if ( n <= 2 )
            v2 ^= v2 >> 1;
        }
      }
    }
  }
  return v2 % n;
}
