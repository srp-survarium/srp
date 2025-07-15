void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteBeginFill(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::InteractiveObject *Target; // ebx
  Scaleform::GFx::InteractiveObject *v3; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  unsigned int v5; // edi
  Scaleform::GFx::AS2::Value *v6; // eax
  int v7; // edi
  double v8; // st7
  bool v9; // c0
  bool v10; // c3
  double v11; // st7
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-18h]
  Scaleform::GFx::AS2::Environment *v13; // [esp-4h] [ebp-18h]
  float v14; // [esp+18h] [ebp+4h]
  float v15; // [esp+18h] [ebp+4h]
  float v16; // [esp+18h] [ebp+4h]

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      v3 = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
    else
      v3 = 0;
    Target = v3;
  }
  else
  {
    Target = fn->Env->Target;
  }
  if ( Target )
  {
    if ( fn->NArgs <= 0 )
    {
      Scaleform::GFx::AS2::AvmSprite::SetNoFill((Scaleform::GFx::AS2::AvmSprite *)(&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                 + Target->AvmObjOffset));
      return;
    }
    Env = fn->Env;
    v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    v5 = Scaleform::GFx::AS2::Value::ToUInt32(v4, Env) | 0xFF000000;
    if ( fn->NArgs <= 1 )
      goto LABEL_14;
    v13 = fn->Env;
    v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
    v14 = Scaleform::GFx::AS2::Value::ToNumber(v6, v13);
    v7 = v5 & 0xFFFFFF;
    v15 = v14 * 255.0 / 100.0;
    v8 = v15;
    if ( v15 >= 255.0 )
    {
      v15 = 255.0;
    }
    else
    {
      v9 = v8 > 0.0;
      v10 = 0.0 == v8;
      v11 = 0.0;
      if ( !v9 && !v10 )
      {
LABEL_13:
        v16 = v11;
        v5 = ((__int64)v16 << 24) | v7;
LABEL_14:
        Scaleform::GFx::AS2::AvmSprite::BeginFill(
          (Scaleform::GFx::AS2::AvmSprite *)(&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + Target->AvmObjOffset),
          v5);
        return;
      }
    }
    v11 = v15;
    goto LABEL_13;
  }
}
