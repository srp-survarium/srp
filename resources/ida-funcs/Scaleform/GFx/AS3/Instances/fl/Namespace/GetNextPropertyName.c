void __thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::GetNextPropertyName(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        Scaleform::GFx::AS3::Value *name,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::VM *VMRef; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString v; // [esp+0h] [ebp-8h] BYREF
  Scaleform::GFx::ASString v6; // [esp+4h] [ebp-4h] BYREF

  VMRef = this->VMRef;
  if ( ind.Index == 1 )
  {
    v6.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 VMRef->StringManagerRef->pStringManager,
                 "uri",
                 3u,
                 0);
    ++v6.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Assign(name, &v6);
    pNode = v6.pNode;
  }
  else
  {
    if ( ind.Index != 2 )
      return;
    v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                VMRef->StringManagerRef->pStringManager,
                "prefix",
                6u,
                0);
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Assign(name, &v);
    pNode = v.pNode;
  }
  if ( !--pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
