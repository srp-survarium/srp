void *__cdecl CallCatchBlock(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext,
        const _s_FuncInfo *pFuncInfo,
        int CatchDepth,
        unsigned int NLGCode)
{
  void *handlerAddress; // ecx
  void *v7; // ebx
  void *v8; // eax
  unsigned int magicNumber; // eax
  FrameInfo FrameInfo; // [esp+10h] [ebp-3Ch] BYREF
  int ExceptionObjectDestroyed; // [esp+18h] [ebp-34h]
  _CONTEXT *pSaveExContext; // [esp+1Ch] [ebp-30h]
  EHExceptionRecord *pSaveException; // [esp+20h] [ebp-2Ch]
  FrameInfo *pFrameInfo; // [esp+24h] [ebp-28h]
  void *saveESP; // [esp+28h] [ebp-24h]
  void *continuationAddress; // [esp+30h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+34h] [ebp-18h]

  v7 = handlerAddress;
  continuationAddress = handlerAddress;
  ExceptionObjectDestroyed = 0;
  saveESP = (void *)pRN[-1].state;
  pFrameInfo = _CreateFrameInfo(&FrameInfo, pExcept->params.pExceptionObject);
  pSaveException = (EHExceptionRecord *)_getptd()->_curexception;
  pSaveExContext = (_CONTEXT *)_getptd()->_curcontext;
  _getptd()->_curexception = pExcept;
  _getptd()->_curcontext = pContext;
  ms_exc.registration.TryLevel = 1;
  _CallCatchBlock2(pRN, pFuncInfo, v7, CatchDepth, NLGCode);
  continuationAddress = v8;
  ms_exc.registration.TryLevel = -2;
  pRN[-1].state = (int)saveESP;
  _FindAndUnlinkFrame(pFrameInfo);
  _getptd()->_curexception = pSaveException;
  _getptd()->_curcontext = pSaveExContext;
  if ( pExcept->ExceptionCode == -529697949 && pExcept->NumberParameters == 3 )
  {
    magicNumber = pExcept->params.magicNumber;
    if ( (magicNumber == 429065504 || magicNumber == 429065505 || magicNumber == 429065506)
      && !ExceptionObjectDestroyed
      && continuationAddress
      && _IsExceptionObjectToBeDestroyed(pExcept->params.pExceptionObject) )
    {
      __DestructExceptionObject(pExcept);
    }
  }
  return continuationAddress;
}
