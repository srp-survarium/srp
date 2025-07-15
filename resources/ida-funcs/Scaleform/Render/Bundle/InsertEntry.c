void __thiscall Scaleform::Render::Bundle::InsertEntry(
        Scaleform::Render::Bundle *this,
        unsigned int index,
        Scaleform::Render::BundleEntry *shape)
{
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::BundleEntry *,Scaleform::AllocatorLH<Scaleform::Render::BundleEntry *,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Entries,
    index,
    (Scaleform::Render::Text::LineBuffer::Line **)&shape);
}
