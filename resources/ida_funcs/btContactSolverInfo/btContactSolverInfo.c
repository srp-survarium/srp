btContactSolverInfo *__usercall btContactSolverInfo::btContactSolverInfo@<eax>(
        btContactSolverInfo *this@<ecx>,
        btContactSolverInfo *result@<eax>)
{
  const vostok::math::float4x4 *v2; // xmm1_4

  v2 = clear_value;
  result->m_tau = 0.60000002;
  result->m_friction = s_aim_transition_time;
  result->m_maxErrorReduction = 20.0;
  LODWORD(result->m_damping) = v2;
  result->m_restitution = 0.0;
  result->m_erp = 0.2;
  result->m_globalCfm = 0.0;
  LODWORD(result->m_sor) = v2;
  result->m_linearSlop = 0.0;
  result->m_numIterations = 10;
  result->m_erp2 = FLOAT_0_1;
  result->m_splitImpulse = 0;
  result->m_splitImpulsePenetrationThreshold = -0.02;
  result->m_warmstartingFactor = 0.85000002;
  result->m_solverMode = 260;
  result->m_restingContactRestitutionThreshold = 2;
  result->m_minimumSolverBatchSize = 128;
  return result;
}
