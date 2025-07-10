void __thiscall Scaleform::Render::Text::GFxLineCursor::operator+=(
        Scaleform::Render::Text::GFxLineCursor *this,
        unsigned int n)
{
  Scaleform::Render::Text::CompositionStringBase *pObject; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // edi
  unsigned int v6; // ebx
  unsigned int v7; // ebp
  unsigned int v8; // eax

  pObject = this->pComposStr.pObject;
  if ( pObject
    && pObject->GetLength(pObject)
    && (v4 = this->CharIter.CurTextIndex + this->pParagraph->StartIndex,
        v4 <= this->pComposStr.pObject->GetPosition(this->pComposStr.pObject)) )
  {
    v5 = n;
    if ( v4 + n >= this->pComposStr.pObject->GetPosition(this->pComposStr.pObject) )
    {
      v6 = this->pComposStr.pObject->GetPosition(this->pComposStr.pObject) - v4;
      if ( v6 >= n )
        v6 = n;
      v7 = this->ComposStrCurPos - v6 + n;
      if ( v7 <= this->pComposStr.pObject->GetLength(this->pComposStr.pObject) )
      {
        this->NumChars += n - v6;
        this->ComposStrCurPos = v7;
      }
      else
      {
        v6 = n + this->ComposStrCurPos - this->pComposStr.pObject->GetLength(this->pComposStr.pObject);
        v8 = this->pComposStr.pObject->GetLength(this->pComposStr.pObject);
        this->NumChars += v8;
        this->ComposStrCurPos = v8;
      }
      v5 = v6;
    }
  }
  else
  {
    v5 = n;
  }
  if ( v5 )
  {
    Scaleform::Render::Text::Paragraph::CharactersIterator::operator+=(&this->CharIter, v5);
    this->NumChars += v5;
  }
}
