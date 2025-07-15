void __thiscall Scaleform::GFx::MovieImpl::ClearDrawingContextList(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::DrawingContext *pNext; // eax
  Scaleform::List<Scaleform::GFx::DrawingContext,Scaleform::GFx::DrawingContext> *p_DrawingContextList; // ecx
  int v3; // edx
  Scaleform::GFx::DrawingContext *v4; // edx

  pNext = this->DrawingContextList.Root.pNext;
  p_DrawingContextList = &this->DrawingContextList;
  while ( 1 )
  {
    v3 = p_DrawingContextList ? (int)&p_DrawingContextList[-1] : 0;
    if ( pNext == (Scaleform::GFx::DrawingContext *)v3 )
      break;
    v4 = pNext->pNext;
    pNext->pNext = 0;
    pNext->pPrev = 0;
    pNext = v4;
  }
  if ( p_DrawingContextList )
  {
    p_DrawingContextList->Root.pNext = (Scaleform::GFx::DrawingContext *)&p_DrawingContextList[-1];
    p_DrawingContextList->Root.pPrev = (Scaleform::GFx::DrawingContext *)&p_DrawingContextList[-1];
  }
  else
  {
    MEMORY[4] = 0;
    MEMORY[0] = 0;
  }
}
