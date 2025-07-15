Scaleform::Render::Text::Allocator *__thiscall Scaleform::Render::Text::StyledText::GetAllocator(
        Scaleform::Render::Text::StyledText *this)
{
  Scaleform::MemoryHeap *v2; // esi
  Scaleform::Render::Text::Allocator *v3; // eax
  Scaleform::Render::Text::Allocator *v4; // eax
  Scaleform::Render::Text::Allocator *v5; // esi
  Scaleform::Render::Text::Allocator *pObject; // ecx

  if ( this->pTextAllocator.pObject )
    return this->pTextAllocator.pObject;
  v2 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v3 = (Scaleform::Render::Text::Allocator *)v2->Alloc(v2, 76u, 0);
  if ( v3 )
  {
    Scaleform::Render::Text::Allocator::Allocator(v3, v2, 0);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  pObject = this->pTextAllocator.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pTextAllocator.pObject = v5;
  return v5;
}
