void __thiscall Scaleform::GFx::DisplayObjContainer::MoveDisplayObject(
        Scaleform::GFx::DisplayObjContainer *this,
        const Scaleform::GFx::CharPosInfo *pos)
{
  Scaleform::GFx::DisplayList::MoveDisplayObject(&this->mDisplayList, this, pos);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this);
}
