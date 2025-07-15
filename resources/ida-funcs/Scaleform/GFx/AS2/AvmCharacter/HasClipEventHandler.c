bool __thiscall Scaleform::GFx::AS2::AvmCharacter::HasClipEventHandler(
        Scaleform::GFx::AS2::AvmCharacter *this,
        const Scaleform::GFx::EventId *id)
{
  unsigned int TouchID; // esi
  unsigned int v3; // edi
  unsigned int KeyCode; // edx
  int v5; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> >::TableType *pTable; // esi
  Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *p_EventHandlers; // ecx
  int v8; // eax
  signed int v9; // eax
  int v10; // eax
  Scaleform::GFx::EventId v12; // [esp+Ch] [ebp-14h] BYREF

  if ( id->Id == 64 || id->Id == 128 )
  {
    v3 = id->Id;
    v12.WcharCode = 0;
    KeyCode = 0;
    v12.AsciiCode = 0;
    v12.RollOverCnt = 0;
    v12.MouseWheelDelta = 0;
    *(_WORD *)&v12.ControllerIndex = 255;
  }
  else
  {
    TouchID = id->TouchID;
    v3 = id->Id;
    v12.WcharCode = id->WcharCode;
    KeyCode = id->KeyCode;
    v5 = *(_DWORD *)&id->RollOverCnt;
    v12.TouchID = TouchID;
    *(_DWORD *)&v12.RollOverCnt = v5;
  }
  pTable = this->EventHandlers.mHash.pTable;
  p_EventHandlers = &this->EventHandlers;
  v12.KeyCode = KeyCode;
  v12.Id = v3;
  if ( !pTable )
    return 0;
  v8 = v3;
  if ( ((unsigned int)&loc_20000 & v3) != 0 )
    v8 = v3 ^ KeyCode;
  v9 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::EventId>(
         &p_EventHandlers->mHash,
         &v12,
         v8 & pTable->SizeMask);
  return v9 >= 0 && (v10 = (int)&pTable[5 * v9 + 2]) != 0 && v10 != -20;
}
