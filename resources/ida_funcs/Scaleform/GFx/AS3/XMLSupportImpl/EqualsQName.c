Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::XMLSupportImpl::EqualsQName(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::CheckResult *result,
        bool *resulta,
        Scaleform::GFx::AS3::Instances::fl::QName *l,
        Scaleform::GFx::AS3::Instances::fl::QName *r)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // ecx
  Scaleform::GFx::AS3::CheckResult *v7; // eax

  pObject = l->Ns.pObject;
  if ( pObject
    && (v6 = r->Ns.pObject) != 0
    && pObject->Uri.pNode == v6->Uri.pNode
    && ((*((_BYTE *)v6 + 20) ^ *((_BYTE *)pObject + 20)) & 0xF) == 0
    && l->LocalName.pNode == r->LocalName.pNode )
  {
    *resulta = 1;
    v7 = result;
    result->Result = 1;
  }
  else
  {
    *resulta = 0;
    v7 = result;
    result->Result = 1;
  }
  return v7;
}
