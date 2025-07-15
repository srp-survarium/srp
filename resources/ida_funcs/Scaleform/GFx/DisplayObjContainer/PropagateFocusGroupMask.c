void __thiscall Scaleform::GFx::DisplayObjContainer::PropagateFocusGroupMask(
        Scaleform::GFx::DisplayObjContainer *this,
        unsigned int mask)
{
  unsigned int Size; // eax
  int v4; // esi
  unsigned int v5; // ebx
  Scaleform::GFx::DisplayObjectBase *v6; // ecx
  long double (__thiscall *GetZ)(Scaleform::GFx::DisplayObjectBase *); // eax

  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  this->FocusGroupMask = mask;
  if ( Size )
  {
    v4 = 0;
    v5 = Size;
    do
    {
      v6 = LOBYTE(this->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter->Flags) >> 7 != 0
         ? this->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter
         : 0;
      if ( v6 )
      {
        GetZ = v6->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetZ;
        LOWORD((LOBYTE(this->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter->Flags) >> 7 != 0
              ? (Scaleform::GFx::DisplayObjectBase *)((char *)&this->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter[1].LastHitTestY
                                                    + 2)
              : (Scaleform::GFx::DisplayObjectBase *)110)->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable) = mask;
        ((void (__stdcall *)(unsigned int))GetZ)(mask);
      }
      ++v4;
      --v5;
    }
    while ( v5 );
  }
}
