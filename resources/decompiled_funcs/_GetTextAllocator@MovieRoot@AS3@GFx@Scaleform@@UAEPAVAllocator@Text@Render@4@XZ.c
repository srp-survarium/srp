Scaleform::Render::Text::Allocator *__thiscall Scaleform::GFx::AS3::MovieRoot::GetTextAllocator(
        Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::MemoryContextImpl *pObject; // eax
  Scaleform::Render::Text::Allocator *v3; // eax
  Scaleform::Render::Text::Allocator *v4; // eax
  Scaleform::Render::Text::Allocator *v5; // ebx
  Scaleform::GFx::AS3::MemoryContextImpl *v6; // esi
  Scaleform::RefCountNTSImpl *v7; // ecx
  Scaleform::Ptr<Scaleform::Render::Text::Allocator> *p_TextAllocator; // esi

  pObject = this->MemContext.pObject;
  if ( pObject->TextAllocator.pObject )
    return pObject->TextAllocator.pObject;
  v3 = (Scaleform::Render::Text::Allocator *)pObject->Heap->Alloc(pObject->Heap, 76u, 0);
  if ( v3 )
  {
    Scaleform::Render::Text::Allocator::Allocator(v3, this->MemContext.pObject->Heap, 0);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v6 = this->MemContext.pObject;
  v7 = v6->TextAllocator.pObject;
  p_TextAllocator = &v6->TextAllocator;
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  p_TextAllocator->pObject = v5;
  return this->MemContext.pObject->TextAllocator.pObject;
}
