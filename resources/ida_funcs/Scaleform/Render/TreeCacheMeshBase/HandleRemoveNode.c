void __thiscall Scaleform::Render::TreeCacheMeshBase::HandleRemoveNode(Scaleform::Render::TreeCacheMeshBase *this)
{
  Scaleform::Render::TreeCacheNode::HandleRemoveNode(this);
  this->SorterShapeNode.Removed = 1;
}
