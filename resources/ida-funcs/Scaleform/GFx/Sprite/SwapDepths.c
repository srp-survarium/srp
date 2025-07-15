char __thiscall Scaleform::GFx::Sprite::SwapDepths(
        Scaleform::GFx::Sprite *this,
        int depth1,
        int depth2,
        unsigned int frame)
{
  return Scaleform::GFx::DisplayList::SwapDepths(&this->mDisplayList, this, depth1, depth2, frame);
}
