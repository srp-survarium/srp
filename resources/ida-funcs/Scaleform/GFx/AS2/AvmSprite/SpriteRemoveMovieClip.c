void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteRemoveMovieClip(Scaleform::GFx::ASStringNode *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *pLower; // esi
  Scaleform::GFx::InteractiveObject *v2; // esi
  Scaleform::GFx::ASString *Name; // eax
  Scaleform::GFx::ASStringNode *v4; // eax

  pLower = (Scaleform::GFx::AS2::ObjectInterface *)fn->pLower;
  if ( pLower )
  {
    if ( pLower->GetObjectType((Scaleform::GFx::AS2::ObjectInterface *)fn->pLower) == Object_Sprite )
      v2 = (Scaleform::GFx::InteractiveObject *)pLower[1].__vftable;
    else
      v2 = 0;
  }
  else
  {
    v2 = (Scaleform::GFx::InteractiveObject *)*((_DWORD *)fn[1].pData + 28);
  }
  if ( v2 )
  {
    if ( v2->Depth >= 0x4000 )
    {
      Scaleform::GFx::InteractiveObject::RemoveDisplayObject(v2);
    }
    else
    {
      Name = Scaleform::GFx::DisplayObject::GetName(v2, (Scaleform::GFx::ASString *)&fn);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        &v2->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "%s.removeMovieClip() failed - depth must be >= 0",
        Name->pNode->pData);
      v4 = fn;
      --fn->RefCount;
      if ( !v4->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v4);
    }
  }
}
