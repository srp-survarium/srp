void __thiscall Scaleform::Render::TreeNode::NodeData::NodeData(
        Scaleform::Render::TreeNode::NodeData *this,
        Scaleform::Render::ContextImpl::EntryData::EntryType type)
{
  Scaleform::Render::Matrix3x4<float> *p_M34; // edi

  p_M34 = &this->M34;
  this->Type = type;
  this->Flags = 1;
  this->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::TreeNode::NodeData::`vftable';
  memset((int)&this->M34, 0, sizeof(this->M34));
  p_M34->M[0][0] = 1.0;
  this->M34.M[1][1] = 1.0;
  this->M34.M[2][2] = 1.0;
  this->States.ArraySize = 0;
  this->States.DataValue = 0;
  Scaleform::Render::Cxform::Cxform(&this->Cx);
  this->AproxLocalBounds.x1 = 0.0;
  this->AproxLocalBounds.y1 = 0.0;
  this->AproxLocalBounds.x2 = 0.0;
  this->AproxLocalBounds.y2 = 0.0;
  this->AproxParentBounds.x1 = 0.0;
  this->AproxParentBounds.y1 = 0.0;
  this->AproxParentBounds.x2 = 0.0;
  this->AproxParentBounds.y2 = 0.0;
}
