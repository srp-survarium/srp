void __thiscall Scaleform::Render::HAL::beginDisplay(
        Scaleform::Render::HAL *this,
        Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2> >::NodeType *data)
{
  Scaleform::Render::RenderEvent *v3; // eax
  Scaleform::String::DataDesc *v4; // ecx
  Scaleform::Render::RenderEvent *v5; // edi
  void (__thiscall **p_Begin)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *); // esi
  unsigned int HALState; // eax
  unsigned int pNext; // ecx
  Scaleform::Render::Viewport *v10; // ebx
  int Height; // eax
  void (__thiscall *clearSolidRectangle)(Scaleform::Render::HAL *, const Scaleform::Render::Rect<int> *, Scaleform::Render::Color); // edx
  Scaleform::String v13; // [esp-4h] [ebp-50h] BYREF
  _DWORD v14[4]; // [esp+10h] [ebp-3Ch] BYREF
  _BYTE v15[44]; // [esp+20h] [ebp-2Ch] BYREF
  Scaleform::String::DataDesc *backgroundColor; // [esp+50h] [ebp+4h]

  v3 = this->GetEvent(this, 4);
  v13.pData = v4;
  v5 = v3;
  p_Begin = (void (__thiscall **)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *))&v3->Begin;
  Scaleform::String::String(&v13, "Scaleform::Render::HAL::beginDisplay");
  (*p_Begin)(v5, v13.pData);
  HALState = this->HALState;
  if ( (HALState & 2) != 0 )
  {
    this->HALState = HALState | 8;
    pNext = (unsigned int)data[2].pNext;
    data->pNext = this->BeginDisplayDataList.FirstEmptySlot;
    this->BeginDisplayDataList.FirstEmptySlot = data;
    backgroundColor = (Scaleform::String::DataDesc *)pNext;
    v10 = (Scaleform::Render::Viewport *)&data[3];
    if ( (this->HALState & 4) == 0 )
    {
      this->BeginScene(this);
      this->HALState |= 0x200u;
    }
    Scaleform::Render::HAL::applyBlendMode(
      this,
      this->CurrentBlendState.Mode,
      this->CurrentBlendState.SourceAc,
      (Scaleform::String::DataDesc *)this->CurrentBlendState.ForceAc);
    this->beginMaskDisplay(this);
    qmemcpy(&this->VP, this->Matrices.pObject->SetOrientation(this->Matrices.pObject, v15, v10), sizeof(this->VP));
    if ( Scaleform::Render::Viewport::GetClippedRect<int>(&this->VP, &this->ViewRect, 0) )
      this->HALState |= 0x20u;
    else
      this->HALState &= ~0x20u;
    this->updateViewport(this);
    if ( HIBYTE(backgroundColor) )
    {
      v13.pData = backgroundColor;
      Height = v10->Height;
      v14[2] = v10->Width;
      clearSolidRectangle = this->clearSolidRectangle;
      v14[3] = Height;
      v14[0] = 0;
      v14[1] = 0;
      ((void (__thiscall *)(Scaleform::Render::HAL *, _DWORD *, Scaleform::String::DataDesc *))clearSolidRectangle)(
        this,
        v14,
        backgroundColor);
    }
  }
}
