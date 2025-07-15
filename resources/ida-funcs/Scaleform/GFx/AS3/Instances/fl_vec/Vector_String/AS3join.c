void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3join(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::ASString *separator)
{
  Scaleform::GFx::ASString *v3; // eax
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v5; // ecx
  Scaleform::GFx::ASStringNode *v7; // eax

  v3 = Scaleform::GFx::AS3::ArrayBase::ToString(&this->V, (Scaleform::GFx::ASString *)&separator, separator);
  pNode = v3->pNode;
  ++v3->pNode->RefCount;
  v5 = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v7 = (Scaleform::GFx::ASStringNode *)separator;
  result->pNode = pNode;
  if ( !--v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}
