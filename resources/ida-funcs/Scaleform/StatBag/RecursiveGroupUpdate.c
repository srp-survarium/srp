void __thiscall Scaleform::StatBag::RecursiveGroupUpdate(Scaleform::StatBag *this, Scaleform::StatDesc::Iterator it)
{
  Scaleform::StatDesc *pChild; // esi
  unsigned int Id; // eax
  int v5; // edx
  int v6; // eax
  Scaleform::Stat *v7; // eax

  if ( it.pDesc )
  {
    pChild = it.pDesc->pChild;
    if ( (it.pDesc->Flags & 5) == 5 )
    {
      for ( ; pChild; pChild = pChild->pNextSibling )
      {
        Scaleform::StatBag::RecursiveGroupUpdate(this, (Scaleform::StatDesc::Iterator)pChild);
        Id = pChild->Id;
        if ( Id < 0x1000 )
        {
          v5 = this->IdPageTable[Id >> 4];
          if ( v5 != 0xFFFF )
          {
            v6 = *(unsigned __int16 *)&this->pMem[8 * v5 + 2 * (pChild->Id & 0xF)];
            if ( v6 != 0xFFFF )
            {
              v7 = (Scaleform::Stat *)&this->pMem[8 * v6];
              if ( v7 )
                Scaleform::StatBag::Add(this, it.pDesc->Id, v7);
            }
          }
        }
      }
    }
    else
    {
      for ( ; pChild; pChild = pChild->pNextSibling )
        Scaleform::StatBag::RecursiveGroupUpdate(this, (Scaleform::StatDesc::Iterator)pChild);
    }
  }
}
