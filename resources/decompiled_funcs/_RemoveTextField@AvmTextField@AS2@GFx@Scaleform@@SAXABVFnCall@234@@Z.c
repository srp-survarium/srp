void __cdecl Scaleform::GFx::AS2::AvmTextField::RemoveTextField(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *v3; // esi
  Scaleform::GFx::ASString *Name; // eax
  Scaleform::GFx::ASStringNode *v5; // eax

  v1 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = v1->ThisPtr;
    if ( (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 )
      v3 = 0;
    else
      v3 = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
    if ( v3->Depth >= 0x4000 )
    {
      Scaleform::GFx::InteractiveObject::RemoveDisplayObject(v3);
    }
    else
    {
      Name = Scaleform::GFx::DisplayObject::GetName(v3, (Scaleform::GFx::ASString *)&fn);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        &v3->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "%s.removeMovieClip() failed - depth must be >= 0",
        Name->pNode->pData);
      v5 = (Scaleform::GFx::ASStringNode *)fn;
      --fn->ThisFunctionRef.Function;
      if ( !v5->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    }
  }
}
