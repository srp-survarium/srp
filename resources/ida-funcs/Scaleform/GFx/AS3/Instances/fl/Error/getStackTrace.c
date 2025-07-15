void __thiscall Scaleform::GFx::AS3::Instances::fl::Error::getStackTrace(
        Scaleform::GFx::AS3::Instances::fl::Error *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v3; // ecx

  pNode = this->pTraits.pObject->pVM->StringManagerRef->Builtins[2].pNode;
  ++pNode->RefCount;
  v3 = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v3);
  result->pNode = pNode;
}
