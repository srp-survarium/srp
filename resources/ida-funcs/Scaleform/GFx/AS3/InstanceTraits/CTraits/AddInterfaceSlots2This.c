void __thiscall Scaleform::GFx::AS3::InstanceTraits::CTraits::AddInterfaceSlots2This(
        Scaleform::GFx::AS3::InstanceTraits::CTraits *this,
        Scaleform::GFx::AS3::VMAbcFile *file_ptr,
        Scaleform::GFx::AS3::InstanceTraits::Traits *This)
{
  Scaleform::GFx::AS3::VM *pVM; // ecx
  unsigned int v5; // edx
  Scaleform::GFx::AS3::VMAppDomain *SystemDomain; // eax
  int v7; // ebx
  int i; // edi
  Scaleform::GFx::AS3::Multiname *v9; // esi
  Scaleform::GFx::ASString *v10; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pNode; // eax
  Scaleform::GFx::ASStringNode *v12; // edi
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *appDomain; // [esp+8h] [ebp-10h]
  Scaleform::GFx::AS3::VM *vm; // [esp+Ch] [ebp-Ch]
  unsigned int size; // [esp+10h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v18; // [esp+14h] [ebp-4h]

  pVM = this->pVM;
  v5 = this->ImplementsInterfaces.Data.Size;
  vm = pVM;
  size = v5;
  if ( file_ptr )
    SystemDomain = file_ptr->AppDomain;
  else
    SystemDomain = pVM->SystemDomain;
  v7 = 0;
  appDomain = (Scaleform::GFx::ASStringNode *)SystemDomain;
  if ( v5 )
  {
    for ( i = 0; ; ++i )
    {
      v9 = &this->ImplementsInterfaces.Data.Data[i];
      v10 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(pVM, v9, appDomain);
      if ( !v10 )
        break;
      pNode = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v10[25].pNode;
      if ( !pNode )
        break;
      Scaleform::GFx::AS3::InstanceTraits::Traits::AddInterfaceSlots(This, file_ptr, pNode);
      if ( ++v7 >= size )
        return;
      pVM = vm;
    }
    v12 = (Scaleform::GFx::ASStringNode *)this->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&size,
      (Scaleform::GFx::AS3::VM_vtbl *)0x3F6,
      v12,
      &v9->Name);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      (Scaleform::GFx::AS3::VM *)v12,
      v13,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
    v14 = v18;
    --v18->RefCount;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
}
