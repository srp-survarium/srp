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
  Scaleform::GFx::Viewport v; // [esp+10h] [ebp-34h] BYREF

  pObject = this->pUserEventHandler.pObject;
  if ( pObject )
  {
    v16 = 25 - (scaleMode != SM_NoScale);
    LOBYTE(v17) = 0;
    pObject->HandleEvent(pObject, this, (const Scaleform::GFx::Event *)&v16);
  }
  this->ViewScaleMode = scaleMode;
  BufferWidth = this->mViewport.BufferWidth;
  v.Scale = this->mViewport.Scale;
  BufferHeight = this->mViewport.BufferHeight;
  Left = this->mViewport.Left;
  v.AspectRatio = this->mViewport.AspectRatio;
  v.BufferWidth = BufferWidth;
  Top = this->mViewport.Top;
  v.BufferHeight = BufferHeight;
  Width = this->mViewport.Width;
  v.Left = Left;
  Height = this->mViewport.Height;
  v.Top = Top;
  Flags = this->mViewport.Flags;
  v.Width = Width;
  ScissorLeft = this->mViewport.ScissorLeft;
  v.Height = Height;
  ScissorTop = this->mViewport.ScissorTop;
  v.Flags = Flags;
  ScissorWidth = this->mViewport.ScissorWidth;
  v.ScissorLeft = ScissorLeft;
  ScissorHeight = this->mViewport.ScissorHeight;
  ++this->mViewport.Flags;
  v.ScissorTop = ScissorTop;
  SetViewport = this->SetViewport;
  v.ScissorWidth = ScissorWidth;
  v.ScissorHeight = ScissorHeight;
  SetViewport(this, &v);
}
