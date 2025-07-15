Scaleform::GFx::MovieImpl::DragState *__thiscall Scaleform::GFx::MovieImpl::DragState::operator=(
        Scaleform::GFx::MovieImpl::DragState *this,
        const Scaleform::GFx::MovieImpl::DragState *__that)
{
  Scaleform::GFx::MovieImpl::DragState *result; // eax
  float __thata; // [esp+4h] [ebp+4h]
  float __thatb; // [esp+4h] [ebp+4h]
  float __thatc; // [esp+4h] [ebp+4h]

  result = this;
  result->pCharacter = __that->pCharacter;
  result->LockCenter = __that->LockCenter;
  result->Bound = __that->Bound;
  __thata = __that->BoundLT.y;
  result->BoundLT.x = __that->BoundLT.x;
  result->BoundLT.y = __thata;
  __thatb = __that->BoundRB.y;
  result->BoundRB.x = __that->BoundRB.x;
  result->BoundRB.y = __thatb;
  __thatc = __that->CenterDelta.y;
  result->CenterDelta.x = __that->CenterDelta.x;
  result->CenterDelta.y = __thatc;
  result->MouseIndex = __that->MouseIndex;
  return result;
}
