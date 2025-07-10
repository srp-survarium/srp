BOOL __cdecl __TypeMatch(const _s_HandlerType *pCatch, const _s_CatchableType *pCatchable, const _s_ThrowInfo *pThrow)
{
  TypeDescriptor *pType; // eax
  TypeDescriptor *v4; // ecx
  int v5; // eax
  BOOL result; // eax

  pType = pCatch->pType;
  result = 1;
  if ( pType && pType->name[0] )
  {
    v4 = pCatchable->pType;
    if ( pType != v4 )
    {
      strcmp((unsigned __int8 *)pType->name, (unsigned __int8 *)v4->name);
      if ( v5 )
        return 0;
    }
    if ( (pCatchable->properties & 2) != 0 && (pCatch->adjectives & 8) == 0
      || (pThrow->attributes & 1) != 0 && (pCatch->adjectives & 1) == 0
      || (pThrow->attributes & 2) != 0 && (pCatch->adjectives & 2) == 0 )
    {
      return 0;
    }
  }
  return result;
}
