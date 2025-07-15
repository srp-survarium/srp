void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteCurveTo(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::InteractiveObject *Target; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Environment *ay; // [esp+Ch] [ebp-18h]
  Scaleform::GFx::AS2::Environment *aya; // [esp+Ch] [ebp-18h]
  Scaleform::GFx::AS2::Environment *ayb; // [esp+Ch] [ebp-18h]
  Scaleform::GFx::AS2::Environment *ayc; // [esp+Ch] [ebp-18h]
  float v11; // [esp+18h] [ebp-Ch]
  float cy; // [esp+1Ch] [ebp-8h]
  float v13; // [esp+20h] [ebp-4h]
  float v14; // [esp+28h] [ebp+4h]

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
  if ( Target )
  {
    if ( fn->NArgs >= 4 )
    {
      ay = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v13 = Scaleform::GFx::AS2::Value::ToNumber(v3, ay);
      aya = fn->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      cy = Scaleform::GFx::AS2::Value::ToNumber(v4, aya);
      ayb = fn->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
      v11 = Scaleform::GFx::AS2::Value::ToNumber(v5, ayb);
      ayc = fn->Env;
      v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
      v14 = Scaleform::GFx::AS2::Value::ToNumber(v6, ayc);
      Scaleform::GFx::AS2::AvmSprite::CurveTo(
        (Scaleform::GFx::AS2::AvmSprite *)(&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + Target->AvmObjOffset),
        v13,
        cy,
        v11,
        v14);
    }
  }
}
