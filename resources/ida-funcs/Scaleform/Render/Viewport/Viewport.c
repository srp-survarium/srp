void __thiscall Scaleform::Render::Viewport::Viewport(
        Scaleform::Render::Viewport *this,
        const Scaleform::Render::Viewport *src)
{
  *this = *src;
}


void __thiscall Scaleform::Render::Viewport::Viewport(
        Scaleform::Render::Viewport *this,
        int bw,
        int bh,
        int left,
        int top,
        int w,
        int h,
        unsigned int flags)
{
  this->BufferWidth = bw;
  this->BufferHeight = bh;
  this->Left = left;
  this->Top = top;
  this->Width = w;
  this->Height = h;
  this->Flags = flags;
  this->ScissorHeight = 0;
  this->ScissorWidth = 0;
  this->ScissorTop = 0;
  this->ScissorLeft = 0;
}


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


void __thiscall Scaleform::Render::Viewport::Viewport(Scaleform::Render::Viewport *this)
{
  this->BufferWidth = 0;
  this->BufferHeight = 0;
  this->Top = 0;
  this->Left = 0;
  this->Height = 1;
  this->Width = 1;
  this->ScissorHeight = 0;
  this->ScissorWidth = 0;
  this->ScissorTop = 0;
  this->ScissorLeft = 0;
  this->Flags = 0;
}
