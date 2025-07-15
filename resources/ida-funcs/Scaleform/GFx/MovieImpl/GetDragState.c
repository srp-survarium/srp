void __thiscall Scaleform::GFx::MovieImpl::GetDragState(
        Scaleform::GFx::MovieImpl *this,
        unsigned int mouseIndex,
        Scaleform::GFx::MovieImpl::DragState *st)
{
  Scaleform::GFx::MovieImpl::DragState::operator=(st, &this->CurrentDragStates[mouseIndex]);
}
