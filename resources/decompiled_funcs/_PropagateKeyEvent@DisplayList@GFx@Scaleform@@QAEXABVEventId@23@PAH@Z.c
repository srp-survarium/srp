void __thiscall Scaleform::GFx::DisplayList::PropagateKeyEvent(
        Scaleform::GFx::DisplayList *this,
        const Scaleform::GFx::EventId *id,
        int *pkeyMask)
{
  unsigned int v4; // ebx
  int v5; // ebp
  Scaleform::GFx::DisplayObjectBase *pCharacter; // esi

  v4 = 0;
  if ( this->DisplayObjectArray.Data.Size )
  {
    v5 = 0;
    do
    {
      pCharacter = this->DisplayObjectArray.Data.Data[v5].pCharacter;
      if ( pCharacter )
        ++pCharacter->RefCount;
      if ( pCharacter->GetVisible(pCharacter) && SLOBYTE(pCharacter->Flags) < 0 )
        ((void (__thiscall *)(Scaleform::GFx::DisplayObjectBase *, const Scaleform::GFx::EventId *, int *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetX)(
          pCharacter,
          id,
          pkeyMask);
      Scaleform::RefCountNTSImpl::Release(pCharacter);
      ++v4;
      ++v5;
    }
    while ( v4 < this->DisplayObjectArray.Data.Size );
  }
}
