void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::GetNextPropertyName(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *name,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString v; // [esp+0h] [ebp-4h] BYREF

  v.pNode = (Scaleform::GFx::ASStringNode *)this;
  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  if ( ind.Index )
  {
    v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                StringManagerRef->pStringManager,
                (char *)&stru_95AF78.m_key_bindings[6].m_keyboard[1],
                1u,
                0);
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Assign(name, &v);
    pNode = v.pNode;
    --v.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(name, (const Scaleform::GFx::ASString *)&StringManagerRef->Builtins[2]);
  }
}
