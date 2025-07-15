void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::getRendererString(
        Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *o)
{
  char *RendererString; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v8; // zf

  if ( o )
  {
    RendererString = (char *)Scaleform::GFx::DisplayObjectBase::GetRendererString(o->pDispObj.pObject);
    if ( RendererString )
    {
      Scaleform::GFx::ASString::operator=(result, RendererString);
    }
    else
    {
      pStringManager = this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
      pStringManager->EmptyStringNode.RefCount += 2;
      p_EmptyStringNode = &pStringManager->EmptyStringNode;
      pNode = result->pNode;
      v8 = result->pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      result->pNode = p_EmptyStringNode;
      v8 = p_EmptyStringNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
    }
  }
}
