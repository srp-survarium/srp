void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3namespace_(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v5; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString pref; // [esp+8h] [ebp-4h] BYREF

  if ( argc )
  {
    pStringManager = this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
    pref.pNode = &pStringManager->EmptyStringNode;
    ++pStringManager->EmptyStringNode.RefCount;
    if ( Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &pref)->Result )
    {
      v7 = this->FindNamespaceByPrefix(this, &pref, 0);
      if ( v7 )
        Scaleform::GFx::AS3::Value::Assign(result, v7);
      else
        Scaleform::GFx::AS3::Value::SetUndefined(result);
    }
    pNode = pref.pNode;
    --pref.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    v5 = this->GetCurrNamespace(this);
    Scaleform::GFx::AS3::Value::Assign(result, v5);
  }
}
