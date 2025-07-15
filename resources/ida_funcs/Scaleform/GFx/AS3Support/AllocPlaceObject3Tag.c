Scaleform::GFx::PlaceObject3Tag *__thiscall Scaleform::GFx::AS3Support::AllocPlaceObject3Tag(
        Scaleform::GFx::AS3Support *this,
        Scaleform::GFx::LoadProcess *p,
        unsigned int dataSz)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned int v6; // eax
  Scaleform::GFx::PlaceObject3Tag *pCurrent; // esi
  unsigned int v8; // edx
  Scaleform::GFx::PlaceObject3Tag *result; // eax

  pObject = p->pLoadData.pObject;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  p_TagMemAllocator = &pObject->TagMemAllocator;
  v6 = (dataSz + 10) & 0xFFFFFFFC;
  if ( v6 > BytesLeft )
  {
    result = (Scaleform::GFx::PlaceObject3Tag *)Scaleform::GFx::DataAllocator::OverflowAlloc(
                                                  p_TagMemAllocator,
                                                  (dataSz + 10) & 0xFFFFFFFC);
  }
  else
  {
    pCurrent = (Scaleform::GFx::PlaceObject3Tag *)p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += v6;
    v8 = BytesLeft - v6;
    result = pCurrent;
    p_TagMemAllocator->BytesLeft = v8;
  }
  if ( !result )
    return 0;
  result->__vftable = (Scaleform::GFx::PlaceObject3Tag_vtbl *)&Scaleform::GFx::PlaceObject3Tag::`vftable';
  return result;
}
