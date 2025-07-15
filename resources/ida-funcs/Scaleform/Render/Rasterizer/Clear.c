void __thiscall Scaleform::Render::Rasterizer::Clear(Scaleform::Render::Rasterizer *this)
{
  this->Cells.MaxPages = 0;
  this->Cells.NumPages = 0;
  this->Cells.Size = 0;
  this->Cells.Pages = 0;
  this->SortedCells.Size = 0;
  this->SortedCells.Array = 0;
  this->SortedYs.Size = 0;
  this->SortedYs.Array = 0;
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->LHeap);
  this->LastXf = 0.0;
  this->CurrCell.x = 0x7FFFFFFF;
  this->LastYf = 0.0;
  this->CurrCell.y = 0x7FFFFFFF;
  this->MinX = 0x7FFFFFFF;
  this->MinY = 0x7FFFFFFF;
  this->CurrCell.Cover = 0;
  this->CurrCell.Area = 0;
  this->StartX = 0;
  this->StartY = 0;
  this->LastX = 0;
  this->LastY = 0;
  this->MaxX = -2147483647;
  this->MaxY = -2147483647;
}
