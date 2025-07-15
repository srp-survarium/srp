void __thiscall Scaleform::GFx::AS3::MovieRoot::NotifyQueueSetFocus(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Sprite *ch,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::MovieImpl::TransferFocus(this->pMovieImpl, ch, controllerIdx, fmt);
}
