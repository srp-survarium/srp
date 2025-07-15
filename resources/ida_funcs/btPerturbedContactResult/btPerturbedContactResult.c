void __stdcall btPerturbedContactResult::btPerturbedContactResult(
        btPerturbedContactResult *this,
        btManifoldResult *originalResult,
        const btTransform *transformA,
        bool perturbA,
        btIDebugDraw *debugDrawer)
{
  const btTransform *transformB; // edx
  const btTransform *unPerturbedTransform; // ecx

  this->__vftable = (btPerturbedContactResult_vtbl *)&btPerturbedContactResult::`vftable';
  this->m_partId0 = -1;
  this->m_partId1 = -1;
  this->m_index0 = -1;
  this->m_index1 = -1;
  this->m_originalManifoldResult = originalResult;
  this->m_transformA = *transformA;
  this->m_transformB = *transformB;
  this->m_unPerturbedTransform = *unPerturbedTransform;
  this->m_perturbA = perturbA;
  this->m_debugDrawer = debugDrawer;
}
