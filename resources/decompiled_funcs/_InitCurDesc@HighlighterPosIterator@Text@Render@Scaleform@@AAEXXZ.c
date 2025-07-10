void __thiscall Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(
        Scaleform::Render::Text::HighlighterPosIterator *this)
{
  unsigned __int8 v1; // al
  unsigned __int8 *p_Flags; // esi
  int v3; // ebx
  unsigned int v4; // edx
  unsigned int v5; // edi
  unsigned __int8 v6; // bl
  unsigned int v7; // eax
  unsigned int CurAdjStartPos; // eax
  unsigned int Size; // [esp+4h] [ebp-2Ch]
  unsigned int desc_24; // [esp+20h] [ebp-10h]
  unsigned int desc_28; // [esp+24h] [ebp-Ch]
  unsigned int desc_32; // [esp+28h] [ebp-8h]

  if ( this->CurAdjStartPos >= this->NumGlyphs )
  {
    this->CurDesc.Info.UnderlineColor.Raw = 0;
    this->CurDesc.Info.TextColor.Raw = 0;
    this->CurDesc.Info.BackgroundColor.Raw = 0;
    this->CurDesc.Info.Flags = 0;
    this->CurDesc.GlyphNum = 0;
    CurAdjStartPos = this->CurAdjStartPos;
    this->CurDesc.Id = 0;
    this->CurDesc.AdjStartPos = CurAdjStartPos;
  }
  else
  {
    v1 = 0;
    desc_32 = 0;
    desc_28 = 0;
    desc_24 = 0;
    if ( this->pManager->Highlighters.Data.Size )
    {
      p_Flags = &this->pManager->Highlighters.Data.Data->Info.Flags;
      Size = this->pManager->Highlighters.Data.Size;
      do
      {
        v3 = *((_DWORD *)p_Flags - 5);
        if ( v3 )
        {
          v4 = *((_DWORD *)p_Flags - 6);
          v5 = this->CurAdjStartPos;
          if ( v5 >= v4 && v5 < v3 + v4 )
          {
            v6 = *p_Flags;
            if ( (*p_Flags & 7) != 0 )
              v1 = *p_Flags & 7 | v1 & 0xF8;
            if ( (v6 & 8) != 0 )
            {
              v1 |= 8u;
              desc_24 = *((_DWORD *)p_Flags - 3);
            }
            if ( (v6 & 0x10) != 0 )
            {
              v1 |= 0x10u;
              desc_28 = *((_DWORD *)p_Flags - 2);
            }
            if ( (v6 & 0x20) != 0 )
            {
              v1 |= 0x20u;
              desc_32 = *((_DWORD *)p_Flags - 1);
            }
          }
        }
        p_Flags += 40;
        --Size;
      }
      while ( Size );
    }
    this->CurDesc.StartPos = -1;
    this->CurDesc.Offset = -1;
    this->CurDesc.Length = 0;
    this->CurDesc.AdjStartPos = 0;
    this->CurDesc.Id = 0;
    this->CurDesc.Info.BackgroundColor.Raw = desc_24;
    this->CurDesc.Info.TextColor.Raw = desc_28;
    this->CurDesc.Info.UnderlineColor.Raw = desc_32;
    this->CurDesc.Info.Flags = v1;
    v7 = this->CurAdjStartPos;
    this->CurDesc.Id = 0;
    this->CurDesc.GlyphNum = 1;
    this->CurDesc.AdjStartPos = v7;
  }
}
