void __thiscall Scaleform::GFx::AS3::InstanceTraits::CTraits::AddInterfaceSlots2This(
        Scaleform::GFx::AS3::InstanceTraits::CTraits *this,
        Scaleform::GFx::AS3::VMAbcFile *file_ptr,
        Scaleform::GFx::AS3::InstanceTraits::Traits *This)
{
  Scaleform::GFx::AS3::VM *pVM; // ecx
  unsigned int Size; // ebp
  int v6; // edi
  int i; // esi
  Scaleform::GFx::ASString *v8; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pNode; // eax
  Scaleform::GFx::AS3::VM *v10; // esi
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::VMAppDomain *appDomain; // [esp+Ch] [ebp-Ch]
  Scaleform::GFx::AS3::VM *vm; // [esp+10h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v15; // [esp+14h] [ebp-4h]

  pVM = this->pVM;
  Size = this->ImplementsInterfaces.Data.Size;
  vm = pVM;
  if ( file_ptr )
    appDomain = file_ptr->AppDomain;
  else
    appDomain = pVM->SystemDomain;
  v6 = 0;
  if ( Size )
  {
    for ( i = 0; ; ++i )
    {
      v8 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
             pVM,
             &this->ImplementsInterfaces.Data.Data[i],
             (Scaleform::GFx::ASStringNode *)appDomain);
      if ( !v8 )
        break;
      pNode = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v8[25].pNode;
      if ( !pNode )
        break;
      Scaleform::GFx::AS3::InstanceTraits::Traits::AddInterfaceSlots(This, file_ptr, pNode);
      if ( ++v6 >= Size )
        return;
      pVM = vm;
    }
    v10 = this->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&vm, eClassNotFoundError, v10);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v10,
      v11,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
    v12 = v15;
    --v15->RefCount;
    if ( !v12->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
}
