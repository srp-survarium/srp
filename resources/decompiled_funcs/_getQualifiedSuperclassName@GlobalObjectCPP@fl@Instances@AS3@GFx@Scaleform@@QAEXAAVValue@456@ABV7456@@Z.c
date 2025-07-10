void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::getQualifiedSuperclassName(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *value)
{
  const Scaleform::GFx::AS3::Traits *pObject; // ecx
  const Scaleform::GFx::ASString *v4; // eax
  Scaleform::GFx::ASStringNode *v5; // eax
  unsigned int v6; // edx
  Scaleform::GFx::AS3::Value::V2U v7; // [esp+4h] [ebp-4h]

  pObject = Scaleform::GFx::AS3::VM::GetInstanceTraits(this->pTraits.pObject->pVM, value)->pParent.pObject;
  if ( pObject )
  {
    v4 = pObject->GetQualifiedName(pObject, (Scaleform::GFx::ASString *)&value, qnfWithColons);
    Scaleform::GFx::AS3::Value::Assign(result, v4);
    v5 = (Scaleform::GFx::ASStringNode *)value;
    --value->value.VS._2.VObj;
    if ( !v5->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  }
  else
  {
    if ( (result->Flags & 0x1F) > 9 )
    {
      if ( (result->Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(result);
    }
    v6 = result->Flags & 0xFFFFFFE0 | 0xC;
    result->value.VS._1.VInt = 0;
    result->Flags = v6;
    result->value.VS._2 = v7;
  }
}
