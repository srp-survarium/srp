Scaleform::String *__thiscall Scaleform::GFx::StaticTextSnapshotData::GetSelectedText(
        Scaleform::GFx::StaticTextSnapshotData *this,
        Scaleform::String *result,
        bool binclNewLines)
{
  Scaleform::String *v3; // ebp
  unsigned int v5; // edi
  unsigned int v6; // esi
  Scaleform::GFx::StaticTextCharacter::HighlightDesc *pHighlight; // ecx
  unsigned int v8; // eax
  unsigned int v9; // edi
  unsigned int Char_Advance0; // eax
  unsigned int v11; // eax
  int v13; // [esp+10h] [ebp-68h]
  unsigned int i; // [esp+14h] [ebp-64h]
  Scaleform::Render::Text::HighlightDesc v15; // [esp+18h] [ebp-60h] BYREF
  Scaleform::Render::Text::HighlighterRangeIterator resulta; // [esp+40h] [ebp-38h] BYREF

  v3 = result;
  Scaleform::String::String(result);
  v5 = 0;
  v6 = 0;
  v13 = 0;
  result = (Scaleform::String *)((this->SnapshotString.HeapTypeBits & 0xFFFFFFFC) + 8);
  for ( i = 0; v5 < this->StaticTextCharRefs.Data.Size; i = ++v5 )
  {
    pHighlight = this->StaticTextCharRefs.Data.Data[v5].pChar.pObject->pHighlight;
    if ( pHighlight )
    {
      Scaleform::Render::Text::Highlighter::GetRangeIterator(&pHighlight->HighlightManager, &resulta, 0, 0xFFFFFFFF);
      if ( !Scaleform::Render::Text::HighlighterRangeIterator::IsFinished(&resulta) )
      {
        do
        {
          Scaleform::Render::Text::HighlighterRangeIterator::operator*(&resulta, &v15);
          v8 = v13 + v15.StartPos;
          v9 = v15.Length + v13 + v15.StartPos;
          v15.StartPos += v13;
          if ( v9 > v6 )
          {
            if ( v6 < v8 )
            {
              do
              {
                Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&result);
                if ( Char_Advance0 )
                {
                  if ( Char_Advance0 == 10 )
                    --v6;
                }
                else
                {
                  result = (Scaleform::String *)((char *)result - 1);
                }
                ++v6;
              }
              while ( v6 < v15.StartPos );
            }
            if ( v6 < v9 )
            {
              while ( 1 )
              {
                v11 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&result);
                if ( !v11 )
                  result = (Scaleform::String *)((char *)result - 1);
                if ( binclNewLines )
                {
                  if ( v11 == 10 )
                  {
                    Scaleform::String::AppendChar(v3, 0xAu);
                  }
                  else
                  {
LABEL_18:
                    Scaleform::String::AppendChar(v3, v11);
                    if ( ++v6 >= v9 )
                      break;
                  }
                }
                else if ( v11 != 10 )
                {
                  goto LABEL_18;
                }
              }
            }
            v6 = v9;
          }
          Scaleform::Render::Text::HighlighterRangeIterator::operator++(&resulta, 0);
        }
        while ( !Scaleform::Render::Text::HighlighterRangeIterator::IsFinished(&resulta) );
        v5 = i;
      }
      v13 += this->StaticTextCharRefs.Data.Data[v5].CharCount;
    }
  }
  return v3;
}
