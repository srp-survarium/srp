void __thiscall Scaleform::Render::Stroker::SetToleranceParam(
        Scaleform::Render::Stroker *this,
        const Scaleform::Render::ToleranceParams *param)
{
  this->CurveTolerance = param->CurveTolerance;
  this->IntersectionEpsilon = param->IntersectionEpsilon;
}
