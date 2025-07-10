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
