Scaleform::GFx::MovieDefRootNode *__thiscall Scaleform::GFx::DisplayObjContainer::FindRootNode(
        Scaleform::GFx::DisplayObjContainer *this)
{
  if ( !this )
    return 0;
  while ( ((this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
          & 0x200) != 0
         ? (unsigned int)this
         : 0) == 0
       || !*((this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
            & 0x200) != 0
           ? &this->pRootNode
           : (Scaleform::GFx::MovieDefRootNode **)148) )
  {
    this = (Scaleform::GFx::DisplayObjContainer *)this->pParent;
    if ( !this )
      return 0;
  }
  return *((this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
          & 0x200) != 0
         ? &this->pRootNode
         : (Scaleform::GFx::MovieDefRootNode **)148);
}
