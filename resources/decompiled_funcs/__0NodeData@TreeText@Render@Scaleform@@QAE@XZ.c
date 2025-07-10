void __thiscall Scaleform::Render::TreeText::NodeData::NodeData(Scaleform::Render::TreeText::NodeData *this)
{
  Scaleform::Render::TreeNode::NodeData::NodeData(this, ET_Text);
  this->__vftable = (Scaleform::Render::TreeText::NodeData_vtbl *)&Scaleform::Render::TreeText::NodeData::`vftable';
  this->pDocView.pObject = 0;
  this->pLayout.pObject = 0;
  this->TextFlags = 0;
}
