void __thiscall Scaleform::Render::Text::Highlighter::Remove(
        Scaleform::Render::Text::Highlighter *this,
        const Scaleform::Render::Text::HighlightDesc *cut)
{
  const Scaleform::Render::Text::HighlightDesc *v2; // edx
  unsigned int v3; // edi
  Scaleform::Render::Text::HighlightDesc *Data; // ebp
  unsigned int Size; // eax
  Scaleform::Render::Text::HighlightDesc *v7; // eax
  unsigned int StartPos; // edx
  unsigned int v9; // ebp
  unsigned int v10; // ecx
  unsigned int v11; // edx
  unsigned int Raw; // edx
  unsigned int v13; // edx
  unsigned __int8 Flags; // al
  unsigned int v15; // edx
  Scaleform::Render::Text::HighlightDesc *v16; // edi
  unsigned int v17; // ebp
  int v18; // [esp+10h] [ebp-3Ch]
  unsigned int i; // [esp+14h] [ebp-38h]
  Scaleform::Array<Scaleform::Render::Text::HighlightDesc,2,Scaleform::ArrayDefaultPolicy> addDescs; // [esp+18h] [ebp-34h] BYREF
  Scaleform::Render::Text::HighlightDesc newdesc; // [esp+24h] [ebp-28h] BYREF

  v2 = cut;
  v3 = cut->StartPos + cut->Length;
  Data = 0;
  Size = 0;
  memset(&addDescs, 0, sizeof(addDescs));
  i = 0;
  if ( this->Highlighters.Data.Size )
  {
    v18 = 0;
    while ( 1 )
    {
      v7 = &this->Highlighters.Data.Data[v18];
      StartPos = v2->StartPos;
      v9 = v7->StartPos;
      v10 = v7->StartPos + v7->Length;
      if ( v7->StartPos < StartPos )
      {
        if ( StartPos < v10 )
        {
          if ( v3 >= v10 )
          {
            v7->Length += StartPos - v10;
LABEL_14:
            v7->GlyphNum = v7->Length;
            goto LABEL_15;
          }
          v11 = StartPos - v9;
          v7->Length = v11;
          v7->GlyphNum = v11;
          newdesc.Offset = v7->Offset;
          newdesc.Id = v7->Id;
          newdesc.Info.BackgroundColor.Raw = v7->Info.BackgroundColor.Raw;
          Raw = v7->Info.TextColor.Raw;
          newdesc.Length = v10 - v3;
          newdesc.GlyphNum = v10 - v3;
          newdesc.Info.TextColor.Raw = Raw;
          v13 = v7->Info.UnderlineColor.Raw;
          Flags = v7->Info.Flags;
          newdesc.Info.UnderlineColor.Raw = v13;
          newdesc.Info.Flags = Flags;
          newdesc.StartPos = v3;
          newdesc.AdjStartPos = v3;
          Scaleform::ArrayData<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorGH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
            &addDescs.Data,
            &newdesc);
          goto LABEL_15;
        }
        if ( v9 < StartPos )
          goto LABEL_16;
      }
      if ( v9 >= v3 )
        goto LABEL_16;
      if ( v10 > v3 )
      {
        v7->StartPos = v3;
        v15 = v7->StartPos;
        v7->Length -= v3 - v9;
        v7->AdjStartPos = v15;
        goto LABEL_14;
      }
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        &this->Highlighters,
        i);
      --v18;
      --i;
LABEL_15:
      this->HasUnderline = 0;
      this->Valid = 0;
LABEL_16:
      ++v18;
      if ( ++i >= this->Highlighters.Data.Size )
      {
        Size = addDescs.Data.Size;
        Data = addDescs.Data.Data;
        break;
      }
      v2 = cut;
    }
  }
  if ( Size )
  {
    v16 = Data;
    v17 = Size;
    do
    {
      Scaleform::Render::Text::Highlighter::CreateNewHighlighter(this, v16++);
      --v17;
    }
    while ( v17 );
    Data = addDescs.Data.Data;
  }
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
}
