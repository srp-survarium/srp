void __thiscall Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *this,
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *a,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned __int8 *v5; // ebx
  unsigned int v6; // eax

  MaxPages = a->MaxPages;
  if ( nb >= MaxPages )
  {
    if ( a->Pages )
    {
      v5 = Scaleform::Render::LinearHeap::Alloc(this->pHeap, 8 * MaxPages);
      memcpy(v5, (unsigned __int8 *)a->Pages, 4 * a->NumPages);
      v6 = a->MaxPages;
      a->Pages = (Scaleform::Render::Tessellator::TriangleType **)v5;
      a->MaxPages = 2 * v6;
    }
    else
    {
      a->MaxPages = 16;
      a->Pages = (Scaleform::Render::Tessellator::TriangleType **)Scaleform::Render::LinearHeap::Alloc(
                                                                    this->pHeap,
                                                                    0x40u);
    }
  }
  a->Pages[nb] = (Scaleform::Render::Tessellator::TriangleType *)Scaleform::Render::LinearHeap::Alloc(
                                                                   this->pHeap,
                                                                   0xC0u);
  ++a->NumPages;
}
