void __thiscall Scaleform::Render::Rasterizer::Rasterizer(
        Scaleform::Render::Rasterizer *this,
        Scaleform::MemoryHeap *heap)
{
  this->__vftable = (Scaleform::Render::Rasterizer_vtbl *)&Scaleform::Render::Rasterizer::`vftable';
  this->LHeap.pHeap = heap;
  this->LHeap.Granularity = 0x2000;
  this->LHeap.pPagePool = 0;
  this->LHeap.pLastPage = 0;
  this->LHeap.MaxPages = 0;
  this->FillRule = FillNonZero;
  this->Cells.pHeap = &this->LHeap;
  this->Cells.Size = 0;
  this->Cells.NumPages = 0;
  this->Cells.MaxPages = 0;
  this->Cells.Pages = 0;
  this->SortedCells.pHeap = &this->LHeap;
  this->SortedCells.Size = 0;
  this->SortedCells.Array = 0;
  this->SortedYs.pHeap = &this->LHeap;
  this->SortedYs.Size = 0;
  this->SortedYs.Array = 0;
  this->LastXf = 0.0;
  this->LastYf = 0.0;
  this->StartX = 0;
  this->StartY = 0;
  this->LastX = 0;
  this->LastY = 0;
  this->CurrCell.Cover = 0;
  this->CurrCell.Area = 0;
  this->MinX = 0x7FFFFFFF;
  this->MinY = 0x7FFFFFFF;
  this->MaxX = -2147483647;
  this->MaxY = -2147483647;
  this->CurrCell.x = 0x7FFFFFFF;
  this->CurrCell.y = 0x7FFFFFFF;
  Scaleform::Render::Rasterizer::setGamma(this, 0, 1.0);
  this->Gamma1 = 1.0;
  Scaleform::Render::Rasterizer::setGamma(this, 1, 1.0);
  this->Gamma2 = 1.0;
}
