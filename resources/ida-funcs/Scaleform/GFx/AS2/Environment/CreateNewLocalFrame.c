Scaleform::GFx::AS2::LocalFrame *__thiscall Scaleform::GFx::AS2::Environment::CreateNewLocalFrame(
        Scaleform::GFx::AS2::Environment *this)
{
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v2; // esi
  Scaleform::GFx::InteractiveObject *Target; // eax
  Scaleform::GFx::AS2::RefCountCollector<323> *v4; // eax
  unsigned int Size; // ecx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *p_LocalFrames; // edi
  unsigned int v7; // edx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v8; // eax
  unsigned int RefCount; // eax

  v2 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)this->StringContext.pContext->pHeap->Alloc(
                                                     this->StringContext.pContext->pHeap,
                                                     72,
                                                     0);
  if ( v2 )
  {
    Target = this->Target;
    if ( Target )
      v4 = *(Scaleform::GFx::AS2::RefCountCollector<323> **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)((*(int (__thiscall **)(int))(*((_DWORD *)&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable + Target->AvmObjOffset) + 4))(
                                                                                                   (int)Target
                                                                                                 + 4
                                                                                                 * Target->AvmObjOffset)
                                                                                               + 16)
                                                                                   + 16)
                                                                       + 28)
                                                           + 16);
    else
      v4 = 0;
    v2->pRCC = v4;
    v2->RefCount = 1;
    v2->__vftable = (Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *)&Scaleform::GFx::AS2::LocalFrame::`vftable';
    v2[1].__vftable = 0;
    v2[1].pRCC = 0;
    v2[1].RootIndex = 0;
    v2[1].RefCount = 0;
    v2[2].__vftable = 0;
    v2[2].pRCC = 0;
    LOBYTE(v2[2].RootIndex) = 0;
    LOBYTE(v2[3].RootIndex) = 0;
  }
  else
  {
    v2 = 0;
  }
  Size = this->LocalFrames.Data.Size;
  p_LocalFrames = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->LocalFrames;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    p_LocalFrames,
    p_LocalFrames,
    Size + 1);
  v7 = p_LocalFrames->Size;
  v8 = &p_LocalFrames->Data[v7 - 1];
  if ( &p_LocalFrames->Data[v7] != (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)4 )
  {
    if ( v2 )
      v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
    v8->pObject = (Scaleform::GFx::AS2::Object *)v2;
  }
  if ( v2 )
  {
    RefCount = v2->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v2->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v2);
    }
  }
  return (Scaleform::GFx::AS2::LocalFrame *)v2;
}
