Scaleform::String *__thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::GetAS3ObjectName(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::String *result)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  const __m128i ***Name; // eax
  Scaleform::String *v4; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString v7; // [esp+0h] [ebp-4h] BYREF

  v7.pNode = (Scaleform::GFx::ASStringNode *)this;
  pObject = this->pDispObj.pObject;
  if ( pObject )
  {
    Name = (const __m128i ***)Scaleform::GFx::DisplayObject::GetName(pObject, &v7);
    v4 = result;
    Scaleform::String::String(result, **Name);
    pNode = v7.pNode;
    --v7.pNode->RefCount;
    if ( !pNode->RefCount )
    {
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return result;
    }
  }
  else
  {
    v4 = result;
    Scaleform::String::String(result, (const __m128i *)uri);
  }
  return v4;
}
