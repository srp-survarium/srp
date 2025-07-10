void __thiscall Scaleform::GFx::GFx_PlaceObjectLoader(
        Scaleform::GFx::AS3::RefCountBaseGC<328> *this,
        Scaleform::GFx::Stream *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *p_DataSize; // ebp
  unsigned int v4; // eax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // ecx
  unsigned int BytesLeft; // edx
  unsigned int v7; // edi
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned int v9; // eax
  unsigned __int8 *pCurrent; // esi
  Scaleform::GFx::PlaceObjectTag *v11; // eax
  Scaleform::GFx::PlaceObjectTag *v12; // eax
  Scaleform::GFx::PlaceObjectTag *v13; // esi

  Scaleform::Render::JPEG::JPEGRwSource::TermSource(this);
  p_DataSize = *(Scaleform::GFx::SWFProcessInfo **)&p[1].BuiltinBuffer[204];
  if ( !p_DataSize )
    p_DataSize = (Scaleform::GFx::SWFProcessInfo *)&p->DataSize;
  v4 = Scaleform::GFx::PlaceObject3Tag::ComputeDataSize(&p_DataSize->Stream);
  v5 = (Scaleform::GFx::MovieDataDef::LoadTaskData *)p->TagStack[0];
  BytesLeft = v5->TagMemAllocator.BytesLeft;
  v7 = v4;
  p_TagMemAllocator = &v5->TagMemAllocator;
  v9 = (v4 + 10) & 0xFFFFFFFC;
  if ( v9 > BytesLeft )
  {
    v11 = (Scaleform::GFx::PlaceObjectTag *)Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, v9);
  }
  else
  {
    pCurrent = p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += v9;
    p_TagMemAllocator->BytesLeft = BytesLeft - v9;
    v11 = (Scaleform::GFx::PlaceObjectTag *)pCurrent;
  }
  if ( v11 )
  {
    Scaleform::GFx::PlaceObjectTag::PlaceObjectTag(v11);
    v13 = v12;
  }
  else
  {
    v13 = 0;
  }
  Scaleform::GFx::Stream::ReadToBuffer(&p_DataSize->Stream, v13->pData, v7);
  Scaleform::GFx::PlaceObjectTag::CheckForCxForm(v13, v7);
  Scaleform::GFx::LoadProcess::AddExecuteTag((Scaleform::GFx::LoadProcess *)p, v13);
}
