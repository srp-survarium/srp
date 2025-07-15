void __thiscall Scaleform::GFx::AS3::Class::Class(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::ASRefCountCollector *GC; // ecx
  const Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::Traits_vtbl *v5; // edi
  Scaleform::GFx::AS3::Class *GetAS3ObjectType; // eax

  GC = t->pVM->GC.GC;
  this->__vftable = (Scaleform::GFx::AS3::Class_vtbl *)&Scaleform::GFx::AS3::Object::`vftable';
  this->RefCount = 1;
  this->pRCCRaw = (unsigned int)GC;
  this->pTraits.pObject = t;
  t->RefCount = (t->RefCount + 1) & 0x8FBFFFFF;
  this->DynAttrs.mHash.pTable = 0;
  this->pUserDataHolder = 0;
  this->__vftable = (Scaleform::GFx::AS3::Class_vtbl *)&Scaleform::GFx::AS3::Class::`vftable';
  pObject = t->pParent.pObject;
  if ( pObject )
  {
    v5 = pObject[1].__vftable;
    if ( !v5[1].GetAS3ObjectType )
      (*((void (__thiscall **)(Scaleform::GFx::AS3::Traits_vtbl *))v5->ForEachChild_GC + 14))(v5);
    GetAS3ObjectType = (Scaleform::GFx::AS3::Class *)v5[1].GetAS3ObjectType;
  }
  else
  {
    GetAS3ObjectType = 0;
  }
  this->ParentClass.pObject = GetAS3ObjectType;
  if ( GetAS3ObjectType )
    GetAS3ObjectType->RefCount = (GetAS3ObjectType->RefCount + 1) & 0x8FBFFFFF;
  this->pPrototype.pObject = 0;
}
