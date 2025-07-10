void __thiscall Scaleform::Render::StrokerAA::SetToleranceParam(
        Scaleform::Render::StrokerAA *this,
        const Scaleform::Render::ToleranceParams *param)
{
  this->Tolerance = param->CurveTolerance;
  this->IntersectionEpsilon = param->IntersectionEpsilon;
}
