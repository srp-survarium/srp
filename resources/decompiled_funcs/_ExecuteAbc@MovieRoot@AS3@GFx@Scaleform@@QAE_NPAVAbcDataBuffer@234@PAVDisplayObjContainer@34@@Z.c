bool __thiscall Scaleform::GFx::AS3::MovieRoot::ExecuteAbc(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Resource *pabc,
        Scaleform::GFx::DisplayObjContainer *m)
{
  int v5; // eax
  Scaleform::GFx::AS3::Abc::File *v6; // edi
  int v7; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // ebx
  Scaleform::GFx::Resource_vtbl **v9; // eax
  Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef *v10; // eax
  Scaleform::GFx::AS3::Abc::File *v11; // eax
  unsigned int v12; // eax
  Scaleform::GFx::AS3::Abc::Reader *v13; // ebp
  int v14; // eax
  int v15; // eax
  const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *v16; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::VMAbcFile *v18; // ecx
  Scaleform::GFx::AS3::ASVM *v19; // ecx
  Scaleform::GFx::MovieDefRootNode *RootNode; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *v21; // esi
  unsigned int Size; // ecx
  unsigned int v23; // eax
  void *v24; // esi
  Scaleform::String fileName; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> vmAbc; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> pAbcFile; // [esp+18h] [ebp-8h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> v29; // [esp+1Ch] [ebp-4h] BYREF
  Scaleform::GFx::AS3::Abc::Reader *result; // [esp+24h] [ebp+4h]
  bool resulta; // [esp+24h] [ebp+4h]

  pAbcFile.pObject = (Scaleform::GFx::AS3::Abc::File *)m->GetResourceMovieDef(m);
  Scaleform::String::String(&fileName, (const Scaleform::String *)&pabc[1].pLib);
  if ( (*(_DWORD *)((int)pabc->pLib & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
  {
    Scaleform::String::AppendString(&fileName, "[", 0xFFFFFFFF);
    Scaleform::String::operator+=(&fileName, (const Scaleform::String *)&pabc->pLib);
    Scaleform::String::AppendString(&fileName, "]", 0xFFFFFFFF);
  }
  v5 = (*(int (__thiscall **)(char *))(*((_DWORD *)&m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                       + m->AvmObjOffset)
                                     + 20))(
         (char *)&m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + 4 * m->AvmObjOffset);
  v6 = 0;
  if ( v5 )
    v7 = v5 - 36;
  else
    v7 = 0;
  Scaleform::GFx::AS3::VM::FindVMAbcFileWeak(
    this->pAVM.pObject,
    &vmAbc,
    (const char *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(Scaleform::GFx::AS3::VMAppDomain **)(v7 + 20));
  pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)vmAbc.pObject;
  if ( vmAbc.pObject )
  {
    resulta = 1;
  }
  else
  {
    v9 = (Scaleform::GFx::Resource_vtbl **)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 8, 0);
    if ( v9 )
    {
      *v9 = pabc[1].__vftable;
      v9[1] = (Scaleform::GFx::Resource_vtbl *)&pabc[2];
      result = (Scaleform::GFx::AS3::Abc::Reader *)v9;
    }
    else
    {
      result = 0;
    }
    v10 = (Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef *)this->pMovieImpl->pHeap->Alloc(
                                                              this->pMovieImpl->pHeap,
                                                              192,
                                                              0);
    if ( v10 )
    {
      Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef::AbcFileWithMovieDef(
        v10,
        (Scaleform::GFx::MovieDefImpl *)pAbcFile.pObject,
        pabc);
      v6 = v11;
    }
    pAbcFile.pObject = v6;
    Scaleform::String::operator=(&v6->Source, &fileName);
    v12 = (unsigned int)pabc[1].__vftable;
    v13 = result;
    v6->DataSize = v12;
    resulta = Scaleform::GFx::AS3::Abc::Reader::Read(result, v6);
    if ( resulta )
    {
      Scaleform::GFx::AS3::MovieRoot::CheckAvm(this, (int)v6);
      v14 = (*(int (__thiscall **)(char *))(*((_DWORD *)&m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                            + m->AvmObjOffset)
                                          + 20))(
              (char *)&m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
            + 4 * m->AvmObjOffset);
      if ( v14 )
        v15 = v14 - 36;
      else
        v15 = 0;
      v16 = (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)Scaleform::GFx::AS3::VM::LoadFile(this->pAVM.pObject, &v29, &pAbcFile, *(Scaleform::GFx::AS3::VMAppDomain **)(v15 + 20), 0);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&vmAbc,
        v16);
      if ( v29.pObject )
      {
        if ( ((int)v29.pObject & 1) == 0 )
        {
          RefCount = v29.pObject->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            v18 = v29.pObject;
            v29.pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
          }
        }
      }
      v19 = this->pAVM.pObject;
      if ( v19->HandleException )
      {
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v19);
        resulta = 0;
      }
      pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)vmAbc.pObject;
    }
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
    if ( v13 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
  }
  if ( pObject )
  {
    RootNode = Scaleform::GFx::DisplayObjContainer::FindRootNode(m);
    v21 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&RootNode[1];
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      v21,
      v21,
      (unsigned int)&RootNode[1].pPrev->Scaleform::ListNode<Scaleform::GFx::MovieDefRootNode>::$BAD91DB6ACB021FD716237F2D22807FC::__vftable
    + 1);
    Size = v21->Size;
    if ( &v21->Data[Size] != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)4 )
    {
      v21->Data[Size - 1].pObject = pObject;
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    }
    if ( ((unsigned __int8)pObject & 1) == 0 )
    {
      v23 = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v23) != 0 )
      {
        pObject->RefCount = v23 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  v24 = (void *)(fileName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v24);
  return resulta;
}
