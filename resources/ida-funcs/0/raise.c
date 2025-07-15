int __usercall raise@<eax>(int a1@<esi>, int signum)
{
  _tiddata *v2; // edi
  _tiddata *v3; // eax
  int result; // eax
  void (__cdecl **p_XcptAction)(int); // esi
  void (__cdecl *v6)(int); // eax
  void (__cdecl *v7)(int); // eax
  int oldfpecode; // [esp+10h] [ebp-30h]
  _EXCEPTION_POINTERS *oldpxcptinfoptrs; // [esp+14h] [ebp-2Ch]
  int indx; // [esp+1Ch] [ebp-24h]
  void (__cdecl *sigact)(int); // [esp+20h] [ebp-20h]
  int siglock; // [esp+24h] [ebp-1Ch]

  v2 = 0;
  siglock = 0;
  if ( signum > 11 )
  {
    if ( signum == 15 )
    {
      p_XcptAction = &term_action;
      v6 = term_action;
      goto LABEL_18;
    }
    if ( signum == 21 )
    {
      p_XcptAction = &ctrlbreak_action;
      v6 = ctrlbreak_action;
      goto LABEL_18;
    }
    if ( signum != 22 )
      goto LABEL_14;
    goto LABEL_15;
  }
  if ( signum != 11 )
  {
    if ( signum == 2 )
    {
      p_XcptAction = &ctrlc_action;
      v6 = ctrlc_action;
LABEL_18:
      siglock = 1;
      v7 = (void (__cdecl *)(int))_decode_pointer(v6);
      goto LABEL_19;
    }
    if ( signum != 4 )
    {
      if ( signum != 6 )
      {
        if ( signum == 8 )
          goto LABEL_7;
LABEL_14:
        *_errno() = 22;
        _invalid_parameter(signum, 0, a1);
        return -1;
      }
LABEL_15:
      p_XcptAction = &abort_action;
      v6 = abort_action;
      goto LABEL_18;
    }
  }
LABEL_7:
  v3 = _getptd_noexit();
  v2 = v3;
  if ( !v3 )
    return -1;
  p_XcptAction = &siglookup(signum, (_XCPT_ACTION *)v3->_pxcptacttab)->XcptAction;
  v7 = *p_XcptAction;
LABEL_19:
  sigact = v7;
  result = 0;
  if ( sigact == (void (__cdecl *)(int))1 )
    return result;
  if ( !sigact )
    _exit(3);
  if ( siglock )
    _lock(0);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    oldpxcptinfoptrs = (_EXCEPTION_POINTERS *)v2->_tpxcptinfoptrs;
    v2->_tpxcptinfoptrs = 0;
    if ( signum != 8 )
      goto LABEL_33;
    oldfpecode = v2->_tfpecode;
    v2->_tfpecode = 140;
  }
  if ( signum == 8 )
  {
    for ( indx = _First_FPE_Indx; indx < _First_FPE_Indx + _Num_FPE; ++indx )
      *((_DWORD *)v2->_pxcptacttab + 3 * indx + 2) = 0;
    goto $LN37_3;
  }
LABEL_33:
  *p_XcptAction = (void (__cdecl *)(int))_encoded_null();
$LN37_3:
  if ( siglock )
    _unlock(0);
  if ( signum == 8 )
    ((void (__cdecl *)(int, int))sigact)(8, v2->_tfpecode);
  else
    sigact(signum);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    v2->_tpxcptinfoptrs = oldpxcptinfoptrs;
    if ( signum == 8 )
      v2->_tfpecode = oldfpecode;
  }
  return 0;
}
