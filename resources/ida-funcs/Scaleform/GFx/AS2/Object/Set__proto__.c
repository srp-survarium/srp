void __thiscall Scaleform::GFx::AS2::Object::Set__proto__(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *protoObj)
{
  void (__thiscall *Finalize_GC)(struct Scaleform::GFx::AS2::Object *); // edx
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pPrev; // ecx
  unsigned int RefCount; // eax
  char v8; // [esp+Fh] [ebp-11h] BYREF
  Scaleform::GFx::AS2::Value v9; // [esp+10h] [ebp-10h] BYREF

  if ( !this->RootIndex )
  {
    Finalize_GC = this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].Finalize_GC;
    pContext = psc->pContext;
    v8 = 3;
    v9.T.Type = 10;
    ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, unsigned __int8 *, Scaleform::GFx::AS2::Value *, char *))Finalize_GC)(
      this,
      psc,
      &pContext->pMovieRoot->pASMovieRoot.pObject[23].AVMVersion,
      &v9,
      &v8);
    if ( v9.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v9);
  }
  if ( protoObj )
    protoObj->RefCount = (protoObj->RefCount + 1) & 0x8FFFFFFF;
  pPrev = this->pPrev;
  if ( pPrev )
  {
    RefCount = pPrev->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pPrev->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pPrev);
    }
  }
  this->RootIndex = (unsigned int)protoObj;
}
