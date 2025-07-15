void __thiscall Scaleform::GFx::MovieImpl::AdvanceFrame(Scaleform::GFx::MovieImpl *this, int nextFrame, float framePos)
{
  const char *pPlayListHead; // eax
  bool v5; // bl
  Scaleform::GFx::InteractiveObject *v6; // esi
  const char *pPlayNext; // edi
  unsigned int v8; // eax
  unsigned int v9; // eax
  Scaleform::GFx::InteractiveObject *pPlayListOptHead; // ecx
  unsigned int Flags; // eax
  const char *pPlayNextOpt; // esi

  if ( (_BYTE)nextFrame )
    this->pASMovieRoot.pObject->OnNextFrame(this->pASMovieRoot.pObject);
  if ( (this->Flags & 0x80000) == 0 )
  {
    pPlayListOptHead = this->pPlayListOptHead;
    _mm_prefetch((const char *)&pPlayListOptHead->pPlayPrevOpt, 2);
    _mm_prefetch((const char *)&pPlayListOptHead->BlendMode, 2);
    _mm_prefetch((const char *)&pPlayListOptHead->32, 2);
    _mm_prefetch((const char *)pPlayListOptHead, 2);
    if ( pPlayListOptHead )
    {
      do
      {
        Flags = pPlayListOptHead->Flags;
        pPlayNextOpt = (const char *)pPlayListOptHead->pPlayNextOpt;
        _mm_prefetch(pPlayNextOpt + 96, 2);
        _mm_prefetch(pPlayNextOpt + 64, 2);
        _mm_prefetch(pPlayNextOpt + 32, 2);
        _mm_prefetch(pPlayNextOpt, 2);
        if ( (Flags & 0x400000) != 0 )
        {
          Scaleform::GFx::InteractiveObject::RemoveFromOptimizedPlayList(pPlayListOptHead);
        }
        else if ( (pPlayListOptHead->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x40) == 0
               && ((_BYTE)nextFrame || (Flags & 0x100000) != 0)
               && (pPlayListOptHead->Scaleform::GFx::DisplayObject::Flags & 0x20) == 0 )
        {
          ((void (__stdcall *)(int, _DWORD))pPlayListOptHead->AdvanceFrame)(nextFrame, LODWORD(framePos));
        }
        pPlayListOptHead = (Scaleform::GFx::InteractiveObject *)pPlayNextOpt;
      }
      while ( pPlayNextOpt );
    }
    goto LABEL_32;
  }
  pPlayListHead = (const char *)this->pPlayListHead;
  _mm_prefetch(pPlayListHead + 96, 2);
  _mm_prefetch(pPlayListHead + 64, 2);
  _mm_prefetch(pPlayListHead + 32, 2);
  _mm_prefetch(pPlayListHead, 2);
  this->pPlayListOptHead = 0;
  this->Flags &= ~0x80000u;
  v5 = (this->Flags2 & 8) == 0;
  if ( (this->Flags2 & 8) != 0 )
    this->Flags2 &= ~8u;
  else
    this->Flags2 |= 8u;
  v6 = this->pPlayListHead;
  if ( !v6 )
  {
LABEL_32:
    this->Flags2 &= ~2u;
    return;
  }
  do
  {
    pPlayNext = (const char *)v6->pPlayNext;
    _mm_prefetch(pPlayNext + 96, 2);
    _mm_prefetch(pPlayNext + 64, 2);
    _mm_prefetch(pPlayNext + 32, 2);
    _mm_prefetch(pPlayNext, 2);
    if ( !Scaleform::GFx::InteractiveObject::IsValidOptAdvListMember(v6, this) )
    {
      v6->Flags &= ~0x200000u;
      v8 = v6->Flags;
      if ( v5 )
        v9 = (unsigned int)&unk_800000 | v8;
      else
        v9 = v8 & 0xFF7FFFFF;
      v6->Flags = v9;
      v6->pPlayPrevOpt = 0;
      v6->pPlayNextOpt = 0;
    }
    if ( (v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x40) == 0
      && (v6->Scaleform::GFx::DisplayObject::Flags & 0x20) == 0 )
    {
      if ( !Scaleform::GFx::InteractiveObject::IsValidOptAdvListMember(v6, this) && v6->CheckAdvanceStatus(v6, 0) == 1 )
        Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v6);
      if ( (_BYTE)nextFrame || (v6->Flags & 0x100000) != 0 )
        ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, int, _DWORD))v6->AdvanceFrame)(
          v6,
          nextFrame,
          LODWORD(framePos));
    }
    v6 = (Scaleform::GFx::InteractiveObject *)pPlayNext;
  }
  while ( pPlayNext );
  this->Flags2 &= ~2u;
}
