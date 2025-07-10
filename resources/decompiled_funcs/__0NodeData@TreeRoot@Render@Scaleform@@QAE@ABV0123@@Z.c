void __thiscall Scaleform::Render::TreeRoot::NodeData::NodeData(
        Scaleform::Render::TreeRoot::NodeData *this,
        const Scaleform::Render::TreeRoot::NodeData *__that)
{
  Scaleform::Render::TreeNode::NodeData::NodeData(this, __that);
  this->__vftable = (Scaleform::Render::TreeRoot::NodeData_vtbl *)&Scaleform::Render::TreeContainer::NodeData::`vftable';
  Scaleform::Render::TreeNodeArray::TreeNodeArray(&this->Children, &__that->Children);
  this->__vftable = (Scaleform::Render::TreeRoot::NodeData_vtbl *)&Scaleform::Render::TreeRoot::NodeData::`vftable';
  this->VP = __that->VP;
  this->BGColor.Raw = __that->BGColor.Raw;
}
