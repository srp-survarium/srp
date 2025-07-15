char __thiscall Scaleform::GFx::AS2::AvmCharacter::InvokeClipEventHandlers(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::EventId *id)
{
  unsigned int v3; // edx
  Scaleform::GFx::AS2::AvmCharacter *v4; // ebx
  unsigned int KeyCode; // edi
  int v6; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> >::TableType *pTable; // esi
  Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *p_EventHandlers; // ecx
  signed int v9; // eax
  int v10; // esi
  _DWORD *v11; // ecx
  int v12; // edi
  int v13; // ebp
  Scaleform::GFx::AS2::Value *v14; // eax
  Scaleform::GFx::AS2::ObjectInterface *v15; // ecx
  Scaleform::GFx::EventId v18; // [esp+10h] [ebp-14h] BYREF

  v3 = id->Id;
  v4 = this;
  if ( id->Id == 64 || v3 == 128 )
  {
    KeyCode = 0;
    v18.WcharCode = 0;
    v18.AsciiCode = 0;
    v18.RollOverCnt = 0;
    v18.MouseWheelDelta = 0;
    *(_WORD *)&v18.ControllerIndex = 255;
  }
  else
  {
    KeyCode = id->KeyCode;
    v18.WcharCode = id->WcharCode;
    v6 = *(_DWORD *)&id->RollOverCnt;
    v18.TouchID = id->TouchID;
    *(_DWORD *)&v18.RollOverCnt = v6;
  }
  pTable = this->EventHandlers.mHash.pTable;
  p_EventHandlers = &this->EventHandlers;
  v18.KeyCode = KeyCode;
  v18.Id = v3;
  if ( !pTable )
    return 0;
  if ( ((unsigned int)&loc_20000 & v3) != 0 )
    v3 ^= KeyCode;
  v9 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::EventId>(
         &p_EventHandlers->mHash,
         &v18,
         v3 & pTable->SizeMask);
  if ( v9 < 0 )
    return 0;
  v10 = (int)&pTable[5 * v9 + 2];
  if ( !v10 )
    return 0;
  v11 = (_DWORD *)(v10 + 20);
  if ( v10 == -20 )
    return 0;
  if ( *(_DWORD *)(v10 + 24) )
  {
    v12 = 0;
    v13 = *(_DWORD *)(v10 + 24);
    while ( 1 )
    {
      v14 = (Scaleform::GFx::AS2::Value *)(v12 + *v11);
      v15 = v4 ? &v4->Scaleform::GFx::AS2::ObjectInterface : 0;
      Scaleform::GFx::AS2::GAS_Invoke(
        v14,
        0,
        v15,
        penv,
        0,
        penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 31,
        0);
      v12 += 16;
      if ( !--v13 )
        break;
      v11 = (_DWORD *)(v10 + 20);
      v4 = this;
    }
  }
  return 1;
}
