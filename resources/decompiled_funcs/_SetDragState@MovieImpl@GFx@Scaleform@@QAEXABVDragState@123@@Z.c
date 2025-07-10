void __thiscall Scaleform::GFx::MovieImpl::SetDragState(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::GFx::MovieImpl::DragState *st)
{
  Scaleform::GFx::MovieImpl::DragState::operator=(&this->CurrentDragStates[st->MouseIndex], st);
}
