void __usercall Scaleform::GFx::AS3::Stage::ExecuteFrame0Events(Scaleform::GFx::AS3::Stage *this@<ecx>, int a2@<edi>)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // ebx
  Scaleform::GFx::Sprite *MovieClip; // eax
  Scaleform::GFx::DisplayObjContainer *v5; // edi
  unsigned __int8 AvmObjOffset; // al
  int v7; // eax
  Scaleform::GFx::ASMovieRootBase *v8; // ecx
  Scaleform::GFx::ASStringManager *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::DisplayObjContainer *v11; // ecx
  Scaleform::Render::TreeContainer *v12; // eax
  Scaleform::Render::TreeNode *v13; // ebp
  int v14; // eax
  Scaleform::GFx::ASMovieRootBase_vtbl *v15; // ecx
  Scaleform::GFx::AS3::Class *Class; // eax
  Scaleform::GFx::AS3::Stage_vtbl **v17; // ecx
  Scaleform::GFx::AS3::Stage_vtbl *v18; // ebp
  Scaleform::GFx::AS3::ASVM *v19; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v20; // ecx
  unsigned int RefCount; // eax
  int v22; // eax
  Scaleform::GFx::ASStringNode *v23; // ecx
  Scaleform::GFx::DisplayObjContainer_vtbl **v24; // eax
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::GFx::AS3::ASVM *v26; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v27; // ecx
  unsigned int v28; // eax
  Scaleform::GFx::AS3::VM *v29; // ecx
  Scaleform::GFx::AS3::VM *v30; // ecx
  Scaleform::GFx::AS3::Value *p_ExceptionObj; // ebp
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  bool v33; // zf
  Scaleform::GFx::AS3::Object *v34; // ecx
  unsigned int v35; // eax
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  unsigned int v39; // [esp+20h] [ebp-3Ch]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo> ploaderInfo; // [esp+34h] [ebp-28h] BYREF
  Scaleform::Render::TreeContainer *v41; // [esp+38h] [ebp-24h]
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+3Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> _class; // [esp+40h] [ebp-1Ch]
  Scaleform::StringDataPtr gname; // [esp+44h] [ebp-18h] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_; // [esp+4Ch] [ebp-10h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_,
    this->pASRoot->pMovieImpl->AdvanceStats.pObject,
    "Stage::ExecuteFrame0Events",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  pObject = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  MovieClip = Scaleform::GFx::AS3::MovieRoot::CreateMovieClip(
                (Scaleform::GFx::AS3::MovieRoot *)this->pASRoot,
                (int)pObject,
                a2,
                this->pDefImpl.pObject->pBindData.pObject->pDataDef.pObject,
                this->pDefImpl.pObject,
                this,
                0,
                1);
  v5 = MovieClip;
  if ( MovieClip )
  {
    AvmObjOffset = MovieClip->AvmObjOffset;
    v5->Scaleform::GFx::InteractiveObject::Flags |= 0x1000u;
    v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x2000u;
    if ( AvmObjOffset )
    {
      v7 = (*(int (__thiscall **)(int))(*((_DWORD *)&v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                        + AvmObjOffset)
                                      + 8))((int)v5 + 4 * AvmObjOffset);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 112))(v7, 0);
    }
    v8 = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v9 = v8->GetStringManager(v8);
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v9, "root1", 5u, 0);
    ++ConstStringNode->RefCount;
    ((void (__thiscall *)(Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::ASStringNode **))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].~Scaleform::GFx::DisplayObjectBase)(
      v5,
      &ConstStringNode);
    v10 = ConstStringNode;
    --ConstStringNode->RefCount;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    ++v5->RefCount;
    v11 = this->pRoot.pObject;
    if ( v11 )
      Scaleform::RefCountNTSImpl::Release(v11);
    this->pRoot.pObject = v5;
    ((void (__thiscall *)(Scaleform::GFx::AS3::Stage *, _DWORD, _DWORD))this->SetFOV)(
      this,
      COERCE_UNSIGNED_INT64(55.0),
      HIDWORD(COERCE_UNSIGNED_INT64(55.0)));
    ((void (__thiscall *)(Scaleform::GFx::DisplayObjContainer *, _DWORD, _DWORD))v5->SetFOV)(
      v5,
      COERCE_UNSIGNED_INT64(55.0),
      HIDWORD(COERCE_UNSIGNED_INT64(55.0)));
    v12 = this->GetRenderContainer(this);
    v13 = v12;
    v41 = v12;
    if ( v12 )
      ++v12->RefCount;
    Scaleform::GFx::DisplayList::AddEntryAtIndex(
      &this->mDisplayList,
      this,
      (Scaleform::GFx::DisplayObjectBase *)this->mDisplayList.DisplayObjectArray.Data.Size,
      v5);
    Scaleform::Render::TreeContainer::Insert(this->pASRoot->pMovieImpl->pRenderRoot.pObject, 0, v13);
    v5->pParent = this;
    Scaleform::GFx::InteractiveObject::AddToPlayList(v5);
    v14 = (*(int (__thiscall **)(char *, _DWORD))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                  + this->AvmObjOffset)
                                                + 60))(
            (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
          + 4 * this->AvmObjOffset,
            0);
    v15 = pObject[2].__vftable;
    pObject[22].__vftable = (Scaleform::GFx::ASMovieRootBase_vtbl *)((char *)pObject[22].__vftable + v14);
    gname.pStr = "flash.display.LoaderInfo";
    gname.Size = 24;
    Class = Scaleform::GFx::AS3::VM::GetClass(
              (Scaleform::GFx::AS3::VM *)v15,
              (Scaleform::GFx::ASStringNode *)&gname,
              (Scaleform::GFx::ASStringNode *)v15[1].GenerateMouseEvents);
    _class.pObject = Class;
    if ( Class )
    {
      Class->RefCount = (Class->RefCount + 1) & 0x8FBFFFFF;
      v17 = &this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
          + this->AvmObjOffset;
      v18 = v17[2];
      if ( !v18 )
        v18 = v17[1];
      ConstStringNode = (Scaleform::GFx::ASStringNode *)v18;
      if ( ((unsigned __int8)v18 & 1) != 0 )
        ConstStringNode = (Scaleform::GFx::ASStringNode *)((char *)&v18[-1].ExecuteFrameTags + 3);
      v19 = (Scaleform::GFx::AS3::ASVM *)pObject[2].__vftable;
      ploaderInfo.pObject = 0;
      if ( Scaleform::GFx::AS3::ASVM::_constructInstance(
             v19,
             (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&ploaderInfo,
             Class,
             0,
             0)
        && ConstStringNode )
      {
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::SetLoaderInfo(
          (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)ConstStringNode,
          ploaderInfo.pObject);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&ploaderInfo.pObject->Content,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)ConstStringNode);
      }
      v20 = ploaderInfo.pObject;
      if ( ploaderInfo.pObject )
      {
        if ( ((int)ploaderInfo.pObject & 1) == 0 )
        {
          RefCount = ploaderInfo.pObject->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            ploaderInfo.pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
          }
        }
      }
      v13 = v41;
    }
    Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(
      (Scaleform::GFx::AS3::AvmDisplayObj *)(&v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + v5->AvmObjOffset),
      (int)v13,
      (int)v5);
    if ( _class.pObject )
    {
      v22 = v5->AvmObjOffset;
      v23 = (Scaleform::GFx::ASStringNode *)*((_DWORD *)&v5->pWeakProxy + v22);
      v24 = &v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
          + v22;
      if ( v23 )
        v25 = v23;
      else
        v25 = (Scaleform::GFx::ASStringNode *)v24[1];
      ConstStringNode = v25;
      if ( ((unsigned __int8)v25 & 1) != 0 )
        ConstStringNode = (Scaleform::GFx::ASStringNode *)((char *)v25 - 1);
      v26 = (Scaleform::GFx::AS3::ASVM *)pObject[2].__vftable;
      ploaderInfo.pObject = 0;
      if ( Scaleform::GFx::AS3::ASVM::_constructInstance(
             v26,
             (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&ploaderInfo,
             _class.pObject,
             0,
             0)
        && ConstStringNode )
      {
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::SetLoaderInfo(
          (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)ConstStringNode,
          ploaderInfo.pObject);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&ploaderInfo.pObject->Content,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)ConstStringNode);
      }
      v27 = ploaderInfo.pObject;
      if ( ploaderInfo.pObject )
      {
        if ( ((int)ploaderInfo.pObject & 1) == 0 )
        {
          v28 = ploaderInfo.pObject->RefCount;
          if ( (v28 & 0x3FFFFF) != 0 )
          {
            ploaderInfo.pObject->RefCount = v28 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v27);
          }
        }
      }
    }
    pObject[22].__vftable = (Scaleform::GFx::ASMovieRootBase_vtbl *)((char *)pObject[22].__vftable
                                                                   + Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(
                                                                       (Scaleform::GFx::AS3::AvmDisplayObj *)(&v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable + v5->AvmObjOffset),
                                                                       0));
    if ( (*(_BYTE *)(&v5->pPerspectiveData + v5->AvmObjOffset) & 4) == 0 )
      v5->ExecuteFrame0Events(v5);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(
      (Scaleform::GFx::AS3::MovieRoot *)this->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      (int)v13,
      AL_Highest);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(
      (Scaleform::GFx::AS3::MovieRoot *)this->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      (int)v13,
      AL_High);
    while ( pObject[22].__vftable )
    {
      v29 = (Scaleform::GFx::AS3::VM *)pObject[2].__vftable;
      v39 = (unsigned int)pObject[22].__vftable;
      pObject[22].__vftable = 0;
      Scaleform::GFx::AS3::VM::ExecuteCode(v29, v39);
      v30 = (Scaleform::GFx::AS3::VM *)pObject[2].__vftable;
      if ( v30->HandleException )
      {
        p_ExceptionObj = &v30->ExceptionObj;
        v30->HandleException = 0;
        Scaleform::GFx::AS3::VM::OutputError(v30, &v30->ExceptionObj);
        if ( (p_ExceptionObj->Flags & 0x1F) > 9 )
        {
          if ( (p_ExceptionObj->Flags & 0x200) != 0 )
          {
            pWeakProxy = p_ExceptionObj->Bonus.pWeakProxy;
            v33 = pWeakProxy->RefCount-- == 1;
            if ( v33 )
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
            p_ExceptionObj->Flags &= 0xFFFFFDE0;
            p_ExceptionObj->Bonus.pWeakProxy = 0;
            p_ExceptionObj->value.VS._1.VInt = 0;
            p_ExceptionObj->value.VS._2.VObj = 0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(p_ExceptionObj);
          }
        }
        p_ExceptionObj->Flags &= 0xFFFFFFE0;
        this->FrameCounterObj.pObject->Flags |= 0x20u;
        v13 = v41;
      }
    }
    (*(void (__thiscall **)(int, int))(*((_DWORD *)&v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                       + v5->AvmObjOffset)
                                     + 76))(
      (int)v5 + 4 * v5->AvmObjOffset,
      1);
    this->pASRoot->pMovieImpl->Flags |= 0x80000u;
    ((void (__stdcall *)(int, _DWORD))this->FrameCounterObj.pObject->AdvanceFrame)(1, 0.0);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(
      (Scaleform::GFx::AS3::MovieRoot *)this->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      (int)v13,
      AL_Frame);
    v34 = _class.pObject;
    if ( _class.pObject )
    {
      if ( ((int)_class.pObject & 1) == 0 )
      {
        v35 = _class.pObject->RefCount;
        if ( (v35 & 0x3FFFFF) != 0 )
        {
          _class.pObject->RefCount = v35 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v34);
        }
      }
    }
    if ( v13 )
    {
      v33 = v13->RefCount-- == 1;
      if ( v33 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v13);
    }
    Scaleform::RefCountNTSImpl::Release(v5);
  }
  Stats = _amp_timer_.Stats;
  if ( _amp_timer_.Stats )
  {
    p_NativePopCallstack = &_amp_timer_.Stats->NativePopCallstack;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(_amp_timer_.StartTicks),
      (ProfileTicks - _amp_timer_.StartTicks) >> 32);
  }
}
