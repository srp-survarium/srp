void __thiscall Scaleform::GFx::StaticTextSnapshotData::SetSelected(
        Scaleform::GFx::StaticTextSnapshotData *this,
        unsigned int start,
        unsigned int end,
        bool bselect)
{
  unsigned int v4; // edi
  unsigned int v6; // esi
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  Scaleform::GFx::StaticTextCharacter *pObject; // eax
  Scaleform::GFx::StaticTextCharacter::HighlightDesc *pHighlight; // ecx
  unsigned int Raw; // eax
  unsigned int v12; // edi
  Scaleform::GFx::StaticTextSnapshotData::CharRef *Data; // edx
  unsigned int v14; // edx
  unsigned int lenUnprocessed; // [esp+10h] [ebp-34h]
  Scaleform::GFx::StaticTextCharacter *pstc; // [esp+14h] [ebp-30h]
  unsigned int charEndIdx; // [esp+18h] [ebp-2Ch]
  Scaleform::Render::Text::HighlightDesc desc; // [esp+1Ch] [ebp-28h] BYREF

  v4 = start;
  v6 = 0;
  v7 = 0;
  for ( lenUnprocessed = end - start; v7 < this->StaticTextCharRefs.Data.Size; v6 = v8 )
  {
    v8 = v6 + this->StaticTextCharRefs.Data.Data[v7].CharCount;
    charEndIdx = v8;
    if ( v4 > v6 )
      goto LABEL_5;
    if ( v6 < end )
      goto LABEL_6;
    if ( v4 >= v6 )
    {
LABEL_5:
      if ( v4 < v8 )
      {
LABEL_6:
        pObject = this->StaticTextCharRefs.Data.Data[v7].pChar.pObject;
        pHighlight = pObject->pHighlight;
        pstc = pObject;
        if ( !pHighlight )
          pHighlight = Scaleform::GFx::StaticTextCharacter::CreateTextHighlighter(pObject);
        Raw = this->SelectColor.Raw;
        desc.Length = 0;
        desc.Offset = -1;
        memset(&desc.AdjStartPos, 0, 12);
        desc.Info.UnderlineColor.Raw = 0;
        desc.Info.TextColor.Raw = 0;
        desc.Info.Flags = 8;
        desc.Info.BackgroundColor.Raw = Raw;
        if ( v6 <= v4 )
          v12 = v4 - v6;
        else
          v12 = 0;
        Data = this->StaticTextCharRefs.Data.Data;
        desc.StartPos = v12;
        v14 = Data[v7].CharCount - v12;
        if ( lenUnprocessed < v14 )
          v14 = lenUnprocessed;
        desc.Length = v14;
        desc.GlyphNum = v14;
        desc.AdjStartPos = v12;
        if ( bselect )
          Scaleform::Render::Text::Highlighter::Add(&pHighlight->HighlightManager, &desc);
        else
          Scaleform::Render::Text::Highlighter::Remove(&pHighlight->HighlightManager, &desc);
        lenUnprocessed -= desc.Length;
        Scaleform::GFx::StaticTextCharacter::RecreateVisibleTextLayout(pstc);
        v4 = start;
        v8 = charEndIdx;
      }
    }
    ++v7;
  }
}
