void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteSwapDepths(Scaleform::GFx::Sprite *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *pWeakProxy; // esi
  Scaleform::GFx::InteractiveObject *v3; // esi
  Scaleform::GFx::AS2::Value *v4; // ebx
  Scaleform::GFx::InteractiveObject *TargetByValue; // ebp
  unsigned int v6; // ebx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // edi
  Scaleform::GFx::AS2::Environment *Depth; // ecx
  int v9; // esi
  unsigned int v10; // eax
  Scaleform::GFx::InteractiveObject *poldTarget; // [esp+8h] [ebp-4h]
  Scaleform::GFx::Sprite *pparent; // [esp+10h] [ebp+4h]

  pWeakProxy = (Scaleform::GFx::AS2::ObjectInterface *)fn->pWeakProxy;
  if ( pWeakProxy )
  {
    if ( (unsigned int)(pWeakProxy->GetObjectType((Scaleform::GFx::AS2::ObjectInterface *)fn->pWeakProxy) - 2) > 3 )
      v3 = 0;
    else
      v3 = (Scaleform::GFx::InteractiveObject *)pWeakProxy[1].__vftable;
  }
  else
  {
    v3 = *(Scaleform::GFx::InteractiveObject **)(fn->Depth + 112);
  }
  if ( !v3 || (int)fn->CreateFrame < 1 )
    return;
  pparent = (Scaleform::GFx::Sprite *)v3->pParent;
  v4 = Scaleform::GFx::AS2::FnCall::Arg((Scaleform::GFx::AS2::FnCall *)fn, 0);
  TargetByValue = 0;
  if ( v4->T.Type == 3 || v4->T.Type == 4 )
  {
    v6 = (int)Scaleform::GFx::AS2::Value::ToNumber(v4, (Scaleform::GFx::AS2::Environment *)fn->Depth) + 0x4000;
    if ( v6 > 0x7EFFFFFD )
      return;
    v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pparent;
    goto LABEL_19;
  }
  Depth = (Scaleform::GFx::AS2::Environment *)fn->Depth;
  if ( ((v3->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 ? (unsigned int)v3 : 0) != 0 )
  {
    poldTarget = Depth->Target;
    Scaleform::GFx::AS2::Environment::SetTarget(
      Depth,
      (v3->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 ? v3 : 0);
    TargetByValue = Scaleform::GFx::AS2::Environment::FindTargetByValue(
                      (Scaleform::GFx::AS2::Environment *)fn->Depth,
                      v4);
    Scaleform::GFx::AS2::Environment::SetTarget((Scaleform::GFx::AS2::Environment *)fn->Depth, poldTarget);
  }
  else
  {
    TargetByValue = Scaleform::GFx::AS2::Environment::FindTargetByValue(Depth, v4);
  }
  if ( TargetByValue )
  {
    if ( TargetByValue != v3 )
    {
      v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pparent;
      if ( pparent == TargetByValue->pParent )
      {
        v6 = TargetByValue->Depth;
LABEL_19:
        if ( v3->Depth >= 0 )
        {
          v3->SetAcceptAnimMoves(v3, 0);
          if ( v7 )
          {
            v9 = v3->Depth;
            v10 = ((int (__thiscall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *))v7->__vftable[35].ForEachChild_GC)(v7);
            if ( Scaleform::GFx::Sprite::SwapDepths((Scaleform::GFx::Sprite *)v7, v9, v6, v10) )
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
