char __thiscall Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::Split(
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *this,
        unsigned int i,
        unsigned int at)
{
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *Arrays; // eax
  unsigned int v5; // ebp
  unsigned int Size; // edx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // [esp+Ch] [ebp-8h]
  Scaleform::Render::Tessellator::TriangleType **newPages; // [esp+10h] [ebp-4h]
  unsigned int newNumPages; // [esp+18h] [ebp+4h]
  unsigned int newMaxPages; // [esp+1Ch] [ebp+8h]

  Arrays = this->Arrays;
  v5 = i;
  if ( at >= Arrays[i].Size )
    return 0;
  Size = Arrays[i].Size;
  v8 = &Arrays[v5];
  v9 = at;
  v10 = at >> 4;
  newNumPages = v8->NumPages - (at >> 4);
  newMaxPages = v8->MaxPages - (at >> 4);
  newPages = &v8->Pages[v10];
  v9 &= 0xFFFFFFF0;
  v12 = Size;
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(this);
  this->Arrays[v5].NumPages = v10;
  this->Arrays[v5].MaxPages = v10;
  this->Arrays[v5].Size = v9;
  v11 = this->NumArrays - 1;
  this->Arrays[v11].NumPages = newNumPages;
  this->Arrays[v11].MaxPages = newMaxPages;
  this->Arrays[v11].Size = v12 - v9;
  this->Arrays[v11].Pages = newPages;
  return 1;
}
