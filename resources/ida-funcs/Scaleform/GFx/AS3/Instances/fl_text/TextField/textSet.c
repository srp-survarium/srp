void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::textSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::TextField *pObject; // ecx
  Scaleform::GFx::ASStringNode *pNode; // esi
  const __m128i *pData; // edi

  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  pObject->Flags &= ~2u;
  pNode = value->pNode;
  ++pNode->RefCount;
  pData = (const __m128i *)pNode->pData;
  if ( (pObject->Flags & 2) != 0 )
    pObject->Flags &= ~2u;
  Scaleform::GFx::TextField::SetTextValue(pObject, pData, 0, 1);
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
