Scaleform::GFx::RemoveObjectTag *__thiscall Scaleform::GFx::AS2Support::AllocRemoveObjectTag(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  Scaleform::GFx::RemoveObjectTag *result; // eax

  pObject = p->pLoadData.pObject;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  p_TagMemAllocator = &pObject->TagMemAllocator;
  if ( BytesLeft < 0xC )
  {
    result = (Scaleform::GFx::RemoveObjectTag *)Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 0xCu);
  }
  else
  {
    result = (Scaleform::GFx::RemoveObjectTag *)p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 12;
    p_TagMemAllocator->BytesLeft = BytesLeft - 12;
  }
  if ( !result )
    return 0;
  result->__vftable = (Scaleform::GFx::RemoveObjectTag_vtbl *)&Scaleform::GFx::AS2::RemoveObjectEH::`vftable';
  return result;
}
