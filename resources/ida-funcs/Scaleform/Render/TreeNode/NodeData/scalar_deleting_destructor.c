Scaleform::Render::TreeNode::NodeData *__thiscall Scaleform::Render::TreeNode::NodeData::`scalar deleting destructor'(
        Scaleform::Render::TreeNode::NodeData *this,
        char a2)
{
  bool v3; // zf
  Scaleform::Render::StateBag *p_States; // ecx

  v3 = this->States.ArraySize == 0;
  p_States = &this->States;
  if ( !v3 )
    Scaleform::Render::StateData::destroyBag_NotEmpty(p_States);
  Scaleform::Render::ContextImpl::EntryData::~EntryData(&this->Scaleform::Render::ContextImpl::EntryData);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
