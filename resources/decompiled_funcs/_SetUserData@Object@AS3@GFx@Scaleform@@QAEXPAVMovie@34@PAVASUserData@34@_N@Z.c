void __thiscall Scaleform::GFx::AS3::Object::SetUserData(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::Movie *pmovieView,
        Scaleform::GFx::ASUserData *puserData,
        bool isdobj)
{
  Scaleform::GFx::AS3::Object::UserDataHolder *pUserDataHolder; // eax
  Scaleform::GFx::AS3::Object::UserDataHolder *v6; // eax
  int v7; // [esp+8h] [ebp-4h] BYREF

  pUserDataHolder = this->pUserDataHolder;
  if ( pUserDataHolder )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pUserDataHolder);
  v7 = 337;
  v6 = (Scaleform::GFx::AS3::Object::UserDataHolder *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        this,
                                                        8,
                                                        &v7);
  if ( v6 )
  {
    v6->pMovieView = pmovieView;
    v6->pUserData = puserData;
  }
  else
  {
    v6 = 0;
  }
  this->pUserDataHolder = v6;
  if ( puserData )
    Scaleform::GFx::ASUserData::SetLastObjectValue(
      puserData,
      (Scaleform::GFx::Value::ObjectInterface *)pmovieView[1].pASMovieRoot.pObject,
      this,
      isdobj);
}
