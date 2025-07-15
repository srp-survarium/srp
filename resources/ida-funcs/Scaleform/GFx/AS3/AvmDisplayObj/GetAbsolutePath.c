const char *__thiscall Scaleform::GFx::AS3::AvmDisplayObj::GetAbsolutePath(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::String *ppath)
{
  Scaleform::String *v2; // esi
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  Scaleform::GFx::ASStringNode *v5; // eax

  v2 = ppath;
  pParent = this->pDispObj->pParent;
  if ( pParent )
  {
    Scaleform::GFx::DisplayObject::GetAbsolutePath(pParent, ppath);
    Scaleform::String::AppendString(v2, (const __m128i *)".", 0xFFFFFFFF);
    Scaleform::GFx::DisplayObject::GetName(this->pDispObj, (Scaleform::GFx::ASString *)&ppath);
    Scaleform::String::AppendString(v2, (const __m128i *)ppath->pData, 0xFFFFFFFF);
    v5 = (Scaleform::GFx::ASStringNode *)ppath;
    --ppath[3].HeapTypeBits;
    if ( !v5->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  }
  return (const char *)((v2->HeapTypeBits & 0xFFFFFFFC) + 8);
}
