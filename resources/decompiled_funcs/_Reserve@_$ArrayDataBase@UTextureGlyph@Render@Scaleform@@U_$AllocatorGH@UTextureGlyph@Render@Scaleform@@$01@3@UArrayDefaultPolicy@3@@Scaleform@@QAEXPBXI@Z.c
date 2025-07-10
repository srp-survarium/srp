void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::TextureGlyph *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::TextureGlyph *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                this->Data,
                                                192 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::Render::TextureGlyph *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                48 * v4,
                                                &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
  }
  else
  {
    if ( this->Data )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->Data);
      this->Data = 0;
    }
    this->Policy.Capacity = 0;
  }
}
