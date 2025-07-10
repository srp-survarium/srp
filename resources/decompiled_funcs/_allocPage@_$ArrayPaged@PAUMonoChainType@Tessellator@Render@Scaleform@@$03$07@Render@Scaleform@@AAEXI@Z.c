void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  Scaleform::Render::LinearHeap *pHeap; // ecx
  unsigned __int8 *v5; // edi
  unsigned int v6; // eax

  MaxPages = this->MaxPages;
  if ( nb >= MaxPages )
  {
    pHeap = this->pHeap;
    if ( this->Pages )
    {
      v5 = Scaleform::Render::LinearHeap::Alloc(pHeap, 8 * MaxPages);
      memcpy(v5, (unsigned __int8 *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::Tessellator::MonoVertexType ***)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 8;
      this->Pages = (Scaleform::Render::Tessellator::MonoVertexType ***)Scaleform::Render::LinearHeap::Alloc(
                                                                          pHeap,
                                                                          0x20u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::Tessellator::MonoVertexType **)Scaleform::Render::LinearHeap::Alloc(
                                                                         this->pHeap,
                                                                         0x40u);
  ++this->NumPages;
}
