void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteMoveTo(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::InteractiveObject *Target; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Environment *y; // [esp+4h] [ebp-10h]
  Scaleform::GFx::AS2::Environment *ya; // [esp+4h] [ebp-10h]
  float x; // [esp+10h] [ebp-4h]
  float v8; // [esp+18h] [ebp+4h]

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
      y = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      x = Scaleform::GFx::AS2::Value::ToNumber(v3, y);
      ya = fn->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      v8 = Scaleform::GFx::AS2::Value::ToNumber(v4, ya);
      Scaleform::GFx::AS2::AvmSprite::MoveTo(
        (Scaleform::GFx::AS2::AvmSprite *)(&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + Target->AvmObjOffset),
        x,
        v8);
    }
  }
}
