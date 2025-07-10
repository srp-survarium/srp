void __thiscall Scaleform::GFx::AS3::InstanceTraits::Function::RegisterSlots(
        Scaleform::GFx::AS3::InstanceTraits::Function *this)
{
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *pObject; // edx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::AS3::ThunkInfo *v6; // edi
  int v7; // ebx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > v8; // [esp-14h] [ebp-24h]
  const Scaleform::GFx::AS3::ClassTraits::Traits *v9; // [esp-10h] [ebp-20h]
  Scaleform::GFx::ASString name; // [esp+Ch] [ebp-4h] BYREF

  pVM = this->pVM;
  pObject = pVM->TraitsObject.pObject;
  v4 = pVM->PublicNamespace.pObject;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
  v9 = pObject;
  v8.pV = v4;
  name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 this->pVM->StringManagerRef->pStringManager,
                 "prototype",
                 9u,
                 0);
  ++name.pNode->RefCount;
  Scaleform::GFx::AS3::Traits::AddSlotCPP(this, &name, v8, v9, BT_ObjectCpp, (Scaleform::GFx::AS3::AbsoluteIndex)32, 0);
  pNode = name.pNode;
  --name.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v6 = Scaleform::GFx::AS3::InstanceTraits::Function::f;
  v7 = 3;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this, &Scaleform::GFx::AS3::fl::FunctionCI, v6++);
    --v7;
  }
  while ( v7 );
}
