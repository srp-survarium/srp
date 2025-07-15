char __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        const Scaleform::GFx::ASString *type,
        bool useCapture)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // esi
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *pRootHead; // esi
  int v8; // eax
  int v9; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v10; // ecx

  if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(this, type, useCapture) )
    return 1;
  pObject = this->pTraits.pObject;
  if ( (unsigned int)(pObject->TraitsType - 17) <= 0xC && (pObject->Flags & 0x20) == 0 )
  {
    pRCC = this[1]._pRCC;
    if ( pRCC )
    {
      pRootHead = pRCC->FinalizeRoots.pRootHead;
      if ( pRootHead )
      {
        while ( 1 )
        {
          v8 = (*(int (__thiscall **)(int))(*((_DWORD *)&pRootHead->__vftable + BYTE1(pRootHead[3]._pRCC)) + 4))((int)pRootHead + 4 * BYTE1(pRootHead[3]._pRCC));
          if ( v8 )
            v9 = v8 - 28;
          else
            v9 = 0;
          v10 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v9 + 8);
          if ( !v10 )
            v10 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v9 + 4);
          if ( ((unsigned __int8)v10 & 1) != 0 )
            v10 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v10 - 1);
          if ( v10 && Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(v10, type, useCapture) )
            break;
          pRootHead = pRootHead[1].pPrev;
          if ( !pRootHead )
            return 0;
        }
        return 1;
      }
    }
  }
  return 0;
}
