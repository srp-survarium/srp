void __thiscall Scaleform::Render::StrokeSorter::StrokeSorter(
        Scaleform::Render::StrokeSorter *this,
        Scaleform::Render::LinearHeap *heap)
{
  this->__vftable = (Scaleform::Render::StrokeSorter_vtbl *)&Scaleform::Render::StrokeSorter::`vftable';
  this->pHeap = heap;
  this->SrcVertices.pHeap = heap;
  this->SrcVertices.Size = 0;
  this->SrcVertices.NumPages = 0;
  this->SrcVertices.MaxPages = 0;
  this->SrcVertices.Pages = 0;
  this->SrcPaths.pHeap = heap;
  this->SrcPaths.Size = 0;
  this->SrcPaths.NumPages = 0;
  this->SrcPaths.MaxPages = 0;
  this->SrcPaths.Pages = 0;
  this->SortedPaths.pHeap = heap;
  this->SortedPaths.Size = 0;
  this->SortedPaths.Array = 0;
  this->OutVertices.pHeap = heap;
  this->OutVertices.Size = 0;
  this->OutVertices.NumPages = 0;
  this->OutVertices.MaxPages = 0;
  this->OutVertices.Pages = 0;
  this->OutPaths.pHeap = heap;
  this->OutPaths.Size = 0;
  this->OutPaths.NumPages = 0;
  this->OutPaths.MaxPages = 0;
  this->OutPaths.Pages = 0;
  this->LastVertex = 0;
}
