int __thiscall Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(
        Scaleform::GFx::AS2::ArraySortOnFunctor *this,
        Scaleform::GFx::AS2::Value *a,
        Scaleform::GFx::AS2::Value *b)
{
  Scaleform::GFx::AS2::Value *p_dummy; // ecx
  Scaleform::GFx::AS2::Value *v5; // esi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::CharacterHandle *pCharHandle; // ecx
  Scaleform::GFx::InteractiveObject *v8; // eax
  Scaleform::GFx::InteractiveObject *v9; // ecx
  int v10; // edx
  int v11; // eax
  Scaleform::GFx::AS2::ObjectInterface *v12; // ebp
  Scaleform::GFx::AS2::Object *v13; // eax
  Scaleform::GFx::AS2::Environment *v14; // eax
  Scaleform::GFx::CharacterHandle *v15; // ecx
  Scaleform::GFx::InteractiveObject *v16; // eax
  Scaleform::GFx::InteractiveObject *v17; // ecx
  int v18; // edx
  int v19; // eax
  Scaleform::GFx::AS2::ObjectInterface *v20; // edi
  Scaleform::GFx::AS2::Object *v21; // eax
  const Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *FieldArray; // eax
  int v23; // esi
  int v24; // esi
  unsigned int i; // [esp+18h] [ebp-3Ch]
  int j; // [esp+1Ch] [ebp-38h]
  Scaleform::GFx::AS2::ASStringContext *psc; // [esp+20h] [ebp-34h]
  Scaleform::GFx::AS2::Value valB; // [esp+24h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value valA; // [esp+34h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value dummy; // [esp+44h] [ebp-10h] BYREF

  p_dummy = a;
  dummy.T.Type = 0;
  if ( !a )
  {
    a = &dummy;
    p_dummy = &dummy;
  }
  v5 = b;
  if ( !b )
  {
    b = &dummy;
    v5 = &dummy;
  }
  psc = &this->Env->StringContext;
  i = 0;
  if ( !this->FunctorArray.Data.Size )
    return 0;
  for ( j = 0; ; ++j )
  {
    Env = this->Env;
    if ( p_dummy->T.Type == 7 )
    {
      if ( Env )
      {
        pCharHandle = p_dummy->V.pCharHandle;
        if ( pCharHandle )
        {
          v8 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pCharHandle, Env->Target->pASRoot->pMovieImpl);
          if ( v8 )
          {
            if ( (LOBYTE(v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
                ? (unsigned int)v8
                : 0) != 0 )
            {
              v10 = *(LOBYTE(v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
                    ? &v8->AvmObjOffset
                    : (unsigned __int8 *)65);
              v9 = LOBYTE(v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
                 ? v8
                 : 0;
              v11 = (*(int (__thiscall **)(int))(*((_DWORD *)&v9->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                 + v10)
                                               + 4))((int)v9 + 4 * v10);
              if ( v11 )
              {
                v12 = (Scaleform::GFx::AS2::ObjectInterface *)(v11 + 4);
                goto LABEL_18;
              }
            }
          }
        }
      }
    }
    else
    {
      v13 = Scaleform::GFx::AS2::Value::ToObject(p_dummy, this->Env);
      if ( v13 )
      {
        v12 = &v13->Scaleform::GFx::AS2::ObjectInterface;
        goto LABEL_18;
      }
    }
    v12 = 0;
LABEL_18:
    v14 = this->Env;
    if ( v5->T.Type == 7 )
    {
      if ( !v14
        || (v15 = v5->V.pCharHandle) == 0
        || (v16 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v15, v14->Target->pASRoot->pMovieImpl)) == 0
        || (LOBYTE(v16->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
          ? (unsigned int)v16
          : 0) == 0
        || (v18 = *(LOBYTE(v16->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
                  ? &v16->AvmObjOffset
                  : (unsigned __int8 *)65),
            v17 = LOBYTE(v16->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
                ? v16
                : 0,
            (v19 = (*(int (__thiscall **)(int))(*((_DWORD *)&v17->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                + v18)
                                              + 4))((int)v17 + 4 * v18)) == 0) )
      {
LABEL_27:
        v20 = 0;
        goto LABEL_28;
      }
      v20 = (Scaleform::GFx::AS2::ObjectInterface *)(v19 + 4);
    }
    else
    {
      v21 = Scaleform::GFx::AS2::Value::ToObject(v5, this->Env);
      if ( !v21 )
        goto LABEL_27;
      v20 = &v21->Scaleform::GFx::AS2::ObjectInterface;
    }
LABEL_28:
    if ( !v12 || !v20 )
      goto LABEL_38;
    FieldArray = this->FieldArray;
    valA.T.Type = 0;
    valB.T.Type = 0;
    v23 = (int)&FieldArray->Data.Data[i];
    if ( v12->GetMemberRaw(v12, psc, (const Scaleform::GFx::ASString *)v23, &valA)
      && v20->GetMemberRaw(v20, psc, (const Scaleform::GFx::ASString *)v23, &valB) )
    {
      v24 = Scaleform::GFx::AS2::ArraySortFunctor::Compare(&this->FunctorArray.Data.Data[j], &valA, &valB);
      if ( v24 )
        break;
    }
    if ( valB.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&valB);
    if ( valA.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&valA);
    v5 = b;
LABEL_38:
    if ( ++i >= this->FunctorArray.Data.Size )
      return 0;
    p_dummy = a;
  }
  if ( valB.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&valB);
  if ( valA.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&valA);
  return v24;
}
