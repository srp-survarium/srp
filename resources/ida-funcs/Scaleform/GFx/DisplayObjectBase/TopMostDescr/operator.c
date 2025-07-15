Scaleform::GFx::DisplayObjectBase::TopMostDescr *__thiscall Scaleform::GFx::DisplayObjectBase::TopMostDescr::operator=(
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *this,
        const Scaleform::GFx::DisplayObjectBase::TopMostDescr *__that)
{
  Scaleform::GFx::DisplayObjectBase::TopMostDescr *result; // eax
  float y; // [esp+4h] [ebp+4h]

  result = this;
  result->pResult = __that->pResult;
  y = __that->LocalPt.y;
  result->LocalPt.x = __that->LocalPt.x;
  result->LocalPt.y = y;
  result->pIgnoreMC = __that->pIgnoreMC;
  result->pHitArea = __that->pHitArea;
  result->ControllerIdx = __that->ControllerIdx;
  result->TestAll = __that->TestAll;
  return result;
}
