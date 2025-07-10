Scaleform::GFx::DrawingContext *__thiscall Scaleform::GFx::MovieImpl::CreateDrawingContext(
        Scaleform::GFx::MovieImpl *this)
{
  char v2; // bl
  Scaleform::GFx::DrawingContext *v3; // edi
  Scaleform::GFx::ImageCreator *v4; // ebp
  Scaleform::GFx::DrawingContext *v5; // eax
  Scaleform::GFx::DrawingContext *v6; // edi
  Scaleform::GFx::DrawingContext *pPrev; // edx

  v2 = 0;
  v3 = (Scaleform::GFx::DrawingContext *)this->pHeap->Alloc(this->pHeap, 160, 0);
  if ( v3 )
  {
    v2 = 1;
    v4 = (Scaleform::GFx::ImageCreator *)this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 11);
    Scaleform::GFx::DrawingContext::DrawingContext(v3, this->pHeap, &this->RenderContext, v4);
    v6 = v5;
  }
  else
  {
    v4 = 0;
    v6 = 0;
  }
  if ( (v2 & 1) != 0 && v4 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
  pPrev = this->DrawingContextList.Root.pPrev;
  v6->pNext = (Scaleform::GFx::DrawingContext *)&this->RegisteredFonts.Data.Size;
  v6->pPrev = pPrev;
  this->DrawingContextList.Root.pPrev->pNext = v6;
  this->DrawingContextList.Root.pPrev = v6;
  return v6;
}
