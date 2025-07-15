void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteGotoAndPlay(unsigned int fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::ObjectInterface *v2; // esi
  Scaleform::GFx::InteractiveObject *v3; // esi
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // edi
  bool v6; // zf
  const Scaleform::GFx::AS2::FnCall *v7; // eax
  Scaleform::GFx::ASString sa0; // [esp+8h] [ebp-4h] BYREF

  v1 = (const Scaleform::GFx::AS2::FnCall *)fn;
  v2 = *(Scaleform::GFx::AS2::ObjectInterface **)(fn + 8);
  if ( v2 )
  {
    if ( v2->GetObjectType(*(Scaleform::GFx::AS2::ObjectInterface **)(fn + 8)) == Object_Sprite )
      v3 = (Scaleform::GFx::InteractiveObject *)v2[1].__vftable;
    else
      v3 = 0;
  }
  else
  {
    v3 = *(Scaleform::GFx::InteractiveObject **)(*(_DWORD *)(fn + 24) + 112);
  }
  if ( v3 )
  {
    if ( v1->NArgs < 1 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptError(
        &v3->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "AvmSprite::SpriteGotoAndPlay needs one arg");
      return;
    }
    v4 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
    fn = -1;
    if ( v4->T.Type == 5 )
    {
      Scaleform::GFx::AS2::Value::ToStringImpl(v4, &sa0, v1->Env, -1, 0);
      pNode = sa0.pNode;
      if ( !v3->GetLabeledFrame(v3, sa0.pNode->pData, &fn, 1) )
      {
        v6 = pNode->RefCount-- == 1;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        return;
      }
      v6 = pNode->RefCount-- == 1;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v7 = (const Scaleform::GFx::AS2::FnCall *)fn;
    }
    else
    {
      v7 = (const Scaleform::GFx::AS2::FnCall *)(Scaleform::GFx::AS2::Value::ToUInt32(v4, v1->Env) - 1);
      fn = (unsigned int)v7;
    }
    v3->GotoFrame(v3, (unsigned int)v7);
    v3->SetPlayState(v3, State_Playing);
  }
}
