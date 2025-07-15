void __thiscall Scaleform::GFx::FontCompactor::MoveTo(Scaleform::GFx::FontCompactor *this, __int16 x, __int16 y)
{
  unsigned int Size; // ebp
  unsigned int v5; // edi
  Scaleform::GFx::FontCompactor::ContourType *v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // edi
  Scaleform::GFx::FontCompactor::VertexType v; // [esp+14h] [ebp+4h]

  if ( this->TmpContours.Size )
    Scaleform::GFx::FontCompactor::normalizeLastContour(this);
  Size = this->TmpVertices.Size;
  v5 = this->TmpContours.Size >> 6;
  if ( v5 >= this->TmpContours.NumPages )
    Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::ContourType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::ContourType,261>>::allocatePage(
      (Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::KerningPairType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::KerningPairType,261> > *)&this->TmpContours,
      this->TmpContours.Size >> 6);
  v6 = this->TmpContours.Pages[v5];
  v7 = this->TmpContours.Size & 0x3F;
  v6[v7].DataStart = Size;
  v6[v7].DataSize = 1;
  ++this->TmpContours.Size;
  v8 = this->TmpVertices.Size >> 6;
  v.x = 2 * x;
  v.y = y;
  if ( v8 >= this->TmpVertices.NumPages )
    Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
      &this->TmpVertices,
      v8);
  this->TmpVertices.Pages[v8][this->TmpVertices.Size++ & 0x3F] = v;
}
