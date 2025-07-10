void __cdecl Scaleform::GFx::SkipButtonSoundDef(Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::LoadProcess *v1; // ebx
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  Scaleform::GFx::Stream *p_Stream; // edi
  int v4; // eax
  unsigned int Pos; // eax
  __int16 v6; // dx
  bool v7; // bl
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  unsigned int v12; // eax
  unsigned __int8 v13; // cl
  int v14; // edi
  int v15; // edx
  int v16; // ecx
  int v17; // edx
  bool HasLoops; // [esp+12h] [ebp-6h]
  bool HasEnvelope; // [esp+13h] [ebp-5h]
  int v20; // [esp+14h] [ebp-4h]

  v1 = p;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v20 = 4;
  do
  {
    p_Stream = v1->pAltStream;
    if ( !p_Stream )
      p_Stream = &v1->ProcessInfo.Stream;
    v4 = p_Stream->DataSize - p_Stream->Pos;
    p_Stream->UnusedBits = 0;
    if ( v4 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(p_Stream, 2);
    Pos = p_Stream->Pos;
    v6 = *(_WORD *)&p_Stream->pBuffer[Pos];
    p_Stream->Pos = Pos + 2;
    if ( v6 )
    {
      Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 2);
      Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1);
      Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1);
      HasEnvelope = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
      HasLoops = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
      v7 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
      if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
      {
        v8 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v8 < 4 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
        pAltStream->Stream.Pos += 4;
      }
      if ( v7 )
      {
        v9 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v9 < 4 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
        pAltStream->Stream.Pos += 4;
      }
      if ( HasLoops )
      {
        v10 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v10 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        pAltStream->Stream.Pos += 2;
      }
      if ( HasEnvelope )
      {
        v11 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v11 < 1 )
          Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
        v12 = pAltStream->Stream.Pos;
        v13 = pAltStream->Stream.pBuffer[v12];
        pAltStream->Stream.Pos = v12 + 1;
        if ( v13 )
        {
          v14 = v13;
          do
          {
            v15 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
            pAltStream->Stream.UnusedBits = 0;
            if ( v15 < 4 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
            pAltStream->Stream.Pos += 4;
            v16 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
            pAltStream->Stream.UnusedBits = 0;
            if ( v16 < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
            pAltStream->Stream.Pos += 2;
            v17 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
            pAltStream->Stream.UnusedBits = 0;
            if ( v17 < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
            pAltStream->Stream.Pos += 2;
            --v14;
          }
          while ( v14 );
        }
      }
      v1 = p;
    }
    --v20;
  }
  while ( v20 );
}
