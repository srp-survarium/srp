void __thiscall Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(
        Scaleform::GFx::Value_AS2ObjectData *this,
        const Scaleform::GFx::Value::ObjectInterface *i,
        Scaleform::GFx::AS2::ObjectInterface *pdata,
        bool isdobj)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // edi
  Scaleform::GFx::AS2::MovieRoot *pObject; // eax
  int v7; // ecx
  Scaleform::GFx::InteractiveObject *v8; // eax
  int v9; // eax

  pMovieRoot = i->pMovieRoot;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)pMovieRoot->pASMovieRoot.pObject;
  this->pRoot = pObject;
  v7 = (int)pObject->pMovieImpl->pMainMovie + 4 * pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  this->pEnv = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 124))(v7);
  this->pObject = pdata;
  if ( isdobj )
  {
    v8 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, pMovieRoot);
    if ( v8 )
    {
      v9 = (*(int (__thiscall **)(int))(*((_DWORD *)&v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                        + v8->AvmObjOffset)
                                      + 4))((int)v8 + 4 * v8->AvmObjOffset);
      if ( v9 )
        this->pObject = (Scaleform::GFx::AS2::ObjectInterface *)(v9 + 4);
      else
        this->pObject = 0;
    }
    else
    {
      this->pObject = 0;
    }
  }
}
