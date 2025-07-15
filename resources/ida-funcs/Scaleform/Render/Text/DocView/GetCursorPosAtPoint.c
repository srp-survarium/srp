int __thiscall Scaleform::Render::Text::DocView::GetCursorPosAtPoint(
        Scaleform::Render::Text::DocView *this,
        float x,
        float y)
{
  Scaleform::Render::Text::LineBuffer *pLineBuffer; // eax
  signed int CurrentPos; // ecx
  int yoff; // [esp+Ch] [ebp-2Ch]
  Scaleform::Render::Text::LineBuffer::Iterator result; // [esp+10h] [ebp-28h] BYREF
  float v9; // [esp+30h] [ebp-8h]
  int v10; // [esp+34h] [ebp-4h]
  float relativeOffsetX; // [esp+3Ch] [ebp+4h]
  float v12; // [esp+40h] [ebp+8h]

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  relativeOffsetX = x - (this->mLineBuffer.Geom.VisibleRect.x1 - this->ViewRect.x1);
  v12 = y - (this->mLineBuffer.Geom.VisibleRect.y1 - this->ViewRect.y1);
  *(float *)&yoff = (double)(unsigned int)Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(&this->mLineBuffer)
                  + v12;
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(&this->mLineBuffer, &result, yoff);
  pLineBuffer = result.pLineBuffer;
  if ( !result.pLineBuffer
    || (CurrentPos = result.CurrentPos, result.CurrentPos >= result.pLineBuffer->Lines.Data.Size)
    || (result.CurrentPos & 0x80000000) != 0 )
  {
    result.pHighlight = 0;
    v9 = 0.0;
    result.YOffset = 0.0;
    if ( v12 > 0.0 )
      CurrentPos = this->mLineBuffer.Lines.Data.Size - 1;
    else
      CurrentPos = 0;
    LOBYTE(v10) = (this->mLineBuffer.Geom.Flags & 4) != 0;
    pLineBuffer = &this->mLineBuffer;
    *(_DWORD *)&result.StaticText = v10;
    result.CurrentPos = CurrentPos;
    result.pLineBuffer = &this->mLineBuffer;
  }
  if ( pLineBuffer && CurrentPos < pLineBuffer->Lines.Data.Size && CurrentPos >= 0 )
    return Scaleform::Render::Text::DocView::GetCursorPosInLineByOffset(this, CurrentPos, relativeOffsetX);
  else
    return -(this->mLineBuffer.Lines.Data.Size != 0);
}
