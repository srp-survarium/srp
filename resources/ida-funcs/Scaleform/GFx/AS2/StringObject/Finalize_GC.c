void __thiscall Scaleform::GFx::AS2::StringObject::Finalize_GC(Scaleform::GFx::AS2::StringObject *this)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx

  pNode = this->sValue.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
