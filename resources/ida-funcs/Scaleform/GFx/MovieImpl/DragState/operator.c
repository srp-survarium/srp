Scaleform::GFx::MovieImpl::DragState *__thiscall Scaleform::GFx::MovieImpl::DragState::operator=(
        Scaleform::GFx::MovieImpl::DragState *this,
        const Scaleform::GFx::MovieImpl::DragState *__that)
{
  Scaleform::GFx::MovieImpl::DragState *result; // eax
  float y; // [esp+4h] [ebp+4h]
  float v5; // [esp+4h] [ebp+4h]
  float v6; // [esp+4h] [ebp+4h]

  result = this;
  result->pCharacter = __that->pCharacter;
  result->LockCenter = __that->LockCenter;
  result->Bound = __that->Bound;
  y = __that->BoundLT.y;
  result->BoundLT.x = __that->BoundLT.x;
  result->BoundLT.y = y;
  v5 = __that->BoundRB.y;
  result->BoundRB.x = __that->BoundRB.x;
  result->BoundRB.y = v5;
  v6 = __that->CenterDelta.y;
  result->CenterDelta.x = __that->CenterDelta.x;
  result->CenterDelta.y = v6;
  result->MouseIndex = __that->MouseIndex;
  return result;
}
