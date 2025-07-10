void __thiscall Scaleform::GFx::AS2Support::DoActionLoader(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v3; // ecx
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned __int8 *pCurrent; // eax
  Scaleform::GFx::AS2::DoActionTag *v8; // esi

  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)tagInfo->TagType);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v3);
  pObject = p->pLoadData.pObject;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  p_TagMemAllocator = &pObject->TagMemAllocator;
  if ( BytesLeft < 8 )
  {
    pCurrent = Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 8u);
  }
  else
  {
    pCurrent = p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 8;
    p_TagMemAllocator->BytesLeft = BytesLeft - 8;
  }
  v8 = 0;
  if ( pCurrent )
  {
    *(_DWORD *)pCurrent = &Scaleform::GFx::AS2::DoActionTag::`vftable';
    *((_DWORD *)pCurrent + 1) = 0;
    v8 = (Scaleform::GFx::AS2::DoActionTag *)pCurrent;
  }
  Scaleform::GFx::AS2::DoActionTag::Read(v8, p);
  Scaleform::GFx::LoadProcess::AddExecuteTag(p, v8);
}
