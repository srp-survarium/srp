Scaleform::String *__thiscall Scaleform::GFx::AS3::Traits::GetAS3ObjectName(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::String *result)
{
  const __m128i ***v2; // eax
  Scaleform::GFx::ASStringNode *v3; // eax
  Scaleform::GFx::ASStringNode *v5; // [esp+8h] [ebp-4h] BYREF

  v2 = (const __m128i ***)this->GetQualifiedName(this, &v5, 0);
  Scaleform::String::String(result, **v2);
  v3 = v5;
  --v5->RefCount;
  if ( !v3->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v3);
  return result;
}
