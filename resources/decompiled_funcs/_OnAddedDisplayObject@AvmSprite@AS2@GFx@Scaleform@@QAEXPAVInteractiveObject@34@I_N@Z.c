void __thiscall Scaleform::GFx::AS2::AvmSprite::OnAddedDisplayObject(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::InteractiveObject *pscriptCh,
        unsigned int sessionId,
        bool placeObject)
{
  Scaleform::GFx::InteractiveObject *v4; // esi
  bool v5; // zf
  Scaleform::GFx::EventId id; // [esp+8h] [ebp-14h] BYREF

  v4 = (pscriptCh->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 ? pscriptCh : 0;
  if ( placeObject )
  {
    v5 = v4 == 0;
  }
  else
  {
    Scaleform::GFx::AS2::MovieRoot::DoActionsForSession(
      (Scaleform::GFx::AS2::MovieRoot *)this->pDispObj->pASRoot,
      sessionId);
    if ( !v4 )
      return;
    id.Id = 1;
    memset(&id.WcharCode, 0, 9);
    id.RollOverCnt = 0;
    id.KeysState.States = 0;
    id.MouseWheelDelta = 0;
    id.ControllerIndex = -1;
    v5 = !Scaleform::GFx::DisplayObject::HasEventHandler(v4, &id);
  }
  if ( !v5 )
    LOBYTE(v4[1].pIndXFormData) |= 0x80u;
}
