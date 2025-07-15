void __thiscall Scaleform::GFx::DisplayObjContainer::ReplaceDisplayObject(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::DisplayObjectBase *pos,
        Scaleform::GFx::InteractiveObject *ch,
        const Scaleform::GFx::ASString *name)
{
  if ( name->pNode->Size
    && (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x100) != 0 )
  {
    Scaleform::GFx::DisplayObject::SetName(ch, (int)name);
  }
  Scaleform::GFx::DisplayList::ReplaceDisplayObject(&this->mDisplayList, this, pos, ch);
  if ( name->pNode->Size && SLOBYTE(ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
    this->pASRoot->ResolveStickyVariables(this->pASRoot, ch);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this);
}
