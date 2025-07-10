void __thiscall Scaleform::Render::Text::HighlighterRangeIterator::InitCurDesc(
        Scaleform::Render::Text::HighlighterRangeIterator *this)
{
  unsigned int v1; // esi
  unsigned __int64 v2; // rcx
  unsigned int CurTextPos; // ebp
  const Scaleform::Render::Text::Highlighter *pManager; // eax
  unsigned __int8 *p_Flags; // eax
  unsigned int v7; // edx
  unsigned __int8 v8; // dl
  unsigned int v9; // esi
  unsigned int v10; // edx
  unsigned int nearestNextPos; // [esp+10h] [ebp-3Ch]
  unsigned int *p_StartPos; // [esp+14h] [ebp-38h]
  unsigned int Size; // [esp+18h] [ebp-34h]
  unsigned int v14; // [esp+20h] [ebp-2Ch]
  unsigned int desc; // [esp+24h] [ebp-28h]
  int desc_4; // [esp+28h] [ebp-24h]
  int desc_8; // [esp+2Ch] [ebp-20h]
  unsigned int desc_20; // [esp+38h] [ebp-14h]
  unsigned int desc_24; // [esp+3Ch] [ebp-10h]
  unsigned int desc_28; // [esp+40h] [ebp-Ch]
  unsigned int desc_32; // [esp+44h] [ebp-8h]
  unsigned __int8 desc_36; // [esp+48h] [ebp-4h]

  v1 = 0;
  HIDWORD(v2) = 0;
  desc = -1;
  desc_4 = 0;
  desc_8 = -1;
  CurTextPos = 0;
  desc_20 = 0;
  desc_32 = 0;
  desc_28 = 0;
  desc_24 = 0;
  desc_36 = 0;
  do
  {
    pManager = this->pManager;
    LODWORD(v2) = -1;
    nearestNextPos = -1;
    if ( !this->pManager->Highlighters.Data.Size )
      goto LABEL_32;
    p_StartPos = &pManager->Highlighters.Data.Data->StartPos;
    p_Flags = &pManager->Highlighters.Data.Data->Info.Flags;
    Size = this->pManager->Highlighters.Data.Size;
    do
    {
      if ( (this->Flags & *p_Flags) == 0 )
        goto LABEL_30;
      HIDWORD(v2) = this->CurTextPos;
      if ( *((_DWORD *)p_Flags - 5) )
      {
        v7 = *((_DWORD *)p_Flags - 6);
        if ( HIDWORD(v2) >= v7 )
        {
          v14 = v7 + *((_DWORD *)p_Flags - 5);
          if ( HIDWORD(v2) < v14 )
          {
            if ( !desc_4 )
            {
              desc = *p_StartPos;
              desc_4 = *((_DWORD *)p_Flags - 8);
              desc_8 = *((_DWORD *)p_Flags - 7);
              desc_20 = *((_DWORD *)p_Flags - 4);
              desc_24 = *((_DWORD *)p_Flags - 3);
              desc_28 = *((_DWORD *)p_Flags - 2);
              desc_32 = *((_DWORD *)p_Flags - 1);
              v1 = v7 - HIDWORD(v2) + *((_DWORD *)p_Flags - 5);
              CurTextPos = this->CurTextPos;
              desc_36 = *p_Flags;
              LODWORD(v2) = nearestNextPos;
              if ( v7 + *((_DWORD *)p_Flags - 5) > nearestNextPos )
                v1 = nearestNextPos - HIDWORD(v2);
              goto LABEL_24;
            }
            if ( (this->Flags & *p_Flags) != this->Flags )
            {
              if ( (*p_Flags & 7) != 0 )
                desc_36 = *p_Flags & 7 | desc_36 & 0xF8;
              v8 = *p_Flags;
              if ( (*p_Flags & 8) != 0 )
              {
                desc_36 |= 8u;
                desc_24 = *((_DWORD *)p_Flags - 3);
              }
              if ( (v8 & 0x10) != 0 )
              {
                desc_36 |= 0x10u;
                desc_28 = *((_DWORD *)p_Flags - 2);
              }
              if ( (v8 & 0x20) != 0 )
              {
                desc_36 |= 0x20u;
                desc_32 = *((_DWORD *)p_Flags - 1);
              }
              v9 = CurTextPos + v1;
              if ( v14 < v9 )
                v9 = v14;
              v1 = v9 - CurTextPos;
              LODWORD(v2) = v1 + CurTextPos;
              nearestNextPos = v1 + CurTextPos;
              goto LABEL_24;
            }
          }
          LODWORD(v2) = nearestNextPos;
        }
      }
LABEL_24:
      v10 = *((_DWORD *)p_Flags - 6);
      if ( v10 > HIDWORD(v2) )
      {
        if ( (unsigned int)v2 >= v10 )
        {
          LODWORD(v2) = *((_DWORD *)p_Flags - 6);
          nearestNextPos = v2;
        }
        if ( desc_4 )
        {
          if ( v1 + CurTextPos > (unsigned int)v2 )
            v1 = v2 - CurTextPos;
        }
      }
LABEL_30:
      p_StartPos += 10;
      p_Flags += 40;
      --Size;
    }
    while ( Size );
    HIDWORD(v2) = desc_4;
LABEL_32:
    this->CurDesc.StartPos = desc;
    this->CurDesc.Offset = desc_8;
    this->CurDesc.Id = desc_20;
    this->CurDesc.Length = HIDWORD(v2);
    this->CurDesc.AdjStartPos = CurTextPos;
    this->CurDesc.GlyphNum = v1;
    this->CurDesc.Info.BackgroundColor.Raw = desc_24;
    this->CurDesc.Info.TextColor.Raw = desc_28;
    this->CurDesc.Info.UnderlineColor.Raw = desc_32;
    this->CurDesc.Info.Flags = desc_36;
    this->CurTextPos = v2;
  }
  while ( v2 < 0xFFFFFFFF );
}
