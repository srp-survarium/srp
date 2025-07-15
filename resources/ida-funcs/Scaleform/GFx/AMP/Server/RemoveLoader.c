void __thiscall Scaleform::GFx::AMP::Server::RemoveLoader(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::GFx::Loader *loader)
{
  Scaleform::Render::Renderer2D **p_CurrentRenderer; // ebp
  unsigned int Capacity; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::Loader **Size; // edx

  p_CurrentRenderer = &this->CurrentRenderer;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->CurrentRenderer);
  Capacity = this->TaskStats.Data.Policy.Capacity;
  v5 = 0;
  if ( !Capacity )
    goto LABEL_13;
  Size = (Scaleform::GFx::Loader **)this->TaskStats.Data.Size;
  while ( *Size != loader )
  {
    ++v5;
    ++Size;
    if ( v5 >= Capacity )
      goto LABEL_13;
  }
  if ( Capacity != 1 )
  {
    memmove(
      this->TaskStats.Data.Size + 4 * v5,
      (const __m128i *)(this->TaskStats.Data.Size + 4 * v5 + 4),
      4 * (Capacity - v5) - 4);
    --this->TaskStats.Data.Policy.Capacity;
LABEL_13:
    LeaveCriticalSection((LPCRITICAL_SECTION)p_CurrentRenderer);
    return;
  }
  if ( ((int)this->Loaders.Data.Data & 0xFFFFFFFE) != 0 )
  {
    if ( this->TaskStats.Data.Size )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->TaskStats.Data.Size);
      this->TaskStats.Data.Size = 0;
    }
    this->Loaders.Data.Data = 0;
  }
  this->TaskStats.Data.Policy.Capacity = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)p_CurrentRenderer);
}
