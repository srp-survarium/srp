LONG Scaleform::StatDesc::InitChildTree()
{
  LONG result; // eax
  LONG v1; // esi
  Scaleform::StatDesc *v2; // ecx
  unsigned int GroupId; // eax
  Scaleform::StatDesc *pNextSibling; // esi
  Scaleform::StatDesc *v5; // eax
  Scaleform::StatDesc *pChild; // edx
  Scaleform::StatDesc *v7; // eax

  result = Stats_InitDone;
  if ( !Stats_InitDone )
  {
    do
    {
      v1 = Stats_InitByUs;
      if ( Stats_InitByUs == 1 )
      {
        while ( !Stats_InitDone )
          ;
        return result;
      }
      result = InterlockedCompareExchange(&Stats_InitByUs, 1, Stats_InitByUs);
    }
    while ( result != v1 );
    v2 = Stats_pFirstDesc;
    if ( Stats_pFirstDesc )
    {
      do
      {
        GroupId = v2->GroupId;
        pNextSibling = v2->pNextSibling;
        v2->pNextSibling = 0;
        if ( Scaleform::StatDescRegistryInstance.IdPageTable[GroupId >> 3] )
          v5 = (Scaleform::StatDesc *)*((_DWORD *)&Scaleform::StatDescRegistryInstance.DescMem[Scaleform::StatDescRegistryInstance.IdPageTable[GroupId >> 3]
                                                                                             - 1]
                                      + (GroupId & 7));
        else
          v5 = 0;
        if ( v5 != v2 )
        {
          pChild = v5->pChild;
          if ( pChild )
          {
            v7 = v5->pChild;
            if ( pChild->pNextSibling )
            {
              do
                v7 = v7->pNextSibling;
              while ( v7->pNextSibling );
            }
            v7->pNextSibling = v2;
          }
          else
          {
            v5->pChild = v2;
          }
        }
        v2 = pNextSibling;
      }
      while ( pNextSibling );
    }
    Stats_pFirstDesc = 0;
    Stats_pLastDesc = 0;
    return InterlockedExchange(&Stats_InitDone, 1);
  }
  return result;
}
