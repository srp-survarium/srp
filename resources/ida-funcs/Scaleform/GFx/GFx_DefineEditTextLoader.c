void __stdcall Scaleform::GFx::GFx_DefineEditTextLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // eax
  unsigned __int8 *pBuffer; // ecx
  __int16 v6; // dx
  unsigned __int16 v7; // bx
  Scaleform::GFx::TextFieldDef *v8; // eax
  Scaleform::GFx::TextFieldDef *v9; // eax
  Scaleform::GFx::TextFieldDef *v10; // esi

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v3 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v3 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  pBuffer = pAltStream->Stream.pBuffer;
  v6 = pBuffer[Pos + 1];
  LOWORD(pBuffer) = pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  v7 = (unsigned __int16)pBuffer | (v6 << 8);
  v8 = (Scaleform::GFx::TextFieldDef *)p->pLoadData.pObject->pHeap->Alloc(p->pLoadData.pObject->pHeap, 96, 0);
  if ( v8 )
  {
    Scaleform::GFx::TextFieldDef::TextFieldDef(v8);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "EditTextChar, id = %d\n",
    v7);
  Scaleform::GFx::TextFieldDef::Read(v10, p, tagInfo->TagType);
  if ( p->LoadState == LS_LoadingRoot )
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(p->pLoadData.pObject, (Scaleform::GFx::ResourceId)v7, v10);
  if ( v10 )
    Scaleform::GFx::Resource::Release(v10);
}
