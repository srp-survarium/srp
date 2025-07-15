char __thiscall Scaleform::GFx::AS3::InstanceTraits::CTraits::SupportsInterface(
        Scaleform::GFx::AS3::InstanceTraits::CTraits *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *itraits)
{
  Scaleform::GFx::ASStringNode *VStr; // edi
  Scaleform::GFx::AS3::Multiname *v4; // esi
  bool v5; // bl
  Scaleform::GFx::AS3::ClassTraits::ClassClass *pObject; // eax
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // ecx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *v10; // ecx
  int v12; // [esp+10h] [ebp-14h]
  int j; // [esp+14h] [ebp-10h]
  Scaleform::GFx::AS3::VMAppDomain *v14; // [esp+18h] [ebp-Ch]
  unsigned int i; // [esp+1Ch] [ebp-8h]
  Scaleform::GFx::AS3::VM *vm; // [esp+20h] [ebp-4h]

  v12 = 0;
  vm = this->pVM;
  i = 0;
  if ( !this->ImplementsInterfaces.Data.Size )
    return 0;
  VStr = (Scaleform::GFx::ASStringNode *)itraits;
  for ( j = 0; ; ++j )
  {
    v5 = 1;
    v4 = &this->ImplementsInterfaces.Data.Data[j];
    v14 = this->GetAppDomain(this);
    if ( (v4->Name.Flags & 0x1F) != 0 && ((v4->Name.Flags & 0x1F) - 12 > 3 || v4->Name.value.VS._1.VInt) )
    {
      if ( (v4->Name.Flags & 0x1F) != 0xA || (VStr = v4->Name.value.VS._1.VStr, v12 |= 1u, ++VStr->RefCount, VStr->Size) )
        v5 = 0;
    }
    if ( (v12 & 1) != 0 )
    {
      v12 &= ~1u;
      if ( VStr->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
    }
    if ( v5 )
    {
      pObject = vm->TraitsClassClass.pObject;
    }
    else
    {
      ParentDomain = v14->ParentDomain;
      if ( !ParentDomain || (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, v4)) == 0 )
      {
        ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                       &v14->ClassTraitsSet,
                       v4);
        if ( !ClassTrait )
          goto LABEL_22;
      }
      pObject = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)*ClassTrait;
    }
    if ( pObject )
    {
      v10 = pObject->ITraits.pObject;
      if ( v10 == itraits || v10->SupportsInterface((Scaleform::GFx::AS3::InstanceTraits::Traits *)v10, itraits) )
        break;
    }
LABEL_22:
    if ( ++i >= this->ImplementsInterfaces.Data.Size )
      return 0;
  }
  return 1;
}
