void __thiscall Scaleform::GFx::AS3::ValueStack::~ValueStack(Scaleform::GFx::AS3::ValueStack *this)
{
  Scaleform::GFx::AS3::ValueStack::Page *pReserved; // eax
  Scaleform::GFx::AS3::Value *pCurrent; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  bool v5; // zf
  Scaleform::GFx::ASStringNode *VStr; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::ValueStack::Page *pCurrentPage; // edx
  Scaleform::GFx::AS3::ValueStack::Page *pPrev; // eax
  Scaleform::GFx::AS3::ValueStack::Page *v11; // ecx

  while ( this->pReserved )
  {
    pReserved = this->pReserved;
    this->pReserved = pReserved->pNext;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pReserved);
  }
  while ( this->pCurrentPage )
  {
    for ( ; this->pCurrent >= this->pCurrentPage->Values; --this->pCurrent )
    {
      pCurrent = this->pCurrent;
      if ( (this->pCurrent->Flags & 0x1F) > 9 )
      {
        if ( (this->pCurrent->Flags & 0x200) != 0 )
        {
          pWeakProxy = pCurrent->Bonus.pWeakProxy;
          v5 = pWeakProxy->RefCount-- == 1;
          if ( v5 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          pCurrent->Flags &= 0xFFFFFDE0;
          pCurrent->Bonus.pWeakProxy = 0;
          pCurrent->value.VS._1.VInt = 0;
          pCurrent->value.VS._2.VObj = 0;
        }
        else
        {
          switch ( this->pCurrent->Flags & 0x1F )
          {
            case 0xAu:
              VStr = pCurrent->value.VS._1.VStr;
              v5 = VStr->RefCount-- == 1;
              if ( v5 )
                Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
              break;
            case 0xBu:
            case 0xCu:
            case 0xDu:
            case 0xEu:
            case 0xFu:
              VObj = pCurrent->value.VS._1.VObj;
              if ( ((unsigned __int8)VObj & 1) == 0 )
                goto LABEL_17;
              pCurrent->value.VS._1.VInt = (int)&VObj[-1].RefCount + 3;
              break;
            case 0x10u:
            case 0x11u:
              VObj = pCurrent->value.VS._2.VObj;
              if ( ((unsigned __int8)VObj & 1) != 0 )
              {
                pCurrent->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)&VObj[-1].RefCount + 3);
              }
              else
              {
LABEL_17:
                if ( VObj )
                {
                  RefCount = VObj->RefCount;
                  if ( (RefCount & 0x3FFFFF) != 0 )
                  {
                    VObj->RefCount = RefCount - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
                  }
                }
              }
              break;
            default:
              continue;
          }
        }
      }
    }
    pCurrentPage = this->pCurrentPage;
    pPrev = pCurrentPage->pPrev;
    this->pCurrentPage = pPrev;
    if ( pPrev )
    {
      v11 = this->pCurrentPage;
      this->pCurrent = pPrev->pCurrent;
      this->pStack = v11->pFirst;
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pCurrentPage);
  }
}
