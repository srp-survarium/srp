void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::htmlTextGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *Text; // eax
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v4; // ecx
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASString v7; // [esp+0h] [ebp-4h] BYREF

  v7.pNode = (Scaleform::GFx::ASStringNode *)this;
  Text = Scaleform::GFx::TextField::GetText(
           (Scaleform::GFx::TextField *)this->pDispObj.pObject,
           &v7,
           (Scaleform::String)1);
  pNode = Text->pNode;
  ++Text->pNode->RefCount;
  v4 = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v6 = v7.pNode;
  result->pNode = pNode;
  if ( !--v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
}
