void __thiscall Scaleform::GFx::AS2::ObjectInterface::SetUserData(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::Movie *pmovieView,
        Scaleform::GFx::ASUserData *puserData,
        bool isdobj)
{
  Scaleform::GFx::AS2::ObjectInterface::UserDataHolder *pUserDataHolder; // eax
  Scaleform::GFx::AS2::ObjectInterface::UserDataHolder *v6; // eax
  Scaleform::GFx::DisplayObject *v7; // ecx
  Scaleform::GFx::CharacterHandle *pObject; // eax
  int v9; // [esp+Ch] [ebp-4h] BYREF

  pUserDataHolder = this->pUserDataHolder;
  if ( pUserDataHolder )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pUserDataHolder);
  v9 = 323;
  v6 = (Scaleform::GFx::AS2::ObjectInterface::UserDataHolder *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                 Scaleform::Memory::pGlobalHeap,
                                                                 this,
                                                                 8,
                                                                 &v9);
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
  {
    if ( isdobj )
    {
      if ( (unsigned int)(this->GetObjectType(this) - 2) > 3 )
        v7 = 0;
      else
        v7 = (Scaleform::GFx::DisplayObject *)this[1].__vftable;
      pObject = v7->pNameHandle.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v7);
      Scaleform::GFx::ASUserData::SetLastObjectValue(
        puserData,
        (Scaleform::GFx::Value::ObjectInterface *)pmovieView[1].pASMovieRoot.pObject,
        pObject,
        isdobj);
    }
    else
    {
      Scaleform::GFx::ASUserData::SetLastObjectValue(
        puserData,
        (Scaleform::GFx::Value::ObjectInterface *)pmovieView[1].pASMovieRoot.pObject,
        this,
        0);
    }
  }
}
