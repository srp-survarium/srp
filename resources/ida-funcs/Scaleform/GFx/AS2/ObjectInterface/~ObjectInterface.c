void __thiscall Scaleform::GFx::AS2::ObjectInterface::~ObjectInterface(Scaleform::GFx::AS2::ObjectInterface *this)
{
  Scaleform::GFx::AS2::ObjectInterface::UserDataHolder *pUserDataHolder; // esi
  Scaleform::GFx::ASUserData *pUserData; // ecx
  Scaleform::GFx::AS2::Object *pObject; // ecx
  unsigned int RefCount; // eax

  pUserDataHolder = this->pUserDataHolder;
  this->__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable';
  if ( pUserDataHolder )
  {
    pUserData = pUserDataHolder->pUserData;
    if ( pUserData )
    {
      Scaleform::GFx::ASUserData::SetLastObjectValue(pUserData, 0, 0, 0);
      pUserDataHolder->pUserData->OnDestroy(pUserDataHolder->pUserData, pUserDataHolder->pMovieView, this);
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pUserDataHolder);
  }
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
}
