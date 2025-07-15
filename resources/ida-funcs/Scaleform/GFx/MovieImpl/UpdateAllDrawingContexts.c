void __thiscall Scaleform::GFx::MovieImpl::UpdateAllDrawingContexts(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::DrawingContext *pNext; // esi
  Scaleform::List<Scaleform::GFx::DrawingContext,Scaleform::GFx::DrawingContext> *p_DrawingContextList; // edi
  int v3; // eax

  pNext = this->DrawingContextList.Root.pNext;
  p_DrawingContextList = &this->DrawingContextList;
  while ( 1 )
  {
    v3 = p_DrawingContextList ? (int)&p_DrawingContextList[-1] : 0;
    if ( pNext == (Scaleform::GFx::DrawingContext *)v3 )
      break;
    if ( (pNext->States & 0x80u) != 0 )
      Scaleform::GFx::DrawingContext::UpdateRenderNode(pNext);
    pNext = pNext->pNext;
  }
}
