void __thiscall Scaleform::GFx::AS3::TR::State::exec_newactivation(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *ActivationInstanceTraits; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString name; // [esp+8h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value val; // [esp+Ch] [ebp-10h] BYREF

  name.pNode = this->pTracer->CF->Name.pObject;
  ++name.pNode->RefCount;
  ActivationInstanceTraits = Scaleform::GFx::AS3::VMFile::GetActivationInstanceTraits(
                               this->pTracer->CF->pFile,
                               this->pTracer->CF->MBIIndex,
                               (Scaleform::GFx::AS3::InstanceTraits::Traits *)&name);
  pNode = name.pNode;
  --name.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  val.Bonus.pWeakProxy = 0;
  val.value.VS._1.VInt = (int)ActivationInstanceTraits;
  val.Flags = 8;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->OpStack.Data,
    &val);
}
