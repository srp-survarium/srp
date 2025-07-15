void __thiscall Scaleform::Render::StrokeSorter::Clear(Scaleform::Render::StrokeSorter *this)
{
  this->SrcVertices.MaxPages = 0;
  this->SrcVertices.NumPages = 0;
  this->SrcVertices.Size = 0;
  this->SrcVertices.Pages = 0;
  this->SrcPaths.MaxPages = 0;
  this->SrcPaths.NumPages = 0;
  this->SrcPaths.Size = 0;
  this->SrcPaths.Pages = 0;
  this->SortedPaths.Size = 0;
  this->SortedPaths.Array = 0;
  this->OutVertices.MaxPages = 0;
  this->OutVertices.NumPages = 0;
  this->OutVertices.Size = 0;
  this->OutVertices.Pages = 0;
  this->OutPaths.MaxPages = 0;
  this->OutPaths.NumPages = 0;
  this->OutPaths.Size = 0;
  this->OutPaths.Pages = 0;
  this->LastVertex = 0;
  Scaleform::Render::LinearHeap::ClearAndRelease(this->pHeap);
}
