void __thiscall Scaleform::Render::Tessellator::SetToleranceParam(
        Scaleform::Render::Tessellator *this,
        const Scaleform::Render::ToleranceParams *param)
{
  float parama; // [esp+4h] [ebp+4h]

  parama = param->Epsilon;
  this->Epsilon = parama;
  this->HasEpsilon = parama > 0.0;
  this->IntersectionEpsilon = param->IntersectionEpsilon;
}
