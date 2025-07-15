Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::Instances::fl::RegExp::optionFlagsGet(
        Scaleform::GFx::AS3::Instances::fl::RegExp *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  const __m128i *v4; // edx
  const __m128i *v5; // edx
  const __m128i *v6; // edx
  const __m128i *v7; // edx
  const __m128i *v8; // edx

  p_EmptyStringNode = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  result->pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v4 = (const __m128i *)"g";
  if ( !this->IsGlobal )
    v4 = (const __m128i *)uri;
  Scaleform::GFx::ASString::Append(result, v4, (Scaleform::GFx::ASStringNode *)strlen(v4->m128i_i8));
  v5 = (const __m128i *)"i";
  if ( (this->OptionFlags & 1) == 0 )
    v5 = (const __m128i *)uri;
  Scaleform::GFx::ASString::Append(result, v5, (Scaleform::GFx::ASStringNode *)strlen(v5->m128i_i8));
  v6 = (const __m128i *)"m";
  if ( (this->OptionFlags & 2) == 0 )
    v6 = (const __m128i *)uri;
  Scaleform::GFx::ASString::Append(result, v6, (Scaleform::GFx::ASStringNode *)strlen(v6->m128i_i8));
  v7 = (const __m128i *)"s";
  if ( (this->OptionFlags & 4) == 0 )
    v7 = (const __m128i *)uri;
  Scaleform::GFx::ASString::Append(result, v7, (Scaleform::GFx::ASStringNode *)strlen(v7->m128i_i8));
  v8 = (const __m128i *)"x";
  if ( (this->OptionFlags & 8) == 0 )
    v8 = (const __m128i *)uri;
  Scaleform::GFx::ASString::Append(result, v8, (Scaleform::GFx::ASStringNode *)strlen(v8->m128i_i8));
  return result;
}
