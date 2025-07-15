void __cdecl __FrameUnwindToState(EHRegistrationNode *pRN, void *pDC, const _s_FuncInfo *pFuncInfo, int targetState)
{
  int state; // esi
  _tiddata *v5; // eax
  int v6; // eax
  const _s_UnwindMapEntry *v7; // ecx
  _tiddata *v8; // eax

  if ( pFuncInfo->maxState > 128 )
    state = pRN->state;
  else
    state = SLOBYTE(pRN->state);
  v5 = _getptd();
  ++v5->_ProcessingThrow;
  while ( state != targetState )
  {
    if ( state <= -1 || state >= pFuncInfo->maxState )
      _inconsistency();
    v6 = state;
    v7 = &pFuncInfo->pUnwindMap[state];
    state = v7->toState;
    if ( v7->action )
    {
      pRN->state = state;
      _CallSettingFrame(
        (int)pFuncInfo->pUnwindMap,
        (int)pFuncInfo,
        state,
        (unsigned int)pFuncInfo->pUnwindMap[v6].action,
        (unsigned int)pRN,
        0x103u);
    }
  }
  if ( _getptd()->_ProcessingThrow > 0 )
  {
    v8 = _getptd();
    --v8->_ProcessingThrow;
  }
  if ( state != targetState )
    _inconsistency();
  pRN->state = state;
}
