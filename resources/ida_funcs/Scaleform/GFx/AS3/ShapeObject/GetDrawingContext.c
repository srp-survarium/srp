Scaleform::GFx::DrawingContext *__thiscall Scaleform::GFx::AS3::ShapeObject::GetDrawingContext(
        Scaleform::GFx::AS3::ShapeObject *this)
{
  Scaleform::GFx::DisplayObject *Mask; // eax
  Scaleform::GFx::DisplayObject *v3; // ebx
  Scaleform::GFx::DrawingContext *DrawingContext; // eax
  Scaleform::GFx::DrawingContext *pObject; // ecx
  Scaleform::GFx::DrawingContext *v6; // edi
  Scaleform::Render::TreeContainer *v7; // edi
  unsigned int Size; // eax
  Scaleform::Render::TreeContainer *v10; // [esp-Ch] [ebp-10h]

  if ( !this->pDrawing.pObject )
  {
    Mask = Scaleform::GFx::DisplayObject::GetMask(this);
    v3 = Mask;
    if ( Mask )
    {
      ++Mask->RefCount;
      Scaleform::GFx::DisplayObject::SetMask(this, 0);
    }
    DrawingContext = Scaleform::GFx::MovieImpl::CreateDrawingContext(this->pASRoot->pMovieImpl);
    pObject = this->pDrawing.pObject;
    v6 = DrawingContext;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    this->pDrawing.pObject = v6;
    v7 = Scaleform::GFx::DisplayObjectBase::ConvertToTreeContainer(this);
    Scaleform::Render::TreeContainer::Remove(v7, 0, 1u);
    v10 = this->pDrawing.pObject->pTreeContainer.pObject;
    Size = Scaleform::Render::TreeContainer::GetSize(v7);
    Scaleform::Render::TreeContainer::Insert(v7, Size, v10);
    if ( v3 )
    {
      Scaleform::GFx::DisplayObject::SetMask(this, v3);
      Scaleform::RefCountNTSImpl::Release(v3);
    }
  }
  return this->pDrawing.pObject;
}
