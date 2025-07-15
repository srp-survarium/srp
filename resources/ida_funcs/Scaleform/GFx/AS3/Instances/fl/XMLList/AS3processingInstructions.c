void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3processingInstructions(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // ebx
  unsigned int v6; // ebp
  unsigned int j; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v8; // ecx
  Scaleform::GFx::AS3::Value *v9; // ecx
  unsigned int Size; // ebp
  unsigned int i; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> list; // [esp+10h] [ebp-4h] BYREF

  Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(this, &list);
  pV = list.pV;
  Scaleform::GFx::AS3::Value::Pick(result, list.pV);
  if ( argc )
  {
    v9 = argv;
    argc = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
    ++argc->RefCount;
    if ( Scaleform::GFx::AS3::Value::Convert2String(
           v9,
           (Scaleform::GFx::AS3::CheckResult *)&result,
           (Scaleform::GFx::ASString *)&argc)->Result )
    {
      Size = this->List.Data.Size;
      for ( i = 0; i < Size; ++i )
      {
        pObject = this->List.Data.Data[i].pObject;
        pObject->GetChildren(pObject, pV, kInstruction, (const Scaleform::GFx::ASString *)&argc);
      }
    }
    v13 = argc;
    --argc->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
  else
  {
    v6 = this->List.Data.Size;
    for ( j = 0; j < v6; ++j )
    {
      v8 = this->List.Data.Data[j].pObject;
      v8->GetChildren(v8, pV, kInstruction, 0);
    }
  }
}
