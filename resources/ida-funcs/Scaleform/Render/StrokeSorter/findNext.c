unsigned int __thiscall Scaleform::Render::StrokeSorter::findNext(
        Scaleform::Render::StrokeSorter *this,
        const Scaleform::Render::StrokeSorter::PathType *outPath)
{
  Scaleform::Render::StrokeSorter::VertexType **Pages; // edx
  unsigned int v4; // ecx
  float *p_x; // eax
  unsigned int Size; // ecx
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ecx
  Scaleform::Render::StrokeSorter::SortedPathType *i; // esi
  Scaleform::Render::StrokeSorter::SortedPathType val; // [esp+4h] [ebp-Ch] BYREF

  Pages = this->OutVertices.Pages;
  v4 = (outPath->numVer & 0xFFFFFFF) + outPath->start - 1;
  p_x = &Pages[v4 >> 4][v4 & 0xF].x;
  Size = this->SortedPaths.Size;
  val.x = *p_x;
  val.y = p_x[1];
  val.thisPath = 0;
  v7 = Scaleform::Alg::LowerBoundSliced<Scaleform::Render::ArrayUnsafe<Scaleform::Render::StrokeSorter::SortedPathType>,Scaleform::Render::StrokeSorter::SortedPathType,bool (__cdecl *)(Scaleform::Render::StrokeSorter::SortedPathType const &,Scaleform::Render::StrokeSorter::SortedPathType const &)>(
         &this->SortedPaths,
         0,
         Size,
         &val,
         (bool (__cdecl *)(const Scaleform::Render::StrokeSorter::SortedPathType *, const Scaleform::Render::StrokeSorter::SortedPathType *))Scaleform::Render::StrokeSorter::cmpPaths);
  v8 = this->SortedPaths.Size;
  v9 = v7;
  if ( v7 < v8 )
  {
    for ( i = &this->SortedPaths.Array[v7]; val.x == i->x && val.y == i->y; ++i )
    {
      if ( (i->thisPath->numVer & 0x40000000) == 0 )
        return v9;
      if ( ++v9 >= v8 )
        return -1;
    }
  }
  return -1;
}
