void __thiscall Scaleform::Render::Hairliner::SetToleranceParam(
        Scaleform::Render::Hairliner *this,
        const Scaleform::Render::ToleranceParams *param)
{
  this->Epsilon = param->Epsilon;
  this->IntersectionEpsilon = param->IntersectionEpsilon;
}
