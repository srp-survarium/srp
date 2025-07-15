void __thiscall Scaleform::Render::Stroker::Clear(Scaleform::Render::Stroker *this)
{
  this->Path.Path.MaxPages = 0;
  this->Path.Path.NumPages = 0;
  this->Path.Path.Size = 0;
  this->Path.Path.Pages = 0;
  this->Closed = 0;
  Scaleform::Render::LinearHeap::ClearAndRelease(this->pHeap);
}
