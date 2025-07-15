Scaleform::Ptr<Scaleform::Render::TreeNode> *__thiscall Scaleform::GFx::StaticTextCharacter::CreateRenderNode(
        Scaleform::GFx::StaticTextCharacter *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::TreeText::NodeData *v3; // eax
  Scaleform::Render::ContextImpl::EntryData *v4; // esi
  Scaleform::Render::TreeNode *EntryHelper; // eax

  v3 = (Scaleform::Render::TreeText::NodeData *)context->pHeap->Alloc(context->pHeap, 160, 0);
  v4 = v3;
  if ( v3 )
    Scaleform::Render::TreeText::NodeData::NodeData(v3);
  EntryHelper = (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::createEntryHelper(context, v4);
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
