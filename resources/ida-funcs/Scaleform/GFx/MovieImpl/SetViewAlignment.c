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
  Scaleform::GFx::Viewport v; // [esp+0h] [ebp-34h] BYREF

  this->ViewAlignment = align;
  BufferWidth = this->mViewport.BufferWidth;
  v.Scale = this->mViewport.Scale;
  BufferHeight = this->mViewport.BufferHeight;
  AspectRatio = this->mViewport.AspectRatio;
  v.BufferWidth = BufferWidth;
  v.AspectRatio = AspectRatio;
  Left = this->mViewport.Left;
  v.BufferHeight = BufferHeight;
  Top = this->mViewport.Top;
  v.Left = Left;
  Width = this->mViewport.Width;
  v.Top = Top;
  Height = this->mViewport.Height;
  v.Width = Width;
  Flags = this->mViewport.Flags;
  v.Height = Height;
  ScissorLeft = this->mViewport.ScissorLeft;
  v.Flags = Flags;
  ScissorTop = this->mViewport.ScissorTop;
  v.ScissorLeft = ScissorLeft;
  ScissorWidth = this->mViewport.ScissorWidth;
  v.ScissorTop = ScissorTop;
  ScissorHeight = this->mViewport.ScissorHeight;
  ++this->mViewport.Flags;
  v.ScissorWidth = ScissorWidth;
  SetViewport = this->SetViewport;
  v.ScissorHeight = ScissorHeight;
  SetViewport(this, &v);
}
