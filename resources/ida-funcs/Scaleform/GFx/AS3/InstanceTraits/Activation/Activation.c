void __thiscall Scaleform::GFx::AS3::InstanceTraits::Activation::Activation(
        Scaleform::GFx::AS3::InstanceTraits::Activation *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::ASStringNode *vm,
        const Scaleform::GFx::AS3::Abc::MethodBodyInfo *mbi)
{
  Scaleform::GFx::AS3::VM *v4; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *HashFlags; // edi
  Scaleform::GFx::ASStringNode *v7; // eax
  const Scaleform::GFx::AS3::Abc::MethodBodyInfo *v8; // [esp-Ch] [ebp-18h]

  v4 = (Scaleform::GFx::AS3::VM *)vm;
  HashFlags = (Scaleform::GFx::AS3::Instances::fl::Namespace *)vm[9].HashFlags;
  if ( HashFlags )
    HashFlags->RefCount = (HashFlags->RefCount + 1) & 0x8FBFFFFF;
  vm = Scaleform::GFx::ASStringManager::CreateConstStringNode(
         v4->StringManagerRef->pStringManager,
         "activation@",
         0xBu,
         0);
  ++vm->RefCount;
  Scaleform::GFx::AS3::InstanceTraits::RTraits::RTraits(
    this,
    v4,
    (const Scaleform::GFx::ASString *)&vm,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace>)HashFlags,
    0,
    1,
    1);
  v7 = vm;
  --vm->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v8 = mbi;
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::Activation_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Activation::`vftable';
  this->TraitsType = Traits_Activation;
  Scaleform::GFx::AS3::Traits::AddSlots(this, (Scaleform::GFx::AS3::CheckResult *)&vm, v8, file, 0x20u);
}
