int __cdecl __BuildCatchObjectHelper(
        EHExceptionRecord *pExcept,
        int (__stdcall *pRN)(),
        const _s_HandlerType *pCatch,
        const _s_CatchableType *pConv)
{
  TypeDescriptor *pType; // ecx
  int dispCatchObj; // ecx
  int (__stdcall *v6)(); // esi
  char *pExceptionObject; // eax
  char *v8; // eax
  const __m128i *v9; // eax
  int (__stdcall *v11)(); // [esp-8h] [ebp-34h]
  unsigned int sizeOrOffset; // [esp-4h] [ebp-30h]
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  pType = pCatch->pType;
  if ( pType )
  {
    if ( pType->name[0] )
    {
      dispCatchObj = pCatch->dispCatchObj;
      if ( dispCatchObj || (pCatch->adjectives & 0x80000000) != 0 )
      {
        v6 = pRN;
        if ( (pCatch->adjectives & 0x80000000) == 0 )
          v6 = (int (__stdcall *)())((char *)pRN + dispCatchObj + 12);
        if ( (pCatch->adjectives & 8) != 0 )
        {
          if ( _ValidateRead((int (__stdcall *)())pExcept->params.pExceptionObject) && _ValidateRead(v6) )
          {
            pExceptionObject = (char *)pExcept->params.pExceptionObject;
            *(_DWORD *)v6 = pExceptionObject;
            v8 = __AdjustPointer(pExceptionObject, &pConv->thisDisplacement);
LABEL_11:
            *(_DWORD *)v6 = v8;
            return retval;
          }
        }
        else
        {
          v11 = (int (__stdcall *)())pExcept->params.pExceptionObject;
          if ( (pConv->properties & 1) != 0 )
          {
            if ( _ValidateRead(v11) && _ValidateRead(v6) )
            {
              memmove((int)v6, (const __m128i *)pExcept->params.pExceptionObject, pConv->sizeOrOffset);
              if ( pConv->sizeOrOffset != 4 || !*(_DWORD *)v6 )
                return retval;
              v8 = __AdjustPointer(*(char **)v6, &pConv->thisDisplacement);
              goto LABEL_11;
            }
          }
          else if ( pConv->copyFunction )
          {
            if ( _ValidateRead(v11) && _ValidateRead(v6) && _ValidateRead((int (__stdcall *)())pConv->copyFunction) )
              return ((pConv->properties & 4) != 0) + 1;
          }
          else if ( _ValidateRead(v11) && _ValidateRead(v6) )
          {
            sizeOrOffset = pConv->sizeOrOffset;
            v9 = (const __m128i *)__AdjustPointer((char *)pExcept->params.pExceptionObject, &pConv->thisDisplacement);
            memmove((int)v6, v9, sizeOrOffset);
            return retval;
          }
        }
        _inconsistency();
      }
    }
  }
  return 0;
}
