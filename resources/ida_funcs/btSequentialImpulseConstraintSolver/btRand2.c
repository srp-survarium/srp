unsigned int __thiscall btSequentialImpulseConstraintSolver::btRand2(btSequentialImpulseConstraintSolver *this)
{
  unsigned int result; // eax

  result = 1664525 * this->m_btSeed2 + 1013904223;
  this->m_btSeed2 = result;
  return result;
}
