void __thiscall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::hasDefinition(
        Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this,
        bool *result,
        const Scaleform::GFx::ASString *name)
{
  const char *pData; // eax
  const Scaleform::GFx::AS3::Multiname *v5; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // ecx
  Scaleform::StringDataPtr qname; // [esp+4h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Multiname v9; // [esp+Ch] [ebp-18h] BYREF

  pData = name->pNode->pData;
  qname.pStr = pData;
  if ( pData )
    qname.Size = strlen(pData);
  else
    qname.Size = 0;
  Scaleform::GFx::AS3::Multiname::Multiname(&v9, this->pTraits.pObject->pVM, &qname);
  *result = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(this->VMDomain, v5) != 0;
  if ( (v9.Name.Flags & 0x1F) > 9 )
  {
    if ( (v9.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v9.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v9.Name);
  }
  if ( v9.Obj.pObject && ((int)v9.Obj.pObject & 1) == 0 )
  {
    RefCount = v9.Obj.pObject->RefCount;
    pObject = v9.Obj.pObject;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      v9.Obj.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
}
