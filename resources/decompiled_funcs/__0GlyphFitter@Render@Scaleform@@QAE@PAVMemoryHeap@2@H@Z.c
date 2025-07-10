void __thiscall Scaleform::Render::GlyphFitter::GlyphFitter(
        Scaleform::Render::GlyphFitter *this,
        Scaleform::MemoryHeap *heap,
        int nominalFontHeight)
{
  Scaleform::Render::LinearHeap *p_LHeap; // ecx

  this->NominalFontHeight = nominalFontHeight;
  this->__vftable = (Scaleform::Render::GlyphFitter_vtbl *)&Scaleform::Render::GlyphFitter::`vftable';
  this->LHeap.pHeap = heap;
  this->LHeap.Granularity = 0x2000;
  this->LHeap.pPagePool = 0;
  this->LHeap.pLastPage = 0;
  this->LHeap.MaxPages = 0;
  this->Contours.Size = 0;
  this->Contours.NumPages = 0;
  this->Contours.MaxPages = 0;
  this->Contours.Pages = 0;
  p_LHeap = &this->LHeap;
  this->Contours.pHeap = p_LHeap;
  this->Vertices.pHeap = p_LHeap;
  this->Vertices.Size = 0;
  this->Vertices.NumPages = 0;
  this->Vertices.MaxPages = 0;
  this->Vertices.Pages = 0;
  this->Events.pHeap = p_LHeap;
  this->Events.Size = 0;
  this->Events.Array = 0;
  this->LerpPairs.pHeap = p_LHeap;
  this->LerpPairs.Size = 0;
  this->LerpPairs.NumPages = 0;
  this->LerpPairs.MaxPages = 0;
  this->LerpPairs.Pages = 0;
  this->LerpRampX.pHeap = p_LHeap;
  this->LerpRampX.Size = 0;
  this->LerpRampX.Array = 0;
  this->LerpRampY.pHeap = p_LHeap;
  this->LerpRampY.Size = 0;
  this->LerpRampY.Array = 0;
  this->StartX = 0.0;
  this->StartY = 0.0;
  this->LastXf = 0.0;
  this->LastYf = 0.0;
}
