void __thiscall Scaleform::Render::Viewport::Viewport(
        Scaleform::Render::Viewport *this,
        Scaleform::Render::Size<int> bufferSize,
        Scaleform::Render::Rect<int> view,
        unsigned int flags)
{
  this->BufferWidth = bufferSize.Width;
  this->Left = view.x1;
  this->BufferHeight = bufferSize.Height;
  this->Top = view.y1;
  this->Height = view.y2 - view.y1;
  this->Width = view.x2 - view.x1;
  this->Flags = flags;
  this->ScissorHeight = 0;
  this->ScissorWidth = 0;
  this->ScissorTop = 0;
  this->ScissorLeft = 0;
}
