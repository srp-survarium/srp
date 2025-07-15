void __thiscall Scaleform::GFx::AS3::InstanceTraits::Activation::Activation(
        Scaleform::GFx::AS3::InstanceTraits::Activation *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Abc::MethodBodyInfo *mbi,
        const Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::AS3::VM *v5; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edi
  Scaleform::GFx::AS3::VM *ConstStringNode; // eax
  const Scaleform::GFx::ASString *v9; // edx
  const Scaleform::GFx::ASString *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  const Scaleform::GFx::AS3::Abc::MethodBodyInfo *v13; // [esp-Ch] [ebp-1Ch]
  Scaleform::GFx::ASString result; // [esp+Ch] [ebp-4h] BYREF

  v5 = vm;
  pObject = vm->PublicNamespace.pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  ConstStringNode = (Scaleform::GFx::AS3::VM *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                 v5->StringManagerRef->pStringManager,
                                                 "activation@",
                                                 0xBu,
                                                 0);
  v9 = name;
  vm = ConstStringNode;
  ++ConstStringNode->StringManagerRef;
  v10 = Scaleform::GFx::ASString::operator+((Scaleform::GFx::ASString *)&vm, &result, v9);
  Scaleform::GFx::AS3::InstanceTraits::RTraits::RTraits(
    this,
    v5,
    v10,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace>)pObject,
    0,
    1,
    1);
  pNode = result.pNode;
  --result.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v12 = (Scaleform::GFx::ASStringNode *)vm;
  --vm->StringManagerRef;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v13 = mbi;
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::Activation_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Activation::`vftable';
  this->TraitsType = Traits_Activation;
  Scaleform::GFx::AS3::Traits::AddSlots(this, (Scaleform::GFx::AS3::CheckResult *)&vm, v13, file, 0x20u);
}
