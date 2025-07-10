Scaleform::GFx::PlaceObject2Taga *__thiscall Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject2Taga>(
        Scaleform::GFx::LoadProcess *this,
        unsigned int len)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::PlaceObject2Taga *pCurrent; // esi
  unsigned int v7; // edx
  Scaleform::GFx::PlaceObject2Taga *result; // eax

  pObject = this->pLoadData.pObject;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  p_TagMemAllocator = &pObject->TagMemAllocator;
  v5 = (len + 10) & 0xFFFFFFFC;
  if ( v5 > BytesLeft )
  {
    result = (Scaleform::GFx::PlaceObject2Taga *)Scaleform::GFx::DataAllocator::OverflowAlloc(
                                                   p_TagMemAllocator,
                                                   (len + 10) & 0xFFFFFFFC);
  }
  else
  {
    pCurrent = (Scaleform::GFx::PlaceObject2Taga *)p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += v5;
    v7 = BytesLeft - v5;
    result = pCurrent;
    p_TagMemAllocator->BytesLeft = v7;
  }
  if ( !result )
    return 0;
  result->__vftable = (Scaleform::GFx::PlaceObject2Taga_vtbl *)&Scaleform::GFx::PlaceObject2Taga::`vftable';
  return result;
}
