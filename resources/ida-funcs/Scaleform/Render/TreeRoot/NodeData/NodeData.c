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


void __thiscall Scaleform::Render::TreeRoot::NodeData::NodeData(Scaleform::Render::TreeRoot::NodeData *this)
{
  Scaleform::Render::TreeNode::NodeData::NodeData(this, ET_Root);
  this->Children.pData[1] = 0;
  this->Children.pData[0] = 0;
  this->__vftable = (Scaleform::Render::TreeRoot::NodeData_vtbl *)&Scaleform::Render::TreeRoot::NodeData::`vftable';
  this->VP.BufferWidth = 0;
  this->VP.BufferHeight = 0;
  this->VP.Top = 0;
  this->VP.Left = 0;
  this->VP.ScissorHeight = 0;
  this->VP.ScissorWidth = 0;
  this->VP.ScissorTop = 0;
  this->VP.ScissorLeft = 0;
  this->VP.Flags = 0;
  this->VP.Height = 1;
  this->VP.Width = 1;
  this->BGColor.Raw = 0;
}
