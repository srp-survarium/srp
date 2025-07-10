char __thiscall Scaleform::GFx::AS2::AvmCharacter::SetMember(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::ASStringNode *v6; // eax
  bool v7; // zf
  Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *p_EventHandlers; // esi
  Scaleform::GFx::AS2::Value *v9; // ebx
  const Scaleform::GFx::AS2::Environment *v11; // eax
  char v12; // al
  Scaleform::GFx::AS2::Object *pObject; // eax
  const Scaleform::GFx::AS2::Environment *v14; // eax
  char v15; // al
  Scaleform::GFx::InteractiveObject *v16; // esi
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::Environment *v18; // eax
  unsigned __int64 v19; // st7
  Scaleform::GFx::AS2::Environment *v20; // eax
  unsigned __int64 v21; // st7
  Scaleform::GFx::AS2::Environment *v22; // eax
  unsigned __int64 v23; // st7
  Scaleform::GFx::AS2::Object *v24; // eax
  Scaleform::GFx::AS2::ObjectInterface *v25; // eax
  int v26; // esi
  int v27; // eax
  Scaleform::GFx::AS2::Value *v28; // ebx
  Scaleform::GFx::AS2::Environment *v29; // eax
  unsigned __int64 v30; // st7
  Scaleform::GFx::AS2::Environment *v31; // eax
  unsigned __int64 v32; // st7
  Scaleform::GFx::AS2::Environment *v33; // eax
  unsigned int v34; // eax
  bool (__thiscall **p_ActsAsButton)(Scaleform::GFx::AvmInteractiveObjBase *); // esi
  Scaleform::GFx::AS2::Object *v36; // eax
  int v37; // eax
  int v38; // [esp+28Ch] [ebp-90h]
  unsigned int v39; // [esp+290h] [ebp-8Ch]
  int v; // [esp+2A4h] [ebp-78h]
  void (__thiscall **vb)(struct Scaleform::GFx::AS2::Object *); // [esp+2A4h] [ebp-78h]
  bool (__thiscall **vc)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::AS2::Object *); // [esp+2A4h] [ebp-78h]
  void (__thiscall **vd)(struct Scaleform::GFx::AS2::Object *); // [esp+2A4h] [ebp-78h]
  bool va[4]; // [esp+2A4h] [ebp-78h]
  int v45; // [esp+2A8h] [ebp-74h]
  const Scaleform::GFx::InteractiveObject *(__thiscall **p_GetASCharacter)(Scaleform::GFx::AS2::Object *); // [esp+2A8h] [ebp-74h]
  void (__thiscall **p_CheckAndResetCtorRef)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::FunctionObject *); // [esp+2A8h] [ebp-74h]
  Scaleform::Render::Matrix3x4<float> v48; // [esp+2ACh] [ebp-70h] BYREF
  Scaleform::Render::Matrix4x4<float> m; // [esp+2DCh] [ebp-40h] BYREF
  int savedregs; // [esp+31Ch] [ebp+0h] BYREF

  if ( (name->pNode->HashFlags & 0x20000000) == 0 )
  {
    if ( Scaleform::GFx::ASConstString::GetLength(name) && Scaleform::GFx::ASConstString::GetCharAt(name, 0) == 95 )
    {
      v6 = Scaleform::GFx::ASConstString::ToLowerNode(name);
      ++v6->RefCount;
      if ( (v6->HashFlags & 0x10000000) != 0 )
      {
        v7 = v6->RefCount-- == 1;
        if ( v7 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v6);
        goto LABEL_7;
      }
      v7 = v6->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    }
    v9 = val;
    goto LABEL_12;
  }
