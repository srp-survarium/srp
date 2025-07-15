void __usercall Scaleform::GFx::MovieImpl::UpdateAllDrawingContexts(
        Scaleform::GFx::MovieImpl *this@<ecx>,
        int a2@<ebx>)
{
  Scaleform::GFx::DrawingContext *pNext; // esi
  Scaleform::List<Scaleform::GFx::DrawingContext,Scaleform::GFx::DrawingContext> *p_DrawingContextList; // edi
  int v4; // eax

  pNext = this->DrawingContextList.Root.pNext;
  p_DrawingContextList = &this->DrawingContextList;
  while ( 1 )
  {
    v4 = p_DrawingContextList ? (int)&p_DrawingContextList[-1] : 0;
    if ( pNext == (Scaleform::GFx::DrawingContext *)v4 )
      break;
    if ( (pNext->States & 0x80u) != 0 )
      Scaleform::GFx::DrawingContext::UpdateRenderNode(pNext, a2);
    pNext = pNext->pNext;
  }
}
