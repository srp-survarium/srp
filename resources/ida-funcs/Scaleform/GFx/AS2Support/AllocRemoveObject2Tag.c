Scaleform::GFx::RemoveObject2Tag *__thiscall Scaleform::GFx::AS2Support::AllocRemoveObject2Tag(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  Scaleform::GFx::RemoveObject2Tag *result; // eax

  pObject = p->pLoadData.pObject;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  p_TagMemAllocator = &pObject->TagMemAllocator;
  if ( BytesLeft < 8 )
  {
    result = (Scaleform::GFx::RemoveObject2Tag *)Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 8u);
  }
  else
  {
    result = (Scaleform::GFx::RemoveObject2Tag *)p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 8;
    p_TagMemAllocator->BytesLeft = BytesLeft - 8;
  }
  if ( !result )
    return 0;
  result->__vftable = (Scaleform::GFx::RemoveObject2Tag_vtbl *)&Scaleform::GFx::AS2::RemoveObject2EH::`vftable';
  return result;
}
