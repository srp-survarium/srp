char __userpurge Scaleform::GFx::AS3ValueObjectInterface::GotoAndPlay@<al>(
        Scaleform::GFx::AS3ValueObjectInterface *this@<ecx>,
        int a2@<ebp>,
        _DWORD *pdata,
        const char *frame,
        bool stop)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // edi
  int v6; // eax
  _WORD *v8; // esi

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v6 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v6 + 60) - 17) >= 0xC || (*(_DWORD *)(v6 + 56) & 0x20) != 0 )
    return 0;
  v8 = (_WORD *)pdata[12];
  if ( (v8[31] & 0x400) == 0
    || !(*(unsigned __int8 (__thiscall **)(_WORD *, const char *, _DWORD **, int))(*(_DWORD *)v8 + 424))(
          v8,
          frame,
          &pdata,
          1) )
  {
    return 0;
  }
  (*(void (__thiscall **)(_WORD *, _DWORD *))(*(_DWORD *)v8 + 432))(v8, pdata);
  (*(void (__thiscall **)(_WORD *, bool))(*(_DWORD *)v8 + 448))(v8, stop);
  Scaleform::GFx::AS3::FrameCounter::QueueFrameActions((Scaleform::GFx::AS3::FrameCounter *)pObject->pStage.pObject->FrameCounterObj.pObject);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, a2, AL_Highest);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, a2, AL_High);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, a2, AL_Frame);
  return 1;
}
