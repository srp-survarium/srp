char __thiscall btGjkEpaPenetrationDepthSolver::calcPenDepth(
        btGjkEpaPenetrationDepthSolver *this,
        btVoronoiSimplexSolver *simplexSolver,
        const btConvexShape *pConvexA,
        const btConvexShape *pConvexB,
        const btTransform *transformA,
        const btTransform *transformB,
        btVector3 *v,
        btVector3 *wWitnessOnA,
        btVector3 *wWitnessOnB,
        btIDebugDraw *debugDraw,
        btStackAlloc *stackAlloc)
{
  btVector3 guess; // [esp+BCh] [ebp-60h] BYREF
  btGjkEpaSolver2::sResults results; // [esp+CCh] [ebp-50h] BYREF

  guess.mVec128.m128_f32[0] = transformA->m_origin.mVec128.m128_f32[0] - transformB->m_origin.mVec128.m128_f32[0];
  guess.mVec128.m128_f32[1] = transformA->m_origin.mVec128.m128_f32[1] - transformB->m_origin.mVec128.m128_f32[1];
  guess.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(transformA->m_origin.mVec128.m128_f32[2] - transformB->m_origin.mVec128.m128_f32[2]);
  if ( btGjkEpaSolver2::Penetration(
         pConvexA,
         transformA,
         pConvexB,
         transformB,
         (const gjkepa2_impl::MinkowskiDiff *)&guess,
         &results,
         1) )
  {
    *wWitnessOnA = results.witnesses[0];
    *wWitnessOnB = results.witnesses[1];
    *v = results.normal;
    return 1;
  }
  else
  {
    if ( btGjkEpaSolver2::Distance(pConvexA, transformA, pConvexB, transformB, &guess, &results) )
    {
      *wWitnessOnA = results.witnesses[0];
      *wWitnessOnB = results.witnesses[1];
      *v = results.normal;
    }
    return 0;
  }
}
