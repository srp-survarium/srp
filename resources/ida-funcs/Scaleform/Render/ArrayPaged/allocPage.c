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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
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


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::Tessellator::MonoVertexType ***)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 2;
      this->Pages = (Scaleform::Render::Tessellator::MonoVertexType ***)Scaleform::Render::LinearHeap::Alloc(pHeap, 8u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::Tessellator::MonoVertexType **)Scaleform::Render::LinearHeap::Alloc(
                                                                         this->pHeap,
                                                                         0x40u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::BaseLineType,4,4>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::TessMesh **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 4;
      this->Pages = (Scaleform::Render::TessMesh **)Scaleform::Render::LinearHeap::Alloc(pHeap, 0x10u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::TessMesh *)Scaleform::Render::LinearHeap::Alloc(this->pHeap, 0x1C0u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::Tessellator::MonoVertexType **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 16;
      this->Pages = (Scaleform::Render::Tessellator::MonoVertexType **)Scaleform::Render::LinearHeap::Alloc(
                                                                         pHeap,
                                                                         0x40u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::Tessellator::MonoVertexType *)Scaleform::Render::LinearHeap::Alloc(
                                                                        this->pHeap,
                                                                        0xC0u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::HorizontalEdgeType,2,4>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::HorizontalEdgeType,2,4> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::Hairliner::HorizontalEdgeType **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 4;
      this->Pages = (Scaleform::Render::Hairliner::HorizontalEdgeType **)Scaleform::Render::LinearHeap::Alloc(
                                                                           pHeap,
                                                                           0x10u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::Hairliner::HorizontalEdgeType *)Scaleform::Render::LinearHeap::Alloc(
                                                                          this->pHeap,
                                                                          0x50u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::IntersectionType,4,4>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::IntersectionType,4,4> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::Tessellator::IntersectionType **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 4;
      this->Pages = (Scaleform::Render::Tessellator::IntersectionType **)Scaleform::Render::LinearHeap::Alloc(
                                                                           pHeap,
                                                                           0x10u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::Tessellator::IntersectionType *)Scaleform::Render::LinearHeap::Alloc(
                                                                          this->pHeap,
                                                                          0xC0u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType,4,8>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType,4,8> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::Hairliner::MonoChainType **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 8;
      this->Pages = (Scaleform::Render::Hairliner::MonoChainType **)Scaleform::Render::LinearHeap::Alloc(pHeap, 0x20u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::Hairliner::MonoChainType *)Scaleform::Render::LinearHeap::Alloc(
                                                                     this->pHeap,
                                                                     0x180u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType,4,16>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType,4,16> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::Tessellator::MonoChainType **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 16;
      this->Pages = (Scaleform::Render::Tessellator::MonoChainType **)Scaleform::Render::LinearHeap::Alloc(pHeap, 0x40u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::Tessellator::MonoChainType *)Scaleform::Render::LinearHeap::Alloc(
                                                                       this->pHeap,
                                                                       0x2C0u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::Tessellator::MonotoneType **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 16;
      this->Pages = (Scaleform::Render::Tessellator::MonotoneType **)Scaleform::Render::LinearHeap::Alloc(pHeap, 0x40u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::Tessellator::MonotoneType *)Scaleform::Render::LinearHeap::Alloc(
                                                                      this->pHeap,
                                                                      0x180u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::PathBasic **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 4;
      this->Pages = (Scaleform::Render::PathBasic **)Scaleform::Render::LinearHeap::Alloc(pHeap, 0x10u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::PathBasic *)Scaleform::Render::LinearHeap::Alloc(this->pHeap, 0x20u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PathType,4,4>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshLayer,4,4> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::TmpTextMeshLayer **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 4;
      this->Pages = (Scaleform::Render::TmpTextMeshLayer **)Scaleform::Render::LinearHeap::Alloc(pHeap, 0x10u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::TmpTextMeshLayer *)Scaleform::Render::LinearHeap::Alloc(this->pHeap, 0x100u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::ScanChainType,4,8>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::ScanChainType,4,8> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::Tessellator::ScanChainType **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 8;
      this->Pages = (Scaleform::Render::Tessellator::ScanChainType **)Scaleform::Render::LinearHeap::Alloc(pHeap, 0x20u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::Tessellator::ScanChainType *)Scaleform::Render::LinearHeap::Alloc(
                                                                       this->pHeap,
                                                                       0xC0u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::TessVertex **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 16;
      this->Pages = (Scaleform::Render::TessVertex **)Scaleform::Render::LinearHeap::Alloc(pHeap, 0x40u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::TessVertex *)Scaleform::Render::LinearHeap::Alloc(this->pHeap, 0x140u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::TmpEdgeAAType,3,4>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::TmpEdgeAAType,3,4> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::Tessellator::TmpEdgeAAType **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 4;
      this->Pages = (Scaleform::Render::Tessellator::TmpEdgeAAType **)Scaleform::Render::LinearHeap::Alloc(pHeap, 0x10u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::Tessellator::TmpEdgeAAType *)Scaleform::Render::LinearHeap::Alloc(
                                                                       this->pHeap,
                                                                       0x80u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::TmpTextMeshEntry **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 4;
      this->Pages = (Scaleform::Render::TmpTextMeshEntry **)Scaleform::Render::LinearHeap::Alloc(pHeap, 0x10u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::TmpTextMeshEntry *)Scaleform::Render::LinearHeap::Alloc(this->pHeap, 0x900u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::VertexBasic **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 16;
      this->Pages = (Scaleform::Render::VertexBasic **)Scaleform::Render::LinearHeap::Alloc(pHeap, 0x40u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::VertexBasic *)Scaleform::Render::LinearHeap::Alloc(this->pHeap, 0x80u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(
        Scaleform::Render::ArrayPaged<unsigned int,4,16> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (unsigned int **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 16;
      this->Pages = (unsigned int **)Scaleform::Render::LinearHeap::Alloc(pHeap, 0x40u);
    }
  }
  this->Pages[nb] = (unsigned int *)Scaleform::Render::LinearHeap::Alloc(this->pHeap, 0x40u);
  ++this->NumPages;
}


void __thiscall Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *this,
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
      memcpy((int)v5, (const __m128i *)this->Pages, 4 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::StrokeSorter::VertexType **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 16;
      this->Pages = (Scaleform::Render::StrokeSorter::VertexType **)Scaleform::Render::LinearHeap::Alloc(pHeap, 0x40u);
    }
  }
  this->Pages[nb] = (Scaleform::Render::StrokeSorter::VertexType *)Scaleform::Render::LinearHeap::Alloc(
                                                                     this->pHeap,
                                                                     0x100u);
  ++this->NumPages;
}
