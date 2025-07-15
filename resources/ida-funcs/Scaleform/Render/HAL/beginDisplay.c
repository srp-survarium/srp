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
  Scaleform::Render::BeginDisplayData *pNext; // edx
  Scaleform::Render::HAL_vtbl *v16; // edx
  void (__thiscall *Draw)(Scaleform::Render::HAL *, const Scaleform::Render::RenderQueueItem *); // edx
  _DWORD v18[2]; // [esp+4h] [ebp-40h] BYREF
  Scaleform::Render::BeginDisplayData entry; // [esp+Ch] [ebp-38h] BYREF

  if ( (this->HALState & 2) != 0 )
  {
    BufferHeight = vpin->BufferHeight;
    entry.VP.BufferWidth = vpin->BufferWidth;
    Left = vpin->Left;
    entry.VP.BufferHeight = BufferHeight;
    Top = vpin->Top;
    entry.VP.Left = Left;
    Width = vpin->Width;
    entry.VP.Top = Top;
    Height = vpin->Height;
    entry.VP.Width = Width;
    Flags = vpin->Flags;
    entry.VP.Height = Height;
    ScissorLeft = vpin->ScissorLeft;
    entry.VP.Flags = Flags;
    ScissorTop = vpin->ScissorTop;
    entry.VP.ScissorLeft = ScissorLeft;
    ScissorWidth = vpin->ScissorWidth;
    ScissorHeight = vpin->ScissorHeight;
    entry.VP.ScissorTop = ScissorTop;
    entry.BackgroundColor = backgroundColor;
    entry.VP.ScissorWidth = ScissorWidth;
    entry.VP.ScissorHeight = ScissorHeight;
    v14 = Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2>>::allocate(&this->BeginDisplayDataList);
    pNext = entry.pNext;
    v14->Data[0].pPrev = entry.pPrev;
    v14->Data[0].pNext = pNext;
    v14->Data[0].BackgroundColor = backgroundColor;
    qmemcpy(&v14->Data[0].VP, &entry.VP, sizeof(v14->Data[0].VP));
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
