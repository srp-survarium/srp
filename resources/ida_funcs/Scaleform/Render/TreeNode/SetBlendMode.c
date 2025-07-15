void __thiscall Scaleform::Render::TreeNode::SetBlendMode(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::BlendMode mode)
{
  Scaleform::Render::StateBag *WritableData; // eax

  WritableData = (Scaleform::Render::StateBag *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                                  this,
                                                  (unsigned int)&loc_20000);
  if ( mode )
    Scaleform::Render::StateBag::SetStateVoid(
      WritableData + 8,
      &Scaleform::Render::BlendState::InterfaceImpl,
      (void *)mode);
  else
    Scaleform::Render::StateBag::RemoveState(WritableData + 8, State_Translator);
}
