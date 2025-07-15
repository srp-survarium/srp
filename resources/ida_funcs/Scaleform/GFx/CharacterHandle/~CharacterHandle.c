void __thiscall Scaleform::GFx::CharacterHandle::~CharacterHandle(Scaleform::GFx::CharacterHandle *this)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v3; // zf
  Scaleform::GFx::ASStringNode *v4; // ecx
  Scaleform::GFx::ASStringNode *v5; // ecx

  pNode = this->OriginalName.pNode;
  v3 = pNode->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v4 = this->NamePath.pNode;
  v3 = v4->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v5 = this->Name.pNode;
  v3 = v5->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}
