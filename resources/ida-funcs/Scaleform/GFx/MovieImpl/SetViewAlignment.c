void __thiscall Scaleform::GFx::MovieImpl::SetViewAlignment(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Movie::AlignType align)
{
  int BufferWidth; // edx
  int BufferHeight; // eax
  double AspectRatio; // st7
  int Left; // edx
  int Top; // eax
  int Width; // edx
  int Height; // eax
  unsigned int Flags; // edx
  int ScissorLeft; // eax
  int ScissorTop; // edx
  int ScissorWidth; // eax
  int ScissorHeight; // edx
  void (__thiscall *SetViewport)(Scaleform::GFx::Movie *, const Scaleform::GFx::Viewport *); // eax
  _DWORD v15[13]; // [esp+0h] [ebp-34h] BYREF

  this->ViewAlignment = align;
  BufferWidth = this->mViewport.BufferWidth;
  *(float *)&v15[11] = this->mViewport.Scale;
  BufferHeight = this->mViewport.BufferHeight;
  AspectRatio = this->mViewport.AspectRatio;
  v15[0] = BufferWidth;
  *(float *)&v15[12] = AspectRatio;
  Left = this->mViewport.Left;
  v15[1] = BufferHeight;
  Top = this->mViewport.Top;
  v15[2] = Left;
  Width = this->mViewport.Width;
  v15[3] = Top;
  Height = this->mViewport.Height;
  v15[4] = Width;
  Flags = this->mViewport.Flags;
  v15[5] = Height;
  ScissorLeft = this->mViewport.ScissorLeft;
  v15[10] = Flags;
  ScissorTop = this->mViewport.ScissorTop;
  v15[6] = ScissorLeft;
  ScissorWidth = this->mViewport.ScissorWidth;
  v15[7] = ScissorTop;
  ScissorHeight = this->mViewport.ScissorHeight;
  ++this->mViewport.Flags;
  v15[8] = ScissorWidth;
  SetViewport = this->SetViewport;
  v15[9] = ScissorHeight;
  SetViewport(this, (const Scaleform::GFx::Viewport *)v15);
}
