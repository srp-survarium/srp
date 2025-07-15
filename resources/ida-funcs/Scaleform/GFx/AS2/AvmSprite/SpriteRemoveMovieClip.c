void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteRemoveMovieClip(Scaleform::GFx::ASStringNode *fn)
{
  Scaleform::GFx::ASStringNode *pLower; // esi
  Scaleform::GFx::InteractiveObject *RefCount; // esi
  Scaleform::GFx::ASString *Name; // eax
  Scaleform::GFx::ASStringNode *v4; // eax

  pLower = fn->pLower;
  if ( pLower )
  {
    if ( (*((int (__thiscall **)(Scaleform::GFx::ASStringNode *))pLower->pData + 2))(fn->pLower) == 2 )
      RefCount = (Scaleform::GFx::InteractiveObject *)pLower->RefCount;
    else
      RefCount = 0;
  }
  else
  {
    RefCount = (Scaleform::GFx::InteractiveObject *)*((_DWORD *)fn[1].pData + 28);
  }
  if ( RefCount )
  {
    if ( RefCount->Depth >= 0x4000 )
    {
      Scaleform::GFx::InteractiveObject::RemoveDisplayObject(RefCount);
    }
    else
    {
      Name = Scaleform::GFx::DisplayObject::GetName(RefCount, (Scaleform::GFx::ASString *)&fn);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        &RefCount->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "%s.removeMovieClip() failed - depth must be >= 0",
        Name->pNode->pData);
      v4 = fn;
      --fn->RefCount;
      if ( !v4->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v4);
    }
  }
}
