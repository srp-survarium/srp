void __thiscall Scaleform::GFx::AS3::Classes::fl::Namespace::Construct(
        Scaleform::GFx::AS3::Classes::fl::Namespace *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        bool __formal)
{
  Scaleform::GFx::AS3::VM *pVM; // ebp
  const Scaleform::GFx::AS3::Value *v7; // ebx
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *v10; // ebx
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::AS3::Value *Undefined; // eax
  Scaleform::GFx::AS3::Value *v15; // edi
  Scaleform::GFx::AS3::Value *pV; // esi
  unsigned int v17; // ecx
  unsigned int v18; // edx
  const Scaleform::GFx::AS3::Value *v19; // eax
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > *p_NamespaceSet; // [esp-Ch] [ebp-28h]
  unsigned int v21; // [esp-4h] [ebp-20h]
  Scaleform::GFx::ASString uri; // [esp+10h] [ebp-Ch] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> inst; // [esp+14h] [ebp-8h] BYREF
  Scaleform::GFx::AS3::Value::V2U v24; // [esp+18h] [ebp-4h]

  pVM = this->pTraits.pObject->pVM;
  if ( argc == 1
    && (v7 = argv,
        ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(pVM, argv),
        ValueTraits->TraitsType == Traits_Namespace)
    && (ValueTraits->Flags & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(result, v7);
  }
  else
  {
    pObject = this->pTraits.pObject;
    v10 = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)pObject[1].__vftable;
    pStringManager = pObject->pVM->StringManagerRef->pStringManager;
    ++pStringManager->EmptyStringNode.RefCount;
    p_EmptyStringNode = &pStringManager->EmptyStringNode;
    uri.pNode = p_EmptyStringNode;
    Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(v10, &inst, NS_Public, &uri, Undefined);
    if ( p_EmptyStringNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
    v15 = result;
    if ( (result->Flags & 0x1F) > 9 )
    {
      if ( (result->Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(result);
    }
    pV = (Scaleform::GFx::AS3::Value *)inst.pV;
    v17 = argc;
    v18 = v15->Flags & 0xFFFFFFE0 | 0xB;
    v15->value.VS._2 = v24;
    v19 = argv;
    v15->Flags = v18;
    v15->value.VS._1.VInt = (int)pV;
    (*(void (__thiscall **)(Scaleform::GFx::AS3::Value *, unsigned int, const Scaleform::GFx::AS3::Value *))(pV->Flags + 24))(
      pV,
      v17,
      v19);
    if ( !pVM->HandleException )
    {
      v21 = (4 * (pV[1].value.VS._2.VObj->RefCount & 0xFFFFFF)) ^ ((int)pV[1].Bonus.pWeakProxy << 28 >> 28);
      p_NamespaceSet = &v10->pNamespaceFactory.pObject->NamespaceSet;
      result = pV;
      Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::add<Scaleform::GFx::AS3::Instances::fl::Namespace *>(
        p_NamespaceSet,
        p_NamespaceSet,
        (Scaleform::GFx::AS3::Instances::fl::Namespace *const *)&result,
        v21);
    }
  }
}
