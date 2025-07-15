Scaleform::GFx::MovieImpl *__thiscall Scaleform::GFx::AS2Support::CreateMovie(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::AS2::MemoryContextImpl *memContext)
{
  Scaleform::MemoryHeap *Heap; // esi
  Scaleform::GFx::MovieImpl *v4; // eax
  Scaleform::GFx::MovieImpl *v5; // eax
  Scaleform::GFx::MovieImpl *v6; // edi
  Scaleform::GFx::AS2::MovieRoot *v7; // eax
  Scaleform::RefCountVImpl *v8; // eax

  Heap = memContext->Heap;
  v4 = (Scaleform::GFx::MovieImpl *)Heap->Alloc(Heap, 16496u, 0);
  if ( v4 )
  {
    Scaleform::GFx::MovieImpl::MovieImpl(v4, Heap);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = (Scaleform::GFx::AS2::MovieRoot *)Heap->Alloc(Heap, 808u, 0);
  if ( v7 )
    Scaleform::GFx::AS2::MovieRoot::MovieRoot(v7, memContext, v6, this);
  else
    v8 = 0;
  v6->Flags2 |= 1u;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  return v6;
}
