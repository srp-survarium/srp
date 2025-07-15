void __thiscall Scaleform::GFx::AS2::Environment::AddLocal(
        Scaleform::GFx::AS2::Environment *this,
        const Scaleform::GFx::ASString *varname,
        const Scaleform::GFx::AS2::Value *val)
{
  Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *v3; // eax
  Scaleform::GFx::AS2::LocalFrame *pObject; // esi
  unsigned int RefCount; // eax

  v3 = &this->LocalFrames.Data.Data[this->LocalFrames.Data.Size - 1];
  if ( v3->pObject )
    v3->pObject->RefCount = (v3->pObject->RefCount + 1) & 0x8FFFFFFF;
  pObject = v3->pObject;
  if ( v3->pObject )
  {
    Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
      &pObject->Variables,
      varname,
      val,
      this->StringContext.SWFVersion > 6u);
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
}
