bool __thiscall Scaleform::GFx::AS3::SlotInfo::IsClassType(Scaleform::GFx::AS3::SlotInfo *this)
{
  Scaleform::GFx::AS3::VMAbcFile *pObject; // eax
  Scaleform::GFx::AS3::Abc::TraitInfo *TI; // ecx
  const Scaleform::GFx::AS3::Abc::File *v3; // esi
  const Scaleform::GFx::AS3::Abc::Multiname *TypeName; // eax
  const Scaleform::GFx::AS3::Abc::NamespaceInfo *p_any_namespace; // edi
  Scaleform::GFx::AS3::Abc::StringView *v6; // ecx
  Scaleform::StringDataPtr result; // [esp+4h] [ebp-18h] BYREF
  Scaleform::StringDataPtr v9; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::StringDataPtr v10; // [esp+14h] [ebp-8h] BYREF

  pObject = this->File.pObject;
  if ( !pObject )
    return 0;
  TI = (Scaleform::GFx::AS3::Abc::TraitInfo *)this->TI;
  if ( !TI )
    return 0;
  v3 = pObject->File.pObject;
  TypeName = Scaleform::GFx::AS3::Abc::TraitInfo::GetTypeName(TI, v3);
  if ( TypeName->Ind )
    p_any_namespace = &v3->Const_Pool.ConstNamespace.Data.Data[TypeName->Ind];
  else
    p_any_namespace = &v3->Const_Pool.any_namespace;
  v6 = &v3->Const_Pool.ConstStr.Data.Data[TypeName->NameIndex];
  v9.pStr = "Class";
  v9.Size = 5;
  Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(v6, &result);
  v10 = result;
  return Scaleform::StringDataPtr::operator==(&v10, &v9)
      && (p_any_namespace->Kind == NS_Public || p_any_namespace->Kind == NS_Explicit)
      && !p_any_namespace->NameURI.Size;
}
