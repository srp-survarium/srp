void __thiscall Scaleform::GFx::AS2::AvmCharacter::Set__proto__(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::ObjectInterface::UserDataHolder *protoObj)
{
  int v4; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // esi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pUserDataHolder; // ecx
  unsigned int RefCount; // eax
  unsigned int v8; // eax

  v4 = ((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[13].EntryCount)(&this[-1].EventHandlers);
  v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v4;
  if ( v4 )
  {
    *(_DWORD *)(v4 + 12) = (*(_DWORD *)(v4 + 12) + 1) & 0x8FFFFFFF;
    (*(void (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::ObjectInterface::UserDataHolder *))(*(_DWORD *)(v4 + 16) + 52))(
      v4 + 16,
      psc,
      protoObj);
  }
  if ( protoObj )
    protoObj[1].pUserData = (Scaleform::GFx::ASUserData *)(((int)&protoObj[1].pUserData->__vftable + 1) & 0x8FFFFFFF);
  pUserDataHolder = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)this->pUserDataHolder;
  if ( pUserDataHolder )
  {
    RefCount = pUserDataHolder->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pUserDataHolder->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pUserDataHolder);
    }
  }
  this->pUserDataHolder = protoObj;
  if ( v5 )
  {
    v8 = v5->RefCount;
    if ( (v8 & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = v8 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}
