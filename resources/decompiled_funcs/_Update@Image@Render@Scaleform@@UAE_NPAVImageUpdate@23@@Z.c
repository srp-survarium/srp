char __thiscall Scaleform::Render::Image::Update(
        Scaleform::Render::Image *this,
        Scaleform::Render::ImageUpdate *pupdate)
{
  if ( !this->pUpdateSync )
    return 0;
  this->pUpdateSync->UpdateImage(this->pUpdateSync, pupdate);
  return 1;
}
