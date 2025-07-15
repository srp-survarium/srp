Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::InstanceTraits::Traits::GetQualifiedName(
        Scaleform::GFx::AS3::InstanceTraits::Traits *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Traits::QNameFormat f)
{
  Scaleform::GFx::ASString *p_Uri; // esi
  Scaleform::GFx::ASStringNode *v4; // eax
  Scaleform::GFx::ASString *v5; // esi
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASString *v8; // edi
  Scaleform::GFx::ASString *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *v12; // [esp-Ch] [ebp-14h]
  Scaleform::GFx::ASString name; // [esp+4h] [ebp-4h] BYREF

  p_Uri = &this->Ns.pObject->Uri;
  ((void (__stdcall *)(Scaleform::GFx::ASString *))this->GetName)(&name);
  if ( p_Uri->pNode->Size )
  {
    v8 = result;
    v12 = result;
    if ( f )
      v9 = Scaleform::GFx::ASString::operator+(p_Uri, (Scaleform::GFx::ASString *)&result, (const __m128i *)".");
    else
      v9 = Scaleform::GFx::ASString::operator+(p_Uri, (Scaleform::GFx::ASString *)&result, (const __m128i *)"::");
    Scaleform::GFx::ASString::operator+(v9, v12, &name);
    v10 = (Scaleform::GFx::ASStringNode *)result;
    --result[3].pNode;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    pNode = name.pNode;
    --name.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return v8;
  }
  else
  {
    v4 = name.pNode;
    v5 = result;
    result->pNode = name.pNode;
    ++v4->RefCount;
    v6 = name.pNode;
    --name.pNode->RefCount;
    if ( !v6->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    return v5;
  }
}
