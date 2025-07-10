Scaleform::GFx::PlaceObject2Tag *__thiscall Scaleform::GFx::AS3Support::AllocPlaceObject2Tag(
        Scaleform::GFx::AS3Support *this,
        Scaleform::GFx::LoadProcess *p,
        unsigned int dataSz,
        unsigned __int8 __formal)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::PlaceObject2Tag *pCurrent; // esi
  unsigned int v9; // edx
  Scaleform::GFx::PlaceObject2Tag *result; // eax

  pObject = p->pLoadData.pObject;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  p_TagMemAllocator = &pObject->TagMemAllocator;
  v7 = (dataSz + 10) & 0xFFFFFFFC;
  if ( v7 > BytesLeft )
  {
    result = (Scaleform::GFx::PlaceObject2Tag *)Scaleform::GFx::DataAllocator::OverflowAlloc(
                                                  p_TagMemAllocator,
                                                  (dataSz + 10) & 0xFFFFFFFC);
  }
  else
  {
    pCurrent = (Scaleform::GFx::PlaceObject2Tag *)p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += v7;
    v9 = BytesLeft - v7;
    result = pCurrent;
    p_TagMemAllocator->BytesLeft = v9;
  }
  if ( !result )
    return 0;
  result->__vftable = (Scaleform::GFx::PlaceObject2Tag_vtbl *)&Scaleform::GFx::PlaceObject2Tag::`vftable';
  return result;
}
