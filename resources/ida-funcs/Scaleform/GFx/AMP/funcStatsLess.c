BOOL __cdecl Scaleform::GFx::AMP::funcStatsLess(
        const Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *lhs,
        const Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *rhs)
{
  return lhs->TotalTime > rhs->TotalTime;
}
