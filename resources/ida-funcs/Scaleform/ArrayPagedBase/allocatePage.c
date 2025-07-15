void __thiscall Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  unsigned __int8 **Pages; // edx
  unsigned __int8 **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (unsigned __int8 **)Scaleform::Memory::pGlobalHeap->Realloc(
                                 Scaleform::Memory::pGlobalHeap,
                                 Pages,
                                 4 * MaxPages + 1024);
    }
    else
    {
      nb = 261;
      v6 = (unsigned __int8 **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                 Scaleform::Memory::pGlobalHeap,
                                 this,
                                 1024,
                                 &nb);
    }
    this->MaxPages += 256;
    this->Pages = v6;
  }
  nb = 261;
  this->Pages[v4] = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         4096,
                                         &nb);
  ++this->NumPages;
}


void __thiscall Scaleform::ArrayPagedBase<unsigned int,6,64,Scaleform::AllocatorPagedLH_POD<unsigned int,2>>::allocatePage(
        Scaleform::ArrayPagedBase<unsigned int,6,64,Scaleform::AllocatorPagedLH_POD<unsigned int,2> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  unsigned int **Pages; // edx
  unsigned int **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (unsigned int **)Scaleform::Memory::pGlobalHeap->Realloc(
                              Scaleform::Memory::pGlobalHeap,
                              Pages,
                              4 * MaxPages + 256);
    }
    else
    {
      nb = 2;
      v6 = (unsigned int **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                              Scaleform::Memory::pGlobalHeap,
                              this,
                              256,
                              &nb);
    }
    this->MaxPages += 64;
    this->Pages = v6;
  }
  nb = 2;
  this->Pages[v4] = (unsigned int *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                      Scaleform::Memory::pGlobalHeap,
                                      this,
                                      256,
                                      &nb);
  ++this->NumPages;
}


void __thiscall Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::allocatePage(
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***Pages; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> ***)Scaleform::Memory::pGlobalHeap->Realloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           Pages,
                                                           4 * MaxPages + 20);
    }
    else
    {
      nb = 2;
      v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> ***)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           this,
                                                           20,
                                                           &nb);
    }
    this->MaxPages += 5;
    this->Pages = v6;
  }
  nb = 2;
  this->Pages[v4] = (Scaleform::GFx::AS2::RefCountBaseGC<323> **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   this,
                                                                   4096,
                                                                   &nb);
  ++this->NumPages;
}


void __thiscall Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::ContourType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::ContourType,261>>::allocatePage(
        Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::KerningPairType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::KerningPairType,261> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  Scaleform::GFx::FontCompactor::KerningPairType **Pages; // edx
  Scaleform::GFx::FontCompactor::KerningPairType **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::GFx::FontCompactor::KerningPairType **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                Pages,
                                                                4 * MaxPages + 256);
    }
    else
    {
      nb = 261;
      v6 = (Scaleform::GFx::FontCompactor::KerningPairType **)Scaleform::Memory::pGlobalHeap->Alloc(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                256,
                                                                &nb);
    }
    this->MaxPages += 64;
    this->Pages = v6;
  }
  nb = 261;
  this->Pages[v4] = (Scaleform::GFx::FontCompactor::KerningPairType *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                                        Scaleform::Memory::pGlobalHeap,
                                                                        512,
                                                                        &nb);
  ++this->NumPages;
}


void __thiscall Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::NodeType,8,64,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::NodeType,2>>::allocatePage(
        Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::NodeType,8,64,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::NodeType,2> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  Scaleform::Render::RectPacker::NodeType **Pages; // edx
  Scaleform::Render::RectPacker::NodeType **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::Render::RectPacker::NodeType **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         Pages,
                                                         4 * MaxPages + 256);
    }
    else
    {
      nb = 2;
      v6 = (Scaleform::Render::RectPacker::NodeType **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         this,
                                                         256,
                                                         &nb);
    }
    this->MaxPages += 64;
    this->Pages = v6;
  }
  nb = 2;
  this->Pages[v4] = (Scaleform::Render::RectPacker::NodeType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                 Scaleform::Memory::pGlobalHeap,
                                                                 this,
                                                                 7168,
                                                                 &nb);
  ++this->NumPages;
}


