char __thiscall Scaleform::Render::Image::Update(Scaleform::Render::Image *this)
{
  if ( !this->pUpdateSync )
    return 0;
  this->pUpdateSync->UpdateImage(this->pUpdateSync, this);
  return 1;
}
