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
  unsigned int v11; // [esp+10h] [ebp-3Ch]
  unsigned int *p_StartPos; // [esp+14h] [ebp-38h]
  unsigned int Size; // [esp+18h] [ebp-34h]
  unsigned int v14; // [esp+20h] [ebp-2Ch]
  unsigned int v15; // [esp+24h] [ebp-28h]
  int v16; // [esp+28h] [ebp-24h]
  int v17; // [esp+2Ch] [ebp-20h]
  unsigned int v18; // [esp+38h] [ebp-14h]
  unsigned int v19; // [esp+3Ch] [ebp-10h]
  unsigned int v20; // [esp+40h] [ebp-Ch]
  unsigned int v21; // [esp+44h] [ebp-8h]
  unsigned __int8 v22; // [esp+48h] [ebp-4h]

  v1 = 0;
  HIDWORD(v2) = 0;
  v15 = -1;
  v16 = 0;
  v17 = -1;
  CurTextPos = 0;
  v18 = 0;
  v21 = 0;
  v20 = 0;
  v19 = 0;
  v22 = 0;
  do
  {
    pManager = this->pManager;
    LODWORD(v2) = -1;
    v11 = -1;
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
            if ( !v16 )
            {
              v15 = *p_StartPos;
              v16 = *((_DWORD *)p_Flags - 8);
              v17 = *((_DWORD *)p_Flags - 7);
              v18 = *((_DWORD *)p_Flags - 4);
              v19 = *((_DWORD *)p_Flags - 3);
              v20 = *((_DWORD *)p_Flags - 2);
              v21 = *((_DWORD *)p_Flags - 1);
              v1 = v7 - HIDWORD(v2) + *((_DWORD *)p_Flags - 5);
              CurTextPos = this->CurTextPos;
              v22 = *p_Flags;
              LODWORD(v2) = v11;
              if ( v7 + *((_DWORD *)p_Flags - 5) > v11 )
                v1 = v11 - HIDWORD(v2);
              goto LABEL_24;
            }
            if ( (this->Flags & *p_Flags) != this->Flags )
            {
              if ( (*p_Flags & 7) != 0 )
                v22 = *p_Flags & 7 | v22 & 0xF8;
              v8 = *p_Flags;
              if ( (*p_Flags & 8) != 0 )
              {
                v22 |= 8u;
                v19 = *((_DWORD *)p_Flags - 3);
              }
              if ( (v8 & 0x10) != 0 )
              {
                v22 |= 0x10u;
                v20 = *((_DWORD *)p_Flags - 2);
              }
              if ( (v8 & 0x20) != 0 )
              {
                v22 |= 0x20u;
                v21 = *((_DWORD *)p_Flags - 1);
              }
              v9 = CurTextPos + v1;
              if ( v14 < v9 )
                v9 = v14;
              v1 = v9 - CurTextPos;
              LODWORD(v2) = v1 + CurTextPos;
              v11 = v1 + CurTextPos;
              goto LABEL_24;
            }
          }
          LODWORD(v2) = v11;
        }
      }
LABEL_24:
      v10 = *((_DWORD *)p_Flags - 6);
      if ( v10 > HIDWORD(v2) )
      {
        if ( (unsigned int)v2 >= v10 )
        {
          LODWORD(v2) = *((_DWORD *)p_Flags - 6);
          v11 = v2;
        }
        if ( v16 )
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
    HIDWORD(v2) = v16;
LABEL_32:
    this->CurDesc.StartPos = v15;
    this->CurDesc.Offset = v17;
    this->CurDesc.Id = v18;
    this->CurDesc.Length = HIDWORD(v2);
    this->CurDesc.AdjStartPos = CurTextPos;
    this->CurDesc.GlyphNum = v1;
    this->CurDesc.Info.BackgroundColor.Raw = v19;
    this->CurDesc.Info.TextColor.Raw = v20;
    this->CurDesc.Info.UnderlineColor.Raw = v21;
    this->CurDesc.Info.Flags = v22;
    this->CurTextPos = v2;
  }
  while ( v2 < 0xFFFFFFFF );
}
