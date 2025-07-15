Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASConstString::AppendCharNode(
        Scaleform::GFx::ASConstString *this,
        unsigned int ch)
{
  Scaleform::GFx::ASStringNode *result; // eax
  int pindex; // [esp+8h] [ebp-Ch] BYREF
  char pbuffer[8]; // [esp+Ch] [ebp-8h] BYREF

  pindex = 0;
  Scaleform::UTF8Util::EncodeChar(pbuffer, &pindex, ch);
  result = Scaleform::GFx::ASStringManager::CreateStringNode(
             this->pNode->pManager,
             (const __m128i *)this->pNode->pData,
             this->pNode->Size,
             (const __m128i *)pbuffer,
             (Scaleform::GFx::ASStringNode *)pindex);
  if ( (this->pNode->HashFlags & 0x8000000) != 0 && ch < 0x80 )
    result->HashFlags |= 0x8000000u;
  return result;
}
