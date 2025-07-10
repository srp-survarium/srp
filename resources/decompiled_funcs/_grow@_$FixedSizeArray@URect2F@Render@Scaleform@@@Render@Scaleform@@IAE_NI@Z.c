char __thiscall Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F>::grow(
        Scaleform::Render::FixedSizeArray<Scaleform::Render::Rect2F> *this,
        unsigned int reserve)
{
  unsigned __int8 *v3; // eax
  Scaleform::Render::Rect2F *v4; // ebx

  v3 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Alloc(
                            Scaleform::Memory::pGlobalHeap,
                            32 * ((reserve + 31) & 0xFFFFFFE0),
                            16,
                            0);
  v4 = (Scaleform::Render::Rect2F *)v3;
  if ( !v3 )
    return 0;
  memcpy(v3, (unsigned __int8 *)this->pData, 32 * this->Size);
  if ( this->pData != (Scaleform::Render::Rect2F *)((unsigned int)&this->DataReserve[15] & 0xFFFFFFF0) )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pData);
  this->pData = v4;
  this->Reserve = (reserve + 31) & 0xFFFFFFE0;
  return 1;
}
