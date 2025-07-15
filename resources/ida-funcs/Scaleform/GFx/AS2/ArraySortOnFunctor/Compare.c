int __thiscall Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(
        Scaleform::GFx::AS2::ArraySortOnFunctor *this,
        Scaleform::GFx::AS2::Value *a,
        Scaleform::GFx::AS2::Value *b)
{
  Scaleform::GFx::AS2::Value *v4; // ecx
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
  int v26; // [esp+18h] [ebp-3Ch]
  int i; // [esp+1Ch] [ebp-38h]
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // [esp+20h] [ebp-34h]
  Scaleform::GFx::AS2::Value ba; // [esp+24h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value aa; // [esp+34h] [ebp-20h] BYREF
  _BYTE v31[16]; // [esp+44h] [ebp-10h] BYREF

  v4 = a;
  v31[0] = 0;
  if ( !a )
  {
    a = (Scaleform::GFx::AS2::Value *)v31;
    v4 = (Scaleform::GFx::AS2::Value *)v31;
  }
  v5 = b;
  if ( !b )
  {
    b = (Scaleform::GFx::AS2::Value *)v31;
    v5 = (Scaleform::GFx::AS2::Value *)v31;
  }
  p_StringContext = &this->Env->StringContext;
  v26 = 0;
  if ( !this->FunctorArray.Data.Size )
    return 0;
  for ( i = 0; ; ++i )
  {
    Env = this->Env;
    if ( v4->T.Type == 7 )
    {
      if ( Env )
      {
        pCharHandle = v4->V.pCharHandle;
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
      v13 = Scaleform::GFx::AS2::Value::ToObject(v4, this->Env);
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
    aa.T.Type = 0;
    ba.T.Type = 0;
    v23 = (int)&FieldArray->Data.Data[v26];
    if ( v12->GetMemberRaw(v12, p_StringContext, (const Scaleform::GFx::ASString *)v23, &aa)
      && v20->GetMemberRaw(v20, p_StringContext, (const Scaleform::GFx::ASString *)v23, &ba) )
    {
      v24 = Scaleform::GFx::AS2::ArraySortFunctor::Compare(&this->FunctorArray.Data.Data[i], &aa, &ba);
      if ( v24 )
        break;
    }
    if ( ba.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&ba);
    if ( aa.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&aa);
    v5 = b;
LABEL_38:
    if ( ++v26 >= this->FunctorArray.Data.Size )
      return 0;
    v4 = a;
  }
  if ( ba.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&ba);
  if ( aa.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&aa);
  return v24;
}
