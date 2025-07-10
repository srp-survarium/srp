void __thiscall Scaleform::GFx::AS3::MovieRoot::ChangeMouseCursorType(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Instances::fl_events::Event *mouseIdx,
        Scaleform::GFx::ASStringNode *newCursorType)
{
  Scaleform::GFx::ASStringNode *v3; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v4; // ebp
  Scaleform::GFx::AS3::Stage *pObject; // ecx
  Scaleform::GFx::AS3::ASVM *v7; // eax
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *v8; // edi
  Scaleform::GFx::AS3::Stage *v9; // eax
  int v10; // eax
  int v11; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v12; // ecx
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::GFx::MovieImpl *v16; // esi
  Scaleform::GFx::UserEventHandler *v17; // ecx
  int v18; // [esp+Ch] [ebp-10h] BYREF
  char v19; // [esp+10h] [ebp-Ch]
  Scaleform::GFx::ASStringNode *v20; // [esp+14h] [ebp-8h]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v21; // [esp+18h] [ebp-4h]

  v3 = newCursorType;
  v4 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *)mouseIdx;
  pObject = this->pStage.pObject;
  if ( pObject )
  {
    v7 = this->pAVM.pObject;
    if ( v7 )
    {
      if ( v7->ExtensionsEnabled && pObject->MouseCursorEventCnt )
      {
        v8 = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)v7->EventDispatcherClass.pObject;
        newCursorType = this->BuiltinsMgr.Builtins[0].pNode;
        ++newCursorType->RefCount;
        Scaleform::GFx::AS3::MovieRoot::GetMouseCursorTypeString(this, (Scaleform::GFx::ASString *)&newCursorType, v3);
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseCursorEventObject(
          v8,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&mouseIdx,
          (const Scaleform::GFx::ASString *)&newCursorType,
          v4);
        v9 = this->pStage.pObject;
        if ( v9
          && (v10 = (*(int (__thiscall **)(int))(*((_DWORD *)&v9->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                 + v9->AvmObjOffset)
                                               + 4))((int)v9 + 4 * v9->AvmObjOffset)) != 0 )
        {
          v11 = v10 - 28;
        }
        else
        {
          v11 = 0;
        }
        v12 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v11 + 8);
        if ( !v12 )
          v12 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v11 + 4);
        if ( ((unsigned __int8)v12 & 1) != 0 )
          v12 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v12 - 1);
        if ( v12
          && !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(v12, mouseIdx, this->pStage.pObject) )
        {
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&mouseIdx);
          v13 = newCursorType;
          --newCursorType->RefCount;
          if ( !v13->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v13);
          return;
        }
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&mouseIdx);
        v14 = newCursorType;
        --newCursorType->RefCount;
        if ( !v14->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      }
    }
  }
  pMovieImpl = this->pMovieImpl;
  if ( pMovieImpl->pUserEventHandler.pObject )
  {
    v16 = this->pMovieImpl;
    v17 = pMovieImpl->pUserEventHandler.pObject;
    v19 = 0;
    v18 = 23;
    v20 = v3;
    v21 = v4;
    v17->HandleEvent(v17, v16, (const Scaleform::GFx::Event *)&v18);
  }
}
