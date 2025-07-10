void __thiscall Scaleform::GFx::AS2::SuperObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::Object *pObject; // eax
  unsigned int v4; // ecx
  Scaleform::GFx::AS2::Object *v5; // eax
  unsigned int v6; // ecx

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(this, prcc);
  pObject = this->SuperProto.pObject;
  if ( pObject )
  {
    v4 = ++pObject->RefCount;
    if ( (v4 & 0x70000000) != 0 )
    {
      pObject->RefCount = v4 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, pObject);
    }
  }
  v5 = this->SavedProto.pObject;
  if ( v5 )
  {
    v6 = ++v5->RefCount;
    if ( (v6 & 0x70000000) != 0 )
    {
      v5->RefCount = v6 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, v5);
    }
  }
  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    &this->Constructor,
    prcc);
}
