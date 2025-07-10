Scaleform::GFx::MovieImpl *__thiscall Scaleform::GFx::AS3Support::CreateMovie(
        Scaleform::GFx::AS3Support *this,
        Scaleform::GFx::AS3::MemoryContextImpl *memContext)
{
  Scaleform::MemoryHeap *Heap; // esi
  Scaleform::GFx::MovieImpl *v4; // eax
  Scaleform::GFx::MovieImpl *v5; // eax
  Scaleform::GFx::MovieImpl *v6; // edi
  Scaleform::GFx::AS3::MovieRoot *v7; // eax
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
  v7 = (Scaleform::GFx::AS3::MovieRoot *)Heap->Alloc(Heap, 1720u, 0);
  if ( v7 )
  {
    Scaleform::GFx::AS3::MovieRoot::MovieRoot(v7, memContext, v6, this);
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
  }
  return v6;
}
