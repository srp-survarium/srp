void __thiscall Scaleform::Render::StrokerAA::calcJoin(
        Scaleform::Render::StrokerAA *this,
        const Scaleform::Render::StrokeVertex *v1,
        const Scaleform::Render::StrokeVertex *v2,
        const Scaleform::Render::StrokeVertex *v3,
        const Scaleform::Render::StrokerAA::WidthsType *w,
        Scaleform::Render::StrokerAA::JoinParamType *p)
{
  Scaleform::Render::StrokerAA::calcJoinParam(this, v1, v2, v3, w, p);
  switch ( this->LineJoin )
  {
    case MiterJoin:
    case MiterBevelJoin:
      Scaleform::Render::StrokerAA::calcMiterJoin(this, v1, w, p, this->LineJoin);
      break;
    case RoundJoin:
      Scaleform::Render::StrokerAA::calcRoundJoin(this, v1, w, p);
      break;
    case BevelJoin:
      Scaleform::Render::StrokerAA::calcBevelJoin(this, v1, w, p, BevelJoin);
      break;
    default:
      return;
  }
}
