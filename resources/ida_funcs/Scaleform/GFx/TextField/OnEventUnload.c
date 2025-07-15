void __thiscall Scaleform::GFx::TextField::OnEventUnload(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::RefCountVImpl *v4; // eax
  Scaleform::Render::TreeText *RenderNode; // eax

  pASRoot = this->pASRoot;
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x1000u;
  pMovieImpl = pASRoot->pMovieImpl;
  if ( pMovieImpl )
  {
    v4 = (Scaleform::RefCountVImpl *)pMovieImpl->GetStateAddRef(&pMovieImpl->Scaleform::GFx::StateBag, State_IMEManager);
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
  }
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  Scaleform::GFx::InteractiveObject::OnEventUnload(this);
}
