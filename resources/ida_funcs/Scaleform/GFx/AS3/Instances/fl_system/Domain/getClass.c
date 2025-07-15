void __thiscall Scaleform::GFx::AS3::Instances::fl_system::Domain::getClass(
        Scaleform::GFx::AS3::Instances::fl_system::Domain *this,
        Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *name)
{
  const char *pData; // eax
  const Scaleform::GFx::AS3::Multiname *v5; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // edi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // ecx
  unsigned int v9; // edx
  unsigned int Size; // eax
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::StringDataPtr qname; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Multiname v13; // [esp+10h] [ebp-18h] BYREF

  pData = name->pNode->pData;
  qname.pStr = pData;
  if ( pData )
    qname.Size = strlen(pData);
  else
    qname.Size = 0;
  Scaleform::GFx::AS3::Multiname::Multiname(&v13, this->pTraits.pObject->pVM, &qname);
  ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(this->VMDomain, v5);
  if ( (v13.Name.Flags & 0x1F) > 9 )
  {
    if ( (v13.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v13.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v13.Name);
  }
  if ( v13.Obj.pObject )
  {
    if ( ((int)v13.Obj.pObject & 1) != 0 )
    {
      --v13.Obj.pObject;
    }
    else
    {
      RefCount = v13.Obj.pObject->RefCount;
      pObject = v13.Obj.pObject;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v13.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  v9 = result->Flags & 0xFFFFFFE0 | 0xC;
  result->value.VS._1.VInt = 0;
  Size = qname.Size;
  result->Flags = v9;
  result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)Size;
  if ( ClassTrait )
  {
    Constructor = Scaleform::GFx::AS3::Traits::GetConstructor((*ClassTrait)->ITraits.pObject);
    Scaleform::GFx::AS3::Value::Assign(result, Constructor);
  }
}