void __thiscall Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::PackType,4,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::PackType,2>>::allocatePage(
        Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::PackType,4,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::PackType,2> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  Scaleform::Render::RectPacker::PackType **Pages; // edx
  Scaleform::Render::RectPacker::PackType **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::Render::RectPacker::PackType **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         Pages,
                                                         4 * MaxPages + 64);
    }
    else
    {
      nb = 2;
      v6 = (Scaleform::Render::RectPacker::PackType **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         this,
                                                         64,
                                                         &nb);
    }
    this->MaxPages += 16;
    this->Pages = v6;
  }
  nb = 2;
  this->Pages[v4] = (Scaleform::Render::RectPacker::PackType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                 Scaleform::Memory::pGlobalHeap,
                                                                 this,
                                                                 128,
                                                                 &nb);
  ++this->NumPages;
}


void __thiscall Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::RectType,8,64,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::RectType,2>>::allocatePage(
        Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::RectType,8,64,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::RectType,2> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  Scaleform::Render::RectPacker::RectType **Pages; // edx
  Scaleform::Render::RectPacker::RectType **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::Render::RectPacker::RectType **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         Pages,
                                                         4 * MaxPages + 256);
    }
    else
    {
      nb = 2;
      v6 = (Scaleform::Render::RectPacker::RectType **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         this,
                                                         256,
                                                         &nb);
    }
    this->MaxPages += 64;
    this->Pages = v6;
  }
  nb = 2;
  this->Pages[v4] = (Scaleform::Render::RectPacker::RectType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                 Scaleform::Memory::pGlobalHeap,
                                                                 this,
                                                                 3072,
                                                                 &nb);
  ++this->NumPages;
}


void __thiscall Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::allocatePage(
        Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  Scaleform::Render::GlyphCache::UpdateRect **Pages; // edx
  Scaleform::Render::GlyphCache::UpdateRect **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::Render::GlyphCache::UpdateRect **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           Pages,
                                                           4 * MaxPages + 64);
    }
    else
    {
      nb = 2;
      v6 = (Scaleform::Render::GlyphCache::UpdateRect **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           this,
                                                           64,
                                                           &nb);
    }
    this->MaxPages += 16;
    this->Pages = v6;
  }
  nb = 2;
  this->Pages[v4] = (Scaleform::Render::GlyphCache::UpdateRect *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   this,
                                                                   1792,
                                                                   &nb);
  ++this->NumPages;
}


void __thiscall Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
        Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  Scaleform::GFx::FontCompactor::VertexType **Pages; // edx
  Scaleform::GFx::FontCompactor::VertexType **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::GFx::FontCompactor::VertexType **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           Pages,
                                                           4 * MaxPages + 256);
    }
    else
    {
      nb = 261;
      v6 = (Scaleform::GFx::FontCompactor::VertexType **)Scaleform::Memory::pGlobalHeap->Alloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           256,
                                                           &nb);
    }
    this->MaxPages += 64;
    this->Pages = v6;
  }
  nb = 261;
  this->Pages[v4] = (Scaleform::GFx::FontCompactor::VertexType *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   256,
                                                                   &nb);
  ++this->NumPages;
}


void __thiscall Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  Scaleform::GFx::AS3::CallFrame **Pages; // edx
  Scaleform::GFx::AS3::CallFrame **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::GFx::AS3::CallFrame **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                Pages,
                                                4 * MaxPages + 256);
    }
    else
    {
      nb = 329;
      v6 = (Scaleform::GFx::AS3::CallFrame **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                256,
                                                &nb);
    }
    this->MaxPages += 64;
    this->Pages = v6;
  }
  nb = 329;
  this->Pages[v4] = (Scaleform::GFx::AS3::CallFrame *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        this,
                                                        4608,
                                                        &nb);
  ++this->NumPages;
}
