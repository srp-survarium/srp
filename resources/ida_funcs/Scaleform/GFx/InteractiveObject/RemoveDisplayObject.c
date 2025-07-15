void __thiscall Scaleform::GFx::InteractiveObject::RemoveDisplayObject(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::DisplayObjContainer *pParent; // edx

  pParent = (Scaleform::GFx::DisplayObjContainer *)this->pParent;
  if ( pParent )
  {
    if ( ((pParent->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
         & 0x200) != 0
        ? (unsigned int)pParent
        : 0) != 0 )
      Scaleform::GFx::DisplayObjContainer::RemoveDisplayObject(
        (pParent->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
       & 0x200) != 0
      ? pParent
      : 0,
        this->Depth,
        this->Id);
  }
}
