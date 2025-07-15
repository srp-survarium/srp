Scaleform::GFx::MemoryContext *__thiscall Scaleform::GFx::MovieDefImpl::CreateMemoryContext(
        Scaleform::GFx::MovieDefImpl *this,
        const char *heapName,
        const Scaleform::GFx::MemoryParams *memParams,
        BOOL debugHeap)
{
  Scaleform::GFx::ASSupport *pObject; // esi
  Scaleform::Ptr<Scaleform::GFx::ASSupport> result; // [esp+4h] [ebp-4h] BYREF

  pObject = Scaleform::GFx::MovieDefImpl::GetASSupport(this, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
  if ( pObject )
    return pObject->CreateMemoryContext(pObject, heapName, memParams, debugHeap);
  else
    return 0;
}
