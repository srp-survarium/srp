Scaleform::Ptr<Scaleform::Render::TreeContainer> *__thiscall Scaleform::GFx::Button::CreateStateRenderContainer(
        Scaleform::GFx::Button *this,
        Scaleform::Ptr<Scaleform::Render::TreeContainer> *result,
        Scaleform::GFx::Button::ButtonState buttonState)
{
  Scaleform::Render::ContextImpl::Context *RenderContext; // ebx
  Scaleform::Render::TreeNode::NodeData *v5; // eax
  Scaleform::Render::TreeNode::NodeData *v6; // esi
  Scaleform::Render::ContextImpl::Entry *EntryHelper; // ebx
  __int32 v8; // eax
  Scaleform::Render::ContextImpl::Entry *v9; // ecx
  Scaleform::Render::TreeContainer **v10; // esi
  Scaleform::Ptr<Scaleform::Render::TreeContainer> *v12; // eax

  RenderContext = Scaleform::GFx::DisplayObjectBase::GetRenderContext(this);
  v5 = (Scaleform::Render::TreeNode::NodeData *)RenderContext->pHeap->Alloc(RenderContext->pHeap, 160u, 0);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::Render::TreeNode::NodeData::NodeData(v5, ET_Container);
    v6->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::TreeContainer::NodeData::`vftable';
    *(_DWORD *)&v6[1].Type = 0;
    v6[1].__vftable = 0;
  }
  EntryHelper = Scaleform::Render::ContextImpl::Context::createEntryHelper(
                  RenderContext,
                  &v6->Scaleform::Render::ContextImpl::EntryData);
  v8 = 16 * (buttonState + 8);
  v9 = *(Scaleform::Render::ContextImpl::Entry **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                 + v8);
  v10 = (Scaleform::Render::TreeContainer **)((char *)this + v8);
  if ( v9 )
  {
    if ( v9->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v9);
  }
  *v10 = (Scaleform::Render::TreeContainer *)EntryHelper;
  if ( EntryHelper )
    ++EntryHelper->RefCount;
  v12 = result;
  result->pObject = *v10;
  return v12;
}
