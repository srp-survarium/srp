void __thiscall Scaleform::GFx::MouseState::MouseState(Scaleform::GFx::MouseState *this)
{
  this->TopmostEntity.pProxy.pObject = 0;
  this->PrevTopmostEntity.pProxy.pObject = 0;
  this->ActiveEntity.pProxy.pObject = 0;
  this->MouseButtonDownEntities.Data.Data = 0;
  this->MouseButtonDownEntities.Data.Size = 0;
  this->MouseButtonDownEntities.Data.Policy.Capacity = 0;
  this->LastPosition.y = 0.0;
  *((_BYTE *)this + 52) &= 0xE0u;
  this->LastPosition.x = 0.0;
  this->mPresetCursorType = -1;
  this->CursorType = 0;
  this->PrevButtonsState = 0;
  this->CurButtonsState = 0;
  this->WheelDelta = 0;
}
