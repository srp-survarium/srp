void __thiscall Scaleform::GFx::FontCompactor::QuadTo(
        Scaleform::GFx::FontCompactor *this,
        __int16 cx,
        __int16 cy,
        __int16 ax,
        __int16 ay)
{
  int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // ebx
  Scaleform::GFx::FontCompactor::ContourType *v9; // ecx
  Scaleform::GFx::FontCompactor::VertexType v; // [esp+10h] [ebp-4h]
  Scaleform::GFx::FontCompactor::VertexType va; // [esp+10h] [ebp-4h]
  Scaleform::GFx::FontCompactor::VertexType vb; // [esp+10h] [ebp-4h]

  if ( !this->TmpContours.Pages[(this->TmpContours.Size - 1) >> 6][(this->TmpContours.Size - 1) & 0x3F].DataSize )
    goto LABEL_6;
  v = this->TmpVertices.Pages[(this->TmpVertices.Size - 1) >> 6][(this->TmpVertices.Size - 1) & 0x3F];
  v6 = (ay - v.y) * (cx - ax) - (ax - (v.x >> 1)) * (cy - ay);
  if ( v6 < 0 )
    v6 = (ax - (v.x >> 1)) * (cy - ay) - (ay - v.y) * (cx - ax);
  if ( v6 <= 5 )
  {
    Scaleform::GFx::FontCompactor::LineTo(this, ax, ay);
  }
  else
  {
LABEL_6:
    v7 = this->TmpVertices.Size >> 6;
    va.y = cy;
    if ( v7 >= this->TmpVertices.NumPages )
      Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
        &this->TmpVertices,
        v7);
    va.x = (2 * cx) | 1;
    this->TmpVertices.Pages[v7][this->TmpVertices.Size++ & 0x3F] = va;
    v8 = this->TmpVertices.Size >> 6;
    vb.x = (2 * ax) | 1;
    vb.y = ay;
    if ( v8 >= this->TmpVertices.NumPages )
      Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
        &this->TmpVertices,
        v8);
    this->TmpVertices.Pages[v8][this->TmpVertices.Size++ & 0x3F] = vb;
    v9 = this->TmpContours.Pages[(this->TmpContours.Size - 1) >> 6];
    v9[(this->TmpContours.Size - 1) & 0x3F].DataSize += 2;
  }
}
