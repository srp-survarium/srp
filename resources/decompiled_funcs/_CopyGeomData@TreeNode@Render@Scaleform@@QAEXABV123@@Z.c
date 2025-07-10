void __thiscall Scaleform::Render::TreeNode::CopyGeomData(
        Scaleform::Render::TreeNode *this,
        const Scaleform::Render::TreeNode *src)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 3u);
  ((void (__thiscall *)(Scaleform::Render::ContextImpl::EntryData *, Scaleform::Render::TreeNode *, const Scaleform::Render::TreeNode *))WritableData->__vftable[1].ConstructCopy)(
    WritableData,
    this,
    src);
}
