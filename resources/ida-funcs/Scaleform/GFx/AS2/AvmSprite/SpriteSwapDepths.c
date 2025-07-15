void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteSwapDepths(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *Target; // esi
  Scaleform::GFx::AS2::Value *v4; // ebx
  Scaleform::GFx::InteractiveObject *TargetByValue; // ebp
  unsigned int Depth; // ebx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // edi
  Scaleform::GFx::AS2::Environment *Env; // ecx
  int v9; // esi
  unsigned int v10; // eax
  Scaleform::GFx::InteractiveObject *ptarget; // [esp+8h] [ebp-4h]
  Scaleform::GFx::AS2::FnCall *pParent; // [esp+10h] [ebp+4h]

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( (unsigned int)(ThisPtr->GetObjectType(fn->ThisPtr) - 2) > 3 )
      Target = 0;
    else
      Target = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
  }
  else
  {
    Target = fn->Env->Target;
  }
  if ( !Target || fn->NArgs < 1 )
    return;
  pParent = (Scaleform::GFx::AS2::FnCall *)Target->pParent;
  v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
  TargetByValue = 0;
  if ( v4->T.Type == 3 || v4->T.Type == 4 )
  {
    Depth = (int)Scaleform::GFx::AS2::Value::ToNumber(v4, fn->Env) + 0x4000;
    if ( Depth > 0x7EFFFFFD )
      return;
    v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pParent;
    goto LABEL_19;
  }
  Env = fn->Env;
  if ( ((Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
      ? (unsigned int)Target
      : 0) != 0 )
  {
    ptarget = Env->Target;
    Scaleform::GFx::AS2::Environment::SetTarget(
      Env,
      (Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 ? Target : 0);
    TargetByValue = Scaleform::GFx::AS2::Environment::FindTargetByValue(fn->Env, (Scaleform::GFx::ASStringNode *)v4);
    Scaleform::GFx::AS2::Environment::SetTarget(fn->Env, ptarget);
  }
  else
  {
    TargetByValue = Scaleform::GFx::AS2::Environment::FindTargetByValue(Env, (Scaleform::GFx::ASStringNode *)v4);
  }
  if ( TargetByValue )
  {
    if ( TargetByValue != Target )
    {
      v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pParent;
      if ( pParent == (Scaleform::GFx::AS2::FnCall *)TargetByValue->pParent )
      {
        Depth = TargetByValue->Depth;
LABEL_19:
        if ( Target->Depth >= 0 )
        {
          Target->SetAcceptAnimMoves(Target, 0);
          if ( v7 )
          {
            v9 = Target->Depth;
            v10 = ((int (__thiscall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *))v7->__vftable[17].GetAS3ObjectName)(v7);
            if ( Scaleform::GFx::Sprite::SwapDepths((Scaleform::GFx::Sprite *)v7, v9, Depth, v10) )
            {
              Scaleform::Render::JPEG::JPEGRwSource::TermSource(v7);
              if ( TargetByValue )
                TargetByValue->SetAcceptAnimMoves(TargetByValue, 0);
            }
          }
        }
      }
    }
  }
}
