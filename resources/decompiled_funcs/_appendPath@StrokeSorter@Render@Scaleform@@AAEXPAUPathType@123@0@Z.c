void __thiscall Scaleform::Render::StrokeSorter::appendPath(
        Scaleform::Render::StrokeSorter *this,
        Scaleform::Render::StrokeSorter::PathType *dst,
        Scaleform::Render::StrokeSorter::PathType *src)
{
  Scaleform::Render::StrokeSorter *v3; // edi
  unsigned int v4; // ecx
  int v5; // ebp
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *p_OutVertices; // esi
  unsigned int v7; // ebx
  _DWORD *p_x; // edi
  _DWORD *v9; // eax
  unsigned int n; // [esp+10h] [ebp-4h]

  v3 = this;
  if ( !dst->numVer )
  {
    dst->start = this->OutVertices.Size;
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
      &this->OutVertices,
      &this->SrcVertices.Pages[src->start >> 4][src->start & 0xF]);
    ++dst->numVer;
  }
  v4 = src->numVer & 0xFFFFFFF;
  v5 = 1;
  n = v4;
  if ( v4 > 1 )
  {
    p_OutVertices = &v3->OutVertices;
    while ( 1 )
    {
      v7 = p_OutVertices->Size >> 4;
      p_x = (_DWORD *)&v3->SrcVertices.Pages[(v5 + src->start) >> 4][(v5 + src->start) & 0xF].x;
      if ( v7 >= p_OutVertices->NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::allocPage(
          p_OutVertices,
          p_OutVertices->Size >> 4);
        v4 = n;
      }
      v9 = (_DWORD *)&p_OutVertices->Pages[v7][p_OutVertices->Size & 0xF].x;
      *v9 = *p_x;
      v9[1] = p_x[1];
      v9[2] = p_x[2];
      v9[3] = p_x[3];
      ++p_OutVertices->Size;
      ++dst->numVer;
      if ( ++v5 >= v4 )
        break;
      v3 = this;
    }
  }
}
