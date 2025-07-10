void __thiscall Scaleform::GFx::DisplayObjContainer::RemoveDisplayObject(
        Scaleform::GFx::DisplayObjContainer *this,
        int depth,
        Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::DisplayList::RemoveDisplayObject(&this->mDisplayList, this, depth, id);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this);
}
