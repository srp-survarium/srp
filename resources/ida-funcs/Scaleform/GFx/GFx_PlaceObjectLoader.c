void __stdcall Scaleform::GFx::GFx_PlaceObjectLoader(Scaleform::GFx::Stream *p, const Scaleform::GFx::TagInfo *tagInfo)
{
  unsigned int *p_DataSize; // ebp
  int v3; // eax
  int v4; // ecx
  unsigned int v5; // edx
  unsigned int v6; // edi
  Scaleform::GFx::DataAllocator *v7; // ecx
  unsigned int v8; // eax
  unsigned __int8 *pCurrent; // esi
  unsigned __int8 *v10; // eax
  Scaleform::GFx::PlaceObjectTag *v11; // eax
  Scaleform::GFx::PlaceObjectTag *v12; // esi

  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p->CurrentByte,
    "  PlaceObject\n");
  p_DataSize = *(unsigned int **)&p[1].BuiltinBuffer[204];
  if ( !p_DataSize )
    p_DataSize = &p->DataSize;
  v3 = Scaleform::GFx::PlaceObjectTag::ComputeDataSize((Scaleform::GFx::Stream *)p_DataSize);
  v4 = p->TagStack[0];
  v5 = *(_DWORD *)(v4 + 12);
  v6 = v3;
  v7 = (Scaleform::GFx::DataAllocator *)(v4 + 8);
  v8 = (v3 + 10) & 0xFFFFFFFC;
  if ( v8 > v5 )
  {
    v10 = Scaleform::GFx::DataAllocator::OverflowAlloc(v7, v8);
  }
  else
  {
    pCurrent = v7->pCurrent;
    v7->pCurrent += v8;
    v7->BytesLeft = v5 - v8;
    v10 = pCurrent;
  }
  if ( v10 )
  {
    Scaleform::GFx::PlaceObjectTag::PlaceObjectTag((Scaleform::GFx::PlaceObjectTag *)v10);
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  Scaleform::GFx::Stream::ReadToBuffer((Scaleform::GFx::Stream *)p_DataSize, v12->pData, v6);
  Scaleform::GFx::PlaceObjectTag::CheckForCxForm(v12, v6);
  Scaleform::GFx::LoadProcess::AddExecuteTag((Scaleform::GFx::LoadProcess *)p, v12);
}
