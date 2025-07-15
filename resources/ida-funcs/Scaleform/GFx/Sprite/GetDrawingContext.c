Scaleform::GFx::DrawingContext *__thiscall Scaleform::GFx::Sprite::GetDrawingContext(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::DisplayObject *Mask; // eax
  Scaleform::GFx::DisplayObject *v3; // edi
  Scaleform::GFx::DrawingContext *DrawingContext; // eax
  Scaleform::GFx::DrawingContext *pObject; // ecx
  Scaleform::GFx::DrawingContext *v6; // ebx
  Scaleform::Render::TreeContainer *v7; // eax

  if ( !this->pDrawingAPI.pObject )
  {
    Mask = Scaleform::GFx::DisplayObject::GetMask(this);
    v3 = Mask;
    if ( Mask )
    {
      ++Mask->RefCount;
      Scaleform::GFx::DisplayObject::SetMask(this, 0);
    }
    DrawingContext = Scaleform::GFx::MovieImpl::CreateDrawingContext(this->pASRoot->pMovieImpl);
    pObject = this->pDrawingAPI.pObject;
    v6 = DrawingContext;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    this->pDrawingAPI.pObject = v6;
    v7 = Scaleform::GFx::DisplayObjectBase::ConvertToTreeContainer(this);
    Scaleform::Render::TreeContainer::Insert(v7, 0, this->pDrawingAPI.pObject->pTreeContainer.pObject);
    if ( v3 )
    {
      Scaleform::GFx::DisplayObject::SetMask(this, v3);
      Scaleform::RefCountNTSImpl::Release(v3);
    }
  }
  return this->pDrawingAPI.pObject;
}
