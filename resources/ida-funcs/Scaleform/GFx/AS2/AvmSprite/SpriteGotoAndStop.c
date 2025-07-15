void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteGotoAndStop(unsigned int fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::ObjectInterface *v2; // esi
  Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *v3; // esi
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::ASStringNode *v5; // edi
  bool v6; // zf
  unsigned int v7; // eax
  Scaleform::GFx::ASStringNode *v8; // [esp+8h] [ebp-4h] BYREF

  v1 = (Scaleform::GFx::AS2::FnCall *)fn;
  v2 = *(Scaleform::GFx::AS2::ObjectInterface **)(fn + 8);
  if ( v2 )
  {
    if ( v2->GetObjectType(*(Scaleform::GFx::AS2::ObjectInterface **)(fn + 8)) == Object_Sprite )
      v3 = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)v2[1].__vftable;
    else
      v3 = 0;
  }
  else
  {
    v3 = *(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> **)(*(_DWORD *)(fn + 24) + 112);
  }
  if ( v3 )
  {
    if ( v1->NArgs < 1 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptError(
        v3 + 3,
        "AvmSprite::SpriteGotoAndStop needs one arg");
      return;
    }
    v4 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
    fn = -1;
    if ( v4->T.Type == 5 )
    {
      Scaleform::GFx::AS2::Value::ToStringImpl(v4, (Scaleform::GFx::ASString *)&v8, v1->Env, -1, 0);
      v5 = v8;
      if ( !((unsigned __int8 (__thiscall *)(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *, const char *, unsigned int *, int))v3->__vftable[53].~Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>)(
              v3,
              v8->pData,
              &fn,
              1) )
      {
        v6 = v5->RefCount-- == 1;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v5);
        return;
      }
      v6 = v5->RefCount-- == 1;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
      v7 = fn;
    }
    else
    {
      v7 = Scaleform::GFx::AS2::Value::ToUInt32(v4, v1->Env) - 1;
      fn = v7;
    }
    ((void (__thiscall *)(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *, unsigned int))v3->__vftable[54].~Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>)(
      v3,
      v7);
    ((void (__thiscall *)(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *, int))v3->__vftable[56].~Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>)(
      v3,
      1);
  }
}
