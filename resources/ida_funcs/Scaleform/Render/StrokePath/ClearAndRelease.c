void __thiscall Scaleform::Render::StrokePath::ClearAndRelease(Scaleform::Render::StrokePath *this)
{
  this->Path.MaxPages = 0;
  this->Path.NumPages = 0;
  this->Path.Size = 0;
  this->Path.Pages = 0;
}
