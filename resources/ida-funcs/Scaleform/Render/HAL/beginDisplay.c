void __thiscall Scaleform::Render::HAL::BeginDisplay(
        Scaleform::Render::HAL *this,
        Scaleform::Render::Color backgroundColor,
        const Scaleform::Render::Viewport *vpin)
{
  int BufferHeight; // edx
  int Left; // ecx
  int Top; // edx
  int Width; // ecx
  int Height; // edx
  unsigned int Flags; // ecx
  int ScissorLeft; // edx
  int ScissorTop; // ecx
  int ScissorWidth; // edx
  int ScissorHeight; // eax
  Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2> >::PageType *v14; // eax
  Scaleform::Render::BeginDisplayData *v15; // edx
  Scaleform::Render::HAL_vtbl *v16; // edx
  void (__thiscall *Draw)(Scaleform::Render::HAL *, const Scaleform::Render::RenderQueueItem *); // edx
  _DWORD v18[5]; // [esp+4h] [ebp-40h] BYREF
  _DWORD v19[11]; // [esp+18h] [ebp-2Ch] BYREF

  if ( (this->HALState & 2) != 0 )
  {
    BufferHeight = vpin->BufferHeight;
    v19[0] = vpin->BufferWidth;
    Left = vpin->Left;
    v19[1] = BufferHeight;
    Top = vpin->Top;
    v19[2] = Left;
    Width = vpin->Width;
    v19[3] = Top;
    Height = vpin->Height;
    v19[4] = Width;
    Flags = vpin->Flags;
    v19[5] = Height;
    ScissorLeft = vpin->ScissorLeft;
    v19[10] = Flags;
    ScissorTop = vpin->ScissorTop;
    v19[6] = ScissorLeft;
    ScissorWidth = vpin->ScissorWidth;
    ScissorHeight = vpin->ScissorHeight;
    v19[7] = ScissorTop;
    v18[4] = backgroundColor.Raw;
    v19[8] = ScissorWidth;
    v19[9] = ScissorHeight;
    v14 = Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2>>::allocate(&this->BeginDisplayDataList);
    v15 = (Scaleform::Render::BeginDisplayData *)v18[3];
    v14->Data[0].pPrev = (Scaleform::Render::BeginDisplayData *)v18[2];
    v14->Data[0].pNext = v15;
    v14->Data[0].BackgroundColor = backgroundColor;
    qmemcpy(&v14->Data[0].VP, v19, sizeof(v14->Data[0].VP));
    v16 = this->__vftable;
    if ( (this->HALState & 4) != 0 )
    {
      Draw = v16->Draw;
      v18[1] = v14;
      v18[0] = &Scaleform::Render::HALBeginDisplayItem::Instance;
      Draw(this, (const Scaleform::Render::RenderQueueItem *)v18);
    }
    else
    {
      v16->beginDisplay(this, v14->Data);
    }
  }
}
