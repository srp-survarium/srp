void __thiscall Scaleform::Render::GlyphFitter::Clear(Scaleform::Render::GlyphFitter *this)
{
  this->Contours.MaxPages = 0;
  this->Contours.NumPages = 0;
  this->Contours.Size = 0;
  this->Contours.Pages = 0;
  this->Vertices.MaxPages = 0;
  this->Vertices.NumPages = 0;
  this->Vertices.Size = 0;
  this->Vertices.Pages = 0;
  this->Events.Size = 0;
  this->Events.Array = 0;
  this->LerpPairs.MaxPages = 0;
  this->LerpPairs.NumPages = 0;
  this->LerpPairs.Size = 0;
  this->LerpPairs.Pages = 0;
  this->LerpRampX.Size = 0;
  this->LerpRampX.Array = 0;
  this->LerpRampY.Size = 0;
  this->LerpRampY.Array = 0;
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->LHeap);
}
