Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASConstString::AppendCharNode(
        Scaleform::GFx::ASConstString *this,
        unsigned int ch)
{
  Scaleform::GFx::ASStringNode *result; // eax
  int index; // [esp+8h] [ebp-Ch] BYREF
  char buff[8]; // [esp+Ch] [ebp-8h] BYREF

  index = 0;
  Scaleform::UTF8Util::EncodeChar(buff, &index, ch);
  result = Scaleform::GFx::ASStringManager::CreateStringNode(
             this->pNode->pManager,
             (char *)this->pNode->pData,
             this->pNode->Size,
             buff,
             (Scaleform::GFx::ASStringNode *)index);
  if ( (this->pNode->HashFlags & 0x8000000) != 0 && ch < 0x80 )
    result->HashFlags |= 0x8000000u;
  return result;
}
