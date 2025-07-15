void __thiscall Scaleform::GFx::FontCompactor::LineTo(Scaleform::GFx::FontCompactor *this, __int16 x, __int16 y)
{
  Scaleform::GFx::FontCompactor::VertexType v4; // eax
  unsigned int v5; // ebx
  Scaleform::GFx::FontCompactor::ContourType *v6; // edx
  Scaleform::GFx::FontCompactor::VertexType v; // [esp+14h] [ebp+8h]

  if ( !this->TmpContours.Pages[(this->TmpContours.Size - 1) >> 6][(this->TmpContours.Size - 1) & 0x3F].DataSize
    || (v4 = this->TmpVertices.Pages[(this->TmpVertices.Size - 1) >> 6][(this->TmpVertices.Size - 1) & 0x3F],
        x != v4.x >> 1)
    || y != v4.y )
  {
    v5 = this->TmpVertices.Size >> 6;
    v.y = y;
    if ( v5 >= this->TmpVertices.NumPages )
      Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
        &this->TmpVertices,
        v5);
    v.x = 2 * x;
    this->TmpVertices.Pages[v5][this->TmpVertices.Size++ & 0x3F] = v;
    v6 = this->TmpContours.Pages[(this->TmpContours.Size - 1) >> 6];
    ++v6[(this->TmpContours.Size - 1) & 0x3F].DataSize;
  }
}
