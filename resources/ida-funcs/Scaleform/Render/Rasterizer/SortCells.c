char __thiscall Scaleform::Render::Rasterizer::SortCells(Scaleform::Render::Rasterizer *this)
{
  unsigned int Size; // eax
  unsigned int i; // eax
  int v5; // ecx
  unsigned int v6; // edx
  unsigned int j; // eax
  Scaleform::Render::Rasterizer::SortedY *Array; // ecx
  unsigned int Start; // edi
  unsigned int k; // edx
  Scaleform::Render::Rasterizer::Cell *v11; // eax
  Scaleform::Render::Rasterizer::SortedY *v12; // ecx
  unsigned int m; // edi
  Scaleform::Render::Rasterizer::SortedY *v14; // edx
  unsigned int Count; // ecx
  unsigned int v16; // eax
  Scaleform::Render::Rasterizer::Cell **v17; // edx
  Scaleform::Alg::ArrayAdaptor<Scaleform::Render::Rasterizer::Cell *> sortedCells; // [esp+8h] [ebp-8h] BYREF

  if ( *(_QWORD *)&this->CurrCell.Cover )
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
      (const Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
  this->CurrCell.x = 0x7FFFFFFF;
  this->CurrCell.y = 0x7FFFFFFF;
  Size = this->Cells.Size;
  this->CurrCell.Cover = 0;
  this->CurrCell.Area = 0;
  if ( !Size )
    return 0;
  if ( !this->SortedYs.Size )
  {
    Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::Cell *>::Resize(
      (Scaleform::Render::ArrayUnsafe<int> *)&this->SortedCells,
      Size);
    Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::SortedY>::Resize(
      &this->SortedYs,
      this->MaxY - this->MinY + 1);
    memset((int)this->SortedYs.Array, 0, 8 * this->SortedYs.Size);
    for ( i = 0; i < this->Cells.Size; ++i )
    {
      v5 = this->Cells.Pages[i >> 4][i & 0xF].y - this->MinY;
      ++this->SortedYs.Array[v5].Start;
    }
    v6 = 0;
    for ( j = 0; j < this->SortedYs.Size; v6 += Start )
    {
      Array = this->SortedYs.Array;
      Start = Array[j].Start;
      Array[j++].Start = v6;
    }
    for ( k = 0; k < this->Cells.Size; ++v12->Count )
    {
      v11 = &this->Cells.Pages[k >> 4][k & 0xF];
      ++k;
      v12 = &this->SortedYs.Array[v11->y - this->MinY];
      *((_DWORD *)&this->SortedCells.Array[v12->Count] + v12->Start) = v11;
    }
    for ( m = 0; m < this->SortedYs.Size; ++m )
    {
      v14 = this->SortedYs.Array;
      Count = v14[m].Count;
      if ( Count )
      {
        v16 = v14[m].Start;
        v17 = this->SortedCells.Array;
        sortedCells.Size = Count;
        sortedCells.Data = &v17[v16];
        Scaleform::Alg::QuickSortSliced<Scaleform::Alg::ArrayAdaptor<Scaleform::Render::Rasterizer::Cell *>,bool (__cdecl *)(Scaleform::Render::Rasterizer::Cell const *,Scaleform::Render::Rasterizer::Cell const *)>(
          &sortedCells,
          0,
          Count,
          (bool (__cdecl *)(const Scaleform::Render::Rasterizer::Cell *, const Scaleform::Render::Rasterizer::Cell *))Scaleform::Render::Rasterizer::cellXLess);
      }
    }
  }
  return 1;
}
