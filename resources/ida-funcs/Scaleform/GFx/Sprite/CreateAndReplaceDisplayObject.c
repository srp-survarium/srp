void __thiscall Scaleform::GFx::Sprite::CreateAndReplaceDisplayObject(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::DisplayObjectBase *pos,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::DisplayObjectBase **newChar)
{
  if ( newChar )
    *newChar = 0;
  Scaleform::GFx::DisplayObjContainer::CreateAndReplaceDisplayObject(this, pos, name, newChar);
  if ( newChar )
  {
    if ( *newChar )
      (*newChar)->CreateFrame = this->CurrentFrame;
  }
}
