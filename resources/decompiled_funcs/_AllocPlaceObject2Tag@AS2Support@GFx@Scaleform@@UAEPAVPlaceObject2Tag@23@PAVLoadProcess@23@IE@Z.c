Scaleform::GFx::PlaceObject2Tag *__thiscall Scaleform::GFx::AS2Support::AllocPlaceObject2Tag(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p,
        unsigned int dataSz,
        unsigned __int8 swfVer)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v4; // ecx
  unsigned int v5; // edx
  Scaleform::GFx::DataAllocator *v6; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::PlaceObject2Tag *v8; // esi
  Scaleform::GFx::PlaceObject2Tag *result; // eax
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned int v13; // eax
  Scaleform::GFx::PlaceObject2Tag *pCurrent; // esi

  if ( swfVer < 6u )
  {
    pObject = p->pLoadData.pObject;
    BytesLeft = pObject->TagMemAllocator.BytesLeft;
    p_TagMemAllocator = &pObject->TagMemAllocator;
    v13 = (dataSz + 10) & 0xFFFFFFFC;
    if ( v13 > BytesLeft )
    {
      result = (Scaleform::GFx::PlaceObject2Tag *)Scaleform::GFx::DataAllocator::OverflowAlloc(
                                                    p_TagMemAllocator,
                                                    (dataSz + 10) & 0xFFFFFFFC);
    }
    else
    {
      pCurrent = (Scaleform::GFx::PlaceObject2Tag *)p_TagMemAllocator->pCurrent;
      p_TagMemAllocator->pCurrent += v13;
      p_TagMemAllocator->BytesLeft = BytesLeft - v13;
      result = pCurrent;
    }
    if ( result )
    {
      result->__vftable = (Scaleform::GFx::PlaceObject2Tag_vtbl *)&Scaleform::GFx::AS2::PlaceObject2EHa::`vftable';
      return result;
    }
  }
  else
  {
    v4 = p->pLoadData.pObject;
    v5 = v4->TagMemAllocator.BytesLeft;
    v6 = &v4->TagMemAllocator;
    v7 = (dataSz + 10) & 0xFFFFFFFC;
    if ( v7 > v5 )
    {
      result = (Scaleform::GFx::PlaceObject2Tag *)Scaleform::GFx::DataAllocator::OverflowAlloc(
                                                    v6,
                                                    (dataSz + 10) & 0xFFFFFFFC);
    }
    else
    {
      v8 = (Scaleform::GFx::PlaceObject2Tag *)v6->pCurrent;
      v6->pCurrent += v7;
      v6->BytesLeft = v5 - v7;
      result = v8;
    }
    if ( result )
    {
      result->__vftable = (Scaleform::GFx::PlaceObject2Tag_vtbl *)&Scaleform::GFx::AS2::PlaceObject2EH::`vftable';
      return result;
    }
  }
  return 0;
}
