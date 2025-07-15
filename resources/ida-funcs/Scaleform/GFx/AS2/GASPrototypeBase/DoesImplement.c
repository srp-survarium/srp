char __thiscall Scaleform::GFx::AS2::GASPrototypeBase::DoesImplement(
        Scaleform::GFx::AS2::GASPrototypeBase *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::AS2::Object *prototype)
{
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *pInterfaces; // eax
  int v5; // edi
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *Data; // ecx
  Scaleform::GFx::AS2::Object *pObject; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> **p_pObject; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // esi
  bool v10; // zf
  unsigned int RefCount; // eax
  unsigned int Size; // [esp+10h] [ebp-4h]

  pInterfaces = this->pInterfaces;
  if ( !pInterfaces )
    return 0;
  v5 = 0;
  Size = pInterfaces->Data.Size;
  if ( !Size )
    return 0;
  while ( 1 )
  {
    Data = this->pInterfaces->Data.Data;
    pObject = Data[v5].pObject;
    p_pObject = &Data[v5].pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
    v9 = *p_pObject;
    if ( !*p_pObject )
      goto LABEL_9;
    v10 = ((unsigned __int8 (__thiscall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::AS2::Object *, int))v9[1].__vftable[6].ExecuteForEachChild_GC)(
            &v9[1],
            penv,
            prototype,
            1) == 0;
    RefCount = v9->RefCount;
    if ( !v10 )
      break;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v9->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
    }
LABEL_9:
    if ( ++v5 >= Size )
      return 0;
  }
  if ( (RefCount & 0x3FFFFFF) != 0 )
  {
    v9->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
  }
  return 1;
}
