int __cdecl _ValidateEH3RN(_EH3_EXCEPTION_REGISTRATION *pRN)
{
  _SCOPETABLE_ENTRY *ScopeTable; // edx
  struct _TEB *v3; // eax
  DWORD TryLevel; // edi
  int v5; // ebx
  DWORD v6; // eax
  _SCOPETABLE_ENTRY *v7; // ecx
  PSCOPETABLE_ENTRY v8; // eax
  int i; // esi
  unsigned __int8 *pPage; // ebx
  unsigned __int8 *pImageBase; // edi
  int v12; // ecx
  bool v13; // cc
  int j; // eax
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // edx
  unsigned __int8 *AllocationBase; // edi
  _IMAGE_SECTION_HEADER *PESection; // eax
  int v19; // edi
  int v20; // eax
  unsigned __int8 **v21; // ecx
  int v22; // esi
  unsigned __int8 *v23; // ecx
  unsigned __int8 *v24; // edx
  _VALID_PAGE_CACHE *v25; // eax
  int v26; // ebx
  unsigned __int8 *v27; // esi
  unsigned __int8 *v28; // edi
  _MEMORY_BASIC_INFORMATION mbi; // [esp+10h] [ebp-40h] BYREF
  unsigned int dwTryLevel; // [esp+2Ch] [ebp-24h]
  unsigned __int8 *pScopePage; // [esp+30h] [ebp-20h]
  _SCOPETABLE_ENTRY *pScopeTable; // [esp+34h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+38h] [ebp-18h]

  ScopeTable = pRN->ScopeTable;
  pScopeTable = ScopeTable;
  if ( ((unsigned __int8)ScopeTable & 3) != 0 )
    return 0;
  v3 = NtCurrentTeb();
  pScopePage = (unsigned __int8 *)v3->NtTib.StackLimit;
  if ( ScopeTable >= (_SCOPETABLE_ENTRY *)pScopePage && ScopeTable < v3->NtTib.StackBase )
    return 0;
  TryLevel = pRN->TryLevel;
  dwTryLevel = TryLevel;
  if ( TryLevel != -1 )
  {
    v5 = 0;
    v6 = 0;
    v7 = ScopeTable;
    do
    {
      if ( v7->EnclosingLevel != -1 && v7->EnclosingLevel >= v6 )
        return 0;
      if ( v7->FilterFunc )
        v5 = 1;
      ++v6;
      ++v7;
    }
    while ( v6 <= TryLevel );
    if ( !v5 || (v8 = pRN[-1].ScopeTable, v8 >= (PSCOPETABLE_ENTRY)pScopePage) && v8 < (PSCOPETABLE_ENTRY)pRN )
    {
      pScopePage = (unsigned __int8 *)((unsigned int)ScopeTable & 0xFFFFF000);
      for ( i = 0; ; ++i )
      {
        if ( i >= nValidPages )
          goto LABEL_39;
        pPage = rgValidPages[i].pPage;
        pImageBase = rgValidPages[i].pImageBase;
        if ( pPage == (unsigned __int8 *)((unsigned int)ScopeTable & 0xFFFFF000) )
          break;
      }
      ms_exc.registration.TryLevel = 0;
      if ( _ValidateImageBase(pImageBase)
        && ValidateScopeTableHandlers(pImageBase, dwTryLevel, pScopeTable)
        && _FindPESection(pImageBase, (char *)pRN->ExceptionHandler - (char *)pImageBase) )
      {
        ms_exc.registration.TryLevel = -2;
        if ( i > 0 && !_InterlockedExchange(&lModifying, 1) )
        {
          if ( rgValidPages[i].pPage != pScopePage )
          {
            v12 = nValidPages;
            i = nValidPages - 1;
            if ( nValidPages - 1 >= 0 )
            {
              while ( rgValidPages[i].pPage != pScopePage )
              {
                if ( --i < 0 )
                  goto LABEL_29;
              }
              pPage = rgValidPages[i].pPage;
              pImageBase = rgValidPages[i].pImageBase;
LABEL_29:
              v13 = i <= 0;
              if ( i >= 0 )
                goto LABEL_34;
            }
            if ( nValidPages < 16 )
              v12 = ++nValidPages;
            i = v12 - 1;
          }
          v13 = i <= 0;
LABEL_34:
          if ( !v13 )
          {
            for ( j = 0; j <= i; ++j )
            {
              v15 = rgValidPages[j].pPage;
              v16 = rgValidPages[j].pImageBase;
              rgValidPages[j].pPage = pPage;
              rgValidPages[j].pImageBase = pImageBase;
              pPage = v15;
              pImageBase = v16;
            }
          }
LABEL_64:
          _InterlockedExchange(&lModifying, 0);
          return 1;
        }
        return 1;
      }
      ms_exc.registration.TryLevel = -2;
      ScopeTable = pScopeTable;
LABEL_39:
      if ( !VirtualQuery(ScopeTable, &mbi, 0x1Cu) )
        return 1;
      if ( (unsigned __int8 *)mbi.Type != &vostok::memory::s_CRT_arena[5574200] )
        return -1;
      AllocationBase = (unsigned __int8 *)mbi.AllocationBase;
      if ( !_ValidateImageBase((unsigned __int8 *)mbi.AllocationBase) )
        return -1;
      if ( ((mbi.Protect & 0xCC) == 0
         || (PESection = _FindPESection(AllocationBase, (char *)pScopeTable - (char *)AllocationBase)) != 0
         && (PESection->Characteristics & 0x80000000) == 0)
        && ValidateScopeTableHandlers(AllocationBase, dwTryLevel, pScopeTable)
        && _FindPESection(AllocationBase, (char *)pRN->ExceptionHandler - (char *)AllocationBase) )
      {
        if ( _InterlockedExchange(&lModifying, 1) )
          return 1;
        v19 = nValidPages;
        v20 = nValidPages;
        if ( nValidPages > 0 )
        {
          v21 = (unsigned __int8 **)(&nValidPages + 2 * nValidPages);
          do
          {
            if ( *v21 == pScopePage )
              break;
            --v20;
            v21 -= 2;
          }
          while ( v20 > 0 );
        }
        if ( v20 )
        {
          *(&lModifying + 2 * v20) = (int)mbi.AllocationBase;
        }
        else
        {
          v22 = 15;
          if ( nValidPages <= 15 )
            v22 = nValidPages;
          v23 = pScopePage;
          v24 = (unsigned __int8 *)mbi.AllocationBase;
          if ( v22 >= 0 )
          {
            v25 = rgValidPages;
            v26 = v22 + 1;
            do
            {
              v27 = v25->pPage;
              v28 = v25->pImageBase;
              v25->pPage = v23;
              v25->pImageBase = v24;
              v23 = v27;
              v24 = v28;
              ++v25;
              --v26;
            }
            while ( v26 );
            v19 = nValidPages;
          }
          if ( v19 < 16 )
            nValidPages = v19 + 1;
        }
        goto LABEL_64;
      }
    }
    return 0;
  }
  return 1;
}
