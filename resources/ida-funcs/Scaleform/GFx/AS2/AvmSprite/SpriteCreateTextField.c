void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteCreateTextField(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *Target; // esi
  Scaleform::GFx::AS2::Value *v4; // eax
  int v5; // eax
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::RefCountNTSImpl *v7; // eax
  Scaleform::RefCountNTSImpl *v8; // esi
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::InteractiveObject *v10; // eax
  int *v11; // esi
  int v12; // ebx
  Scaleform::GFx::AS2::Value *v13; // eax
  int v14; // ebx
  Scaleform::GFx::AS2::Value *v15; // eax
  int v16; // ebx
  Scaleform::GFx::AS2::Value *v17; // eax
  int v18; // ebx
  Scaleform::GFx::AS2::Value *v19; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp+14h] [ebp-A8h]
  Scaleform::GFx::AS2::Environment *v21; // [esp+30h] [ebp-8Ch]
  Scaleform::GFx::ASStringNode *v22; // [esp+50h] [ebp-6Ch] BYREF
  Scaleform::GFx::InteractiveObject *pchar; // [esp+54h] [ebp-68h]
  Scaleform::RefCountNTSImpl *v24; // [esp+58h] [ebp-64h]
  Scaleform::GFx::CharPosInfo v25; // [esp+5Ch] [ebp-60h] BYREF

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      Target = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
    else
      Target = 0;
  }
  else
  {
    Target = fn->Env->Target;
  }
  if ( Target && fn->NArgs >= 6 )
  {
    Env = fn->Env;
    v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
    v5 = (int)Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
    Scaleform::GFx::CharPosInfo::CharPosInfo(
      &v25,
      (Scaleform::GFx::ResourceId)((char *)&_sbh_sizeHeaderList.unused + 2),
      v5 + 0x4000,
      1,
      &Scaleform::Render::Cxform::Identity,
      1,
      &Scaleform::Render::Matrix2x4<float>::Identity,
      0,
      0.0,
      0,
      0,
      Blend_None);
    if ( v25.Depth <= 0x7EFFFFFDu )
    {
      v21 = fn->Env;
      v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v6, (Scaleform::GFx::ASString *)&v22, v21, -1, 0);
      v7 = (Scaleform::RefCountNTSImpl *)((int (__thiscall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::CharPosInfo *, Scaleform::GFx::ASStringNode **, _DWORD, _DWORD, int, int, _DWORD, _DWORD))Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].~Scaleform::GFx::DisplayObjectBase)(
                                           Target,
                                           &v25,
                                           &v22,
                                           0,
                                           0,
                                           -1,
                                           1,
                                           0,
                                           0);
      v8 = v7;
      v24 = v7;
      if ( v7 )
        ++v7->RefCount;
      v9 = v22;
      --v22->RefCount;
      if ( !v9->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      if ( v8 )
      {
        ((void (__thiscall *)(Scaleform::RefCountNTSImpl *, _DWORD))v8->__vftable[51].~Scaleform::RefCountNTSImpl)(
          v8,
          0);
        v10 = BYTE2(v8[7].RefCount) >> 7 != 0 ? (Scaleform::GFx::InteractiveObject *)v8 : 0;
        pchar = v10;
        if ( v10 )
          v11 = (int *)(*(int (__thiscall **)(int))(*((_DWORD *)&v10->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                    + v10->AvmObjOffset)
                                                  + 4))((int)v10 + 4 * v10->AvmObjOffset);
        else
          v11 = 0;
        v12 = *v11;
        v13 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
        (*(void (__thiscall **)(int *, _DWORD, Scaleform::GFx::AS2::Value *, _DWORD))(v12 + 140))(v11, 0, v13, 0);
        v14 = *v11;
        v15 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
        (*(void (__thiscall **)(int *, int, Scaleform::GFx::AS2::Value *, _DWORD))(v14 + 140))(v11, 1, v15, 0);
        v16 = *v11;
        v17 = Scaleform::GFx::AS2::FnCall::Arg(fn, 4);
        (*(void (__thiscall **)(int *, int, Scaleform::GFx::AS2::Value *, _DWORD))(v16 + 140))(v11, 8, v17, 0);
        v18 = *v11;
        v19 = Scaleform::GFx::AS2::FnCall::Arg(fn, 5);
        (*(void (__thiscall **)(int *, int, Scaleform::GFx::AS2::Value *, _DWORD))(v18 + 140))(v11, 9, v19, 0);
        Scaleform::GFx::AS2::Value::SetAsCharacter(fn->Result, pchar);
        Scaleform::RefCountNTSImpl::Release(v24);
      }
    }
    if ( v25.pFilters.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v25.pFilters.pObject);
  }
}
