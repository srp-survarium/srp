Scaleform::Ptr<Scaleform::Render::TreeNode> *__thiscall Scaleform::GFx::TextField::CreateRenderNode(
        Scaleform::GFx::TextField *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::TreeText::NodeData *v4; // eax
  Scaleform::Render::ContextImpl::EntryData *v5; // esi
  Scaleform::Render::TreeText *EntryHelper; // esi

  v4 = (Scaleform::Render::TreeText::NodeData *)context->pHeap->Alloc(context->pHeap, 160, 0);
  v5 = v4;
  if ( v4 )
    Scaleform::Render::TreeText::NodeData::NodeData(v4);
  EntryHelper = (Scaleform::Render::TreeText *)Scaleform::Render::ContextImpl::Context::createEntryHelper(context, v5);
  Scaleform::Render::TreeText::Init(EntryHelper, (Scaleform::GFx::Resource *)this->pDocument.pObject);
  if ( EntryHelper )
    ++EntryHelper->RefCount;
  result->pObject = EntryHelper;
  if ( EntryHelper )
  {
    if ( EntryHelper->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(EntryHelper);
  }
  return result;
}
