void __thiscall Scaleform::GFx::ASStringNode::Release(Scaleform::GFx::ASStringNode *this)
{
  if ( this->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(this);
}
