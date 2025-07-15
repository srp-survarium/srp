unsigned int __thiscall Scaleform::Render::Text::DocView::GetMaxVScroll(Scaleform::Render::Text::DocView *this)
{
  unsigned __int16 FormatCounter; // ax
  int v3; // ebx
  Scaleform::Render::Text::EditorKitBase *pObject; // ecx
  unsigned int Size; // edi
  Scaleform::Render::Text::LineBuffer::Line *v7; // ebp
  signed int v8; // edi
  Scaleform::Render::Text::LineBuffer::Line **Data; // edx
  Scaleform::Render::Text::LineBuffer::Line *v11; // ecx
  Scaleform::Render::Text::LineBuffer::Line **v12; // edx
  unsigned int Height; // ebp
  double v14; // st7
  Scaleform::Render::Text::LineBuffer::Line **i; // ecx
  unsigned int v16; // ecx
  unsigned __int16 v17; // ax
  float top; // [esp+4h] [ebp-4h]

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  FormatCounter = this->FormatCounter;
  if ( this->MaxVScroll.FormatCounter == FormatCounter )
    return this->MaxVScroll.Value;
  v3 = 0;
  if ( this->mLineBuffer.Lines.Data.Size )
  {
    pObject = this->pEditorKit.pObject;
    Size = this->mLineBuffer.Lines.Data.Size;
    v7 = this->mLineBuffer.Lines.Data.Data[Size - 1];
    v8 = Size - 1;
    if ( (!pObject || pObject->IsReadOnly(pObject))
      && !((v7->MemSize & 0x80000000) == 0 ? v7->Data32.TextLength : HIBYTE(v7->Data8.TextPosAndLength)) )
    {
      if ( v8 >= 0 )
        --v8;
      v3 = 1;
    }
    if ( v8 >= this->mLineBuffer.Lines.Data.Size || v8 < 0 )
    {
      v17 = this->FormatCounter;
      this->MaxVScroll.Value = 0;
      this->MaxVScroll.FormatCounter = v17;
      return this->MaxVScroll.Value;
    }
    else
    {
      Data = this->mLineBuffer.Lines.Data.Data;
      v11 = Data[v8];
      v12 = &Data[v8];
      if ( (v11->MemSize & 0x80000000) == 0 )
        Height = v11->Data32.Height;
      else
        Height = v11->Data8.Height;
      v14 = (double)(int)(Height + v11->Data32.OffsetY);
      for ( i = v12; v8 < this->mLineBuffer.Lines.Data.Size; --i )
      {
        if ( v8 < 0 )
          break;
        if ( v3 )
        {
          top = v14 - this->mLineBuffer.Geom.VisibleRect.y2 + this->mLineBuffer.Geom.VisibleRect.y1;
          if ( (double)(*i)->Data32.OffsetY < top )
            break;
        }
        --v8;
        ++v3;
      }
      v16 = this->mLineBuffer.Lines.Data.Size - v3;
      this->MaxVScroll.FormatCounter = this->FormatCounter;
      this->MaxVScroll.Value = v16;
      return v16;
    }
  }
  else
  {
    this->MaxVScroll.FormatCounter = FormatCounter;
    this->MaxVScroll.Value = 0;
    return 0;
  }
}