LABEL_7:
  p_EventHandlers = &this[-1].EventHandlers;
  v9 = val;
  v = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
        (Scaleform::GFx::AS2::AvmCharacter *)((char *)this - 4),
        name);
  if ( ((unsigned __int8 (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *, int, Scaleform::GFx::AS2::Value *, _DWORD))this[-1].EventHandlers.mHash.pTable[17].SizeMask)(
         &this[-1].EventHandlers,
         v,
         val,
         0) )
  {
    return 1;
  }
  switch ( v )
  {
    case 'Y':
      if ( *(_BYTE *)(*(_DWORD *)(((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers)
                                + 116)
                    + 52) == 1 )
      {
        v11 = (const Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers);
        v12 = Scaleform::GFx::AS2::Value::ToBool(val, v11);
        Scaleform::GFx::DisplayObjectBase::SetTopmostLevelFlag(
          (Scaleform::GFx::DisplayObjectBase *)this->pProto.pObject,
          v12);
        pObject = this->pProto.pObject;
        if ( (BYTE2(pObject[1].pPrev) & 2) != 0 )
          Scaleform::GFx::MovieImpl::AddTopmostLevelCharacter(
            (Scaleform::GFx::MovieImpl *)pObject->GetObjectType,
            (int)val,
            (int)&savedregs,
            (Scaleform::GFx::Sprite *)pObject,
            v38,
            v39);
        else
          Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(
            (Scaleform::GFx::MovieImpl *)pObject->GetObjectType,
            (Scaleform::GFx::InteractiveObject *)pObject);
      }
      break;
    case 'Z':
      if ( *(_BYTE *)(*(_DWORD *)(((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers)
                                + 116)
                    + 52) == 1 )
      {
        v14 = (const Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers);
        v15 = Scaleform::GFx::AS2::Value::ToBool(val, v14);
        v16 = (Scaleform::GFx::InteractiveObject *)this->pProto.pObject;
        if ( v15 != ((v16->Flags & 4) != 0) )
        {
          Scaleform::GFx::InteractiveObject::SetNoAdvanceLocalFlag(v16, v15);
          Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList((Scaleform::GFx::InteractiveObject *)this->pProto.pObject);
          Function = this->pProto.pObject->ResolveHandler.Function;
          if ( Function )
          {
            if ( ((int)Function[2].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable
                & 4) == 0 )
              ((void (__thiscall *)(Scaleform::GFx::AS2::Object *))this->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface::__vftable[11].GetValue)(this->pProto.pObject);
          }
        }
      }
      break;
    case '[':
      if ( *(_BYTE *)(*(_DWORD *)(((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers)
                                + 116)
                    + 52) == 1
        && !Scaleform::GFx::AS2::Value::IsUndefined(val) )
      {
        v33 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers);
        v34 = Scaleform::GFx::AS2::Value::ToUInt32(val, v33);
        ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, unsigned int))this->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface::__vftable[11].DoesImplement)(
          this->pProto.pObject,
          v34);
      }
      break;
    case 'n':
      if ( *(_BYTE *)(*(_DWORD *)(((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers)
                                + 116)
                    + 52) == 1 )
      {
        vc = &this->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface::__vftable[2].DoesImplement;
        v20 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers);
        *(double *)&v21 = Scaleform::GFx::AS2::Value::ToNumber(val, v20);
        (*vc)(
          this->pProto.pObject,
          (Scaleform::GFx::AS2::Environment *)v21,
          (const Scaleform::GFx::AS2::Object *)(const Scaleform::GFx::AS2::Object *)HIDWORD(v21));
      }
      break;
    case 'o':
      if ( *(_BYTE *)(*(_DWORD *)(((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers)
                                + 116)
                    + 52) == 1 )
      {
        vd = &this->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface::__vftable[3].~Scaleform::GFx::AS2::Object;
        v22 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers);
        *(double *)&v23 = Scaleform::GFx::AS2::Value::ToNumber(val, v22);
        ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, _DWORD, _DWORD))*vd)(
          this->pProto.pObject,
          v23,
          HIDWORD(v23));
      }
      break;
    case 'p':
      if ( *(_BYTE *)(*(_DWORD *)(((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers)
                                + 116)
                    + 52) == 1 )
      {
        p_GetASCharacter = &this->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface::__vftable[3].GetASCharacter;
        v29 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers);
        *(double *)&v30 = Scaleform::GFx::AS2::Value::ToNumber(val, v29);
        ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, _DWORD, _DWORD))*p_GetASCharacter)(
          this->pProto.pObject,
          v30,
          HIDWORD(v30));
      }
      break;
    case 'q':
      if ( *(_BYTE *)(*(_DWORD *)(((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers)
                                + 116)
                    + 52) == 1 )
      {
        p_CheckAndResetCtorRef = &this->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface::__vftable[3].CheckAndResetCtorRef;
        v31 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers);
        *(double *)&v32 = Scaleform::GFx::AS2::Value::ToNumber(val, v31);
        ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, _DWORD, _DWORD))*p_CheckAndResetCtorRef)(
          this->pProto.pObject,
          v32,
          HIDWORD(v32));
      }
      break;
    case 'r':
      if ( *(_BYTE *)(*(_DWORD *)(((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers)
                                + 116)
                    + 52) == 1 )
      {
        v24 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
        if ( v24 )
        {
          if ( v24->GetObjectType(&v24->Scaleform::GFx::AS2::ObjectInterface) == Object_Array )
          {
            v25 = Scaleform::GFx::AS2::Value::ToObjectInterface(val, penv);
            v26 = 0;
            if ( v25 )
              *(_DWORD *)va = (char *)v25 - 16;
            else
              *(_DWORD *)va = 0;
            Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(&m);
            v45 = *(_DWORD *)(*(_DWORD *)va + 60);
            if ( v45 > 0 )
            {
              do
              {
                v27 = *(_DWORD *)(*(_DWORD *)va + 56);
                v28 = *(Scaleform::GFx::AS2::Value **)(v27 + 4 * v26);
                if ( v28 && Scaleform::GFx::AS2::Value::IsNumber(*(Scaleform::GFx::AS2::Value **)(v27 + 4 * v26)) )
                  m.M[0][v26] = Scaleform::GFx::AS2::Value::ToNumber(v28, penv);
                ++v26;
              }
              while ( v26 < v45 );
              v9 = val;
            }
            Scaleform::Render::Matrix4x4<float>::Transpose(&m);
            Scaleform::Render::Matrix3x4<float>::Matrix3x4<float>(&v48, &m);
            ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::Render::Matrix3x4<float> *))this->pProto.pObject->DoesImplement)(
              this->pProto.pObject,
              &v48);
          }
        }
        else
        {
          Scaleform::GFx::DisplayObjectBase::Clear3D((Scaleform::GFx::DisplayObjectBase *)this->pProto.pObject, 0);
        }
      }
      break;
    case 's':
      if ( *(_BYTE *)(*(_DWORD *)(((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers)
                                + 116)
                    + 52) == 1 )
      {
        vb = &this->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface::__vftable[4].Finalize_GC;
        v18 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))p_EventHandlers->mHash.pTable[15].SizeMask)(&this[-1].EventHandlers);
        *(double *)&v19 = Scaleform::GFx::AS2::Value::ToNumber(val, v18);
        ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, _DWORD, _DWORD))*vb)(
          this->pProto.pObject,
          v19,
          HIDWORD(v19));
      }
      break;
    default:
      break;
  }
LABEL_12:
  if ( penv->StringContext.SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    if ( *(Scaleform::GFx::ASStringNode **)(*(_DWORD *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].AVMVersion
                                          + 8) != name->pNode->pLower
      || v9->T.Type == 10 )
    {
      goto LABEL_58;
    }
  }
  else if ( name->pNode != *(Scaleform::GFx::ASStringNode **)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].AVMVersion
         || v9->T.Type == 10 )
  {
    goto LABEL_58;
  }
  p_ActsAsButton = &this->ActsAsButton;
  v36 = Scaleform::GFx::AS2::Value::ToObject(v9, 0);
  ((void (__thiscall *)(Scaleform::GFx::AS2::AvmCharacter *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))*p_ActsAsButton)(
    this,
    &penv->StringContext,
    v36);
LABEL_58:
  v37 = ((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[13].EntryCount)(&this[-1].EventHandlers);
  if ( v37 )
    return (*(int (__thiscall **)(int, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *))(*(_DWORD *)(v37 + 16) + 12))(
             v37 + 16,
             penv,
             name,
             v9,
             flags);
  else
    return 0;
}
