void __thiscall Scaleform::GFx::AS2::AvmSprite::FillTabableArray(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::ASStringNode *params)
{
  Scaleform::GFx::AS2::AvmSprite *v2; // ebx
  Scaleform::GFx::InteractiveObject::FillTabableParams *v3; // eax
  Scaleform::GFx::InteractiveObject::FillTabableParams *v4; // ebp
  unsigned int Size; // edi
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  char v7; // bl
  Scaleform::GFx::ASStringNode *v8; // eax
  int v9; // edi
  Scaleform::GFx::DisplayObjContainer *v10; // esi
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy> > *Array; // ecx
  unsigned int n; // [esp+10h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+14h] [ebp-10h] BYREF

  v2 = this;
  v3 = *(Scaleform::GFx::InteractiveObject::FillTabableParams **)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 128);
  n = (unsigned int)v3;
  if ( v3 )
  {
    v4 = (Scaleform::GFx::InteractiveObject::FillTabableParams *)params;
    if ( !LOBYTE(this->ASEnvironment.LocalFrames.Data.Policy.Capacity) && !BYTE2(params->pManager) )
    {
      Size = this[-1].InitActionsExecuted.Data.Size;
      if ( Size )
      {
        pLocalFrame = this->ASEnvironment.GlobalRegister[3].V.FunctionValue.pLocalFrame;
        val.T.Type = 0;
        params = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   *(Scaleform::GFx::ASStringManager **)(pLocalFrame->PrevFrame.pObject->RefCount + 788),
                   "tabChildren",
                   0xBu,
                   0);
        ++params->RefCount;
        v7 = (*(int (__thiscall **)(unsigned int, Scaleform::GFx::AS2::LocalFrame **, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *))(*(_DWORD *)(Size + 16) + 44))(
               Size + 16,
               &v2->ASEnvironment.GlobalRegister[3].V.FunctionValue.pLocalFrame,
               &params,
               &val);
        v8 = params;
        --params->RefCount;
        if ( !v8->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        if ( v7 && val.T.Type && val.T.Type != 10 )
          v4->TabChildrenInProto.Value = 2
                                       - (Scaleform::GFx::AS2::Value::ToBool(
                                            &val,
                                            (const Scaleform::GFx::AS2::Environment *)&this->Scaleform::GFx::AS2::ObjectInterface) != 0);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        v3 = (Scaleform::GFx::InteractiveObject::FillTabableParams *)n;
        v2 = this;
      }
    }
    if ( LOBYTE(v2->ASEnvironment.LocalFrames.Data.Policy.Capacity) != 2 && v4->TabChildrenInProto.Value != 2 && v3 )
    {
      v9 = 0;
      params = (Scaleform::GFx::ASStringNode *)v3;
      do
      {
        v10 = *(Scaleform::GFx::DisplayObjContainer **)(v9
                                                      + *(_DWORD *)(v2[-1].InitActionsExecuted.Data.Policy.Capacity + 124));
        if ( v10
          && SLOBYTE(v10->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) < 0
          && v10->GetVisible(v10) )
        {
          if ( v10->TabIndex > 0 && !v4->TabIndexed )
          {
            Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
              &v4->Array->Data,
              v4->Array->Data.pHeap,
              0);
            v4->TabIndexed = 1;
          }
          if ( (v10->IsTabable(v10) || v4->InclFocusEnabled && v10->IsFocusEnabled(v10, GFx_FocusMovedByKeyboard))
            && (!v4->TabIndexed || v10->TabIndex > 0) )
          {
            ++v10->RefCount;
            Array = v4->Array;
            n = (unsigned int)v10;
            Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              Array,
              (const Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&n);
            Scaleform::RefCountNTSImpl::Release(v10);
          }
          if ( (v10->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
              & 0x200) != 0 )
            Scaleform::GFx::DisplayObjContainer::FillTabableArray(v10, v4);
        }
        v9 += 12;
        params = (Scaleform::GFx::ASStringNode *)((char *)params - 1);
      }
      while ( params );
    }
  }
}
