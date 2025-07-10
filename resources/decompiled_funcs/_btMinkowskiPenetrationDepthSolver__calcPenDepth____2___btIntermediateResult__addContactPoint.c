void __thiscall btMinkowskiPenetrationDepthSolver::calcPenDepth_::_2_::btIntermediateResult::addContactPoint(
        btMinkowskiPenetrationDepthSolver::calcPenDepth::__l2::btIntermediateResult *this,
        const btVector3 *normalOnBInWorld,
        const btVector3 *pointInWorld,
        float depth)
{
  this->m_normalOnBInWorld = (btVector3)normalOnBInWorld->mVec128;
  this->m_pointInWorld = (btVector3)pointInWorld->mVec128;
  this->m_depth = depth;
  this->m_hasResult = 1;
}
