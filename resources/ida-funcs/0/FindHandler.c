void __cdecl FindHandler(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext,
        void *pDC,
        const _s_FuncInfo *pFuncInfo,
        unsigned __int8 recursive,
        int CatchDepth,
        EHRegistrationNode *pMarkerRN)
{
  const _s_FuncInfo *v8; // ebx
  int maxState; // eax
  int state; // ecx
  EHExceptionRecord *curexception; // esi
  int arrayOfCatchableTypes; // ebx
  unsigned int magicNumber; // eax
  unsigned int v14; // eax
  const _s_ESTypeList *curexcspec; // edi
  int v16; // esi
  int v17; // ebx
  unsigned int v18; // eax
  const _s_FuncInfo *v19; // edi
  const _s_TryBlockMapEntry *v20; // edi
  const _s_CatchableTypeArray *pCatchableTypeArray; // eax
  const _s_ESTypeList *pESTypeList; // edi
  const _s_ThrowInfo *pThrowInfo; // [esp-4h] [ebp-3Ch]
  std::bad_exception v24; // [esp+Ch] [ebp-2Ch] BYREF
  _EXCEPTION_REGISTRATION_RECORD *v25; // [esp+18h] [ebp-20h]
  unsigned int pEnd; // [esp+1Ch] [ebp-1Ch] BYREF
  int nCatches; // [esp+20h] [ebp-18h]
  int nCatchableTypes; // [esp+24h] [ebp-14h]
  unsigned int pStart; // [esp+28h] [ebp-10h] BYREF
  _s_HandlerType *pHandlerArray; // [esp+2Ch] [ebp-Ch]
  int curState; // [esp+30h] [ebp-8h]
  char v32; // [esp+37h] [ebp-1h]

  v8 = pFuncInfo;
  maxState = pFuncInfo->maxState;
  v32 = 0;
  if ( maxState > 128 )
    state = pRN->state;
  else
    state = SLOBYTE(pRN->state);
  curState = state;
  if ( state < -1 || state >= maxState )
    _inconsistency();
  curexception = pExcept;
  if ( pExcept->ExceptionCode != -529697949 )
  {
LABEL_61:
    if ( v8->nTryBlocks )
    {
      if ( recursive )
        goto LABEL_28;
      FindHandlerForForeignException(curexception, pRN, pContext, pDC, v8, curState, CatchDepth, pMarkerRN);
    }
    goto LABEL_64;
  }
  arrayOfCatchableTypes = 429065504;
  if ( pExcept->NumberParameters == 3 )
  {
    magicNumber = pExcept->params.magicNumber;
    if ( (magicNumber == 429065504 || magicNumber == 429065505 || magicNumber == 429065506)
      && !pExcept->params.pThrowInfo )
    {
      if ( !_getptd()->_curexception )
        return;
      curexception = (EHExceptionRecord *)_getptd()->_curexception;
      pExcept = curexception;
      pContext = (_CONTEXT *)_getptd()->_curcontext;
      if ( !_ValidateRead((int (__stdcall *)())curexception) )
        _inconsistency();
      if ( curexception->ExceptionCode == -529697949 && curexception->NumberParameters == 3 )
      {
        v14 = curexception->params.magicNumber;
        if ( (v14 == 429065504 || v14 == 429065505 || v14 == 429065506) && !curexception->params.pThrowInfo )
          _inconsistency();
      }
      if ( _getptd()->_curexcspec )
      {
        curexcspec = (const _s_ESTypeList *)_getptd()->_curexcspec;
        v16 = 0;
        _getptd()->_curexcspec = 0;
        if ( !IsInExceptionSpec(curexcspec, pExcept) )
        {
          v17 = 0;
          if ( curexcspec->nCount > 0 )
          {
            do
            {
              if ( type_info::operator==(
                     (type_info *)curexcspec->pTypeArray[v17].pType,
                     (const type_info *)&std::bad_exception `RTTI Type Descriptor') )
              {
                __DestructExceptionObject(pExcept);
                std::bad_exception::bad_exception(&v24, "bad exception");
                _CxxThrowException((DWORD)&v24, (const _s__ThrowInfo *)&_TI2_AVbad_exception_std__);
              }
              ++v16;
              ++v17;
            }
            while ( v16 < curexcspec->nCount );
          }
LABEL_28:
          terminate();
        }
        curexception = pExcept;
      }
    }
  }
  if ( curexception->ExceptionCode != -529697949
    || curexception->NumberParameters != 3
    || (v18 = curexception->params.magicNumber, v18 != 429065504) && v18 != 429065505 && v18 != 429065506 )
  {
    v8 = pFuncInfo;
    goto LABEL_61;
  }
  v19 = pFuncInfo;
  if ( pFuncInfo->nTryBlocks )
  {
    v20 = _GetRangeOfTrysToCheck(pFuncInfo, CatchDepth, curState, &pStart, &pEnd);
    while ( pStart < pEnd )
    {
      if ( v20->tryLow <= curState && curState <= v20->tryHigh )
      {
        pHandlerArray = (_s_HandlerType *)v20->pHandlerArray;
        nCatches = v20->nCatches;
        if ( nCatches > 0 )
        {
          while ( 1 )
          {
            pCatchableTypeArray = curexception->params.pThrowInfo->pCatchableTypeArray;
            arrayOfCatchableTypes = (int)pCatchableTypeArray->arrayOfCatchableTypes;
            nCatchableTypes = pCatchableTypeArray->nCatchableTypes;
            if ( nCatchableTypes > 0 )
              break;
LABEL_45:
            --nCatches;
            ++pHandlerArray;
            if ( nCatches <= 0 )
              goto NextTryBlock;
          }
          while ( 1 )
          {
            pThrowInfo = curexception->params.pThrowInfo;
            v25 = *(_EXCEPTION_REGISTRATION_RECORD **)arrayOfCatchableTypes;
            if ( __TypeMatch(pHandlerArray, (const _s_CatchableType *)v25, pThrowInfo) )
              break;
            --nCatchableTypes;
            arrayOfCatchableTypes += 4;
            if ( nCatchableTypes <= 0 )
              goto LABEL_45;
          }
          arrayOfCatchableTypes = (int)pHandlerArray;
          v32 = 1;
          CatchIt(
            pRN,
            pHandlerArray,
            v20,
            curexception,
            pContext,
            pDC,
            pFuncInfo,
            (const _s_CatchableType *)v25,
            CatchDepth,
            pMarkerRN);
          curexception = pExcept;
        }
      }
NextTryBlock:
      ++pStart;
      ++v20;
    }
    v19 = pFuncInfo;
  }
  if ( recursive )
    __DestructExceptionObject(curexception);
  if ( !v32 && (*(_DWORD *)v19 & 0x1FFFFFFFu) >= 0x19930521 )
  {
    pESTypeList = v19->pESTypeList;
    if ( pESTypeList )
    {
      if ( !IsInExceptionSpec(pESTypeList, curexception) )
      {
        _getptd();
        _getptd();
        _getptd()->_curexception = curexception;
        _getptd()->_curcontext = pContext;
        if ( pMarkerRN )
          _UnwindNestedFrames(
            (_EXCEPTION_REGISTRATION_RECORD **)arrayOfCatchableTypes,
            pMarkerRN,
            (_EXCEPTION_RECORD *)curexception);
        else
          _UnwindNestedFrames(
            (_EXCEPTION_REGISTRATION_RECORD **)arrayOfCatchableTypes,
            pRN,
            (_EXCEPTION_RECORD *)curexception);
        __FrameUnwindToState(pRN, pDC, pFuncInfo, -1);
        CallUnexpected();
      }
    }
  }
LABEL_64:
  if ( _getptd()->_curexcspec )
    _inconsistency();
}
