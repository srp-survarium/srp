Scaleform::GFx::ASString *__cdecl Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::ASStringNode *ns,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Traits::QNameFormat f)
{
  Scaleform::GFx::ASString *p_pManager; // ecx
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASString *v6; // eax
  Scaleform::GFx::ASString *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  const Scaleform::GFx::ASString *v9; // [esp-8h] [ebp-8h]

  p_pManager = (Scaleform::GFx::ASString *)&ns[1].pManager;
  if ( ns[1].pManager->pStringNodePages )
  {
    v9 = name;
    if ( f )
      v7 = Scaleform::GFx::ASString::operator+(p_pManager, (Scaleform::GFx::ASString *)&ns, (const __m128i *)".");
    else
      v7 = Scaleform::GFx::ASString::operator+(p_pManager, (Scaleform::GFx::ASString *)&ns, (const __m128i *)"::");
    Scaleform::GFx::ASString::operator+(v7, result, v9);
    v8 = ns;
    --ns->RefCount;
    if ( !v8->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    return result;
  }
  else
  {
    pNode = name->pNode;
    v6 = result;
    result->pNode = name->pNode;
    ++pNode->RefCount;
  }
  return v6;
}
