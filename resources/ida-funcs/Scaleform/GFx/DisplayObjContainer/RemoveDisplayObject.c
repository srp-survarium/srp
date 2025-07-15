void __thiscall Scaleform::GFx::DisplayObjContainer::RemoveDisplayObject(
        Scaleform::GFx::DisplayObjContainer *this,
        int depth,
        Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::DisplayList::RemoveDisplayObject(&this->mDisplayList, this, depth, id);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this);
}


void __thiscall Scaleform::GFx::DisplayObjContainer::RemoveDisplayObject(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::DisplayObjectBase *ch)
{
  Scaleform::GFx::DisplayList *p_mDisplayList; // edi
  signed int DisplayIndex; // eax

  p_mDisplayList = &this->mDisplayList;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(&this->mDisplayList, ch);
  if ( DisplayIndex >= 0 )
    Scaleform::GFx::DisplayList::RemoveEntryAtIndex(p_mDisplayList, this, DisplayIndex);
}
