Scaleform::GFx::AS2::ActionBufferData *__cdecl Scaleform::GFx::AS2::ActionBufferData::CreateNew()
{
  Scaleform::GFx::AS2::ActionBufferData *result; // eax

  result = (Scaleform::GFx::AS2::ActionBufferData *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      24,
                                                      0);
  if ( !result )
    return 0;
  result->__vftable = (Scaleform::GFx::AS2::ActionBufferData_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  result->pBuffer = 0;
  result->BufferLen = 0;
  result->SwdHandle = 0;
  result->SWFFileOffset = 0;
  result->RefCount = 1;
  result->__vftable = (Scaleform::GFx::AS2::ActionBufferData_vtbl *)&Scaleform::GFx::AS2::ActionBufferData::`vftable';
  return result;
}
