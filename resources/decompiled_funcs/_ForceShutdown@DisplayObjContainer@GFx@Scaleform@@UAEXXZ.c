void __thiscall Scaleform::GFx::DisplayObjContainer::ForceShutdown(Scaleform::GFx::DisplayObjContainer *this)
{
  Scaleform::GFx::DisplayList::Clear(&this->mDisplayList, this);
}
