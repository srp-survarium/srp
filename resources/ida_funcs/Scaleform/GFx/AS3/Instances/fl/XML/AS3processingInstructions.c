void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3processingInstructions(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString name; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> list; // [esp+10h] [ebp-4h] BYREF

  Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(this, &list);
  pV = list.pV;
  Scaleform::GFx::AS3::Value::Pick(result, list.pV);
  name.pNode = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  ++name.pNode->RefCount;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&result, &name);
  this->GetChildren(this, pV, kInstruction, &name);
  pNode = name.pNode;
  --name.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
