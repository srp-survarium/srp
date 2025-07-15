void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3toString(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // eax
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v4; // ecx
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASString v7; // [esp+8h] [ebp-4h] BYREF

  v2 = Scaleform::GFx::AS3::ArrayBase::ToString(
         &this->V,
         &v7,
         (const Scaleform::GFx::ASString *)&this->pTraits.pObject->pVM->StringManagerRef->Builtins[14]);
  pNode = v2->pNode;
  ++v2->pNode->RefCount;
  v4 = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v6 = v7.pNode;
  result->pNode = pNode;
  if ( !--v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
}
