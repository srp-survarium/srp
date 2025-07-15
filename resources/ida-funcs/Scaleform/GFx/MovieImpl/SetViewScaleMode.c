void __thiscall Scaleform::GFx::MovieImpl::SetViewScaleMode(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Movie::ScaleModeType scaleMode)
{
  Scaleform::GFx::UserEventHandler *pObject; // ecx
  int BufferWidth; // eax
  int BufferHeight; // ecx
  int Left; // edx
  int Top; // eax
  int Width; // ecx
  int Height; // edx
  unsigned int Flags; // eax
  int ScissorLeft; // ecx
  int ScissorTop; // edx
  int ScissorWidth; // eax
  int ScissorHeight; // ecx
  void (__thiscall *SetViewport)(Scaleform::GFx::Movie *, const Scaleform::GFx::Viewport *); // edx
  int v16; // [esp+8h] [ebp-3Ch] BYREF
  int v17; // [esp+Ch] [ebp-38h]
  _DWORD v18[13]; // [esp+10h] [ebp-34h] BYREF

  pObject = this->pUserEventHandler.pObject;
  if ( pObject )
  {
    v16 = 25 - (scaleMode != SM_NoScale);
    LOBYTE(v17) = 0;
    pObject->HandleEvent(pObject, this, (const Scaleform::GFx::Event *)&v16);
  }
  this->ViewScaleMode = scaleMode;
  BufferWidth = this->mViewport.BufferWidth;
  *(float *)&v18[11] = this->mViewport.Scale;
  BufferHeight = this->mViewport.BufferHeight;
  Left = this->mViewport.Left;
  *(float *)&v18[12] = this->mViewport.AspectRatio;
  v18[0] = BufferWidth;
  Top = this->mViewport.Top;
  v18[1] = BufferHeight;
  Width = this->mViewport.Width;
  v18[2] = Left;
  Height = this->mViewport.Height;
  v18[3] = Top;
  Flags = this->mViewport.Flags;
  v18[4] = Width;
  ScissorLeft = this->mViewport.ScissorLeft;
  v18[5] = Height;
  ScissorTop = this->mViewport.ScissorTop;
  v18[10] = Flags;
  ScissorWidth = this->mViewport.ScissorWidth;
  v18[6] = ScissorLeft;
  ScissorHeight = this->mViewport.ScissorHeight;
  ++this->mViewport.Flags;
  v18[7] = ScissorTop;
  SetViewport = this->SetViewport;
  v18[8] = ScissorWidth;
  v18[9] = ScissorHeight;
  SetViewport(this, (const Scaleform::GFx::Viewport *)v18);
}
