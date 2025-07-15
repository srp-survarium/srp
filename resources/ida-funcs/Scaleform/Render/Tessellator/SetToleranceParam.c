void __thiscall Scaleform::Render::Tessellator::SetToleranceParam(
        Scaleform::Render::Tessellator *this,
        const Scaleform::Render::ToleranceParams *param)
{
  float Epsilon; // [esp+4h] [ebp+4h]

  Epsilon = param->Epsilon;
  this->Epsilon = Epsilon;
  this->HasEpsilon = Epsilon > 0.0;
  this->IntersectionEpsilon = param->IntersectionEpsilon;
}
