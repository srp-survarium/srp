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
  unsigned int i; // [esp+10h] [ebp-34h]
  Scaleform::GFx::StaticTextCharacter *v16; // [esp+14h] [ebp-30h]
  unsigned int v17; // [esp+18h] [ebp-2Ch]
  Scaleform::Render::Text::HighlightDesc merge; // [esp+1Ch] [ebp-28h] BYREF

  v4 = start;
  v6 = 0;
  v7 = 0;
  for ( i = end - start; v7 < this->StaticTextCharRefs.Data.Size; v6 = v8 )
  {
    v8 = v6 + this->StaticTextCharRefs.Data.Data[v7].CharCount;
    v17 = v8;
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
        v16 = pObject;
        if ( !pHighlight )
          pHighlight = Scaleform::GFx::StaticTextCharacter::CreateTextHighlighter(pObject);
        Raw = this->SelectColor.Raw;
        merge.Length = 0;
        merge.Offset = -1;
        memset(&merge.AdjStartPos, 0, 12);
        merge.Info.UnderlineColor.Raw = 0;
        merge.Info.TextColor.Raw = 0;
        merge.Info.Flags = 8;
        merge.Info.BackgroundColor.Raw = Raw;
        if ( v6 <= v4 )
          v12 = v4 - v6;
        else
          v12 = 0;
        Data = this->StaticTextCharRefs.Data.Data;
        merge.StartPos = v12;
        v14 = Data[v7].CharCount - v12;
        if ( i < v14 )
          v14 = i;
        merge.Length = v14;
        merge.GlyphNum = v14;
        merge.AdjStartPos = v12;
        if ( bselect )
          Scaleform::Render::Text::Highlighter::Add(&pHighlight->HighlightManager, &merge);
        else
          Scaleform::Render::Text::Highlighter::Remove(&pHighlight->HighlightManager, &merge);
        i -= merge.Length;
        Scaleform::GFx::StaticTextCharacter::RecreateVisibleTextLayout(v16);
        v4 = start;
        v8 = v17;
      }
    }
    ++v7;
  }
}
