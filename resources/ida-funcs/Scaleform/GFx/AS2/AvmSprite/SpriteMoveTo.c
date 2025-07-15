void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteMoveTo(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::InteractiveObject *Target; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp+4h] [ebp-10h]
  Scaleform::GFx::AS2::Environment *v6; // [esp+4h] [ebp-10h]
  float x; // [esp+10h] [ebp-4h]
  float y; // [esp+18h] [ebp+4h]

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
    if ( fn->NArgs >= 2 )
    {
      Env = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      x = Scaleform::GFx::AS2::Value::ToNumber(v3, Env);
      v6 = fn->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      y = Scaleform::GFx::AS2::Value::ToNumber(v4, v6);
      Scaleform::GFx::AS2::AvmSprite::MoveTo(
        (Scaleform::GFx::AS2::AvmSprite *)(&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + Target->AvmObjOffset),
        x,
        y);
    }
  }
}
